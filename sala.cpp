#include "sala.h"

#include "curso.h"
Sala::Sala() : cursos() {
    this->capacidade = 0;
}

Sala::Sala(int capacidade) {
    this->capacidade = capacidade;
}

int Sala::getCapacidade() const {
    return capacidade;
}

void Sala::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

vector<Curso> Sala::getCursos() const {
    return cursos;
}

void Sala::setCursos(vector<Curso> cursos) {
    this->cursos = cursos;
}
