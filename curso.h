#pragma once

#include <string>
#include <vector>

#include "aluno.h"
#include "professor.h"

using namespace std;

// quantidade de dias de aula por semana
#define QUANT_DIAS 5
// máximo de aulas por curso
#define MAX_AULAS 2

class Aluno;
class Professor;

class Curso {
   private:
    string codigo;
    Professor* prof;
    vector<Aluno*> alunos;
    int numAulas;

   public:
    Curso();
    Curso(string codigo, Professor* prof, vector<Aluno*> alunos, int numAulas);
    Professor* getProfessor() const;
    void setProfessor(Professor* prof);
    string getCodigo() const;
    void setCodigo(string codigo);
    vector<Aluno*> getAlunos() const;
    void setAlunos(vector<Aluno*> alunos);
    int getNumAulas() const;
    void setNumAulas(int numAulas);
    int getNumAlunos();

    void cadastrar(vector<Professor*> professores);
    void incrementarAulas();
    static vector<Curso*> ordenarCursos(vector<Curso*> cursos);
};

bool operator<(const Curso& a, const Curso& b);