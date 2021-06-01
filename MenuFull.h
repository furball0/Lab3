#ifndef LAB3_MENUFULL_H
#define LAB3_MENUFULL_H
#include "MenuBinaryTree.h"
#include "MenuTree3.h"
#endif //LAB3_MENUFULL_H


using namespace std;
auto* tree_int = new vector<BinaryTree<int>*>;
auto* tree_double = new vector<BinaryTree<double>*>;
auto* tree_complex= new vector<BinaryTree<complex<double>>*>;
auto* tree3_int = new vector<Tree3<int>*> ;
auto* tree3_double= new vector<Tree3<double>*>;
auto* tree3_complex = new vector<Tree3<complex<double>>*>;
int chooseTreeType(){
    int type;
    cout << "Select type of Tree: \n"
         << "\t1: Binary Tree\n"
         << "\t2: 3-ary Tree\n\n"
         << "\t0: Exit\n"
         << "Enter a number: ";
    cin >> type;
    cout << sep << endl;
    return type;
}
void menuFull(){

    while(true){
        int type = chooseTreeType();
        if(type == 1)
            MenuBinaryTree(tree_int, tree_double, tree_complex);
        if(type == 2)
            MenuTree3(tree3_int, tree3_double, tree3_complex);

        if(type == 0) break;
        else {
            cout << "write the correct type";
        }

    }
}
