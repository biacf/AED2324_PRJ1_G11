//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#ifndef AED2324_PRJ1_G11_LOG_H
#define AED2324_PRJ1_G11_LOG_H

#include <stack>
#include <string>
#include <sstream>
#include <list>
#include "Aluno.h"

class Log{
private:
    std::stack<std::string> history;

public:
    //constructor
    Log();
    //methods
    void add(const std::string& change);
    bool undo(std::list<Aluno>& alunos, const std::vector<Turma>& turmas);
};
#endif //AED2324_PRJ1_G11_LOG_H
