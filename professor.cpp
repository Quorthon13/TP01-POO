#include "professor.h"

#include <iostream>
#include <string>

#include "pessoa.h"

using namespace std;

Professor::Professor() : cursos() {}

vector<Curso*> Professor::getCursos() const {
    return cursos;
}

void Professor::setCursos(vector<Curso*> cursos) {
    this->cursos = cursos;
}
