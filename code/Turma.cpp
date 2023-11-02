//
// Created by AnaBeatrizCarneiroFe on 24/10/2023.
//
#include "Turma.h"
#include <iomanip>
#include <iostream>
#include <utility>

//! A constructor.
/*!
  Build a Class object from its code, UC, day of the week, start time and type
*/
Turma::Turma(std::string code_, std::string uc_, std::string weekday_, float start_time_, float duration_,
             std::string type_) : code(std::move(code_)), uc(std::move(uc_)), weekday(std::move(weekday_)), start_time(start_time_), duration(duration_), type(std::move(type_)) {n_alunos = 0;}

/**
 * @brief Display class
 *
 * A method that displays the information relating to the Class object
 */
void Turma::display_turma(){
    std::cout << std::fixed << std::setprecision(1) << "Code: " << code << ", UC: " << uc << ", Weekday: " << weekday << ", Start Time: " << start_time << ", End Time: " << this->get_end_time() <<", Type: "<< type << std::endl;
}