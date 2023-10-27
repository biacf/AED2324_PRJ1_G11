//
// Created by AnaBeatrizCarneiroFe on 27/10/2023.
//

#include "Log.h"

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
bool Log::remove(){
    return false;
}