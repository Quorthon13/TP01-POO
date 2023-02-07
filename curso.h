#pragma once

#include <string>
#include <vector>

#include "aluno.h"
#include "crud.h"
#include "professor.h"

using namespace std;
// máximo de aulas por curso
#define MAX_AULAS 2

class Aluno;
class Professor;

class Curso : public Crud {
   private:
    string codigo;
    string nome;
    Professor* prof;
    vector<Aluno*> alunos;
    int numAulas;

   public:
    Curso();
    Curso(string codigo, string nome);
    Professor* getProfessor() const;
    void setProfessor(Professor* prof);
    string getCodigo() const;
    void setCodigo(string codigo);
    string getNome() const;
    void setNome(string nome);
    vector<Aluno*> getAlunos() const;
    void setAlunos(vector<Aluno*> alunos);
    int getNumAulas() const;
    void setNumAulas(int numAulas);
    int getNumAlunos();

    void cadastrar(vector<Professor*> professores);
    void atualizar(Escola* e);
    void excluir(Escola* e);
    void consultar(Escola* e);
    static Curso* listar(vector<Curso*> alunos);

    void incrementarAulas();
    static vector<Curso*> ordenarCursos(vector<Curso*> cursos);
    string toString(bool gestor);
};

bool operator<(const Curso& a, const Curso& b);