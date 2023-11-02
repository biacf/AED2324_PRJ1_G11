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
    std::string name; /*!< Student name */
    std::string student_number; /*!< Student number */
    std::list<Turma> horario; /*!< Student schedule */
    std::string uc; /*!< Curricular unit */
    std::string class_code;/*!< Class code */


public:
    //constructor
    Aluno(std::string name_, std::string student_number_);
    Aluno(std::string name_, std::string student_number_, std::string uc_, std::string class_code_ );

    //getters
    /*! A getter method @return Student name */
    std::string get_name() const{return name;};
    /*! A getter method @return Student number */
    std::string get_number() const{return student_number;};
    /*! A getter method @return Curricular unit */
    std::string get_uc() const{return uc;};
    /*! A getter method @return Class code*/
    std::string get_class_code() const{return class_code;};
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
