#include "escola.h"

#include <iostream>

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
 * limpa a agenda das salas
 */
void Escola::esvaziarSalas() {
    for (Sala* sala : salas) {
        sala->getCursos().clear();
    }
    for (Curso* curso : cursos) {
        curso->setNumAulas(0);
    }
}

/*
 * retorna o curso com mais alunos que possui menos de MAX_AULAS
 * caso NULL, não há mais cursos a serem distribuidos
 */
Curso* Escola::obterMaiorCurso() {
    if (cursos.empty()) {
        return NULL;
    }
    // cria uma copia dos cursos para ordenar
    vector<Curso*> vetor(cursos);

    while (!vetor.empty()) {
        Curso* maior = vetor[0];
        // caso tenha menos que MAX_AULAS, retorna maior curso
        if (maior->getNumAulas() < MAX_AULAS) {
            maior->incrementarAulas();
            return maior;
        }

        // remove o curso invalido do vetor de copia
        vetor = vector<Curso*>(vetor.begin() + 1, vetor.end());
    }
    return NULL;
}

Sala* Escola::obterMaiorSala() {
    if (salas.empty()) {
        return NULL;
    }
    // cria uma copia das salas para ordenar
    vector<Curso*> vetor(cursos);

    return NULL;
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

    // limpa as salas para preparar para a distribuição
    esvaziarSalas();

    while (true) {
        Curso* curso = obterMaiorCurso();
        // caso NULL, não há mais cursos a serem distribuidos
        if (curso == NULL) {
            return true;
        }

        Sala* sala = obterMaiorSala();
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