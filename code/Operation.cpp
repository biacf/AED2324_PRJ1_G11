//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#include <iostream>
#include "Operation.h"

//constructor
Operation::Operation(std::string start, std::vector<Aluno>& aluno_, std::list<Turma>& turma_, std::vector<Aluno> aluno_with_duplicate_) {
    requests.push(start);
    alunos = aluno_;
    turmas = turma_;
    alunos_with_duplicate = aluno_with_duplicate_;

    for (Aluno aluno : alunos) {
        for (const std::string& turma : aluno.unique_turmas()) {
            turma_aluno_count[turma]++;
        }
    }

}

//methods
//access list operations
void Operation::list(){
    int option;
    //display mostrar nome e numero
    std::cout << "CONSULTAR" << std::endl;
    std::cout << "1 - Ver alunos de uma turma" << std::endl;
    std::cout << "2 - Ver alunos de uma Unidade Curricular" << std::endl;
    std::cout << "3 - Ver todos os alunos" << std::endl;
    std::cout << "4 - Ver Turmas" << std::endl;
    std::cout << "5 - Ver Unidades Curriculares" << std::endl;
    std::cout << "6 - Sair" << std::endl;
    std::cin >> option;
    switch (option) {
        case 1:{
            std::vector<Aluno> alunos_da_turma_repetidos;
            std::string codigo_turma;
            std::cout<<"Codigo da Turma: "<<std::endl;
            std::cin>>codigo_turma;
            std::cout<<"Alunos pertencentes a turma "<<codigo_turma<<": "<<std::endl;
            for(const Aluno& aluno : alunos_with_duplicate){
                if(codigo_turma == aluno.get_class_code()){
                    alunos_da_turma_repetidos.push_back(aluno);
                }
            }
            std::vector<Aluno> alunos_da_turma_sem_repetidos;
            for(const Aluno& alunos : alunos_da_turma_repetidos){
                bool add = true;
                std::string nome = alunos.get_name();
                for(const Aluno& alunos : alunos_da_turma_sem_repetidos){
                    if(nome == alunos.get_name()){
                        add = false;
                        break;
                    }
                }
                if (add) {
                    alunos_da_turma_sem_repetidos.push_back(alunos);
                }
            }
            for(const Aluno& aluno: alunos_da_turma_sem_repetidos){
                std::cout<<aluno.get_name()<<", "<<aluno.get_number()<<std::endl;
            }
            break;}

        case 2:{
            std::string uc;
            std::cout<<"Codigo da Unidade Curricular: ";
            std::cin>>uc;
            std::vector<Aluno> alunos_da_uc_repetidos;
            std::cout<<"Alunos pertencentes a unidade curricular "<<uc<<": "<<std::endl;
            for(const Aluno& aluno : alunos_with_duplicate){
                if(uc == aluno.get_uc()){
                    alunos_da_uc_repetidos.push_back(aluno);
                }
            }
            std::vector<Aluno> alunos_da_uc_sem_repetidos;
            for(const Aluno& alunos : alunos_da_uc_repetidos){
                bool add = true;
                std::string nome = alunos.get_name();
                for(const Aluno& alunos : alunos_da_uc_sem_repetidos){
                    if(nome == alunos.get_name()){
                        add = false;
                        break;
                    }
                }
                if (add) {
                    alunos_da_uc_sem_repetidos.push_back(alunos);
                }
            }
            for(const Aluno& aluno: alunos_da_uc_sem_repetidos){
                std::cout<<aluno.get_name()<<", "<<aluno.get_number()<<std::endl;
            }
            break;}

        case 3:{
            std::cout<<"Alunos: "<<std::endl;
            for(const Aluno& aluno : alunos){
                std::cout<<aluno.get_name()<<", "<<aluno.get_number()<<std::endl;
            }
            break;}

        case 4:{
            std::vector<std::string> turmas_sem_repetidos;
            for(Turma& turma : turmas){
                bool add = true;
                std::string codigo_turma = turma.get_code();

                for (const std::string& code : turmas_sem_repetidos) {
                    if (code == codigo_turma) {
                        add = false;
                        break;
                    }
                }

                if (add) {
                    turmas_sem_repetidos.push_back(codigo_turma);
                }
            }
            for(std::string turmas : turmas_sem_repetidos){
                std::cout<<turmas<<std::endl;
            }
            break;}

        case 5:{
            std::vector<std::string> ucs_sem_repetidos;
            for(Turma& turma : turmas){
                bool add = true;
                std::string codigo_uc = turma.get_uc();

                for (const std::string& code : ucs_sem_repetidos) {
                    if (code == codigo_uc) {
                        add = false;
                        break;
                    }
                }

                if (add) {
                    ucs_sem_repetidos.push_back(codigo_uc);
                }
            }
            for(std::string ucs : ucs_sem_repetidos){
                std::cout<<ucs<<std::endl;
            }
            break;}
        case 6:{
            break;}

    }
}

//access sort operations
void Operation::sort() {

}

//access search operations
void Operation::search() {
    int option;
    std::string word;
    int max = turma_aluno_count.begin()->second;
    bool found = false;
    std::cout << "PROCURAR" << std::endl;
    std::cout << "1 - Procurar Nome de ALuno atraves do Numero" << std::endl;
    std::cout << "2 - Procurar Numero de Aluno atraves do Nome" << std::endl;
    std::cout << "3 - Turma com maior numero de alunos" << std::endl;
    std::cout << "4 - Turma com menos alunos" << std::endl;
    std::cout << "5 - UC com mais alunos" << std::endl;
    std::cout << "6 - UC com menos alunos" << std::endl;
    std::cout << "7 - Numero de alunos numa turma" << std::endl;
    std::cout << "8 - Numero de alunos numa UC" << std::endl;
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
        case 3:
            for(auto it = turma_aluno_count.begin(); it != turma_aluno_count.end(); it++){
                if(it->second > max){
                    max = it->second;
                    word = it->first;
                }
            }
            std::cout << "Turma: " << word << " Numero de alunos:" << std::to_string(max) << std::endl;
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
    std::list<Turma> aulas_turma_uc;
    bool possible;
    std::cout << "GESTOR DE HORARIO" << std::endl;
    std::cout << "1 - Inscrever em Turma" << std::endl;
    std::cout << "2 - Desistir de Turma" << std::endl;
    std::cout << "3 - Mudar de Turma" << std::endl;
    std::cout << "4 - Sair" << std::endl;

    std::cin >> option;

    switch(option){
        case 1:
            std::cout << "Nome de Aluno: ";
            std::cin >> nome;
            std::cout << "Codigo da Turma: ";
            std::cin >> turma_f;
            std::cout << "Codigo UC: ";
            std::cin >> uc;

            //get aulas for uc's turma
            for(Turma turma : turmas){
                if(turma.get_uc() == uc && turma.get_code() == turma_f){
                    aulas_turma_uc.push_back(turma);
                }
            }
            for(Aluno& aluno:alunos){
                if(aluno.get_name() == nome){
                    possible = aluno.add_class_check(aulas_turma_uc, turma_f, uc);
                }
            }
            if(possible){
                log.add("signup " + nome + " " + turma_f + " " + uc);
                std::cout << "Inscreveu-se com sucesso" << std::endl;
            }
            else{
                std::cout << "Nao foi possivel realizar a inscricao" << std::endl;
            }

            break;
        case 2:
            std::cout << "Nome do Aluno: ";
            std::cin >> nome;
            std::cout << "Codigo da Turma: ";
            std::cin >> turma_d;
            std::cout << "Codigo UC: ";
            std::cin >> uc;
            log.add("quit " + nome + " " + turma_d + " " + uc);

            for(Aluno aluno:alunos){
                if(aluno.get_name() == nome){
                    aluno.remove_class(turma_d, uc);
                }
            }
            std::cout << "Desistiu com sucesso." << std::endl;
            break;
        case 3:
            std::cout << "Nome do Aluno: ";
            std::cin >> nome;
            std::cout << "Codigo UC: ";
            std::cin >> uc;
            std::cout << "Turma de Origem: ";
            std::cin >> turma_d;
            std::cout << "Turma de Destino: ";
            std::cin >> turma_f;

            //get classes for final class
            for(Turma turma : turmas){
                if(turma.get_uc() == uc && turma.get_code() == turma_f){
                    aulas_turma_uc.push_back(turma);
                }
            }

            //remove from origin class
            for(Aluno aluno: alunos){
                if(aluno.get_name() == nome){
                    aluno.display_horario();
                    std::cout << "----------------------------------------------YEEEEEEE" << std::endl;
                    aluno.remove_class(turma_d, uc);
                    possible = aluno.add_class_check(aulas_turma_uc, turma_f, uc); //add to new class;
                    if(!possible){
                        aulas_turma_uc.clear();
                        for(Turma turma : turmas){
                            if(turma.get_uc() == uc && turma.get_code() == turma_d){
                                aulas_turma_uc.push_back(turma);
                            }
                        }
                        aluno.add_class_check(aulas_turma_uc, turma_d, uc);
                    }
                    aluno.display_horario();
                }
            }

            //add back to origin class if not possible
            if(possible){
                log.add("change " + nome + " " + uc + " " + turma_d + " " + turma_f );
                std::cout << "Mudanca com sucesso." << std::endl;
            }
            else{
                std::cout << "Nao foi possivel efetuar a mudanca." << std::endl;
            }
            break;
        case 4:
            break;
    }

}

//process undo operation
void Operation::undo(){
    std::cout << "UNDO" << std::endl;
    bool success;
    success = log.undo();
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

