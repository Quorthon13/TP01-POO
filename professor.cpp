#include "professor.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "escola.h"
#include "pessoa.h"

using namespace std;

Professor::Professor() : cursos() {}

Professor::Professor(string cpf, string nome, string tel) : Pessoa(cpf, nome, tel) {
}

vector<Curso*> Professor::getCursos() const {
    return cursos;
}

void Professor::setCursos(vector<Curso*> cursos) {
    this->cursos = cursos;
}

void Professor::cadastrar() {
    Pessoa::cadastrar();
}

void Professor::atualizar(Escola* e) {
    int opcao;
    do {
        cout << "1 - Alterar dados pessoais\n0 - Retornar\n\nEscolha uma opcao: ";
        cin >> opcao;
    } while (opcao < 0 || opcao > 3);

    switch (opcao) {
        case 1:
            Pessoa::atualizar();
            break;
    }
}

void Professor::excluir(Escola* e) {
    for (Curso* c : cursos) {
        c->setProfessor(NULL);
    }

    vector<Professor*> v = e->getProfessores();
    v.erase(remove(v.begin(), v.end(), this), v.end());
    e->setProfessores(v);

    cout << endl
         << "Professor " << getNome() << " excluido com sucesso" << endl;
}

void Professor::consultar() {
    cout << endl
         << "------------------------------------\n"
         << toString(true) << "Cursos: ";

    for (Curso* c : getCursos()) {
        cout << c->getCodigo() << " ";
    }

    cout << endl
         << "------------------------------------" << endl;
}

Professor* Professor::listar(vector<Professor*> professores) {
    int i = 1;
    for (Professor* p : professores) {
        cout << i << " - " << p->getNome() << endl;
        i++;
    }

    cout << "0 - Retornar";

    do {
        cout << endl
             << "Escolha o professor: ";
        cin >> i;
    } while (i < 0 || i > professores.size());

    if (i == 0) {
        return NULL;
    }

    return professores[i - 1];
}
