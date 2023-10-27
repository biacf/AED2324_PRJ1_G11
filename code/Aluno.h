a//
// Created by AnaBeatrizCarneiroFe on 23/10/2023.
//

#ifndef AED2324_PRJ1_G11_ALUNO_H
#define AED2324_PRJ1_G11_ALUNO_H

#include <string>
#include "Turma.h"

class Aluno{
private:
    std::string name;
    int student_number;
    std::vector<Turma> horario;
public:
    //constructor
    Aluno(std::string name_, int student_number_);
    //getters
    std::vector<Turma> check_horario(const std::string& restriction = "");
    int n_uc(const std::string& restriction = "");
    std::string get_name();
    int get_number();
    int ano_inscricao(); //para esta função assume-se que está inscrito no ano da maioria das ucs em que tá inscrito
    //methods
    bool mudar_turma(Turma origem, Turma destino);
    void sair_turma(Turma turma);
    bool inscrever_turma(Turma turma);


};

#endif //AED2324_PRJ1_G11_ALUNO_H
