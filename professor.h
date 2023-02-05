#pragma once

#include <string>

#include "curso.h"
#include "pessoa.h"

using namespace std;
class Curso;
class Professor : public Pessoa {
   private:
    vector<Curso*> cursos;

   public:
    Professor();

    vector<Curso*> getCursos() const;
    void setCursos(vector<Curso*> cursos);
};
