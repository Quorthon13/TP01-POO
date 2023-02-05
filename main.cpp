#include <iostream>

#include "aluno.h"
#include "curso.h"
#include "escola.h"
#include "gestor.h"
#include "pessoa.h"
#include "professor.h"
#include "sala.h"

using namespace std;

int main() {
    Aluno a;
    Curso c1, c2, c3;
    c1.setCodigo("c1");
    c2.setCodigo("c2");
    c3.setCodigo("c3");
    c2.setAlunos({&a, &a, &a});
    c3.setAlunos({&a, &a});
    c1.setAlunos({&a});
    vector<Curso*> cursos = Curso::ordenarCursos({&c1, &c2, &c3});
    for (Curso* c : cursos)
        cout << c->getCodigo() << " ";
    return 0;
}