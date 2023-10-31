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
public:
    //constructor
    Aluno(std::string name_, std::string student_number_);
    //getters
    std::string get_name() const{return name;};
    std::string get_number() const{return student_number;};
    void display_horario();
    //methods
    void add_class(Turma turma);

};

#endif //AED2324_PRJ1_G11_ALUNO_H
