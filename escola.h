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
    Sala* obterMaiorSala(Curso* curso);
    bool verificarCursoMesmoDia(Curso* curso, int dia);
    void adicionarCursoEmSala(Curso* c, Sala* s);

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
    void cadastrarAluno();
    void cadastrarProfessor();
    void cadastrarCurso();
    void cadastrarSala();
    void emitirRelatorioAluno(bool gestor);
    void emitirRelatorioProfessor(bool gestor);
    void emitirRelatorioCurso(bool gestor);
    void emitirRelatorioSala(bool gestor);
    vector<Sala*> obterSalasCurso(Curso* c);
};