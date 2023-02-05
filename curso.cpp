#include "curso.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include "professor.h"

Curso::Curso() : alunos() {
    int numAulas = 0;
}

Curso::Curso(string codigo, Professor* prof, vector<Aluno*> alunos, int numAulas) {
    this->prof = prof;
    this->codigo = codigo;
    this->alunos = alunos;
    this->numAulas = numAulas;
}

Professor* Curso::getProfessor() const {
    return prof;
}

void Curso::setProfessor(Professor* prof) {
    this->prof = prof;
}

string Curso::getCodigo() const {
    return codigo;
}

void Curso::setCodigo(string codigo) {
    this->codigo = codigo;
}

vector<Aluno*> Curso::getAlunos() const {
    return alunos;
}

void Curso::setAlunos(vector<Aluno*> alunos) {
    this->alunos = alunos;
}

int Curso::getNumAulas() const {
    return numAulas;
}

void Curso::setNumAulas(int numAulas) {
    this->numAulas = numAulas;
}

int Curso::getNumAlunos() {
    return alunos.size();
}

void Curso::cadastrar(vector<Professor*> professores) {
    cout << "Insira o codigo do curso: ";
    cin >> codigo;

    while (true) {
        int i = 1;
        for (Professor* prof : professores) {
            cout << setw(4) << i << " - " + prof->getNome() << endl;
            i++;
        }

        cout << "Selecione o numero do professor desse curso: ";
        cin >> i;
        if (i >= 1 && i <= professores.size()) {
            break;
        }
    }

    cout << "Curso cadastrado." << endl;
}

void Curso::incrementarAulas() {
    numAulas++;
}

/*
 * retorna cópia do vetor com os cursos ordenados
 */
vector<Curso*> Curso::ordenarCursos(vector<Curso*> cursos) {
    sort(cursos.begin(), cursos.end(),
         [](const Curso* a, const Curso* b) {
             return (*a) < (*b);
         });
    return cursos;
}

bool operator<(const Curso& a, const Curso& b) {
    return a.getAlunos().size() > b.getAlunos().size();
}
