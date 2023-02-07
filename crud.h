#pragma once

#include <string>

using namespace std;

#define CADASTRAR 1
#define CONSULTAR 2
#define EXCLUIR 3
#define ATUALIZAR 4

class Crud {
   public:
    Crud();

    static int menuCrud();
    void virtual cadastrar();
    void virtual atualizar();
    void virtual excluir();
    void virtual consultar();
};

void pause();
