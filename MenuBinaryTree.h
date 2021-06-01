#ifndef LAB3_MENUBINARYTREE_H
#define LAB3_MENUBINARYTREE_H
#include "BinaryTree.h"
#include <typeinfo>
#endif //LAB3_MENUBINARYTREE_H


//void MenuBinaryTree();
#ifndef LAB3_MENUBinaryTree_H
#define LAB3_MENUBinaryTree_H
#include "3-aryTree.h"
#include <typeinfo>
#endif //LAB3_MENUBinaryTree_H

const string sep = "-----------------------------------------";



int chooseType(){
    int type;
    cout << "Select type of numbers: \n"
         << "\t1: int\n"
         << "\t2: double\n"
         << "\t3: complex\n\n"
         << "\t0: Return to select type of tree\n"
         << "Enter a number: ";
    cin >> type;
    cout << sep << endl;
    return type;
}
template <typename T> void showTrees(vector<BinaryTree<T>*>* BinaryTree_T){
    for(int i = 0; i<(int)BinaryTree_T->size(); i++){
        cout << "Tree " << i << ": \n" << BinaryTree_T->at(i);
    }
}
template <typename T> int chooseTree(vector<BinaryTree<T>*>* BinaryTree_T){
    int t = 0;
    showTrees(BinaryTree_T);
    cout << "Enter number of tree (-1 - Return back): ";
    cin >> t;
    return t;
}
int chooseFunction(){
    int func;
    cout << "What function do you want to use?: \n"
         << "\t1: Show Trees\n"
         << "\t2: Add Tree\n"
         << "\t3: Delete Tree\n"
         << "\t4: Trees Functions\n\n"
         << "\t0: Return to select type\n"
         << "Enter a number: ";
    cin >> func;
    cout << sep << endl;
    return func;
}
int chooseTreeFunctionBin(){
    int func;
    cout << "What tree function do you want to use?: \n"
         << "\t1: Add element\n"
         << "\t2: Delete element\n"
         << "\t3: Find\n"
         << "\t4: Get SubTree\n"
         << "\t5: is a SubTree\n"
         << "\t6: Map\n"
         << "\t7: Reduce\n"
         << "\t8: Where\n"
         << "\t9: Print\n\n"
         << "\t0: Return to select tree\n"
         << "Enter a number: ";
    cin >> func;
    cout << sep << endl;
    return func;
}

template <typename T> void SaveTree(BinaryTree<T>* binaryTree, vector<BinaryTree<T>*>* BinaryTree_T){
    BinaryTree_T->push_back(binaryTree);
}

template <typename T> void AddTree(vector<BinaryTree<T>*>* BinaryTree_T){
    int size;
    cout << "Enter count of elements: ";
    cin >> size; cout << endl;
    auto* binaryTree = new BinaryTree<T>;
    cout << "Enter numbers (one by one):" << endl;
    T num;
    for(int i = 0; i < size; i++){
        cin >> num;
        binaryTree->Add(num);
    }
    SaveTree(binaryTree, BinaryTree_T);
}
template <typename T> void DeleteTree(vector<BinaryTree<T>*>* BinaryTree_T){
    int t = chooseTree(BinaryTree_T);
    BinaryTree_T->erase(BinaryTree_T->begin() + t);
}

template <typename T> void AddEl(BinaryTree<T>* BinaryTree){
    cout << "Enter number:" << endl;
    T num;
    cin >> num;
    BinaryTree->Add(num);
}
template <typename T> void DelEl(BinaryTree<T>* BinaryTree){
    cout << "What element do you want to delete?\nEnter a number: ";
    T key;
    cin >> key;
    BinaryTree->Remove(key);
}
template <typename T> void FindEl(BinaryTree<T>* BinaryTree){
    cout << "What element do you want to find?\nEnter a number: ";
    T key;
    cin >> key;
    bool find = BinaryTree->isFind(key);
    if(find) cout << "Element Found.\n";
    else cout << "Element wasn't found.\n";
}
template <typename T> void Get_SubTree(BinaryTree<T>* binaryTree, vector<BinaryTree<T>*>* BinaryTree_T){
    cout << "Enter an element: ";
    T key;
    cin >> key;
    auto* new_tree = binaryTree->GetSubTree(key);
    cout << "Show it? Yes - 1 | No - 0 : ";
    int show;
    cin >> show;
    if(show) cout << new_tree;
    cout << "Save it? Yes - 1 | No - 0 : ";
    int save;
    cin >> save;
    if(save) SaveTree(new_tree, BinaryTree_T);
}
template <typename T> void isSubTree(BinaryTree<T>* binaryTree, vector<BinaryTree<T>*>* BinaryTree_T){
    cout << "Select the subtree. From saved trees - 0 | Add a new tree - 1: ";
    int select; cin >> select;
    auto* subTree = new BinaryTree<T>();
    if(!select){
        int tree_num = chooseTree(BinaryTree_T);
        subTree = BinaryTree_T->at(tree_num);
    }
    if(select){
        AddTree(BinaryTree_T);
        subTree = BinaryTree_T->back();
    }
    bool issubtree = subTree->isSubTree(binaryTree);
    if(issubtree) cout << "Selected tree is a SubTree\n";
    else cout << "Selected tree is not a SubTree\n";
}
template <typename T> T mult_oon_5(T y){
    return y * (T)5;
}
template <typename T> void MapBinaryTree(BinaryTree<T>* tree, vector<BinaryTree<T>*>* BinaryTree_T){
    T (*f)(T) = &mult_oon_5;
    cout << "Map: inplace - 0 | non-inplace - 1: ";
    int map;
    cin >> map;
    if(map){
        auto* BinaryTree_map = new BinaryTree<T>(tree->Map(f, false));
        cout << "Print new tree: Yes - 1 | No - 0: ";
        int print; cin >> print;
        if(print) cout << BinaryTree_map;
        cout << "Save it? Yes - 1 | No - 0: ";
        int save; cin >> save;
        if(save) SaveTree(BinaryTree_map, BinaryTree_T);
    } else{
        tree->Map(f,true);
        cout << "Print new tree: Yes - 1 | No - 0: ";
        int print; cin >> print;
        if(print) cout << tree;
    }
}
template <typename T> T sum(T x1, T x2){
    return x1 + x2;
}
template <typename T> void ReduceBinaryTree(BinaryTree<T>* tree){
    T (*f_reduce)(T, T) = &sum;
    T k = tree->Reduce(f_reduce, 0);
    cout << "Reduce -> " << k << endl;
}

template <typename T> int where_(T x){
    return x > (T)5;
}
template <typename T> void WhereBinaryTree(BinaryTree<T>* tree, vector<BinaryTree<T>*>* BinaryTree_T){
    auto* new_tree = new BinaryTree<T>(tree->Where(&where_));
    cout << "Show it? Yes - 1 | No - 0 : ";
    int show;
    cin >> show;
    if(show) cout << new_tree;
    cout << "Save it? Yes - 1 | No - 0 : ";
    int save;
    cin >> save;
    if(save) SaveTree(new_tree, BinaryTree_T);
}

template <typename T> void TreeFunctions(vector<BinaryTree<T>*>* BinaryTree_T){
    while(true){
        int t = chooseTree(BinaryTree_T);
        if(t != -1){
            auto* tree = BinaryTree_T->at(t);
            while (true){
                int func = chooseTreeFunctionBin();
                if(func == 1) AddEl(tree);
                if(func == 2) DelEl(tree);
                if(func == 3) FindEl(tree);
                if(func == 4) Get_SubTree(tree, BinaryTree_T);
                if(func == 5) isSubTree(tree, BinaryTree_T);
                if(func == 6) MapBinaryTree(tree, BinaryTree_T);
                if(func == 7) ReduceBinaryTree(tree);
                if(func == 8) WhereBinaryTree(tree, BinaryTree_T);
                if(func == 9) cout << tree;
                if(func == 0) break;
            }
        } else break;
    }

}
template <typename T> void UI_BinaryTree(vector<BinaryTree<T>*>* BinaryTree_T)
{
    while(true){
        int func = chooseFunction();
        if(func == 1) showTrees(BinaryTree_T);
        if(func == 2) AddTree(BinaryTree_T);
        if(func == 3) DeleteTree(BinaryTree_T);
        if(func == 4) TreeFunctions(BinaryTree_T);
        if(func == 0) break;
    }
}
void MenuBinaryTree(vector<BinaryTree<int>*>* BinaryTree_int,
                    vector<BinaryTree<double>*>* BinaryTree_double,
                    vector<BinaryTree<complex<double>>*>* BinaryTree_complex)
{
    while(true){
        int type = chooseType();
        if(type == 1) UI_BinaryTree<int>(BinaryTree_int);
        if(type == 2) UI_BinaryTree<double>(BinaryTree_double);
        if(type == 3) UI_BinaryTree<complex<double>>(BinaryTree_complex);
        if(type == 0) break;
    }
}