//
// Created by AnaBeatrizCarneiroFe on 23/10/2023.
//
#include <vector>
#include "DataReader.h"
#include "Operation.h"
#include <iostream>

int main(){
    std::list<Aluno> alunos;
    std::vector<Turma> turmas;
    std::list<Aluno> alunos_with_duplicates;


    //distribute data
    DataReader classes("../code/Data/classes.csv");
    turmas = classes.populate_class();
    DataReader students("../code/Data/students_classes.csv");
    alunos = students.populate_students(turmas);
    DataReader students_with_duplicates("../code/Data/students_classes.csv");
    alunos_with_duplicates = students_with_duplicates.populate_students_with_duplicates(turmas);

    //initialize program
    bool continues = true;
    Operation op("start", alunos, turmas, alunos_with_duplicates);
    std::cout << "Bem vindo ao Gestor de Horario 2LEIC01_G11" << std::endl;
    std::cout << "Selecione o que pretende fazer:" << std::endl;
    std::cout << "1 - Consultar" << std::endl;
    std::cout << "2 - Ordenar" << std::endl;
    std::cout << "3 - Procurar" << std::endl;
    std::cout << "4 - Gerir horario de aluno" << std::endl;
    std::cout << "5 - Desfazer ultima mudanca" << std::endl;
    std::cout << "6 - Executar" << std::endl;

    int option;

    while(continues){
        std::cin >> option;
        switch(option){
            case 1:
                op.add_request("list");
                break;
            case 2:
                op.add_request("sort");
                break;
            case 3:
                op.add_request("search");
                break;
            case 4:
                op.add_request("manage_schedule");
                break;
            case 5:
                op.add_request("undo");
                break;
            case 6:
                continues = false;
                break;
            default:
                std::cout << "Opcao invalida" << std::endl;
                break;
        }
    }
    op.operate();
    return 0;
}
