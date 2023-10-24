//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Aluno.h"

Aluno::Aluno() {
    name = "";
    student_number = 0;
};
Aluno::Aluno(std::string name_, int student_number_) {
    name = name_;
    student_number = student_number_;
}
