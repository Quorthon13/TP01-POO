#include "crud.h"

#include <limits.h>

#include <iostream>
Crud::Crud() {
}

int Crud::menuCrud() {
    int opcao;
    do {
        cout << "1 - Cadastrar" << endl
             << "2 - Consultar" << endl
             << "3 - Excluir" << endl
             << "4 - Atualizar" << endl
             << "0 - Retornar"
             << endl
             << endl
             << "Escolha uma opcao: ";

        cin >> opcao;
    } while (opcao < 0 || opcao > 4);
    pause();
    return opcao;
}

void Crud::cadastrar() {
}

void Crud::atualizar() {
}

void Crud::excluir() {
}

void Crud::consultar() {
}

void pause() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << endl
         << "Pressione qualquer tecla para continuar..." << endl;
    getchar();
}
