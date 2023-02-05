#include "pessoa.h"

#include <iostream>
#include <string>
using namespace std;

Pessoa::Pessoa() {
}

Pessoa::Pessoa(string cpf, string nome, string tel) {
    this->cpf = cpf;
    this->nome = nome;
    this->tel = tel;
}

void Pessoa::cadastrar() {
    cout << "Insira o CPF: ";
    cin >> cpf;
    cout << "Insira o nome: ";
    cin >> nome;
    cout << "Insira o telefone: ";
    cin >> tel;
}

string Pessoa::getCpf() const {
    return cpf;
}

void Pessoa::setCpf(int cpf) {
    this->cpf = cpf;
}

string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

string Pessoa::getTel() const {
    return tel;
}

void Pessoa::setTel(string tel) {
    this->tel = tel;
}

string Pessoa::toString(bool gestor) const {
    return "Nome: " + nome + "\n" + (gestor ? ("CPF: " + cpf + "\nTelefone: " + tel + "\n") : "");
}

std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
    os << p.toString(true);
    return os;
}
