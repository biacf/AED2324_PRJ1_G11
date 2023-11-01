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
    std::list<Turma> get_horario() const{return horario;};
    void display_horario();
    std::vector<std::string> unique_turmas();
    std::vector<std::string> unique_ucs();

    //methods
    void add_class(const Turma& turma);
    void remove_class(const std::string& code, const std::string& uc);
    bool add_class_check(std::list<Turma> turmas, const std::string& code, const std::string& uc, const std::list<Turma>& outras_t_uc);
    std::list<Turma> sort_horario();
    static bool turma_comp(const Turma& turma1, const Turma& turma2);

};

#endif //AED2324_PRJ1_G11_ALUNO_H
