#pragma once

#include <string>

#include "crud.h"

using namespace std;
class Pessoa : public Crud {
   private:
    string cpf;
    string nome;
    string tel;

   public:
    Pessoa();
    virtual ~Pessoa();
    Pessoa(string cpf, string nome, string tel);
    string getCpf() const;
    void setCpf(int cpf);
    string getNome() const;
    void setNome(string nome);
    string getTel() const;
    void setTel(string tel);
    string toString(bool gestor) const;

    void cadastrar();
    void atualizar();
};

std::ostream& operator<<(std::ostream& os, const Pessoa& p);
