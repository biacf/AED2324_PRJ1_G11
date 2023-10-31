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
    std::string code;
    std::string uc;
    std::string weekday;
    float start_time;
    float duration;
    std::string type;
public:
    //constructor
    Turma(std::string code_, std::string uc_, std::string weekday_, float start_time_, float duration_, std::string type_);
    //getters
    std::string get_code() const{return code;};
    std::string get_uc() const{return uc;};
    std::string get_weekday() const{return weekday;};
    float get_start_time() const{return start_time;};
    float get_duration() const{return duration;};
    std::string get_type() const{return type;};
    float get_end_time() const{return start_time + duration;};
};


#endif //AED2324_PRJ1_G11_TURMA_H
