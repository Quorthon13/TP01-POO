#pragma once

#include <string>
using namespace std;

class Pessoa {
   private:
    string cpf;
    string nome;
    string tel;

   public:
    Pessoa();
    Pessoa(string cpf, string nome, string tel);

    void cadastrar();
    string getCpf() const;
    void setCpf(int cpf);
    string getNome() const;
    void setNome(string nome);
    string getTel() const;
    void setTel(string tel);
    string toString(bool gestor) const;
};

std::ostream& operator<<(std::ostream& os, const Pessoa& p);
