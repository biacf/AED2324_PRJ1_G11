//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Aluno.h"
#include <map>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <utility>

//constructor
Aluno::Aluno(std::string name_, std::string student_number_) : name(std::move(name_)), student_number(std::move(student_number_)) {}
Aluno::Aluno(std::string name_, std::string student_number_, std::string uc_, std::string class_code_ ): name(std::move(name_)), student_number(std::move(student_number_)), uc(std::move(uc_)), class_code(std::move(class_code_)) {}

//getters
void Aluno::display_horario() {
    auto it = horario.begin();
    while(it != horario.end()){
        std::cout << std::fixed << std::setprecision(1) <<"Class code: " << it->get_code() << ", UC: " << it->get_uc() << ", Weekday: " << it->get_weekday() << ", Start Time: " << std::to_string(it->get_start_time()) << ", Duration: " << std::to_string(it->get_duration()) << ", Type: " << it->get_type() << std::endl;
        it++;
    }
}

//returns vector of turmas that the aluno is signed up for
std::vector<std::string> Aluno::unique_turmas(){
    std::vector<std::string> returns;
    for(const Turma& turma : horario){
        if(find(returns.begin(), returns.end(), turma.get_code()) == returns.end()){
            returns.push_back(turma.get_code());
        }
    }

    return returns;
}

//returns vector of ucs that the aluno is signed up for
std::vector<std::string> Aluno::unique_ucs(){
    std::vector<std::string> returns;
    for(const Turma& turma : horario){
        if(find(returns.begin(), returns.end(), turma.get_uc()) == returns.end()){
            returns.push_back(turma.get_uc());
        }
    }

    return returns;
}

//methods
//add class to schedule
void Aluno::add_class(const Turma& turma) {
    horario.push_back(turma);
}

//remove class from schedule
void Aluno::remove_class(const std::string& code_, const std::string& uc_) {
    for(auto it = horario.begin(); it != horario.end(); it++){
        if(it->get_code() == code_ && it->get_uc() == uc_){
            horario.erase(it);
        }
    }
}

//checks for schedule conflits before signing up for class
bool Aluno::add_class_check(std::list<Turma> turmas, const std::string& code_, const std::string& uc_, const std::list<Turma>& outras_t_uc) {
    bool flag = true;
    for (const Turma& turma : outras_t_uc) {
        int count_difference = abs(turma.get_n_alunos() - turmas.front().get_n_alunos());
        if (count_difference > 4 && (turmas.front().get_n_alunos() < turma.get_n_alunos())) {
            std::cout << "Diferenca de numero de alunos maior que 4. Inscricao sem sucesso." << std::endl;
            return false;
        }
    }


    if(!horario.empty()) {
        for (const Turma& turma: horario) {
            //move on if turma is T
            if (turma.get_type() == "T") {
                continue;
            }

            if (turma.get_uc() == uc) {
                std::cout << "Aluno ja inscrito nessa cadeira. Inscricao sem sucesso." << std::endl;
                flag = false;
                break;
            }


            for (const Turma& turma_c: turmas) {
                //move on if turma is T
                if (turma_c.get_type() == "T") {
                    continue;
                } else if (turma_c.get_weekday() != turma.get_weekday()) {
                    continue;
                } else {
                    if (((turma.get_start_time() < turma_c.get_end_time()) && (turma_c.get_start_time() < turma.get_end_time())) ||
                        ((turma.get_end_time() > turma_c.get_start_time()) &&(turma_c.get_end_time() > turma.get_start_time()))) {
                        flag = false;
                    }
                }
            }
        }

    }
    if(flag){
        for(const Turma& turma : turmas){
            this->add_class(turma);
        }
    }

    return flag;
}

std::list<Turma> Aluno::sort_horario(){
    std::list<Turma> sorted;
    sorted = horario;
    sorted.sort(turma_comp);
    return sorted;
}

bool  Aluno::turma_comp(const Turma& turma1, const Turma& turma2){
    std::map<std::string, int> weekday_map = {
            {"Monday",    0},
            {"Tuesday",   1},
            {"Wednesday", 2},
            {"Thursday",  3},
            {"Friday",    4},
            {"Saturday",  5},
            {"Sunday",    6}
    };

    int turma1_dia = weekday_map[turma1.get_weekday()];
    int turma2_dia = weekday_map[turma2.get_weekday()];

    if (turma1_dia != turma2_dia){
        return turma1_dia < turma2_dia;
    }
    else{
        return turma1.get_start_time() < turma2.get_start_time();
    }
}

