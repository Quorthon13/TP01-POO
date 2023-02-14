/*
** Autores:
* Diego Demétrio Santos Rodrigues - 20.2.4093
* Bruna Cristina Goncalves - 20.2.4123
* Jessica Giovana Zacarias - 20.2.4141
* Moema Vieira de Moura - 18.2.4182
*/

#include <iostream>
#include <string>
#include <vector>

#include "aluno.h"
#include "crud.h"
#include "curso.h"
#include "escola.h"
#include "gestor.h"
#include "pessoa.h"
#include "professor.h"
#include "sala.h"

using namespace std;

int obterPerfil() {
    int perfil;
    do {
        cout << "-----PERFIS-----\n1 - Aluno\n2 - Professor\n3 - Gestor\n0 - Sair\n\nInsira o perfil de acesso: ";
        cin >> perfil;
    } while (perfil < 0 || perfil > 3);
    pause();
    return perfil;
}

bool loginGestor(Escola *e) {
    string usuario, senha;
    cout << "-----LOGIN-----" << endl;
    cout << "Insira o usuario do gestor: ";
    cin >> usuario;
    cout << "Insira a senha do gestor: ";
    cin >> senha;

    return e->validarLoginGestor(usuario, senha);
}

void menuGestor(Escola *e) {
    while (true) {
        int opcao;
        cout << "-----GESTOR-----" << endl
             << "1 - Gerenciar Aluno" << endl
             << "2 - Gerenciar Professor" << endl
             << "3 - Gerenciar Curso" << endl
             << "4 - Cadastrar Sala" << endl
             << "5 - Relatorios" << endl
             << "0 - Retornar\n\nEscolha uma opcao: ";
        cin >> opcao;

        if (opcao >= 1 && opcao <= 5) {
            e->gerenciar(opcao);
        } else if (opcao == SAIR) {
            return;
        }
        pause();
    }
    pause();
}

void acessoGestor(Escola *e) {
    if (!loginGestor(e)) {
        cout << "Usuario nao encontrado, retornando ao menu principal.";
        pause();
        return;
    }
    pause();
    menuGestor(e);
}

Escola *inicializarEscola() {
    Escola *e = new Escola();
    Sala *s1 = new Sala(10), *s2 = new Sala(5), *s3 = new Sala(5), *s4 = new Sala(3);
    Curso *c1 = new Curso("c1", "c1"),
          *c2 = new Curso("c2", "c2"),
          *c3 = new Curso("c3", "c3"),
          *c4 = new Curso("c4", "c4"),
          *c5 = new Curso("c5", "c5"),
          *c6 = new Curso("c6", "c6"),
          *c7 = new Curso("c7", "c7"),
          *c8 = new Curso("c8", "c8");
    Gestor *g1 = new Gestor("00000000000", "Welinton", "zap", "admin", "admin");
    Aluno *a1 = new Aluno("00000000001", "Diego", "994781420", "20.2.4093");
    Professor *p1 = new Professor("99999999999", "Elson", "995183910");

    c5->setProfessor(p1);

    p1->setCursos({c5});
    a1->setCursos({c5});
    c5->setAlunos({a1});

    e->setSalas({s1, s2, s3, s4});
    e->setCursos({c1, c2, c3, c4, c5, c6, c7, c8});
    e->setAlunos({a1});
    e->setGestores({g1});
    e->setProfessores({p1});

    e->distribuirSalas();
    return e;
}

int main() {
    Escola *e = inicializarEscola();
    while (true) {
        switch (obterPerfil()) {
            case ALUNO:
                e->menuRelatorioAluno();
                break;
            case PROFESSOR:
                e->menuRelatorioProfessor();
                break;
            case GESTOR:
                acessoGestor(e);
                break;
            case SAIR:
                return 0;
            default:
                continue;
        }
    }
    return 0;
}
