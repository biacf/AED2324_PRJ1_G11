//
// Created by AnaBeatrizCarneiroFe on 01/11/2023.
//

#ifndef AED2324_PRJ1_G11_BSTREE_H
#define AED2324_PRJ1_G11_BSTREE_H

#include <iostream>
#include <list>
#include "Aluno.h"
#include <memory>
#include <utility>

class Node{
public:
    Aluno data; /*!< Node information */
    std::unique_ptr<Node> left;/*!< Pointer to node left of current node*/
    std::unique_ptr<Node> right;/*!< Pointer to node right of current node*/
    //! A constructor.
    /*!
        Builds Binary Search Tree node
    */
    explicit Node(Aluno aluno) : data(std::move(aluno)) {}
};


class BSTree {
private:
    std::unique_ptr<Node> root; /*!< Pointer to Binary Search Tree root*/
    void insert_alphabetical(std::unique_ptr<Node>& node, Aluno aluno);
    void inOrder(const Node* node, std::list<Aluno>& sorted_list) const;

public:
    void insert(Aluno aluno);
    std::list<Aluno> sort() const;
};


#endif //AED2324_PRJ1_G11_BSTREE_H
