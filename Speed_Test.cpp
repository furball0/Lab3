#include "Speed_Test.h"
void test_add_bin(){
    fstream fs;
    fs.open("binary_tree_add.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 2; i < 30000; i++) {
        auto* tree = new BinaryTree<double>;
        auto begin = std::chrono::steady_clock::now();
        int k = i/2;
        for(int j = 0; j < k; j++) {
            tree->Add(sin(j));
            tree->Add(-sin(j));
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
}
}
void test_add_bin_slow(){
    fstream fs;
    fs.open("binary_tree_add_slow.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 2; i < 10000; i++) {
        auto* tree = new BinaryTree<double>;
        auto begin = std::chrono::steady_clock::now();
        int k = i/2;
        for(int j = 0; j < k; j++) {
            tree->Add(j);
            tree->Add(-j);
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }
}
void test_add_3_ary(){
    fstream fs;
    fs.open("3_ary_tree_add.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 2; i < 30000; i++) {
        auto* tree = new Tree3<double>;
        auto begin = std::chrono::steady_clock::now();
        int k = i/2;
        for(int j = 0; j < k; j++) {
            tree->Add(sin(j));
            tree->Add(-sin(j));
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }
}

void test_find_3_ary(){
    auto* tree = new Tree3<double>;
    for(int i = 2; i < 15000; i++){
        tree->Add(sin(i));
        tree->Add(-sin(i));
    }
    fstream fs;
    fs.open("3_ary_tree_find.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 2; i < 30000; i++) {
        auto* tree = new Tree3<double>;
        auto begin = std::chrono::steady_clock::now();
        int k = i/2;
        for(int j = 0; j < k; j++) {
            tree->isFind(sin(j));
            tree->isFind(-sin(j));
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }
}

void test_find_bin(){
    auto* tree = new Tree3<double>;
    for(int i = 2; i < 15000; i++){
        tree->Add(sin(i));
        tree->Add(-sin(i));
    }
    fstream fs;
    fs.open("bin_tree_find.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 2; i < 30000; i++) {
        auto* tree = new BinaryTree<double>;
        auto begin = std::chrono::steady_clock::now();
        int k = i/2;
        for(int j = 0; j < k; j++) {
            tree->isFind(sin(j));
            tree->isFind(-sin(j));
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }
}

void test_find_bin_slow(){
    auto* tree = new Tree3<double>;
    for(int i = 2; i < 15000; i++){
        tree->Add(i);
        tree->Add(-i);
    }
    fstream fs;
    fs.open("bin_tree_find_slow.txt", fstream::in | fstream::out | fstream::app);
    for(int i = 2; i < 30000; i++) {
        auto* tree = new BinaryTree<double>;
        auto begin = std::chrono::steady_clock::now();
        int k = i/2;
        for(int j = 0; j < k; j++) {
            tree->isFind(j);
            tree->isFind(-j);
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fs << elapsed_ms.count() << ',' << i+1 << endl;
    }
}