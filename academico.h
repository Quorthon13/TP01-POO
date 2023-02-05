#pragma once
#include <string>
#include <vector>

#include "curso.h"

using namespace std;

class Academico {
   public:
    virtual vector<Curso *> getCursos() = 0;
    virtual void setCursos(const vector<Curso *> cursos) = 0;
};