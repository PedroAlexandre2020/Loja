#include <iostream>
#include <fstream>
#include <sstream>
#include "Usuario.h"
#include "Produto.h"

using namespace std;


int main() {

    Usuario user(1, "Antonio", "12345", "1234", 20, "Antonio@email.com", "123456789");

    user.salvarUsuarioNoArquivo(user, "usuarios.txt");
    user.carregarUsuariosDoArquivo("usuarios.txt");
    user.excluirUsuarioDoArquivo("usuarios.txt", "Antonio");

    Produto product("Tenis", 89.99, 9);
    product.carregarProdutosDoArquivo("produtos.txt");
    

    return 0;
}
