#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto {
    public:
        Produto(string nome, float preco, int estoque);
        ~Produto();

        int getId() const;
        string getNome() const;
        float getPreco() const;
        int getEstoque() const;
        int getAvaliacao() const;

        void setId(int Id);
        void setNome(string nome);
        void setPreco(float preco);
        void setEstoque(int estoque);
        void setAvaliacao(int avaliacao);

        void salvarProdutoNoArquivo(const Produto& produto, const string& nomeArquivo);
        static void excluirProdutoDoArquivo(const string& nomeArquivo, const string& nomeProduto);
        void carregarProdutosDoArquivo(const string& nomeArquivo);

    private:
        int id;
        string nome;
        float preco;
        int estoque;
        int avaliacao;
    
};

#endif // PRODUTO_H
