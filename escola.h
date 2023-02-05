#pragma once

#include "aluno.h"
#include "curso.h"
#include "gestor.h"
#include "pessoa.h"
#include "professor.h"
#include "sala.h"

using namespace std;
class Escola {
   private:
    vector<Gestor*> gestores;
    vector<Aluno*> alunos;
    vector<Professor*> professores;
    vector<Curso*> cursos;
    vector<Sala*> salas;

    bool cursosTemAlunos();
    void esvaziarSalas();
    Curso* obterMaiorCurso();
    Sala* obterMaiorSala();

   public:
    Escola();

    bool distribuirSalas();
    void cadastrarAluno();
    void cadastrarProfessor();
    void cadastrarCurso();
};