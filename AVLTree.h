//
// Created by cc1 on 10/12/22.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <list>
#include <random>
#include <typeinfo>
#include <cassert>
#include <chrono>
#include <exception>
#include "uint256.h" // custom type for uint256


struct NodePosition;
struct Node;
class AVLTree;


struct Node{
    uint256 key;
    uint64_t value;
    int64_t balance_factor;
    Node* parent;
    Node* left;
    Node* right;
    std::int64_t height;
    Node* tree_root;
    bool is_root;
    bool is_tree_root;

    void checkHeight();
    void processHeight();
    void processBalance();
    void rebalance();
    void remove();
    void LLRotation(NodePosition pos);
    void LRRotation(NodePosition pos);
    void RRRotation(NodePosition pos);
    void RLRotation(NodePosition pos);

};

struct NodePosition{
    Node* node;
    int position;
};

class AVLTree {

public:

    AVLTree();
    ~AVLTree();

    Node* insert(uint256 key, uint64_t value);
    Node* search(uint256 key);
    NodePosition insert_position(uint256 key);
    void setRoot(Node* node);
    std::uint64_t getHeight();
    static uint256 random_256();

    std::list <uint256> history;

private:
    Node* tree_root;

};

#endif //AVLTREE_H
