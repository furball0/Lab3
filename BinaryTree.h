#ifndef LAB3_BINARYTREE_H
#define LAB3_BINARYTREE_H
using namespace std;
#include <vector>
#include <iomanip>
#include "Branch.h"
#include <complex>
#include <iostream>
#pragma once
#endif //LAB3_BINARYTREE_H

template <typename T> class BinaryTree {
private:
    Branch<T>* root;
public:
    //Constructor
    BinaryTree(){
        root = 0;
    }
    BinaryTree(T key){
        root = new Branch<T>;
        root->left = 0;
        root->right = 0;
        root->key = key;
    };
    BinaryTree(BinaryTree<T>* binary_tree){
        copy(binary_tree->root, root);
    };
    BinaryTree(Branch<T>* branch){
        root = new Branch<T>;
        copy(branch, root);
    }
    //Destructor
    ~BinaryTree(){
        delete_tree(root);
    };
    void delete_tree(Branch<T>* current){
        if(current){
            delete_tree(current->left);
            delete_tree(current->right);
            delete current;
        }
    }
    void Add(T key){
        add(key, root);
    };
    void Remove(T key){
        if(!root) return;
        remove(key, root);
    };
    bool isFind(T key){
        if(!root) return false;
        else{
            Branch<T>* buff = find(key, root);
            if(!buff) return false;
            else return true;
        }
    };
    T Get_el(T key){
        auto* t = find(key, root);
        if(!t) return NULL;
        return t->key;
    };

    BinaryTree<T>* GetSubTree(T key){
        if(!root) return NULL;
        auto* branch = find(key, root);
        auto* tree_copy = new BinaryTree<T>(branch);
//        copy(branch, tree_copy->root);
        return tree_copy;
        }
    bool isSubTree(BinaryTree<T>* tree){
        return isSubBranch(tree->root, root);
    }


    Branch<T>* get_root(){
        return root;
    }

    BinaryTree<T>* Map(T(*f)(T), bool is_inplace){
        if(is_inplace){
            mapp(root, root, f);
            return this;
        }
        else{
        auto* tree = new BinaryTree<T>(this);
        mapp(root, tree->root, f);
        return tree;}
    }
    BinaryTree<T>* Where(int (*func)(T)){
        auto* tree = new BinaryTree<T>(this);
        where(func, tree->root);
        return tree;
    }
    T Reduce(T (*f)(T, T), T c){ //LNR
        return reduce(f, this->root, c);
    }
    void Print(){
        if (!root) return;
//        cout << "_________________Tree_______________" << std::endl;
        printTree(root, nullptr, false);
    }
    friend ostream &operator << (ostream& cout, BinaryTree<T>* tree){
        tree->Print();
        return cout;
    }
private:
    struct Trunk
    {
        Trunk *prev;
        string str;
        Trunk(Trunk *prev, string str) {
            this->prev = prev;
            this->str = str;
        }
    };
    void showTrunks(Trunk *p)
    {
        if (p == nullptr) return;
        showTrunks(p->prev);
        cout << p->str;
    }
    void printTree(Branch<T>* branch, Trunk *prev, bool isLeft)
    {
        if (branch == nullptr) {
            return;
        }
        string prev_str = "    ";
        auto* trunk = new Trunk(prev, prev_str);

        printTree(branch->right, trunk, false);

        if (!prev) {
            trunk->str = "---";
        }
        else if (isLeft)
        {
            trunk->str = "`---";
            prev->str = prev_str;

        }
        else {
            trunk->str = ".---";
            prev_str = "   |";
        }

        showTrunks(trunk);
        if(branch->key < T(0)) cout << " ";
        cout << branch->key<<endl;

        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";

        printTree(branch->left, trunk, true);
    }
};

