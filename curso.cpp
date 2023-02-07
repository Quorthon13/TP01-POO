#include "curso.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include "professor.h"

Curso::Curso() : alunos() {
    prof = NULL;
    numAulas = 0;
}

Curso::Curso(string codigo, string nome) {
    this->nome = nome;
    this->codigo = codigo;
    numAulas = 0;
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

void Curso::setNome(string nome) {
    this->nome = nome;
}

string Curso::getNome() const {
    return nome;
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
    getline(cin, codigo);

    cout << "Insira o nome do curso: ";
    getline(cin, nome);

    while (true) {
        int i = 1;
        for (Professor* professor : professores) {
            cout << setw(4) << i << " - " + professor->getNome() << endl;
            i++;
        }

        cout << "Selecione o numero do professor desse curso: ";
        cin >> i;
        if (i >= 1 && i <= professores.size()) {
            prof = professores[i - 1];
            break;
        }
    }

    cout << "Curso cadastrado." << endl;
}

void Curso::atualizar(Escola* e) {
    cadastrar(e->getProfessores());
}

void Curso::excluir(Escola* e) {
    // remove curso dos alunos
    for (Aluno* a : alunos) {
        vector<Curso*> v = a->getCursos();
        v.erase(remove(v.begin(), v.end(), this), v.end());
        a->setCursos(v);
    }
    // remove curso do professor
    vector<Curso*> v = prof->getCursos();
    v.erase(remove(v.begin(), v.end(), this), v.end());
    prof->setCursos(v);

    // remove curso da escola
    v = e->getCursos();
    v.erase(remove(v.begin(), v.end(), this), v.end());
    e->setCursos(v);

    if (!e->distribuirSalas()) {
        // reverte as alteracoes
        cout << "Nao foi possivel remover o curso";
        for (Aluno* a : alunos) {
            v = a->getCursos();
            v.push_back(this);
            a->setCursos(v);
        }
        v = prof->getCursos();
        v.push_back(this);
        prof->setCursos(v);

        v = e->getCursos();
        v.push_back(this);
        e->setCursos(v);

        e->distribuirSalas();
    } else {
        cout << endl
             << "Curso " << getCodigo() << " excluido com sucesso" << endl;
    }
}

void Curso::consultar(Escola* e) {
    cout << endl
         << "------------------------------------\n"
         << toString(true);

    cout << "Horarios: " << endl;
    int i = 1;
    for (Sala* sala : e->getSalas()) {
        for (int dia : sala->obterDiasCurso(this)) {
            cout << "Sala " << i << " - Dia: " << Sala::obterDiaString(dia) << endl;
        }
        i++;
    }
    cout << "------------------------------------" << endl;
}

Curso* Curso::listar(vector<Curso*> cursos) {
    int i = 1;
    for (Curso* a : cursos) {
        cout << i << " - " << a->getNome() << endl;
        i++;
    }

    cout << "0 - Retornar";

    do {
        cout << endl
             << "Escolha o curso: ";
        cin >> i;
    } while (i < 0 || i > cursos.size());

    if (i == 0) {
        return NULL;
    }

    return cursos[i - 1];
}

void Curso::incrementarAulas() {
    numAulas++;
}

/*
 * retorna o vetor com os cursos ordenados
 */
vector<Curso*> Curso::ordenarCursos(vector<Curso*> cursos) {
    sort(cursos.begin(), cursos.end(),
         [](const Curso* a, const Curso* b) {
             return (*a) < (*b);
         });
    return cursos;
}

string Curso::toString(bool gestor) {
    return "Codigo: " + codigo + "\nNome: " + nome + "\nProfessor: " + (prof != NULL ? prof->getNome() : "") + "\n";
}

bool operator<(const Curso& a, const Curso& b) {
    return a.getAlunos().size() > b.getAlunos().size();
}
