#include "gestor.h"

#include <iostream>
#include <string>

#include "pessoa.h"
Gestor::Gestor() {
}

Gestor::Gestor(string cpf, string nome, string tel, string usuario, string senha) : Pessoa(cpf, nome, tel) {
    this->usuario = usuario;
    this->senha = senha;
}

bool Gestor::login(string usuario, string senha) {
    return this->usuario == usuario && this->senha == senha;
}

void Gestor::cadastrar() {
    Pessoa::cadastrar();
    cout << "Especifique o login do usuário " + Pessoa::getNome() + ": ";
    cin >> usuario;
    cout << "Especifique a senha: ";
    cin >> senha;

    cout << "Gestor cadastrado.";
}
