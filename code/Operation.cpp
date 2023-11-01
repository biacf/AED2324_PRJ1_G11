//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#include <iostream>
#include <algorithm>
#include <utility>
#include "Operation.h"

//constructor
Operation::Operation(const std::string& start, std::list<Aluno>& aluno_, std::vector<Turma>& turma_, std::list<Aluno> aluno_with_duplicate_) {
    requests.push(start);
    alunos = aluno_;
    turmas = turma_;
    alunos_with_duplicate = std::move(aluno_with_duplicate_);

    for (Aluno aluno : alunos) {
        for (const std::string& turma : aluno.unique_turmas()) {
            turma_aluno_count[turma]++;
        }
    }
    for (Aluno aluno : alunos) {
        for (const std::string& uc : aluno.unique_ucs()) {
            uc_aluno_count[uc]++;
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
            std::cout<<"Codigo da Turma: ";
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
            for(const std::string& turmas : turmas_sem_repetidos){
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
            for(const std::string& ucs : ucs_sem_repetidos){
                std::cout<<ucs<<std::endl;
            }
            break;}
        case 6:
            break;
        default:
            std::cout << "Opcao invalida" << std::endl;
            break;
    }
}

//access sort operations
void Operation::sort() {
    int option;
    std::cout << "ORDENAR" << std::endl;
    std::cout << "1 - Ordenar alunos por ordem alfabetica" << std::endl;
    std::cout << "2 - Ordenar horario de um aluno (por dia da semana)" << std::endl;
    std::cout << "3 - Sair" << std::endl;
    std::cin >> option;

    switch(option){
        case 1:
        {
            BSTree bst;
            for (const Aluno& aluno : alunos) {
                bst.insert(aluno);
            }

            std::list<Aluno> sorted_alunos = bst.sort();
            alunos = std::move(sorted_alunos);

            for (const Aluno& aluno : alunos) {
                std::cout << aluno.get_name() << ", " << aluno.get_number() << std::endl;
            }
        }
            break;
        case 2:
        {
            std::string name;
            std::list<Turma> sorted_horario;
            std::cout << "Nome: " << std::endl;
            std::cin >> name;
            auto it = std::find_if(alunos.begin(), alunos.end(),[&name](const Aluno& aluno) {return aluno.get_name() == name;});
            if (it != alunos.end()) {
                sorted_horario = it->sort_horario();
            }

            for(Turma turma: sorted_horario){
                turma.display_turma();
            }
        }
            break;
        case 3:
            break;
        default:
            std::cout << "Opcao invalida" << std::endl;
            break;
    }
}

//access search operations
void Operation::search() {
    int option;
    std::string word;
    std::string word_turma = turma_aluno_count.begin()->first;
    std::string word_uc = uc_aluno_count.begin()->first;
    int max_turma = turma_aluno_count.begin()->second;
    int min_turma = turma_aluno_count.begin()->second;
    int max_uc = uc_aluno_count.begin()->second;
    int min_uc = uc_aluno_count.begin()->second;
    bool found = false;
    bool continue_switch = true;
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
            while(continue_switch) {
                std::cout << "Numero do aluno: ";
                std::cin >> word;

                for (const Aluno &aluno: alunos) {
                    if (aluno.get_number() == word) {
                        std::cout << aluno.get_name() << std::endl;
                        found = true;
                        continue_switch = false;
                    }
                }

                if (!found) {
                    std::cout << "Aluno nao encontrado. Insira um numero de aluno existente" << std::endl;
                    continue_switch = true;
                }
            }
            break;

        case 2:
            while(continue_switch) {
                std::cout << "Nome do aluno: ";
                std::cin >> word;

                for (const Aluno &aluno: alunos) {
                    if (aluno.get_name() == word) {
                        std::cout << aluno.get_number() << std::endl;
                        found = true;
                        continue_switch = false;

                    }
                }

                if (!found) {
                    std::cout << "Aluno nao encontrado. Insira um nome de aluno existente" << std::endl;
                    continue_switch = true;

                }
            }
            break;

        case 3:
            for(auto & it : turma_aluno_count){
                if(it.second > max_turma){
                    max_turma = it.second;
                    word_turma = it.first;
                }
            }
            std::cout << "Turma: " << word_turma << " Numero de alunos:" << max_turma <<std::endl;

            break;

        case 4:
            for(auto & it : turma_aluno_count){
                if(it.second < min_turma){
                    min_turma = it.second;
                    word_turma = it.first;
                }
            }
            std::cout << "Turma: " << word_turma << " Numero de alunos:" << min_turma << std::endl;

            break;

        case 5:
            for(auto & it : uc_aluno_count){
                if(it.second > max_uc){
                    max_uc = it.second;
                    word_uc = it.first;
                }
            }
            std::cout << "UC: " << word_uc << " Numero de alunos:" << max_uc<< std::endl;

            break;

        case 6:
            for(auto & it : uc_aluno_count){
                if(it.second < min_uc){
                    min_uc = it.second;
                    word_uc = it.first;
                }
            }
            std::cout << "UC: " << word_uc << " Numero de alunos:" << min_uc << std::endl;

            break;

        case 7:
            while(continue_switch) {
                std::string turma;
                std::cout << "Codigo da turma: ";
                std::cin >> turma;
                int num;
                for (auto & it : turma_aluno_count) {
                    if (it.first == turma) {
                        num = it.second;
                        found = true;
                    }
                }
                if(!found){
                    std::cout << "Turma nao encontrada. Insira um codigo de turma existente" << std::endl;
                    continue_switch = true;
                }
                else{
                    continue_switch = false;
                    std::cout << "Turma: " << turma << std::endl << "Numero de alunos:" << num << std::endl;
                }

            }
            break;

        case 8:
            while (continue_switch) {
                std::string uc;
                std::cout << "Codigo da UC: ";
                std::cin >> uc;
                int num;
                for (auto & it : uc_aluno_count) {
                    if (it.first == uc) {
                        num = it.second;
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "UC nao encontrada. Insira um codigo de UC existente" << std::endl;
                    continue_switch = true;
                }
                else {
                    continue_switch = false;
                    std::cout << "UC: " << uc << std::endl << "Numero de alunos:" << num << std::endl;
                }
            }
            break;
        case 9:
            return;
        default:
            std::cout << "Opcao invalida" << std::endl;
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
    std::list<Turma> uc_outras_t;
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

            //get uc turmas
            for(const Turma& turma: turmas){
                if(turma.get_uc() == uc && turma.get_code() != turma_f){
                    auto it = std::find_if(uc_outras_t.begin(), uc_outras_t.end(),[&turma_f](const Turma& turmas) {return turmas.get_code() == turma_f;});
                    if(it == uc_outras_t.end()){
                        uc_outras_t.push_back(turma);
                    }
                }
            }
            //get aulas for uc's turma
            for(const Turma& turma : turmas){
                if(turma.get_uc() == uc && turma.get_code() == turma_f){
                    aulas_turma_uc.push_back(turma);
                }
            }
            for(Aluno& aluno:alunos){
                if(aluno.get_name() == nome){
                    possible = aluno.add_class_check(aulas_turma_uc, turma_f, uc, uc_outras_t);
                    if(possible){
                        aluno.display_horario();
                    }
                    break;
                }
            }
            if(possible){
                log.add("signup " + nome + " " + turma_f + " " + uc);
                std::cout << "Inscreveu-se com sucesso" << std::endl;
                turma_aluno_count[turma_f]++;
                uc_aluno_count[uc]++;
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

            for(Aluno& aluno:alunos){
                if(aluno.get_name() == nome){
                    aluno.remove_class(turma_d, uc);
                    aluno.display_horario();
                    break;
                }
            }
            std::cout << "Desistiu com sucesso." << std::endl;
            turma_aluno_count[turma_d]--;
            uc_aluno_count[uc]--;
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

            for(const Turma& turma: turmas){
                if(turma.get_uc() == uc && turma.get_code() != turma_f){
                    auto it = std::find_if(uc_outras_t.begin(), uc_outras_t.end(),[&turma_f](const Turma& turmas) {return turmas.get_code() == turma_f;});
                    if(it == uc_outras_t.end()){
                        uc_outras_t.push_back(turma);
                    }
                }
            }
            //get classes for final class
            for(const Turma& turma : turmas){
                if(turma.get_uc() == uc && turma.get_code() == turma_f){
                    aulas_turma_uc.push_back(turma);
                }
            }

            //remove from origin class
            for(Aluno& aluno: alunos){
                if(aluno.get_name() == nome){
                    if(std::find(aluno.unique_ucs().begin(), aluno.unique_ucs().end(), uc) == aluno.unique_ucs().end()){
                        std::cout << "Nao foi possivel mudar pois aluno nao esta inscrito nessa uc" << std::endl;
                        break;
                    }
                    aluno.remove_class(turma_d, uc);
                    possible = aluno.add_class_check(aulas_turma_uc, turma_f, uc, uc_outras_t); //add to new class;
                    //add back to original class if not possible
                    if(!possible){
                        aulas_turma_uc.clear();
                        for(const Turma& turma : turmas){
                            if(turma.get_uc() == uc && turma.get_code() == turma_d){
                                aulas_turma_uc.push_back(turma);
                            }
                        }
                        aluno.add_class_check(aulas_turma_uc, turma_d, uc, uc_outras_t);
                    }
                    else{
                        aluno.display_horario();
                    }
                    break;
                }
            }


            if(possible){
                log.add("change " + nome + " " + uc + " " + turma_d + " " + turma_f );
                std::cout << "Mudanca com sucesso." << std::endl;
                turma_aluno_count[turma_d]--;
                turma_aluno_count[turma_f]++;
            }
            else{
                std::cout << "Nao foi possivel efetuar a mudanca." << std::endl;
            }
            break;
        case 4:
            return;
        default:
            std::cout << "Opcao invalida" << std::endl;
    }

}

//process undo operation
void Operation::undo(){
    std::cout << "UNDO" << std::endl;
    bool success;
    success = log.undo(alunos, turmas);
    if(success){
        std::cout << "Acao desfeita com sucesso." << std::endl;
    }
    else{
        std::cout << "Nao foi possivel desfazer a acao." << std::endl;
    }

    //update
    for (Aluno aluno : alunos) {
        for (const std::string& turma : aluno.unique_turmas()) {
            turma_aluno_count[turma]++;
        }
    }
    for (Aluno aluno : alunos) {
        for (const std::string& uc : aluno.unique_ucs()) {
            uc_aluno_count[uc]++;
        }
    }
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

