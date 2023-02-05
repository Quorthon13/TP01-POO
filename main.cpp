#include <iostream>
#include <string>
#include <vector>

#include "aluno.h"
#include "curso.h"
#include "escola.h"
#include "gestor.h"
#include "pessoa.h"
#include "professor.h"
#include "sala.h"
using namespace std;

#define SAIR 0
#define ALUNO 1
#define PROFESSOR 2
#define GESTOR 3

void pause() {
    cout << endl
         << "Pressione qualquer tecla para continuar..." << endl;
    getchar();
    getchar();
}

int obterPerfil() {
    int perfil;
    do {
        cout << "-----PERFIS-----\n1 - Aluno\n2 - Professor\n3 - Gestor\n0 - Sair\n\nInsira o perfil de acesso: ";
        cin >> perfil;
    } while (perfil < 0 || perfil > 3);
    pause();
    return perfil;
}

void acessoAluno(Escola e) {
    while (true) {
        int relatorio;
        cout << "-----RELATORIOS-----\n1 - Professor\n2 - Curso\n3 - Salas\n0 - Retornar\n\nEscolha um relatorio: ";
        cin >> relatorio;
        if (relatorio == SAIR) {
            return;
        }

        switch (relatorio) {
            case 1:
                e.emitirRelatorioProfessor(false);
                break;
            case 2:
                e.emitirRelatorioCurso(false);
                break;
            case 3:
                e.emitirRelatorioSala(false);
                break;
        }
        pause();
    }
    pause();
}

Escola inicializarEscola() {
    Escola e;
    Sala *s1 = new Sala(10), *s2 = new Sala(5), *s3 = new Sala(5), *s4 = new Sala(3);
    Curso *c1 = new Curso("c1", "c1"),
          *c2 = new Curso("c2", "c2"),
          *c3 = new Curso("c3", "c3"),
          *c4 = new Curso("c4", "c4"),
          *c5 = new Curso("c5", "c5"),
          *c6 = new Curso("c6", "c6"),
          *c7 = new Curso("c7", "c7"),
          *c8 = new Curso("c8", "c8");

    vector<Sala *> salas = {s1, s2, s3, s4};
    vector<Curso *> cursos = {c1, c2, c3, c4, c5, c6, c7, c8};

    e.setSalas(salas);
    e.setCursos(cursos);
    e.distribuirSalas();
    return e;
}
int main() {
    Escola e = inicializarEscola();
    while (true) {
        switch (obterPerfil()) {
            case ALUNO:
                acessoAluno(e);
                break;
            // case PROFESSOR:
            //     acessoProfessor(e);
            //     break;
            // case GESTOR:
            //     acessoGestor(e);
            //     break;
            default:
                return 0;
        }
    }
    return 0;
}
