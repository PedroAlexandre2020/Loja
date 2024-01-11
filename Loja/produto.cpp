#include "produto.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;
Produto::Produto(string nome, float preco, int estoque){
    this->nome = nome;
    this->preco = preco;
    this->estoque = estoque;    
}

Produto::~Produto(){

}

string Produto::getNome() const{
    return this->nome;
}
        
float Produto::getPreco() const{
    return this->preco;
}

int Produto::getEstoque() const{
    return this->estoque;
}
int Produto::getAvaliacao() const{
    return this->avaliacao;
}
int Produto::getId() const {
    return this->id;
}

void Produto::setId(int Id) {
    this->id = Id;
}
void Produto::setNome(string nome){
    this->nome = nome;
}

void Produto::setPreco(float preco){
    this->preco = preco;
}
        
void Produto::setEstoque(int estoque){
    this->estoque = estoque;
}
void Produto::setAvaliacao(int avaliacao){
    this->avaliacao = avaliacao;
}

void Produto::salvarProdutoNoArquivo(const Produto& produto, const string& nomeArquivo) {
    // Abrir o arquivo no modo de escrita (appends)
    ofstream arquivo(nomeArquivo, ios::app);

    if (arquivo.is_open()) {
        // Salvar os campos do usuário separados por vírgula
        arquivo << produto.getNome() << ","
                << produto.getEstoque() << ","
                << produto.getPreco() << ","
                << endl;

        // Fechar o arquivo
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }
}

void Produto::carregarProdutosDoArquivo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        
        string linha;
        while (getline(arquivo, linha)) {
            
            stringstream ss(linha);

            string nome, estoqueStr, precoStr;
            getline(ss, nome, ',');
            getline(ss, estoqueStr, ',');
            getline(ss, precoStr, ',');

    
            int estoque = 0;
            try {
                estoque = stoi(estoqueStr);
            } catch (const invalid_argument& e) {
                cerr << "Erro ao converter estoque para inteiro: " << e.what() << endl;
            }

            float preco = 0;
            try {
                preco = stof(precoStr);
            } catch (const invalid_argument& e) {
                cerr << "Erro ao converter preco para float: " << e.what() << endl;
            }

            Produto produto(nome, estoque, preco);

            cout << "Produto carregado: " << produto.getNome() << ", " << produto.getEstoque() << " produto(s)" << endl;
        }

        arquivo.close();
    } else {
        cerr << "Não há produtos adicionados ainda." << endl;
    }
}
void Produto::excluirProdutoDoArquivo(const string& nomeArquivo, const string& nomeProduto) {
    ifstream arquivoEntrada(nomeArquivo);
    ofstream arquivoSaida("temp.txt");

    if (arquivoEntrada.is_open() && arquivoSaida.is_open()) {
        string linha;
        while (getline(arquivoEntrada, linha)) {
            stringstream ss(linha);
            string nome, estoqueStr, precoStr;
            getline(ss, nome, ',');
            getline(ss, estoqueStr, ',');
            getline(ss, precoStr, ',');

            if (nome != nomeProduto) {
                arquivoSaida << linha << endl;
            }
        }

        arquivoEntrada.close();
        arquivoSaida.close();

        if (remove(nomeArquivo.c_str()) == 0 && rename("temp.txt", nomeArquivo.c_str()) == 0) {
            cout << "Produto excluído com sucesso." << endl;
        } else {
            cerr << "Erro ao excluir o produto." << endl;
        }
    } else {
        cerr << "Erro ao abrir os arquivos para leitura ou escrita." << endl;
    }
}