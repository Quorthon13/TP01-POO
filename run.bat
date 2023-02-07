@echo off
del *.exe
g++ main.cpp crud.cpp pessoa.cpp professor.cpp gestor.cpp curso.cpp aluno.cpp sala.cpp escola.cpp -o escola_mil_grau
escola_mil_grau.exe