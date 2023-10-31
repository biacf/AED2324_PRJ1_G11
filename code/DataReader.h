//
// Created by AnaBeatrizCarneiroFe on 30/10/2023.
//

#ifndef AED2324_PRJ1_G11_DATAREADER_H
#define AED2324_PRJ1_G11_DATAREADER_H

#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Aluno.h"

class DataReader {
private:
    std::string filename;
    std::ifstream file;
public:
    //constructor
    DataReader(std::string path);
    //methods
    std::vector<Aluno> populate_students(std::list<Turma>& turma);
    std::list<Turma> populate_class();
    std::vector<Aluno> populate_students_with_duplicates(std::list<Turma> turma);

};


#endif //AED2324_PRJ1_G11_DATAREADER_H
