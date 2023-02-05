#pragma once

#include <string>
#include <vector>

#include "curso.h"

using namespace std;
class Curso;

class Sala {
   private:
    vector<Curso> cursos;
    int capacidade;

   public:
    Sala();

    Sala(int capacidade);

    int getCapacidade() const;
    void setCapacidade(int capacidade);

    vector<Curso> getCursos() const;
    void setCursos(vector<Curso> cursos);
};
