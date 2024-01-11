#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Usuario {
public:
    Usuario();
    Usuario(int Id, string nome, string senha, string codigoSeguranca, int idade, string email, string numero);
    ~Usuario();

    string getNome() const;  
    string getSenha() const;
    string getCodigoSeguranca() const;  
    int getIdade() const;  
    string getEmail() const; 
    string getNumero() const;
    int getId();



    void setId(int Id);
    void setNome(string nome);
    void setSenha(string senha);
    void setCodigoSeguranca(string codigoSeguranca);
    void setIdade(int idade);
    void setEmail(string email);
    void setNumero(string numero);

    void salvarUsuarioNoArquivo(const Usuario& usuario, const string& nomeArquivo);
    void carregarUsuariosDoArquivo(const string& nomeArquivo);
    void excluirUsuarioDoArquivo(const string& nomeArquivo, const string& nomeUsuario);
    

private:
    int Id;
    string nome;
    string senha;
    string codigoSeguranca;  // codigo para recuperação de senha
    int idade;
    // string cidade; // procurar alguma API que relacione cidade e estado
    string email;
    string numero;
    float orcamento;
};

#endif // USUARIO_H
