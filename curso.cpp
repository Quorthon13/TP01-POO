#include "curso.h"

#include <iomanip>
#include <iostream>
#include <string>

#include "professor.h"

Curso::Curso() : alunos() {
}

Curso::Curso(string codigo, Professor* prof, vector<Aluno*> alunos) {
    this->prof = prof;
    this->codigo = codigo;
    this->alunos = alunos;
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

bool operator<(const Curso& a, const Curso& b) {
    return a.getAlunos().size() < b.getAlunos().size();
}
