#ifndef LAB3_BRANCH3_H
#define LAB3_BRANCH3_H
#pragma once
#include <string>
using namespace std;
#include "stdexcept"
#endif //LAB3_BRANCH3_H

template <typename T> struct Branch3{
    T key;
    Branch3<T>* left = nullptr;
    Branch3<T>* central = nullptr;
    Branch3<T>* right = nullptr;
};


template <typename T> void add(T key, Branch3<T>*& branch3){
    if (!branch3){
        branch3 = new Branch3<T>;
        branch3->key = key;
        branch3->left = 0;
        branch3->central = 0;
        branch3->right = 0;
        return;
    }
    else if (key < branch3->key) {
        add(key, branch3->left);
    }
    else if (key > branch3->key) {
        add(key, branch3->right);
    }
    else if (key == branch3->key){
        add(key, branch3->central);
    }
}
template <typename T> void remove(T key, Branch3<T>*& branch3){
    if (branch3 == NULL) return;
    if (key < branch3->key)
        remove(key, branch3->left);
    else if (key > branch3->key)
        remove(key, branch3->right);
    else if (key == branch3->key){
        if (branch3->central != NULL){
            branch3->central->left = branch3->left;
            branch3->central->right = branch3->right;
            branch3 = branch3->central;
        } else{
            Branch3<T>* buffBranch3;
            if (branch3->right == NULL) {
                buffBranch3 = branch3->left;
            } else {
                Branch3<T> *pointer = branch3->right;
                if (pointer->left == NULL) {
                    pointer->left = branch3->left;
                    buffBranch3 = pointer;
                } else {
                    Branch3<T> *p_min_el = pointer->left;
                    while (p_min_el->left != NULL) {
                        pointer = p_min_el;
                        p_min_el = pointer->left;
                    }
                    pointer->left = p_min_el->right;
                    p_min_el->left = branch3->left;
                    p_min_el->right = branch3->right;
                    buffBranch3 = p_min_el;
                }
            }
            delete branch3;
            branch3 = buffBranch3;
            return;
        }
    }
}
template <typename T> Branch3<T>* find(T key, Branch3<T>* branch3){
    if(branch3 == NULL) return nullptr;
    if(key == branch3->key) return branch3;
    else if(key < branch3->key)
        find(key, branch3->left);
    else
        find(key, branch3->right);
}

template <typename T> Branch3<T>* pathSearch(Branch3<T>* branch3, string path)
{
    if (path.empty()) return branch3;
    switch (path[0])
    {
        case 'l':
            if (branch3->left == nullptr) return nullptr;
            return pathSearch(branch3->left, path.substr(1));
        case 'c':
            if (branch3->central == nullptr) return nullptr;
            return pathSearch(branch3->central, path.substr(1));
        case 'r':
            if (branch3->right == nullptr) return nullptr;
            return pathSearch(branch3->right, path.substr(1));
        default:
            throw invalid_argument("Tree3 pathSearch: path must contain only 'lcr' symbols");
    }
}

template <typename T> void copy_branch3(const Branch3<T>* old_branch3, Branch3<T>*& new_branch3) {
    if (!old_branch3) return;
    new_branch3 = new Branch3<T>;
    new_branch3->left = 0;
    new_branch3->central = 0;
    new_branch3->right = 0;
    new_branch3->key = old_branch3->key;
    copy_branch3(old_branch3->left, new_branch3->left);
    copy_branch3(old_branch3->central, new_branch3->central);
    copy_branch3(old_branch3->right, new_branch3->right);
}
template <typename T> bool areEqual(Branch3<T>* branch3_1, Branch3<T>* branch3_2){
    if(branch3_1 == NULL && branch3_2 == NULL) return true;
    if(branch3_1 != NULL && branch3_2 != NULL){
        if(branch3_1->key == branch3_2->key &&
           areEqual(branch3_1->left, branch3_2->left) &&
           areEqual(branch3_1->central, branch3_2->central) &&
           areEqual(branch3_1->right, branch3_2->right))
        {
            return true;
        }
    }
    return false;
}
template <typename T> bool isSubBranch(Branch3<T>* branch3, Branch3<T>* sub_branch3){
    if(sub_branch3 == NULL) return true;
    if(branch3 == NULL) return false;
    if(areEqual(branch3, sub_branch3)) return true;

    return isSubBranch(branch3->left, sub_branch3) ||
           isSubBranch(branch3->central, sub_branch3) ||
           isSubBranch(branch3->right, sub_branch3);
}

template <typename T> void mapp(Branch3<T>* branch3, Branch3<T>* new_branch3, T (*func)(T)){
    if(!branch3) return;
    mapp(branch3->left,new_branch3->left, func);
    new_branch3->key = func(branch3->key);
    mapp(branch3->central, new_branch3->central, func);
    mapp(branch3->right, new_branch3->right, func);
}
template <typename T> T reduce(T (*f)(T, T), Branch3<T>* branch3,T c){
    if (branch3 == nullptr)
    {
        return c;
    }
    T res = c;
    res = f(branch3->key, res);
    res = reduce(f, branch3->left, res);
    res = reduce(f, branch3->central, res);
    res = reduce(f, branch3->right, res);
    return res;
}
