//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#ifndef AED2324_PRJ1_G11_OPERATION_H
#define AED2324_PRJ1_G11_OPERATION_H

#include <queue>
#include "Log.h"
#include "Aluno.h"

class Operation {
private:
    Log log;
    std::queue<std::string> requests;
    std::vector<Aluno> alunos;
    std::list<Turma> turmas;
public:
    //constructor
    Operation(std::string start, std::vector<Aluno> aluno, std::list<Turma> turma);
    //methods
    void list();
    void sort();
    void search();
    void schedule_manager();
    void undo();
    void operate();
    //request manager
    //add request
    void add_request(const std::string& request);


};


#endif //AED2324_PRJ1_G11_OPERATION_H
