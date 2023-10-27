//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Aluno.h"

//Constructor
Aluno::Aluno(std::string name_, int student_number_) {
    name = name_;
    student_number = student_number_;
}

//Getters
//Returns schedule
std::vector<Turma> Aluno::check_horario(){
    return horario;
}

//Returns number of curricular units
int Aluno::n_uc(){
    return 0;
}

//Returns name
std::string Aluno::get_name(){
    return name;
}

//Returns Student Number
int Aluno::get_number(){
    return student_number;
}

//Returns year
int Aluno::ano_inscricao(){
    return 0;
}

//Returns classes in a specific day
std::vector<Turma> Aluno::aulas_por_dia(std::string weekday){
    return horario;
}

//Methods
//Change class
bool Aluno::mudar_turma(Turma origem, Turma destino){
    return false;
}

//Quit class
void Aluno::sair_turma(Turma turma){
}

//Sign up for class
bool Aluno::inscrever_turma(Turma turma){
    return false;
}




