//
// Created by AnaBeatrizCarneiroFe on 01/11/2023.
//

#include "BSTree.h"

void BSTree::insert_alphabetical(std::unique_ptr<Node>& node, Aluno aluno) {
    if (!node) {
        node.reset(new Node(std::move(aluno)));
        return;
    }
    if (aluno.get_name() < node->data.get_name()) {
        insert_alphabetical(node->left, std::move(aluno));
    } else {
        insert_alphabetical(node->right, std::move(aluno));
    }
}

void BSTree::inOrder(const Node* node, std::list<Aluno>& sorted_list) const {
    if (node) {
        inOrder(node->left.get(), sorted_list);
        sorted_list.push_back(node->data);
        inOrder(node->right.get(), sorted_list);
    }
}

void BSTree::insert(Aluno aluno) {
    insert_alphabetical(root, std::move(aluno));
}

std::list<Aluno> BSTree::sort() const {
    std::list<Aluno> sorted_list;
    inOrder(root.get(), sorted_list);
    return sorted_list;
}