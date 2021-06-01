#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MenuFull.h"
BinaryTree<double>* create_bin_tree(){
    auto* bin_tree = new BinaryTree<double>;
    bin_tree->Add(5);bin_tree->Add(5.5);bin_tree->Add(4.5);
    bin_tree->Add(7.7);bin_tree->Add(4.8);bin_tree->Add(5.3);
    bin_tree->Add(9.0);bin_tree->Add(10);
    return bin_tree;
}

/*
                .---10
            .---9
        .---7.7
    .---5.5
   |    `---5.3
---5
   |    .---4.8
    `---4.5
*/
TEST_CASE("BinaryTreeAdd"){
    auto* bin_tree_add = new BinaryTree<double>(create_bin_tree());
    REQUIRE(bin_tree_add->get_root()->key == 5);
    REQUIRE(bin_tree_add->get_root()->left->key == 4.5);
    REQUIRE(bin_tree_add->get_root()->right->key == 5.5);
    REQUIRE(bin_tree_add->get_root()->right->left->key == 5.3);
    bin_tree_add->Add(6);
    REQUIRE(bin_tree_add->get_root()->right->right->left->key == 6);
}
TEST_CASE("BinaryTreeRemove"){
    auto* bin_tree_remove = new BinaryTree<double>(create_bin_tree());
    bin_tree_remove->Remove(5.5);
    REQUIRE(bin_tree_remove->get_root()->right->key == 7.7);
    REQUIRE(bin_tree_remove->get_root()->right->left->key == 5.3);
    REQUIRE(bin_tree_remove->get_root()->left->key == 4.5);
}
TEST_CASE("BinaryTreeisFind"){
    auto* bin_tree_isFind = new BinaryTree<double>(create_bin_tree());
    REQUIRE(bin_tree_isFind->isFind(5) == 1);
    REQUIRE(bin_tree_isFind->isFind(10) == 1);
    REQUIRE(bin_tree_isFind->isFind(9) == 1);
    REQUIRE(bin_tree_isFind->isFind(4.8) == 1);
    REQUIRE(bin_tree_isFind->isFind(4.7) == 0);
    REQUIRE(bin_tree_isFind->isFind(15) == 0);
}
TEST_CASE("BinaryTreeMap"){
    auto* bin_tree_Map = new BinaryTree<double>(create_bin_tree());
    double (*f_map)(double) = &mult_oon_5;
    bin_tree_Map->Map(f_map, true);
    REQUIRE(bin_tree_Map->get_root()->key == 25);
    REQUIRE(bin_tree_Map->get_root()->left->key == 22.5);
    REQUIRE(bin_tree_Map->get_root()->right->key == 27.5);
    REQUIRE(bin_tree_Map->get_root()->right->left->key == 26.5);
}
TEST_CASE("BinaryTreeWhere"){
    auto* bin_tree_Where = new BinaryTree<double>(create_bin_tree());
    auto* new_tree_where = new BinaryTree<double>(bin_tree_Where->Where(where_));
    REQUIRE(new_tree_where->get_root()->key == 5.3);
    REQUIRE(new_tree_where->get_root()->right->key == 5.5);
    REQUIRE(new_tree_where->get_root()->right->right->key == 7.7);
    REQUIRE(new_tree_where->get_root()->right->right->right->key == 9);
    REQUIRE(new_tree_where->get_root()->right->right->right->right->key == 10);
}
TEST_CASE("BinaryTreeReduce"){
    auto* bin_tree_Reduce = new BinaryTree<double>(create_bin_tree());
    //sum
    double (*f_reduce)(double, double) = &sum;
    REQUIRE(bin_tree_Reduce->Reduce(f_reduce, 1.2) == 53); //sum + 1
}
TEST_CASE("BinaryTreeGetSubTree"){
    auto* bin_tree_GetSubTree = new BinaryTree<double>(create_bin_tree());
    auto* new_tree = bin_tree_GetSubTree->GetSubTree(5.5);
    REQUIRE(new_tree->get_root()->key==5.5);
    REQUIRE(new_tree->get_root()->right->key==7.7);
    REQUIRE(new_tree->get_root()->left->key==5.3);
}
TEST_CASE("BinaryTreeisSubTree"){
    auto* bin_tree_isSubTree = new BinaryTree<double>(create_bin_tree());
    auto* bin_tree_isSubTree1 = new BinaryTree<double>(create_bin_tree());
//    auto* new_is_sub_tree = new BinaryTree<double>(bin_tree_isSubTree->GetSubTree(4.5));
//    auto* new_is_sub_tree_2 = new BinaryTree<double>(bin_tree_isSubTree->GetSubTree(5.5));
    REQUIRE(bin_tree_isSubTree1->isSubTree(bin_tree_isSubTree) == 1);
    bin_tree_isSubTree1->Add(6);
    REQUIRE(bin_tree_isSubTree1->isSubTree(bin_tree_isSubTree) == 0);
}

Tree3<double>* create_3_tree(){
    auto* tree_3 = new Tree3<double>;
    tree_3->Add(5);tree_3->Add(5.5);tree_3->Add(4.5);
    tree_3->Add(7.7);tree_3->Add(4.8);tree_3->Add(5.3);
    tree_3->Add(9.0);tree_3->Add(10);tree_3->Add(5.5);tree_3->Add(4.8);
    return tree_3;
}
/*
                .---10
            .---9
        .---7.7
    .---5.5 ---5.5
   |    `---5.3
---5
   |    .---4.8---4.8
    `---4.5
*/
TEST_CASE("Tree3Add"){
    auto* tree_3_add = new Tree3<double>(create_3_tree());
    REQUIRE(tree_3_add->get_root()->key == 5);
    REQUIRE(tree_3_add->get_root()->left->key == 4.5);
    REQUIRE(tree_3_add->get_root()->right->central->key == 5.5);
    REQUIRE(tree_3_add->get_root()->right->left->key == 5.3);
    tree_3_add->Add(6);
    REQUIRE(tree_3_add->get_root()->right->right->left->key == 6);
}
TEST_CASE("Tree3Remove"){
    auto* tree_3_remove = new Tree3<double>(create_3_tree());
    tree_3_remove->Remove(5.5);
    REQUIRE(tree_3_remove->get_root()->right->right->key == 7.7);
    REQUIRE(tree_3_remove->get_root()->right->key == 5.5);
    REQUIRE(tree_3_remove->get_root()->left->key == 4.5);
}
TEST_CASE("Tree3isFind"){
    auto* tree_3_isFind = new Tree3<double>(create_3_tree());
    REQUIRE(tree_3_isFind->isFind(5) == 1);
    REQUIRE(tree_3_isFind->isFind(10) == 1);
    REQUIRE(tree_3_isFind->isFind(9) == 1);
    REQUIRE(tree_3_isFind->isFind(4.8) == 1);
    REQUIRE(tree_3_isFind->isFind(5.5) == 1);
    REQUIRE(tree_3_isFind->isFind(15) == 0);
}
TEST_CASE("Tree3Map"){
    auto* tree_3_Map = new Tree3<double>(create_3_tree());
    double (*f_map)(double) = &mult_oon_5;
    tree_3_Map->Map(f_map, true);
    REQUIRE(tree_3_Map->get_root()->key == 25);
    REQUIRE(tree_3_Map->get_root()->left->key == 22.5);
    REQUIRE(tree_3_Map->get_root()->right->key == 27.5);
    REQUIRE(tree_3_Map->get_root()->right->left->key == 26.5);
}
TEST_CASE("Tree3Reduce"){
    auto* tree_3_Reduce = new Tree3<double>(create_3_tree());
    //sum
    double (*f_reduce)(double, double) = &sum;
    REQUIRE(tree_3_Reduce->Reduce(f_reduce, 1.9) == 64); //sum + 1
}
TEST_CASE("Tree3isSubTree"){
    auto* tree_3_isSubTree = new Tree3<double>(create_3_tree());
    auto* tree_3_isSubTree1 = new Tree3<double>(create_3_tree());
    REQUIRE(tree_3_isSubTree1->isSubTree(tree_3_isSubTree) == 1);
    tree_3_isSubTree1->Add(6);
    REQUIRE(tree_3_isSubTree1->isSubTree(tree_3_isSubTree) == 0);
}
TEST_CASE("Tree3GetSubTree"){
    auto* tree_3_GetSubTree = new Tree3<double>(create_3_tree());
    auto* new_tree = tree_3_GetSubTree->GetSubTree(5.5);
    REQUIRE(new_tree->get_root()->key==5.5);
    REQUIRE(new_tree->get_root()->central->key==5.5);
    REQUIRE(new_tree->get_root()->right->key==7.7);
    REQUIRE(new_tree->get_root()->left->key==5.3);
}
TEST_CASE("Tree3PathSearch"){
    auto* tree_3_PathSearch = new Tree3<double>(create_3_tree());
    REQUIRE(tree_3_PathSearch->PathSearch("")->key == 5);
    REQUIRE(tree_3_PathSearch->PathSearch("l")->key == 4.5);
    REQUIRE(tree_3_PathSearch->PathSearch("lr")->key == 4.8);
    REQUIRE(tree_3_PathSearch->PathSearch("lrc")->key == 4.8);
    REQUIRE(tree_3_PathSearch->PathSearch("rc")->key == 5.5);
    REQUIRE(tree_3_PathSearch->PathSearch("rr")->key == 7.7);
    REQUIRE(tree_3_PathSearch->PathSearch("rl")->key == 5.3);
    REQUIRE(tree_3_PathSearch->PathSearch("rrrr")->key != 9);
}
/*
                .---10
            .---9
        .---7.7
    .---5.5 ---5.5
   |    `---5.3
---5
   |    .---4.8---4.8
    `---4.5
*/