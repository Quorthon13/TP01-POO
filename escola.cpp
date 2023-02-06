#include "escola.h"

#include <iostream>
#include <vector>
Escola::Escola() : gestores(), alunos(), professores(), cursos(), salas() {
}

/*
 * retorna true se pelo menos 1 curso possui aluno.
 */
bool Escola::cursosTemAlunos() {
    for (Curso* curso : cursos) {
        if (!curso->getAlunos().empty()) {
            return true;
        }
    }

    return false;
}

/*
 * limpa a agenda das salas
 */
void Escola::esvaziarSalas() {
    for (Sala* sala : salas) {
        sala->getCursos().clear();
    }
    for (Curso* curso : cursos) {
        curso->setNumAulas(0);
    }
}

/*
 * retorna o curso com mais alunos que possui menos de MAX_AULAS
 * caso NULL, não há mais cursos a serem distribuidos
 */
Curso* Escola::obterMaiorCurso() {
    if (cursos.empty()) {
        return NULL;
    }
    // cria uma copia dos cursos para ordenar
    vector<Curso*> vetor(cursos);
    vetor = Curso::ordenarCursos(vetor);
    while (!vetor.empty()) {
        Curso* maior = vetor[0];
        // caso tenha pelo menos que MAX_AULAS por semana, retorna maior curso
        if (maior->getNumAulas() < MAX_AULAS) {
            return maior;
        }

        // remove o curso invalido do vetor de copia
        vetor = vector<Curso*>(vetor.begin() + 1, vetor.end());
    }
    return NULL;
}

/*
 * retorna true se o curso já está sendo lecionado neste dia em outra sala
 */
bool Escola::verificarCursoMesmoDia(Curso* curso, int dia) {
    for (Sala* sala : salas) {
        try {
            Curso* c = sala->getCursos().at(dia);
            if (curso->getCodigo() == c->getCodigo()) {
                return true;
            }
        } catch (const out_of_range& e) {
            // não fazer nada
        }
    }

    return false;
}

/*
 * retorna NULL se não há salas disponíveis
 */
Sala* Escola::obterMaiorSala(Curso* curso) {
    if (salas.empty()) {
        return NULL;
    }
    // cria uma copia das salas para ordenar
    vector<Sala*> vetor(salas);
    vetor = Sala::ordenarSalas(vetor);
    while (!vetor.empty()) {
        Sala* maior = vetor[0];
        if (!maior->isSalaLotada() && !verificarCursoMesmoDia(curso, maior->getNumDias())) {
            return maior;
        }

        // remove a sala invalido do vetor de copia
        vetor = vector<Sala*>(vetor.begin() + 1, vetor.end());
    }
    return NULL;
}

void Escola::adicionarCursoEmSala(Curso* c, Sala* s) {
    c->incrementarAulas();
    s->adicionarCurso(c);
}

/*
 * retorna false se não for possível distribuir todos os cursos durante a semana
 */
bool Escola::distribuirSalas() {
    // se não há cursos ou alunos em cursos, não precisa distribuir
    if (cursos.empty()) {
        return true;
    }

    // se não há salas, não há como distribuir
    if (salas.empty()) {
        return false;
    }

    // limpa as salas para preparar para a distribuicão
    esvaziarSalas();
    while (true) {
        Curso* curso = obterMaiorCurso();
        // caso NULL, não há mais cursos a serem distribuidos
        if (curso == NULL) {
            return true;
        }

        Sala* sala = obterMaiorSala(curso);
        // caso NULL, não há salas disponíveis para alocacão

        if (sala == NULL) {
            return false;
        }

        // retorna false caso a maior sala não suporte o maior curso
        if (curso->getNumAlunos() > sala->getCapacidade()) {
            return false;
        }

        adicionarCursoEmSala(curso, sala);
    }
}

void Escola::cadastrarAluno() {
    Aluno* aluno = new Aluno;
    aluno->cadastrar();
    alunos.push_back(aluno);
}

void Escola::cadastrarProfessor() {
    Professor* prof = new Professor;
    prof->cadastrar();
    professores.push_back(prof);
}

void Escola::cadastrarCurso() {
    Curso* curso = new Curso;
    curso->cadastrar(professores);

    for (Curso* c : cursos) {
        if (curso->getCodigo() == c->getCodigo()) {
            cout << "Nao foi possivel cadastrar o curso. Ja existe um curso de codigo " << c->getCodigo() << endl;
            return;
        }
    }

    cursos.push_back(curso);
    if (!distribuirSalas()) {
        cout << "Nao foi possivel cadastrar o curso. Nao ha salas suficientes." << endl;
        cursos.pop_back();
        delete curso;
    }
}

void Escola::cadastrarSala() {
    salas.push_back(new Sala());
}

void Escola::emitirRelatorioAluno(bool gestor) {
    for (Aluno* a : alunos) {
        cout << a->toString(gestor) << "\nCursos: ";

        for (Curso* c : a->getCursos()) {
            cout << c->getCodigo() << " ";
        }
    }
}

void Escola::emitirRelatorioProfessor(bool gestor) {
    for (Professor* p : professores) {
        cout << endl
             << "------------------------------------\n"
             << p->toString(gestor) << "\nCursos: ";

        for (Curso* c : p->getCursos()) {
            cout << c->getCodigo() << " ";
        }

        cout << "------------------------------------" << endl;
    }
}

void Escola::emitirRelatorioCurso(bool gestor) {
    for (Curso* c : cursos) {
        cout << endl
             << "------------------------------------\n"
             << c->toString(gestor);

        cout << "Horarios: " << endl;
        int i = 1;
        for (Sala* sala : salas) {
            for (int dia : sala->obterDiasCurso(c)) {
                cout << "Sala " << i << " - Dia: " << Sala::obterDiaString(dia) << endl;
            }
            i++;
        }
        cout << "------------------------------------" << endl;
    }
}

void Escola::emitirRelatorioSala(bool gestor) {
    int i = 1;
    for (Sala* sala : salas) {
        cout << endl
             << "------------------------------------\n"
             << "Sala " << i << endl;
        cout << "Cursos: ";
        for (Curso* c : sala->getCursos()) {
            cout << c->getCodigo() << " ";
        }

        cout << endl
             << "Dias livres: ";
        for (int dia : sala->obterDiasLivres()) {
            cout << Sala::obterDiaString(dia) << " ";
        }

        cout << endl
             << "Dias reservados: ";
        for (int dia : sala->obterDiasReservados()) {
            cout << Sala::obterDiaString(dia) << " ";
        }
        i++;
    }
}

vector<Sala*> Escola::obterSalasCurso(Curso* c) {
    vector<Sala*> v;
    for (Sala* s : salas) {
        if (s->possuiCurso(c)) {
            v.push_back(s);
        }
    }
    return v;
}

vector<Gestor*> Escola::getGestores() {
    return gestores;
}

void Escola::setGestores(vector<Gestor*> gestores) {
    this->gestores = gestores;
}

vector<Aluno*> Escola::getAlunos() {
    return alunos;
}

void Escola::setAlunos(vector<Aluno*> alunos) {
    this->alunos = alunos;
}

vector<Professor*> Escola::getProfessores() {
    return professores;
}

void Escola::setProfessores(vector<Professor*> professores) {
    this->professores = professores;
}

vector<Curso*> Escola::getCursos() {
    return cursos;
}

void Escola::setCursos(vector<Curso*> cursos) {
    this->cursos = cursos;
}

vector<Sala*> Escola::getSalas() {
    return salas;
}

void Escola::setSalas(vector<Sala*> salas) {
    this->salas = salas;
}