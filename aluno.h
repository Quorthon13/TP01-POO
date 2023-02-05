#pragma once

#include <string>
#include <vector>

#include "curso.h"
#include "pessoa.h"

using namespace std;

class Curso;

class Aluno : public Pessoa {
   private:
    vector<Curso*> cursos;

   public:
    Aluno();
    Aluno(vector<Curso*> cursos);

    vector<Curso*> getCursos() const;
    void setCursos(vector<Curso*> cursos);
};