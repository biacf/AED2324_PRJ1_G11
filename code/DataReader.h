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
    std::string filename; /*!< Path to the .csv file*/
    std::ifstream file; /*!< ifstream object */
public:
    //constructor
    explicit DataReader(std::string path);
    //methods
    std::list<Aluno> populate_students(std::vector<Turma>& turma);
    std::vector<Turma> populate_class();
    std::list<Aluno> populate_students_with_duplicates(const std::vector<Turma>& turma);

};


#endif //AED2324_PRJ1_G11_DATAREADER_H
