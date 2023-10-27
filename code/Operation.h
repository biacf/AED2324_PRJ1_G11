//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#ifndef AED2324_PRJ1_G11_OPERATION_H
#define AED2324_PRJ1_G11_OPERATION_H

#include <queue>
#include "Log.h"
#include "Turma.h"

class Operation {
private:
    std::queue<std::string> requests;
public:
    //constructor
    Operation();
    //methods

    //request manager
        //add request
        //pop request

    //class
    //class finder
        //classes in a day
        //classes in curricular unit
        //classes in a year
        //class schedule
        //class with the most students
        //class with the least students
    //classes sorter
        //by occupancy (lowest to highest or highest to lowest)
        //by day of the week in a uc
    //class lister
        //list class info (code, uc, type, ....)
        //list T/TP/PL classes for UC (all or some)
        //list classes on a specific day
        // students in a class
    //change classes

    //student
    //student finder
        //student schedule
        //student name from number
        //student number from name
        //students in at least n ucs
        //students in a year
     //student sorter
        //alphabetically
        //per year
        //per class
        //per number of ucs
     //student lister
        //list student info (name, number, schedule)
     //student modifier
        //edit name
        //edit number


    //uc manager
        //sign up for uc
        //quit uc
    //uc finder
        //uc with the most students
        //uc with the least students
        //uc with classes on a specific weekday
    //uc lister
        //uc schedule
        //students in a uc
        //ucs on a weekday
    //uc sorter
        //by year
        //by number of students

    //year
    //students in a year
};


#endif //AED2324_PRJ1_G11_OPERATION_H
