#pragma once

#include "aluno.h"
#include "curso.h"
#include "gestor.h"
#include "pessoa.h"
#include "professor.h"
#include "sala.h"

#define SAIR 0
#define ALUNO 1
#define PROFESSOR 2
#define GESTOR 3
#define CURSO 3
#define SALA 4
#define RELATORIO 5

using namespace std;

class Aluno;
class Professor;
class Gestor;
class Sala;
class Gestor;
class Pessoa;

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
    Sala* obterMaiorSala(Curso* curso);
    bool verificarCursoMesmoDia(Curso* curso, int dia);
    void adicionarCursoEmSala(Curso* c, Sala* s);
    void gerenciarAluno();
    void gerenciarProfessor();
    void gerenciarCurso();

    void cadastrarAluno();
    void cadastrarProfessor();
    void cadastrarCurso();
    void cadastrarSala();
    void atualizarAluno();
    void atualizarProfessor();
    void atualizarCurso();
    void excluirAluno();
    void excluirProfessor();
    void excluirCurso();
    void consultarAluno();
    void consultarProfessor();
    void consultarCurso();

   public:
    Escola();
    vector<Gestor*> getGestores();
    void setGestores(vector<Gestor*> gestores);
    vector<Aluno*> getAlunos();
    void setAlunos(vector<Aluno*> alunos);
    vector<Professor*> getProfessores();
    void setProfessores(vector<Professor*> professores);
    vector<Curso*> getCursos();
    void setCursos(vector<Curso*> cursos);
    vector<Sala*> getSalas();
    void setSalas(vector<Sala*> salas);

    bool distribuirSalas();
    void gerenciar(int item);
    bool validarLoginGestor(string usuario, string senha);
    void menuRelatorioGestor();
    void menuRelatorioAluno();
    void menuRelatorioProfessor();
    void emitirRelatorioAluno(bool gestor);
    void emitirRelatorioProfessor(bool gestor);
    void emitirRelatorioCurso(bool gestor);
    void emitirRelatorioSala(bool gestor);
    vector<Sala*> obterSalasCurso(Curso* c);
};