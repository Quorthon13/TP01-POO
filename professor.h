#pragma once

#include <string>

#include "curso.h"
#include "escola.h"
#include "pessoa.h"

using namespace std;
class Curso;
class Escola;
class Professor : public Pessoa {
   private:
    vector<Curso*> cursos;

   public:
    Professor();
    Professor(string cpf, string nome, string tel);
    vector<Curso*> getCursos() const;
    void setCursos(vector<Curso*> cursos);

    void cadastrar();
    void atualizar(Escola* e);
    void excluir(Escola* e);
    void consultar();
    static Professor* listar(vector<Professor*> alunos);
};
