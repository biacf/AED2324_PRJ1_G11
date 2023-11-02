//
// Created by AnaBeatrizCarneiroFe on 01/11/2023.
//

#include "BSTree.h"

/**
 * @brief Inserts student in Binary Search Tree
 *
 * A method that adds a student to the Binary Search Tree in alphabetical order
 *
 * @param node Pointer to "current node"
 * @param aluno Node information
 */
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

/**
 *@brief Collects Binary Search Tree data
 *
 * Creates an ordered (sorted) list of Student objects, through the traversal of the Binary Search Tree
 *
 * @param node Pointer to "current node"
 * @param sorted_list List of students
 */
void BSTree::inOrder(const Node* node, std::list<Aluno>& sorted_list) const {
    if (node) {
        inOrder(node->left.get(), sorted_list);
        sorted_list.push_back(node->data);
        inOrder(node->right.get(), sorted_list);
    }
}

/**
 * @brief Adds student to Binary Search Tree
 *
 * A method that adds a student to the Binary Search Tree
 * @param aluno Student to be added to BST
 */
void BSTree::insert(Aluno aluno) {
    insert_alphabetical(root, std::move(aluno));
}

/**
 * @brief Returns sorted data from Binary Search Tree
 *
 * This method returns an alphabetically sorted list of Student objects, created through the traversal of the Binary Search Tree using the inOrder method
 *
 * @return List of alphabetically sorted Student objects
 */
std::list<Aluno> BSTree::sort() const {
    std::list<Aluno> sorted_list;
    inOrder(root.get(), sorted_list);
    return sorted_list;
}