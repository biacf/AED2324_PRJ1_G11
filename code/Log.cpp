//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#include "Log.h"
#include <iostream>
#include <sstream>
#include <algorithm>

//constructor
Log::Log(){
    history.emplace("start");
}

//methods
//adds most recent alteration to history stack
void Log::add(const std::string& change){
    history.push(change);
}

//removes last step (has to check if possible, will return false if no)
bool Log::undo(std::list<Aluno>& alunos, const std::vector<Turma>& turmas){
    std::string change = history.top();
    std::string action, name, uc, turma_d, turma_f;
    bool possible;
    std::list<Turma> aulas_turma_uc;
    std::list<Turma> uc_outras_t;

    if(change == "start"){
        std::cout << "There is no operation to undo." << std::endl;
        return false;
    }
    else{
        std::istringstream iss(change);
        iss >> action;
        if(action == "signup"){
            iss >> name >> turma_f >> uc;
            for(Aluno& aluno:alunos){
                if(aluno.get_name() == name){
                    aluno.remove_class(turma_f, uc);
                    aluno.display_horario();
                    break;
                }
            }

            return true;
        }
        else if(action == "quit"){
            iss >> name >> turma_d >> uc;
            for(const Turma& turma: turmas){
                if(turma.get_uc() == uc && turma.get_code() != turma_d){
                    auto it = std::find_if(uc_outras_t.begin(), uc_outras_t.end(),[&turma_d](const Turma& turmas) {return turmas.get_code() == turma_d;});
                    if(it == uc_outras_t.end()){
                        uc_outras_t.push_back(turma);
                    }
                }
            }
            for(const Turma& turma : turmas){
                if(turma.get_uc() == uc && turma.get_code() == turma_d){
                    aulas_turma_uc.push_back(turma);
                }
            }
            for(Aluno& aluno:alunos){
                if(aluno.get_name() == name){
                    possible = aluno.add_class_check(aulas_turma_uc, turma_d, uc, uc_outras_t);
                    if(possible){
                        aluno.display_horario();
                    }
                    break;
                }
            }
            if(possible){
                return true;
            }
            else{
                return false;
            }
        }
        else if(action == "change"){
            iss >> name >> uc >> turma_f >> turma_d;
            for(const Turma& turma: turmas){
                if(turma.get_uc() == uc && turma.get_code() != turma_f){
                    auto it = std::find_if(uc_outras_t.begin(), uc_outras_t.end(),[&turma_f](const Turma& turmas) {return turmas.get_code() == turma_f;});
                    if(it == uc_outras_t.end()){
                        uc_outras_t.push_back(turma);
                    }
                }
            }
            //get classes for final class
            for(const Turma& turma : turmas){
                if(turma.get_uc() == uc && turma.get_code() == turma_f){
                    aulas_turma_uc.push_back(turma);
                }
            }

            //remove from origin class
            for(Aluno& aluno: alunos){
                if(aluno.get_name() == name){
                    aluno.remove_class(turma_d, uc);
                    possible = aluno.add_class_check(aulas_turma_uc, turma_f, uc,uc_outras_t); //add to new class;
                    if(!possible){
                        aulas_turma_uc.clear();
                        for(const Turma& turma : turmas){
                            if(turma.get_uc() == uc && turma.get_code() == turma_d){
                                aulas_turma_uc.push_back(turma);
                            }
                        }
                        aluno.add_class_check(aulas_turma_uc, turma_d, uc, uc_outras_t);
                    }
                    else{
                        aluno.display_horario();
                    }
                    break;
                }
            }

            //add back to origin class if not possible
            if(possible){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}