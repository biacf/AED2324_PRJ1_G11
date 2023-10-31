//
// Created by AnaBeatrizCarneiroFe on 23/10/2023.
//
#include <vector>
#include <fstream>
#include "DataReader.h"
#include "Operation.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <map>

int main(){
    std::vector<Aluno> alunos;
    std::list<Turma> turmas;

    //distribute data
    DataReader classes("../code/Data/classes.csv");
    turmas = classes.populate_class();
    DataReader students("../code/Data/students_classes.csv");
    alunos = students.populate_students(turmas);


    //initialize program
    bool continues = true;
    Operation op("start", alunos, turmas);
    std::cout << "Bem vindo ao Gestor de Horario 2LEIC01_G11" << std::endl;
    std::cout << "Selecione o que pretende fazer:" << std::endl;
    std::cout << "1 - Consultar" << std::endl;
    std::cout << "2 - Ordenar" << std::endl;
    std::cout << "3 - Procurar" << std::endl;
    std::cout << "4 - Gerir horario de aluno" << std::endl;
    std::cout << "5 - Desfazer ultima mudanca" << std::endl;
    std::cout << "6 - Executar" << std::endl;

    int option;

    while(continues){
        std::cin >> option;
        switch(option){
            case 1:
                op.add_request("list");
                break;
            case 2:
                op.add_request("sort");
                break;
            case 3:
                op.add_request("search");
                break;
            case 4:
                op.add_request("manage_schedule");
                break;
            case 5:
                op.add_request("undo");
                break;
            case 6:
                continues = false;
                break;
        }
    }

    op.operate();
    /*
    //Menu
    int escolha;
    bool continue_switch = true;
    while(continue_switch) {
        std::cout << "Escolha um numero associado a escolha pretendida: " << std::endl;
        std::cout << "0 - Sair da pesquisa"<<std::endl;
        std::cout << "1 - Pesquisa" << std::endl;
        std::cin >> escolha;
        if(escolha == 0){
            continue_switch = false;
        }
        else{
            switch (escolha) {
                case 1: {
                    int pesquisa;
                    std::cout << "Escolha um numero associado a escolha pretendida: " << std::endl;
                    std::cout << "0 - Sair da pesquisa"<<std::endl;
                    std::cout << "1 - Alunos" << std::endl;
                    std::cout << "2 - Turmas" << std::endl;
                    std::cout << "3 - Cadeira" << std::endl;
                    std::cin >> pesquisa;
                    if(pesquisa == 0){
                        continue_switch = false;
                    }
                    else{
                        switch (pesquisa) {
                            case 1: {
                                int aluno;
                                std::cout << "Escolha um numero associado a escolha pretendida: " << std::endl;
                                std::cout << "0 - Sair da pesquisa"<<std::endl;
                                std::cout << "1 - Numero up" << std::endl;
                                std::cout << "2 - Nome" << std::endl;
                                std::cin >> aluno;
                                if(aluno == 0){
                                    continue_switch = false;
                                }
                                else{
                                    switch (aluno) {
                                        case 1: {
                                            std::string numero_up;
                                            std::cout << "Insira o numero up que deseja procurar" << std::endl;
                                            std::cin >> numero_up;
                                            for (auto students: alunos) {
                                                if (numero_up == students.get_number()) {
                                                    std::cout << students.get_name() << ", " << students.get_number() << std::endl;
                                                }
                                            }
                                            continue_switch = false;

                                            int horario;
                                            std::cout << "0 - Sair da pesquisa"<<std::endl;
                                            std::cout << "1 - Horario" << std::endl;
                                            std::cin >> horario;
                                            if(horario == 0){
                                                continue_switch = false;
                                            }
                                            else{
                                                std::cout<<"Dia da semana : "<< <<std::cout<<", das "<<
                                                std::cout<<"Duracao : "<<
                                                std::cout<<"Tipo : "
                                                std::cout<<"Cadeira : "<<
                                                std::cout<<"Turma : "<<
                                            }

                                            break;
                                        }
                                        case 2: {
                                            std::string name;
                                            std::cout << "Insira o nome que deseja procurar" << std::endl;
                                            std::cin >> name;
                                            for (auto students: alunos) {
                                                if (name == students.get_name()) {
                                                    std::cout << students.get_name() << ", " << students.get_number() << std::endl;
                                                }
                                            }
                                            continue_switch = false;
                                            break;
                                        }
                                    }}
                                break;
                            }
                            case 3:{
                                std::string uccode;
                                std::cout<<"Escreva o codigo da unidade curricular";
                                std::cin>>uccode;
                                std::cout<<"Turmas pertencetes a "<<uccode<<": "<<std::endl;
                                if(cadeiras.find(uccode) != cadeiras.end()){
                                    std::vector<std::string> iterar = cadeiras[uccode];
                                    for(auto turma : iterar){
                                        std::cout <<"- "<< turma << std::endl;
                                    }
                                }
                                continue_switch = false;
                                break;
                            }
                        }}
                    break;
                }
            }
        }
    }
    */
    return 0;
}
//distribuir info por structures
//ler input
//mandar para operation
//quando acabado dar opcao de quit ou continuar (se continuar, loop)
