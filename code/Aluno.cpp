//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Aluno.h"
#include <iostream>

//constructor
Aluno::Aluno(std::string name_, std::string student_number_) : name(name_), student_number(student_number_) {}

//getters
void Aluno::display_horario() {
    auto it = horario.begin();
    while(it != horario.end()){
        std::cout << "Class code: " << it->get_code() << ", UC: " << it->get_uc() << ", Weekday: " << it->get_weekday() << ", Start Time: " << std::to_string(it->get_start_time()) << ", Duration: " << std::to_string(it->get_duration()) << ", Type: " << it->get_type() << std::endl;
        it++;
    }
}
//methods
//add class to schedule
void Aluno::add_class(Turma turma) {
    horario.push_back(turma);
}




