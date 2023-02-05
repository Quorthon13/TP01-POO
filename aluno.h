#pragma once

#include <string>
#include <vector>

#include "curso.h"
#include "pessoa.h"

using namespace std;

class Curso;

class Aluno : public Pessoa {
   private:
    string matricula;
    vector<Curso*> cursos;

   public:
    Aluno();
    Aluno(string matricula, vector<Curso*> cursos);
    vector<Curso*> getCursos() const;
    void setCursos(vector<Curso*> cursos);
    string getMatricula() const;
    void setMatricula(string matricula);
    void cadastrar();
};