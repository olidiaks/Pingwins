//
// Created by olidiaks on 10.01.2026.
//

#ifndef PROJECT_BINNARYTREE_H
#define PROJECT_BINNARYTREE_H

#include <stddef.h>

struct Node {
    int *data;
    struct Node *left;
    struct Node *right;
};

struct Node *insertNode(struct Node *root, int *value);

void searchNode(struct Node *treeBranch, int *value);

struct Node *createNode(int *value);

#endif // PROJECT_BINNARYTREE_H
