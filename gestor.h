#pragma once

#include <string>

#include "pessoa.h"

using namespace std;

class Gestor : public Pessoa {
   private:
    string usuario;
    string senha;

   public:
    Gestor();
    Gestor(string cpf, string nome, string tel, string usuario, string senha);

    bool login(string usuario, string senha);
    void cadastrar();
};
