#ifndef LAB3_3_ARYTREE_H
#define LAB3_3_ARYTREE_H
#include "Branch3.h"
#include <iostream>
#include <complex>
#include <vector>
#pragma once
using namespace std;
#endif //LAB3_3_ARYTREE_H


template <typename T> class Tree3{
private:
    Branch3<T>* root = nullptr;
public:
    //Constructor
    Tree3(){
        root = 0;
    };
    Tree3(T data){
        root = new Branch3<T>;
        root->left = 0;
        root->central = 0;
        root->right = 0;
        root->key = data;
    };
    Tree3(Tree3<T>* tree3){
        copy_branch3(tree3->root, root);
    };
    Tree3(Branch3<T>* branch){
        root = new Branch3<T>;
        copy_branch3(branch, root);
    };
    //Destructor
    ~Tree3(){
        delete_tree3(root);
    }
    void delete_tree3(Branch3<T>* current){
        if(current){
            delete_tree3(current->left);
            delete_tree3(current->central);
            delete_tree3(current->right);
            delete current;
        }
    }
    //Operations
    void Add(T key){
        add(key, root);
    };
    void Remove(T key){
        if(!root) return;
        remove(key, root);
    }
    bool isFind(T key){
        if(!root) return false;
        else{
            Branch3<T>* buff = find(key, root);
            if(!buff) return false;
            else return true;
        }
    };
    T Get_el(T key){
        auto* t = find(key, root);
        return t->key;
    };

    Branch3<T>* get_root(){
        return root;
    }
    Branch3<T>* PathSearch(Tree3<T>* tree3,string path){
        return pathSearch(tree3->get_root(), path);
    }
    Branch3<T>* PathSearch(string path){
        return pathSearch(root, path);
    }

    Tree3<T>* Map(T(*f)(T), bool is_inplace){
        if(is_inplace){
            mapp(root, root, f);
            return this;
        }
        else{
            auto* tree3 = new Tree3<T>(this);
            mapp(root, tree3->root, f);
            return tree3;
        }
    }
    T Reduce(T (*f)(T, T), T c){
        return reduce(f, this->root, c);
    }

    Tree3<T>* GetSubTree(T key){
        if(!root) return NULL;
        auto* branch3 = find(key, root);
        auto* tree_copy = new Tree3<T>(branch3);
        return tree_copy;
    }
    bool isSubTree(Tree3<T>* tree3){
        return isSubBranch(tree3->root, root);
    }

    void Print(){
        if (!root) return;
//        cout << "__________________Tree__________________" << endl;
        printTree(root, nullptr, false, false);
    }
    friend ostream &operator << (ostream &cout, Tree3<T>* tree){
        tree->Print();
        return cout;
    }
private:
    struct Trunk
    {
        Trunk *prev;
        string str;
        Trunk(Trunk *prev, string& str) {
            this->prev = prev;
            this->str = str;
        }
    };
    void showTrunks(Trunk *p)
    {
        if (p == nullptr) {
            return;
        }
        showTrunks(p->prev);
        cout << p->str;
    }
    void printTree(Branch3<T>* branch3, Trunk *prev, bool isLeft, bool center)
    {
        if (branch3 == nullptr) {
            return;
        }
        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);

        printTree(branch3->right, trunk, false, false);

        if (!prev || center == true) {
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

        if(!center) {
            showTrunks(trunk);
            if(branch3->key < T(0)) cout << " ";
            cout << branch3->key;
            if (prev) {
                prev->str = prev_str;
            }
            trunk->str = "   |";
        }
        else{
            cout << " ---";
            if(branch3->key < T(0)) cout << " ";
            cout << branch3->key;
        }
        printTree(branch3->central, trunk, false, true);
        if(!center)cout << endl;
        printTree(branch3->left, trunk, true, false);
    }
};
