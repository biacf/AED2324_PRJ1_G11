//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#include <iostream>
#include "Operation.h"

//constructor
Operation::Operation(std::string start, std::vector<Aluno> aluno, std::list<Turma> turma) {
    requests.push(start);
    alunos = aluno;
    turmas = turma;
}

//methods
//access list operations
void Operation::list(){

}

//access sort operations
void Operation::sort() {

}

//access search operations
void Operation::search() {
    int option;
    std::string word;
    bool found = false;
    std::cout << "PROCURAR" << std::endl;
    std::cout << "1 - Procurar Nome de ALuno atraves do Numero" << std::endl;
    std::cout << "2 - Procurar Numero de Aluno atraves do Nome" << std::endl;
    /*
    std::cout << "3 - Turma com maior numero de alunos" << std::endl;
    std::cout << "4 - Turma com menos alunos" << std::endl;
    std::cout << "5 - UC com mais alunos" << std::endl;
    std::cout << "6 - UC com menos alunos" << std::endl;
    std::cout << "7 - Numero de alunos numa turma" << std::endl;
    std::cout << "8 - Numero de alunos numa UC" << std::endl;
     */
    std::cout << "9 - Sair" << std::endl;

    std::cin >> option;

    switch(option){
        case 1:
            std::cout << "Numero do aluno: ";
            std::cin >> word;

            for(const Aluno& aluno : alunos){
                if(aluno.get_number() == word){
                    std::cout << aluno.get_name() << std::endl;
                    found = true;
                }
            }

            if(!found){
                std::cout << "Aluno nao encontrado." << std::endl;
            }

            break;
        case 2:
            std::cout << "Nome do aluno: ";
            std::cin >> word;

            for(const Aluno& aluno : alunos){
                if(aluno.get_name() == word){
                    std::cout << aluno.get_number() << std::endl;
                    found = true;
                }
            }

            if(!found){
                std::cout << "Aluno nao encontrado." << std::endl;
            }

            break;
            /*
        case 3:
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            break;
        case 8:
            break;
             */
        case 9:
            break;
    }
}

//access schedule manager operations
void Operation::schedule_manager() {
    int option;
    std::string nome;
    std::string turma_d;
    std::string uc;
    std::string turma_f;
    std::cout << "Gestor de Horario" << std::endl;
    std::cout << "1 - Inscrever em Turma" << std::endl;
    std::cout << "2 - Desistir de Turma" << std::endl;
    std::cout << "3 - Mudar de Turma" << std::endl;
    std::cout << "4 - Sair" << std::endl;

    std::cin >> option;

    switch(option){
        case 1:
            break;
        case 2:
            std::cout << "Nome do Aluno: ";
            std::cin >> nome;
            std::cout << "Codigo da Turma: ";
            std::cin >> turma_d;
            std::cout << "Codigo UC: ";
            std::cin >> uc;

            
            break;
        case 3:
            break;
        case 4:
            break;
    }

}

//process undo operation
void Operation::undo(){
}

//run
void Operation::operate() {
    while(true){
        if(requests.front() == "start"){
            requests.pop();
        }
        else if(requests.front() == "list"){
            list();
            requests.pop();
        }
        else if(requests.front() == "sort"){
            sort();
            requests.pop();
        }
        else if(requests.front() == "search"){
            search();
            requests.pop();
        }
        else if(requests.front() == "manage_schedule"){
            schedule_manager();
            requests.pop();
        }
        else if(requests.front() == "undo"){
            undo();
            requests.pop();
        }
        else if(requests.empty()){
            return;
        }
    }

}

//add request
void Operation::add_request(const std::string &request) {
    requests.push(request);
}

