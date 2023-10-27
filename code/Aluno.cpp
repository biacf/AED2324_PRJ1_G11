//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Aluno.h"

//constructor
Aluno::Aluno(std::string name_, int student_number_) {
    name = name_;
    student_number = student_number_;
}

//getters
//returns classes (full or w/restrictions)
std::vector<Turma> Aluno::check_horario(const std::string& restriction = ""){
    return horario;
}

//returns number of curricular units (all or w/restrictions)
int Aluno::n_uc(const std::string& restriction = ""){
    return 0;
}

//returns name
std::string Aluno::get_name(){
    return name;
}

//returns student number
int Aluno::get_number(){
    return student_number;
}

//returns year
int Aluno::ano_inscricao(){
    return 0;
}

//methods
//change class
bool Aluno::mudar_turma(Turma origem, Turma destino){
    return false;
}

//quit class
void Aluno::sair_turma(Turma turma){
}

//sign up for class
bool Aluno::inscrever_turma(Turma turma){
    return false;
}




