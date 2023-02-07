#pragma once

#include <string>
#include <vector>

#include "curso.h"
#include "escola.h"
#include "pessoa.h"

using namespace std;

class Curso;
class Escola;
class Aluno : public Pessoa {
   private:
    string matricula;
    vector<Curso*> cursos;

    void matricularCurso(Escola* e);
    void limparCursos();

   public:
    Aluno();
    Aluno(string cpf, string nome, string tel, string matricula);
    Aluno(string matricula);
    vector<Curso*> getCursos() const;
    void setCursos(vector<Curso*> cursos);
    string getMatricula() const;
    void setMatricula(string matricula);

    void cadastrar();
    void atualizar(Escola* e);
    void excluir(Escola* e);
    void consultar();
    static Aluno* listar(vector<Aluno*> alunos);
};