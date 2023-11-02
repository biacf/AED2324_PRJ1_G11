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
#include <list>


class Turma{
private:
    std::string code; /*!< Class code */
    std::string uc; /*!< UC code */
    std::string weekday; /*!< Day of the week the lecture is held in */
    float start_time; /*!< Start time for lecture */
    float duration; /*!< Lecture duration */
    std::string type; /*!< Lecture type */
    int n_alunos; /*!< Number of students enrolled in class */
public:
    //constructor
    Turma(std::string code_, std::string uc_, std::string weekday_, float start_time_, float duration_, std::string type_);
    //getters
    void display_turma();
    /*! A getter method @return Class code */
    std::string get_code() const{return code;};
    /*! A getter method @return UC code */
    std::string get_uc() const{return uc;};
    /*! A getter method @return Day of the week the lecture is held in */
    std::string get_weekday() const{return weekday;};
    /*! A getter method @return Start time for lecture */
    float get_start_time() const{return start_time;};
    /*! A getter method @return Lecture duration */
    float get_duration() const{return duration;};
    /*! A getter method @return Lecture type */
    std::string get_type() const{return type;};
    /*! A getter method @return End time for lecture */
    float get_end_time() const{return start_time + duration;};
    /*! A getter method @return Number of students enrolled in class */
    int get_n_alunos() const{return n_alunos;};
    /*! Increments number of students enrolled in class */
    void add_alunos(){n_alunos++;};
};


#endif //AED2324_PRJ1_G11_TURMA_H
