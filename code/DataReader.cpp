//
// Created by AnaBeatrizCarneiroFe on 30/10/2023.
//

#include <algorithm>
#include <utility>
#include "DataReader.h"

//! A constructor.
/*!
    Builds a DataReader object from the path of the .csv file to be parsed
*/
DataReader::DataReader(std::string path) {
    filename = std::move(path);
}

/**
 * @brief Collects data from "students_classes.csv"
 *
 * Creates Student Objects from data collected from .csv file, associating them with the classes they're enrolled in
 *
 * @param turma A vector of all the existing Classes
 * @return A list of all the existing Student objects
 */
std::list<Aluno> DataReader::populate_students(std::vector<Turma>& turma) {
    std::list<Aluno> alunos;
    file.open(filename);
    std::string line;
    getline(file, line); // Ignore header

    std::string name, number, class_code, uc;

    while (getline(file, line)) {
        std::istringstream iss(line);
        getline(iss, number, ',');
        getline(iss, name, ',');
        getline(iss, uc, ',');
        getline(iss, class_code, ',');

        // Check if the student exists
        auto it = std::find_if(alunos.begin(), alunos.end(), [&number](const Aluno& aluno) { return aluno.get_number() == number;});

        if (it == alunos.end()) {
            alunos.emplace_back(name, number);
            it = std::prev(alunos.end());
        }

        for (Turma& turmas: turma) {
            if (turmas.get_uc() == uc && turmas.get_code() == class_code) {
                it->add_class(turmas);
                turmas.add_alunos();
            }
        }
    }

    file.close();
    return alunos;
}


/**
 * @brief Creates Class objects
 *
 * Creates Class objects from data collected from .csv file
 * @return Vector of Class objects for every existing class/lecture
 */
std::vector<Turma> DataReader::populate_class() {
    std::vector<Turma> turmas;
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

/**
 * @brief Creates Student Object for every Class they're enrolled in
 *
 * Creates Student objects without excluding duplicates, to be used in methods in the Operation class
 *
 * @param turma A vector of all the existing Classes
 * @return A list of Student Objects, including duplicates (one for every class they're enrolled in)
 */
std::list<Aluno> DataReader::populate_students_with_duplicates(const std::vector<Turma>& turma) {
    std::list<Aluno> alunos_with_duplicates;
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