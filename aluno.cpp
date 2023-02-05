#include "aluno.h"

Aluno::Aluno() : cursos() {
}

Aluno::Aluno(vector<Curso*> cursos) {
    this->cursos = cursos;
}

vector<Curso*> Aluno::getCursos() const {
    return cursos;
}

void Aluno::setCursos(vector<Curso*> cursos) {
    this->cursos = cursos;
}