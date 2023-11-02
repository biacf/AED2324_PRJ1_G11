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
    Log log; /*!< Log object */
    std::queue<std::string> requests;/*!< Queue to keep track of requests */
    std::list<Aluno> alunos; /*!< List of existing students */
    std::vector<Turma> turmas; /*!< Vector of existing classes/lectures */
    std::list<Aluno> alunos_with_duplicate; /*!< List of Student objects including duplicates */
    std::map<std::string, int> turma_aluno_count; /*!< Map that associates classes with occupancy */
    std::map<std::string, int> uc_aluno_count; /*!< Map that associates UCs with occupancy */

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
