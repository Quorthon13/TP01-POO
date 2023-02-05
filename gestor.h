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
    Gestor(string login, string senha);

    void cadastrar();
};
