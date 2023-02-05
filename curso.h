#pragma once

#include <string>
#include <vector>

#include "aluno.h"
#include "professor.h"

using namespace std;

class Aluno;
class Professor;

class Curso {
   private:
    string codigo;
    Professor* prof;
    vector<Aluno*> alunos;

   public:
    Curso();
    Curso(string codigo, Professor* prof, vector<Aluno*> alunos);

    Professor* getProfessor() const;
    void setProfessor(Professor* prof);

    string getCodigo() const;
    void setCodigo(string codigo);

    vector<Aluno*> getAlunos() const;
    void setAlunos(vector<Aluno*> alunos);

    void cadastrar(vector<Professor*> professores);
};

bool operator<(const Curso& a, const Curso& b);