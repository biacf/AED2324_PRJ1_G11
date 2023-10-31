//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#include "Operation.h"

//constructor
Operation::Operation(std::string start, std::vector<Aluno> aluno, std::list<Turma> turma) {
    requests.push(start);
    alunos = aluno;
    turmas = turma;
}

//methods
//access list operations
void Operation::list(){

}

//access sort operations
void Operation::sort() {

}

//access search operations
void Operation::search() {

}

//access schedule manager operations
void Operation::schedule_manager() {

}

//process undo operation
void Operation::undo(){

}


//add request
void Operation::add_request(const std::string &request) {
    requests.push(request);
}

//pop request
void Operation::pop_request() {
    if(!requests.empty()){
        requests.pop();
    }
    else{
        requests.emplace("start");
    }

}