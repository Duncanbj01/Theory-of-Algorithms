#include "BinaryTreeNode.h"

#ifndef BinaryTreeNodeComparator_h
#define BinaryTreeNodeComparator_h

struct BinaryTreeNodeComparator {
    int operator()(const BinaryTreeNode *arg1,
                   const BinaryTreeNode *arg2) const {
        if (arg1->value != arg2->value)
            return arg1->value > arg2->value;
        return arg1->character > arg2->character;
    }
};

#endif /* BinaryTreeNodeComparator_h */
