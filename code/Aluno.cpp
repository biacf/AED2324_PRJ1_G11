//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Aluno.h"
#include <algorithm>
#include <iostream>

//constructor
Aluno::Aluno(std::string name_, std::string student_number_) : name(name_), student_number(student_number_) {}
Aluno::Aluno(std::string name_, std::string student_number_, std::string uc_, std::string class_code_ ): name(name_), student_number(student_number_), uc(uc_), class_code(class_code_) {}

//getters
void Aluno::display_horario() {
    auto it = horario.begin();
    while(it != horario.end()){
        std::cout << "Class code: " << it->get_code() << ", UC: " << it->get_uc() << ", Weekday: " << it->get_weekday() << ", Start Time: " << std::to_string(it->get_start_time()) << ", Duration: " << std::to_string(it->get_duration()) << ", Type: " << it->get_type() << std::endl;
        it++;
    }
}

//returns vector of turmas that the aluno is signed up for
std::vector<std::string> Aluno::unique_turmas(){
    std::vector<std::string> returns;
    for(Turma turma : horario){
        if(find(returns.begin(), returns.end(), turma.get_code()) == returns.end()){
            returns.push_back(turma.get_code());
        }
    }

    return returns;
}

//methods
//add class to schedule
void Aluno::add_class(Turma turma) {
    horario.push_back(turma);
}

//remove class from schedule
void Aluno::remove_class(std::string code, std::string uc) {
    for(auto it = horario.begin(); it != horario.end(); it++){
        if(it->get_code() == code && it->get_uc() == uc){
            horario.erase(it);
        }
    }
}

//checks for schedule conflits before signing up for class
bool Aluno::add_class_check(std::list<Turma> turmas, std::string code, std::string uc) {
    bool flag = true;
    if(!horario.empty()) {
        for (Turma turma: horario) {
            //move on if turma is T
            if (turma.get_type() == "T") {
                continue;
            }

            if (turma.get_uc() == uc) {
                std::cout << "Aluno ja inscrito nessa cadeira. Inscricao sem sucesso." << std::endl;
                flag = false;
                break;
            }


            for (Turma turma_c: turmas) {
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
        for(Turma turma : turmas){
            this->add_class(turma);
        }
    }

    return flag;
}




