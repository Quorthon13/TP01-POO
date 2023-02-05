#include "escola.h"

#include <iostream>

#define QUANT_DIAS 5

Escola::Escola() : gestores(), alunos(), professores(), cursos(), salas() {
}

/*
 * retorna true se pelo menos 1 curso possui aluno.
 */
bool Escola::cursosTemAlunos() {
    for (Curso* curso : cursos) {
        if (!curso->getAlunos().empty()) {
            return true;
        }
    }

    return false;
}

/*
 * retorna true se pelo menos 1 curso possui aluno.
 */
void Escola::esvaziarSalas() {
    for (Sala* sala : salas) {
        sala->getCursos().clear();
    }
}

/*
 * retorna false se não for possível distribuir todos os cursos durante a semana
 */
bool Escola::distribuirSalas() {
    // se não há cursos ou alunos em cursos, não precisa distribuir
    if (cursos.empty() || !cursosTemAlunos()) {
        return true;
    }

    // se não há salas, não há como distribuir
    if (salas.empty()) {
        return false;
    }

    return true;
}

void Escola::cadastrarAluno() {
    Aluno* aluno = new Aluno;
    aluno->cadastrar();
    alunos.push_back(aluno);
}

void Escola::cadastrarProfessor() {
    Professor* prof = new Professor;
    prof->cadastrar();
    professores.push_back(prof);
}

void Escola::cadastrarCurso() {
    Curso* curso = new Curso;
    curso->cadastrar(professores);
    cursos.push_back(curso);

    if (!distribuirSalas()) {
        cout << "Nao foi possivel cadastrar o curso. Nao ha salas suficientes." << endl;
        cursos.pop_back();
        delete curso;
    }
}