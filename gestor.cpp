#include "gestor.h"

#include <iostream>
#include <string>

#include "pessoa.h"
Gestor::Gestor() {
}

Gestor::Gestor(string usuario, string senha) {
    this->usuario = usuario;
    this->senha = senha;
}

void Gestor::cadastrar() {
    Pessoa::cadastrar();
    cout << "Especifique o login do usuário " + Pessoa::getNome() + ": ";
    cin >> usuario;
    cout << "Especifique a senha: ";
    cin >> senha;

    cout << "Gestor cadastrado.";
}
