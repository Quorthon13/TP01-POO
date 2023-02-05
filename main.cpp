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
    Escola escola;
    escola.cadastrarProfessor();
    escola.cadastrarCurso();
    return 0;
}