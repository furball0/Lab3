#ifndef LAB3_BRANCH_H
#define LAB3_BRANCH_H
using namespace std;
#include <complex>
#endif //LAB3_BRANCH_H
template <typename T> struct Branch{
    T key;
    Branch<T>* left;
    Branch<T>* right;
    Branch() {
        key = 0;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T> void add(T key, Branch<T>*& branch){
    if (!branch){
        branch = new Branch<T>;
        branch->key = key;
        branch->left = 0;
        branch->right = 0;
        return;
    }
    else if (key < branch->key) {
        add(key, branch->left);
    }
    else if (key > branch->key) {
        add(key, branch->right);
    }
}
template <typename T> void remove(T key, Branch<T>*& branch){
    if (branch == NULL) return;
    if (key < branch->key)
        remove(key, branch->left);
    else if (key > branch->key)
        remove(key, branch->right);
    else {
        Branch<T> *buffBranch;
        if (branch->right == NULL) {
            buffBranch = branch->left;
        } else {
            Branch<T> *pointer = branch->right;
            if (pointer->left == NULL) {
                pointer->left = branch->left;
                buffBranch = pointer;
            } else {
                Branch<T> *p_min_el = pointer->left;
                while (p_min_el->left != NULL) {
                    pointer = p_min_el;
                    p_min_el = pointer->left;
                }
                pointer->left = p_min_el->right;
                p_min_el->left = branch->left;
                p_min_el->right = branch->right;
                buffBranch = p_min_el;
            }
        }
        delete branch;
        branch = buffBranch;
        return;
    }
}
template <typename T> Branch<T>* find(T key, Branch<T>* branch){
    if(branch == NULL) return NULL;
    if(key == branch->key) return branch;
    else if(key < branch->key)
        find(key, branch->left);
    else
        find(key, branch->right);
}

template <typename T> void copy(const Branch<T>* old_branch, Branch<T>*& new_branch) {
    if (!old_branch) return;
    new_branch = new Branch<T>;
    new_branch->left = 0;
    new_branch->right = 0;
    new_branch->key = old_branch->key;
    copy(old_branch->left, new_branch->left);
    copy(old_branch->right, new_branch->right);
}

template <typename T> bool isSubBranch(Branch<T>* branch, Branch<T>* sub_branch){
    // root - branch; sub_branch - sub_tree->get_root();
    if(sub_branch == NULL) return true;
    if(branch == NULL) return false;
    if(areEqual(branch, sub_branch)) return true;

    return isSubBranch(branch->left, sub_branch) || isSubBranch(branch->right, sub_branch);
}
template <typename T> bool areEqual(Branch<T>* branch_1, Branch<T>* branch_2){
    if(branch_1 == NULL && branch_2 == NULL) return true;
    if(branch_1 != NULL && branch_2 != NULL){
        if(branch_1->key == branch_2->key && areEqual(branch_1->left, branch_2->left) && areEqual(branch_1->right, branch_2->right)){
            return true;
        }
    }
    return false;
}

template <typename T> void where(int(*func)(T), Branch<T>*& branch){
    if(!func(branch->key)){
        remove(branch->key,branch);
        if(!branch) return;
        where(func, branch);
        return;
    }
    if(branch->left == nullptr && branch->right == nullptr) return;
    if(branch->left != nullptr) where(func, branch->left);
    if(branch->right != nullptr) where(func, branch->right);
}
template <typename T> void mapp(Branch<T>* branch, Branch<T>* new_branch, T (*func)(T)){
    if(!branch) return;
    mapp(branch->left,new_branch->left, func);
    new_branch->key = func(branch->key);
    mapp(branch->right, new_branch->right, func);
}
template <typename T> T reduce(T (*f)(T, T), Branch<T>* branch,T c){
    if (branch == nullptr)
    {
        return c;
    }
    T res = c;
    res = f(branch->key, res);
    res = reduce(f, branch->left, res);
    res = reduce(f, branch->right, res);
    return res;
}

template<typename T> inline _GLIBCXX_CONSTEXPR bool
operator<(const complex<T>& _x, const complex<T>& _y) {
    if (pow(_x.real(),2)+pow(_x.imag(),2) < pow(_y.real(),2)+pow(_y.imag(),2)) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T> inline _GLIBCXX_CONSTEXPR bool
operator>(const complex<T>& _x, const complex<T>& _y) {
    if (pow(_x.real(),2)+pow(_x.imag(),2) > pow(_y.real(),2)+pow(_y.imag(),2)) {
        return true;
    }
    else {
        return false;
    }
}
