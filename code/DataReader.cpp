//
// Created by AnaBeatrizCarneiroFe on 30/10/2023.
//

#include <algorithm>
#include "DataReader.h"

DataReader::DataReader(std::string path) {
    filename = path;
}

std::vector<Aluno> DataReader::populate_students(std::list<Turma>& turma) {
    std::vector<Aluno> alunos;
    file.open(filename);
    std::string line;
    getline(file, line); //ignore header
    std::string name, number, class_code, uc;

    while(getline(file, line)){
        std::istringstream iss(line);
        getline(iss,number,',');
        getline(iss,name,',');
        getline(iss,uc,',');
        getline(iss,class_code,',');


        auto it = std::find_if(alunos.begin(), alunos.end(),
                               [&number](const Aluno& aluno) {
                                   return aluno.get_number() == number;
                               });

        if (it == alunos.end()) {
            Aluno aluno(name, number);
            alunos.push_back(aluno);
            it = alunos.end() - 1;
        }

        for(Turma& turmas : turma){
            if(turmas.get_uc() == uc && turmas.get_code() == class_code){
                it->add_class(turmas);
            }
        }
    }

    file.close();
    return alunos;
}


std::list<Turma> DataReader::populate_class() {
    std::list<Turma> turmas;
    file.open(filename);
    std::string line;
    getline(file, line); // ignore header
    std::string code, uc, weekday, start_time, duration, type;

    while(getline(file, line)){
        std::istringstream iss(line);
        getline(iss, code, ',');
        getline(iss, uc, ',');
        getline(iss, weekday, ',');
        getline(iss,start_time,',');
        getline(iss,duration,',');
        getline(iss,type,',');

        Turma turma(code, uc, weekday, stof(start_time), stof(duration), type);
        turmas.push_back(turma);
    }

    file.close();
    return turmas;
}
std::vector<Aluno> DataReader::populate_students_with_duplicates(std::list<Turma> turma) {
    std::vector<Aluno> alunos_with_duplicates;
    file.open(filename);
    std::string line;
    getline(file, line); //ignore header
    std::string name, number, class_code, uc;

    while(getline(file, line)){
        std::istringstream iss(line);
        getline(iss,number,',');
        getline(iss,name,',');
        getline(iss,uc,',');
        getline(iss,class_code,',');
        Aluno aluno(name, number, uc, class_code);
        alunos_with_duplicates.push_back(aluno);
    }

    file.close();
    return alunos_with_duplicates;
}