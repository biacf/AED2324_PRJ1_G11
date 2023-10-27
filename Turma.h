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
    int start_hour;
    int duration;

public:
    Turma(std::ostringstream& line);

};


#endif //AED2324_PRJ1_G11_TURMA_H
