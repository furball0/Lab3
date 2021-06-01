#ifndef LAB3_MENUTREE3_H
#define LAB3_MENUTREE3_H
#include "3-aryTree.h"
#include <typeinfo>
#endif //LAB3_MENUTREE3_H

template <typename T> void showTrees(vector<Tree3<T>*>* tree3_T){
    for(int i = 0; i<(int)tree3_T->size(); i++){
        cout << "Tree " << i << ": \n" << tree3_T->at(i);
    }
}
template <typename T> int chooseTree(vector<Tree3<T>*>* tree3_T){
    int t = 0;
    showTrees(tree3_T);
    cout << "Enter number of tree (-1 - Return back): ";
    cin >> t;
    return t;
}

int chooseTreeFunction(){
    int func;
    cout << "What tree function do you want to use?: \n"
         << "\t1: Add element\n"
         << "\t2: Delete element\n"
         << "\t3: Find\n"
         << "\t4: Get SubTree\n"
         << "\t5: is a SubTree\n"
         << "\t6: Map\n"
         << "\t7: Reduce\n"
         << "\t8: PathSearch\n"
         << "\t9: Print\n\n"
         << "\t0: Return to select tree\n"
         << "Enter a number: ";
    cin >> func;
    cout << sep << endl;
    return func;
}

template <typename T> void SaveTree(Tree3<T>* tree3, vector<Tree3<T>*>* tree3_T){
    tree3_T->push_back(tree3);
}

template <typename T> void AddTree(vector<Tree3<T>*>* tree3_T){
    int size;
    cout << "Enter count of elements: ";
    cin >> size; cout << endl;
    auto* tree3 = new Tree3<T>;
    cout << "Enter numbers (one by one):" << endl;
    T num;
    for(int i = 0; i < size; i++){
        cin >> num;
        tree3->Add(num);
    }
    SaveTree(tree3, tree3_T);
}
template <typename T> void DeleteTree(vector<Tree3<T>*>* tree3_T){
    int t = chooseTree(tree3_T);
    tree3_T->erase(tree3_T->begin() + t);
}

template <typename T> void AddEl(Tree3<T>* tree3){
    cout << "Enter number:" << endl;
    T num;
    cin >> num;
    tree3->Add(num);
}
template <typename T> void DelEl(Tree3<T>* tree3){
    cout << "What element do you want to delete?\nEnter a number: ";
    T key;
    cin >> key;
    tree3->Remove(key);
}
template <typename T> void FindEl(Tree3<T>* tree3){
    cout << "What element do you want to find?\nEnter a number: ";
    T key;
    cin >> key;
    bool find = tree3->isFind(key);
    if(find) cout << "Element Found.\n";
    else cout << "Element wasn't found.\n";
}
template <typename T> void Get_SubTree(Tree3<T>* tree3, vector<Tree3<T>*>* tree3_T){
    cout << "Enter an element: ";
    T key;
    cin >> key;
    auto* new_tree = tree3->GetSubTree(key);
    cout << "Show it? Yes - 1 | No - 0 : ";
    int show;
    cin >> show;
    if(show) cout << new_tree;
    cout << "Save it? Yes - 1 | No - 0 : ";
    int save;
    cin >> save;
    if(save) SaveTree(new_tree, tree3_T);
}
template <typename T> void isSubTree(Tree3<T>* tree3, vector<Tree3<T>*>* tree3_T){
    cout << "Select the subtree. From saved trees - 0 | Add a new tree - 1: ";
    int select; cin >> select;
    auto* subTree = new Tree3<T>();
    if(!select){
        int tree_num = chooseTree(tree3_T);
        subTree = tree3_T->at(tree_num);
    }
    if(select){
        AddTree(tree3_T);
        subTree = tree3_T->back();
    }
    bool issubtree = subTree->isSubTree(tree3);
    if(issubtree) cout << "Selected tree is a SubTree\n";
    else cout << "Selected tree is not a SubTree\n";
}

template <typename T> T mult_on_5(T y){
    return y * (T)5;
}
template <typename T> void MapTree3(Tree3<T>* tree, vector<Tree3<T>*>* tree3_T){
    T (*f)(T) = &mult_on_5;
    cout << "Map: inplace - 0 | non-inplace - 1: ";
    int map;
    cin >> map;
    if(map){
        auto* tree3_map = new Tree3<T>(tree->Map(f, false));
        cout << "Print new tree: Yes - 1 | No - 0: ";
        int print; cin >> print;
        if(print) cout << tree3_map;
        cout << "Save it? Yes - 1 | No - 0: ";
        int save; cin >> save;
        if(save) SaveTree(tree3_map, tree3_T);
    } else{
        tree->Map(f,true);
        cout << "Print new tree: Yes - 1 | No - 0: ";
        int print; cin >> print;
        if(print) cout << tree;
    }
}
template <typename T> void ReduceTree3(Tree3<T>* tree){
    T (*f_reduce)(T, T) = &sum;
    T k = tree->Reduce(f_reduce, 0);
    cout << "Reduce -> " << k << endl;
}
template <typename T> void PathSearch(Tree3<T>* tree,vector<Tree3<T>*>* tree3_T){
    string path;
    cout << tree << "Write the path: \n";
    cin >> path;
    Tree3<T>* pathTree = new Tree3<T>(tree->PathSearch(path));
    cout << "Show it? Yes - 1 | No - 0 : ";
    int show;
    cin >> show;
    if(show) cout << pathTree;
    cout << "Save it? Yes - 1 | No - 0 : ";
    int save;
    cin >> save;
    if(save) SaveTree(pathTree, tree3_T);
}

template <typename T> void TreeFunctions(vector<Tree3<T>*>* tree3_T){
    while(true){
        int t = chooseTree(tree3_T);
        if(t != -1){
            auto* tree = tree3_T->at(t);
            while (true){
                int func = chooseTreeFunction();
                if(func == 1) AddEl(tree);
                if(func == 2) DelEl(tree);
                if(func == 3) FindEl(tree);
                if(func == 4) Get_SubTree(tree, tree3_T);
                if(func == 5) isSubTree(tree, tree3_T);
                if(func == 6) MapTree3(tree, tree3_T);
                if(func == 7) ReduceTree3(tree);
                if(func == 8) PathSearch(tree, tree3_T);
                if(func == 9) cout << tree;
                if(func == 0) break;
            }
        } else break;
    }

}
template <typename T> void UI_Tree3(vector<Tree3<T>*>* tree3_T)
{
    while(true){
        int func = chooseFunction();
        if(func == 1) showTrees(tree3_T);
        if(func == 2) AddTree(tree3_T);
        if(func == 3) DeleteTree(tree3_T);
        if(func == 4) TreeFunctions(tree3_T);
        if(func == 0) break;
    }
}
void MenuTree3(vector<Tree3<int>*>* tree3_int,
                    vector<Tree3<double>*>* tree3_double,
                    vector<Tree3<complex<double>>*>* tree3_complex)
{
    while(true){
        int type = chooseType();
        if(type == 1) UI_Tree3<int>(tree3_int);
        if(type == 2) UI_Tree3<double>(tree3_double);
        if(type == 3) UI_Tree3<complex<double>>(tree3_complex);
        if(type == 0) break;
    }
}