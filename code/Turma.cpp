//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Turma.h"

//constructor
Turma::Turma(std::ostringstream& line){}

//getters
//returns students in class(all or w/ restrictions)
std::vector<Aluno> Turma::show_alunos(const std::string& restriction = ""){
    return alunos;
}

//returns weekday
std::string Turma::get_weekday(){
    return weekday;
}

//returns star hour
float Turma::get_start_hour(){
    return start_hour;
}

//returns end hour
float Turma::get_end_hour(){
    return start_hour + duration;
}

//returns number of students(all or w/ restrictions)
int Turma::student_number(const std::string& restriction = ""){
    return alunos.size();
}

//returns year
int Turma::get_year(){
    return year; //VOU MELHORAR ESTA FUNÇÃO QUANDO CRIAR A CLASSE UC!!!!!
}

//methods
bool Turma::intersects(Turma turma){
    return false;
}

//adds student
void Turma::add_student(Aluno aluno){}

//removes student
void Turma::remove_student(Aluno aluno){}