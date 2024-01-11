#include "usuario.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

Usuario::Usuario(){
    
}

Usuario::Usuario(int Id, string nome, string senha, string codigoSeguranca, int idade, string email, string numero){
    this->Id = Id;
    this->nome = nome;
    this->senha = senha;
    this->codigoSeguranca = codigoSeguranca;
    this->idade = idade;
    this->email = email;
    this->numero = numero;
}
Usuario::~Usuario(){

}


void Usuario::setNome(string nome){
    this->nome = nome;
}
string Usuario::getNome() const {
    return this->nome;
}

string Usuario::getSenha() const {
    return this->senha;
}

string Usuario::getCodigoSeguranca() const {
    return this->codigoSeguranca;
}

int Usuario::getIdade() const {
    return this->idade;
}

string Usuario::getEmail() const {
    return this->email;
}

string Usuario::getNumero() const {
    return this->numero;
}
void Usuario::setCodigoSeguranca(string codigoSeguranca){
    this->codigoSeguranca = codigoSeguranca;
}
void Usuario::setIdade(int idade){
    this->idade = idade;
}
void Usuario::setEmail(string email){
    this->email = email;
}
void Usuario::setNumero(string numero){
    this->numero = numero;
}

int Usuario::getId(){
    return this->Id;
}

void Usuario::setId(int Id){
    this->Id = Id;
}

void Usuario::salvarUsuarioNoArquivo(const Usuario& usuario, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo, ios::app);

    if (arquivo.is_open()) {
        arquivo << usuario.getNome() << ","
                << usuario.getSenha() << ","
                << usuario.getCodigoSeguranca() << ","
                << usuario.getIdade() << ","
                << usuario.getEmail() << ","
                << usuario.getNumero() << endl;

        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }
}

void Usuario::carregarUsuariosDoArquivo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);

            string nome, senha, codigoSeguranca, idadeStr, email, numero;
            getline(ss, nome, ',');
            getline(ss, senha, ',');
            getline(ss, codigoSeguranca, ',');
            getline(ss, idadeStr, ',');
            getline(ss, email, ',');
            getline(ss, numero, ',');

            int idade = 0;
            try {
                idade = stoi(idadeStr);
            } catch (const invalid_argument& e) {
                cerr << "Erro ao converter idade para inteiro: " << e.what() << endl;
            }

            Usuario usuario(0, nome, senha, codigoSeguranca, idade, email, numero);

            cout << "Usuario carregado: " << usuario.getNome() << ", " << usuario.getIdade() << " anos" << endl;
        }
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
    }
}

void Usuario::excluirUsuarioDoArquivo(const string& nomeArquivo, const string& nomeUsuario) {
    ifstream arquivoEntrada(nomeArquivo);
    ofstream arquivoSaida("temp.txt");


    if (arquivoEntrada.is_open() && arquivoSaida.is_open()) {
        string linha;
        while (getline(arquivoEntrada, linha)) {
            stringstream ss(linha);
            string nome, senha, codigoSeguranca, idade, email, numero;
            getline(ss, nome, ',');
            getline(ss, senha, ',');
            getline(ss, codigoSeguranca, ',');
            getline(ss, idade, ',');
            getline(ss, email, ',');
            getline(ss, numero, ',');

            if (nome != nomeUsuario) {
                arquivoSaida << linha << endl;
            }
        }

        arquivoEntrada.close();
        arquivoSaida.close();

        if (remove(nomeArquivo.c_str()) == 0 && rename("temp.txt", nomeArquivo.c_str()) == 0) {
            cout << "Usuario excluido com sucesso." << endl;
        } else {
            cerr << "Erro ao excluir o produto." << endl;
        }
    } else {
        cerr << "Erro ao abrir os arquivos para leitura ou escrita." << endl;
    }
}