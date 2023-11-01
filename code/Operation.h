//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#ifndef AED2324_PRJ1_G11_OPERATION_H
#define AED2324_PRJ1_G11_OPERATION_H

#include <queue>
#include <map>
#include "Log.h"
#include "Aluno.h"
#include "BSTree.h"

class Operation {
private:
    Log log;
    std::queue<std::string> requests;
    std::list<Aluno> alunos;
    std::vector<Turma> turmas;
    std::list<Aluno> alunos_with_duplicate;
    std::map<std::string, int> turma_aluno_count;
    std::map<std::string, int> uc_aluno_count;

public:
    //constructor
    Operation(const std::string& start, std::list<Aluno>& aluno_, std::vector<Turma>& turma_, std::list<Aluno> alunos_with_duplicate_);
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
