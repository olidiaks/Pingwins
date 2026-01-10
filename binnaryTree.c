//
// Created by olidiaks on 10.01.2026.
//

#include "binnaryTree.h"

#include <stdio.h>
#include <stdlib.h>

struct Node *insertNode(struct Node *root, int *value) {
    if (!root)
        return createNode(value);

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}
struct Node *createNode(int *value) {
    struct Node *node = malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed for next binary tree node.\n");
        exit(3);
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int *searchNode(struct Node *root, int *value) {
    if (!root || root->data == value)
        return root->data;
    return searchNode(value < root->data ? root->left : root->right, value);
}

void freeTree(struct Node *root) {
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void inorderTraversal(struct Node *root) {
    if (!root)
        return;
    inorderTraversal(root->left);
    printf("%d ->", *root->data);
    inorderTraversal(root->right);
}
