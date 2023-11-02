//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Aluno.h"
#include <map>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <utility>

//! A constructor.
/*!
  Build a Student object from its name and number.
*/
Aluno::Aluno(std::string name_, std::string student_number_) : name(std::move(name_)), student_number(std::move(student_number_)) {}
//! A constructor.
/*!
    Build a Student object from its name and number, also including a specefic Class represented by its code and curricular unit
*/
Aluno::Aluno(std::string name_, std::string student_number_, std::string uc_, std::string class_code_ ): name(std::move(name_)), student_number(std::move(student_number_)), uc(std::move(uc_)), class_code(std::move(class_code_)) {}

/**
 * @brief Display student schedule
 *
 * A method that displays the Student's schedule, in the order the classes were added to the horario list
 */
void Aluno::display_horario() {
    auto it = horario.begin();
    while(it != horario.end()){
        std::cout << std::fixed << std::setprecision(1) <<"Class code: " << it->get_code() << ", UC: " << it->get_uc() << ", Weekday: " << it->get_weekday() << ", Start Time: " << std::to_string(it->get_start_time()) << ", Duration: " << std::to_string(it->get_duration()) << ", Type: " << it->get_type() << std::endl;
        it++;
    }
}

/**
 * @brief Get unique classes the student is enrolled in
 *
 * A method that goes through the classes the student is enrolled in and excludes duplicates
 *
 * @return A vector of the unique classes the student is enrolled in
 */
std::vector<std::string> Aluno::unique_turmas(){
    std::vector<std::string> returns;
    for(const Turma& turma : horario){
        if(find(returns.begin(), returns.end(), turma.get_code()) == returns.end()){
            returns.push_back(turma.get_code());
        }
    }

    return returns;
}

/**
 * @brief Get UCs the student is enrolled in
 *
 * A method that goes through the classes the student is enrolled in and collects the respective UCs
 *
 * @return A vector of the UCs the student is enrolled in
 */
std::vector<std::string> Aluno::unique_ucs(){
    std::vector<std::string> returns;
    for(const Turma& turma : horario){
        if(find(returns.begin(), returns.end(), turma.get_uc()) == returns.end()){
            returns.push_back(turma.get_uc());
        }
    }

    return returns;
}

/**
 * @brief Adds class to student schedule
 *
 * A method that adds a class to a student's schedule without checking for conflicts. Used when parsing data from .csv files at the start of the program.
 *
 * @param turma The class to be added to the students schedule
 */
void Aluno::add_class(const Turma& turma) {
    horario.push_back(turma);
}

/**
 * @brief Removes class from student schedule
 *
 * Removes class from Student schedule when student decides to quit or change classes.
 *
 * @param code_ Class code
 * @param uc_  UC code
 */
void Aluno::remove_class(const std::string& code_, const std::string& uc_) {
    for(auto it = horario.begin(); it != horario.end(); it++){
        if(it->get_code() == code_ && it->get_uc() == uc_){
            horario.erase(it);
        }
    }
}

/**
 * @brief Checks if student can enroll in new class and enrolls student if yes
 *
 * This method takes a list of lectures from a certain class and verifies if there are any conflicts with the other lectures from classes the student is enrolled in. If not, enrolls the student in the new class.
 *
 * @param turmas The lectures from the class the student wants to enroll in
 * @param code_ The class code
 * @param uc_ The UC code
 * @param outras_t_uc A list of the other classes for the same UC. Avoids imbalances in the number of students between classes.
 *
 * @return Boolean value. False if Student was unable to enroll in the new class and true otherwise
 */
bool Aluno::add_class_check(std::list<Turma> turmas, const std::string& code_, const std::string& uc_, const std::list<Turma>& outras_t_uc) {
    bool flag = true;
    for (const Turma& turma : outras_t_uc) {
        int count_difference = abs(turma.get_n_alunos() - turmas.front().get_n_alunos());
        if (count_difference > 4 && (turmas.front().get_n_alunos() < turma.get_n_alunos())) {
            std::cout << "Diferenca de numero de alunos maior que 4. Inscricao sem sucesso." << std::endl;
            return false;
        }
    }


    if(!horario.empty()) {
        for (const Turma& turma: horario) {
            //move on if turma is T
            if (turma.get_type() == "T") {
                continue;
            }

            if (turma.get_uc() == uc) {
                std::cout << "Aluno ja inscrito nessa cadeira. Inscricao sem sucesso." << std::endl;
                flag = false;
                break;
            }


            for (const Turma& turma_c: turmas) {
                //move on if turma is T
                if (turma_c.get_type() == "T") {
                    continue;
                } else if (turma_c.get_weekday() != turma.get_weekday()) {
                    continue;
                } else {
                    if (((turma.get_start_time() < turma_c.get_end_time()) && (turma_c.get_start_time() < turma.get_end_time())) ||
                        ((turma.get_end_time() > turma_c.get_start_time()) &&(turma_c.get_end_time() > turma.get_start_time()))) {
                        flag = false;
                    }
                }
            }
        }

    }
    if(flag){
        for(const Turma& turma : turmas){
            this->add_class(turma);
        }
    }

    return flag;
}

/**
 * @brief Sorts the schedule
 *
 * A method that organises the lectures from the classes the student is enrolled in, based on what day of the week and hour they take place
 *
 * @return Sorted list of classes
 */
std::list<Turma> Aluno::sort_horario(){
    std::list<Turma> sorted;
    sorted = horario;
    sorted.sort(turma_comp);
    return sorted;
}

/**
 * @brief Auxiliary method
 *
 * A method used to compare two classes to see which one comes first. Used in the sort_horario() method
 *
 * @param turma1 First class
 * @param turma2 Second class
 * @return Boolean value. True if turma1 is before turma2 and false otherwise
 */
bool  Aluno::turma_comp(const Turma& turma1, const Turma& turma2){
    std::map<std::string, int> weekday_map = {
            {"Monday",    0},
            {"Tuesday",   1},
            {"Wednesday", 2},
            {"Thursday",  3},
            {"Friday",    4},
            {"Saturday",  5},
            {"Sunday",    6}
    };

    int turma1_dia = weekday_map[turma1.get_weekday()];
    int turma2_dia = weekday_map[turma2.get_weekday()];

    if (turma1_dia != turma2_dia){
        return turma1_dia < turma2_dia;
    }
    else{
        return turma1.get_start_time() < turma2.get_start_time();
    }
}

