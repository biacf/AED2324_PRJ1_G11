//
// Created by AnaBeatrizCarneiroFe on 23/10/2023.
//

#ifndef AED2324_PRJ1_G11_TURMA_H
#define AED2324_PRJ1_G11_TURMA_H

#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
#include "Aluno.h"

class Turma{
private:
    std::vector<Aluno> alunos;
    std::string code;
    std::string uc_code;
    std::string type;
    std::string weekday;
    float start_hour;
    float duration;
    int year;

public:
    //constructor
    Turma(std::ostringstream& line);
    //getters
    std::vector<Aluno> show_alunos(const std::string& restriction = "");
    std::string get_weekday();
    float get_start_hour();
    float get_end_hour();
    int student_number(const std::string& restriction = "");
    int get_year();
    //methods
    bool intersects(Turma turma);
    void add_student(Aluno aluno);
    void remove_student(Aluno aluno);
};


#endif //AED2324_PRJ1_G11_TURMA_H
