#include "aluno.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "aluno.h"
#include "curso.h"
#include "escola.h"
#include "pessoa.h"

using namespace std;

void Aluno::limparCursos() {
    for (Curso* c : cursos) {
        vector<Aluno*> v = c->getAlunos();
        v.erase(remove(v.begin(), v.end(), this), v.end());

        c->setAlunos(v);
    }
    cursos = {};
}

void Aluno::matricularCurso(Escola* e) {
    int i = 1;
    for (Curso* c : e->getCursos()) {
        cout << i << " - " << c->getCodigo() << ": " << c->getNome() << endl;
        i++;
    }

    do {
        cout << "Escolha o curso a ser matriculado: ";
        cin >> i;
    } while (i < 1 || i > e->getCursos().size());

    Curso* c = e->getCursos()[i - 1];
    if (find(cursos.begin(), cursos.end(), c) != cursos.end()) {
        cout << "O aluno ja se encontra matriculado neste curso." << endl;
    } else {
        vector<Aluno*> alunos = c->getAlunos();
        alunos.push_back(this);
        c->setAlunos(alunos);

        cursos.push_back(c);
        if (!e->distribuirSalas()) {
            cout << "Nao foi possivel adicionar o aluno na sala.";
            cursos.pop_back();
            alunos.pop_back();
            c->setAlunos(alunos);
        }
    }
}

Aluno::Aluno() : cursos() {
}

Aluno::Aluno(string cpf, string nome, string tel, string matricula) : Pessoa(cpf, nome, tel) {
    this->matricula = matricula;
}

Aluno::Aluno(string matricula) {
    this->matricula = matricula;
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
    cout << "Insira a matricula do aluno: ";
    cin >> matricula;
}

void Aluno::atualizar(Escola* e) {
    int opcao;
    do {
        cout << "1 - Alterar dados pessoais\n2 - Matricular em curso\n3 - Limpar cursos\n0 - Retornar\n\nEscolha uma opcao: ";
        cin >> opcao;
    } while (opcao < 0 || opcao > 3);

    switch (opcao) {
        case 1:
            Pessoa::atualizar();
            break;
        case 2:
            matricularCurso(e);
            break;
        case 3:
            limparCursos();
            break;
    }
}

void Aluno::excluir(Escola* e) {
    for (Curso* c : cursos) {
        vector<Aluno*> v = c->getAlunos();
        v.erase(remove(v.begin(), v.end(), this), v.end());
        c->setAlunos(v);
    }
    vector<Aluno*> v = e->getAlunos();
    v.erase(remove(v.begin(), v.end(), this), v.end());
    e->setAlunos(v);

    if (!e->distribuirSalas()) {
        // reverte as alteracoes
        cout << "Nao foi possivel remover o aluno";
        for (Curso* c : cursos) {
            vector<Aluno*> v = c->getAlunos();
            v.push_back(this);
            c->setAlunos(v);
        }
        vector<Aluno*> v = e->getAlunos();
        v.push_back(this);
        e->setAlunos(v);

        e->distribuirSalas();
    } else {
        cout << endl
             << "Aluno " << getNome() << " excluido com sucesso" << endl;
    }
}

void Aluno::consultar() {
    cout << endl
         << "------------------------------------\n"
         << toString(true) << "Cursos: ";

    for (Curso* c : getCursos()) {
        cout << c->getCodigo() << " ";
    }

    cout << endl
         << "------------------------------------" << endl;
}

Aluno* Aluno::listar(vector<Aluno*> alunos) {
    int i = 1;
    for (Aluno* a : alunos) {
        cout << i << " - " << a->getNome() << " - " << a->getMatricula() << endl;
        i++;
    }

    cout << "0 - Retornar";

    do {
        cout << endl
             << "Escolha o aluno: ";
        cin >> i;
    } while (i < 0 || i > alunos.size());

    if (i == 0) {
        return NULL;
    }

    return alunos[i - 1];
}
