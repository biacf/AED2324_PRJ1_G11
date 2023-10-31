//
// Created by AnaBeatrizCarneiroFe on 23/10/2023.
//

#ifndef AED2324_PRJ1_G11_ALUNO_H
#define AED2324_PRJ1_G11_ALUNO_H

#include <string>
#include <list>
#include <set>
#include "Turma.h"

class Aluno{
private:
    std::string name;
    std::string student_number;
    std::list<Turma> horario;
    std::string uc;
    std::string class_code;


public:
    //constructor
    Aluno(std::string name_, std::string student_number_);
    Aluno(std::string name_, std::string student_number_, std::string uc_, std::string class_code_ );

    //getters
    std::string get_name() const{return name;};
    std::string get_number() const{return student_number;};
    std::string get_uc() const{return uc;};
    std::string get_class_code() const{return class_code;};
    void display_horario();
    std::vector<std::string> unique_turmas();
    //methods
    void add_class(Turma turma);
    void remove_class(std::string code, std::string uc);
    bool add_class_check(std::list<Turma> turmas, std::string code, std::string uc);

};

#endif //AED2324_PRJ1_G11_ALUNO_H
