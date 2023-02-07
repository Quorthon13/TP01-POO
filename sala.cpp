#include "sala.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include "curso.h"
Sala::Sala() : cursos() {
    this->capacidade = 0;
}

Sala::Sala(int capacidade) : cursos() {
    this->capacidade = capacidade;
}

int Sala::getCapacidade() const {
    return capacidade;
}

void Sala::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

int Sala::getNumDias() const {
    return cursos.size();
}

vector<Curso*> Sala::getCursos() const {
    return cursos;
}

void Sala::setCursos(vector<Curso*> cursos) {
    this->cursos = cursos;
}

// returna true se a sala está ocupada nos QUANT_DIAS da semana
bool Sala::isSalaLotada() const {
    return getNumDias() >= QUANT_DIAS;
}

void Sala::cadastrar() {
    cout << "Insira a capacidade da sala: ";
    cin >> capacidade;
}

vector<Sala*> Sala::ordenarSalas(vector<Sala*> salas) {
    sort(salas.begin(), salas.end(),
         [](const Sala* a, const Sala* b) {
             return a->getCapacidade() > b->getCapacidade();
         });
    return salas;
}

void Sala::adicionarCurso(Curso* curso) {
    this->cursos.push_back(curso);
}

string Sala::obterDiaString(int dia) {
    switch (dia) {
        case SEGUNDA:
            return "Segunda-feira";
        case TERCA:
            return "Terca-feira";
        case QUARTA:
            return "Quarta-feira";
        case QUINTA:
            return "Quinta-feira";
        case SEXTA:
            return "Sexta-feira";
        default:
            return "erro";
    }
}

vector<int> Sala::obterDiasCurso(Curso* c) {
    vector<int> dias;

    int i = 1;
    for (Curso* curso : cursos) {
        if (curso->getCodigo() == c->getCodigo()) {
            dias.push_back(i);
        }
        i++;
    }

    return dias;
}

vector<int> Sala::obterDiasReservados() {
    vector<int> dias;

    int i = 1;
    for (Curso* c : cursos) {
        dias.push_back(i++);
    }

    return dias;
}

vector<int> Sala::obterDiasLivres() {
    vector<int> dias;

    int i = getNumDias();
    while (i < QUANT_DIAS) {
        dias.push_back(++i);
    }

    return dias;
}

bool Sala::possuiCurso(Curso* c) {
    for (Curso* curso : cursos) {
        if (curso->getCodigo() == c->getCodigo()) {
            return true;
        }
    }
    return false;
}
