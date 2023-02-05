#include "aluno.h"

#include <iostream>
#include <string>

Aluno::Aluno() : cursos() {
}

Aluno::Aluno(string matricula, vector<Curso*> cursos) {
    this->matricula = matricula;
    this->cursos = cursos;
}

vector<Curso*> Aluno::getCursos() const {
    return cursos;
}

void Aluno::setCursos(vector<Curso*> cursos) {
    this->cursos = cursos;
}

string Aluno::getMatricula() const {
    return matricula;
}

void Aluno::setMatricula(string matricula) {
    this->matricula = matricula;
}

void Aluno::cadastrar() {
    Pessoa::cadastrar();
    cout << "Insira a matrícula do aluno: ";
    cin >> matricula;
}