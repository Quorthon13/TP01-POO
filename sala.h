#pragma once

#include <string>
#include <vector>

#include "crud.h"
#include "curso.h"

// quantidade de dias de aula por semana
#define QUANT_DIAS 5

#define SEGUNDA 1
#define TERCA 2
#define QUARTA 3
#define QUINTA 4
#define SEXTA 5

using namespace std;
class Curso;

class Sala : public Crud {
   private:
    vector<Curso*> cursos;
    int capacidade;

   public:
    Sala();
    Sala(int capacidade);
    int getCapacidade() const;
    void setCapacidade(int capacidade);
    int getNumDias() const;
    vector<Curso*> getCursos() const;
    void setCursos(vector<Curso*> cursos);
    bool isSalaLotada() const;

    void cadastrar();
    static vector<Sala*> ordenarSalas(vector<Sala*> salas);
    void adicionarCurso(Curso* curso);
    static string obterDiaString(int dia);
    vector<int> obterDiasCurso(Curso* c);
    vector<int> obterDiasLivres();
    vector<int> obterDiasReservados();
    bool possuiCurso(Curso* c);
};