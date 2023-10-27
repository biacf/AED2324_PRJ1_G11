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
    Aluno(std::string name_, int student_number_);
    std::vector<Turma> check_horario();
    int n_uc();
    std::string get_name();
    int get_number();
    bool mudar_turma(Turma origem, Turma destino);
    void sair_turma(Turma turma);
    bool inscrever_turma(Turma turma);
    std::vector<Turma> aulas_por_dia(std::string weekday);
    int ano_inscricao(); //para esta função assume-se que está inscrito no ano da maioria das ucs em que tá inscrito

};

#endif //AED2324_PRJ1_G11_ALUNO_H
