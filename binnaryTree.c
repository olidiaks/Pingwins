//
// Created by olidiaks on 10.01.2026.
//

#include "binnaryTree.h"


struct Node *insertRecursive(struct Node *root, void *value) {
    if (!root)
        return createNode(value);

    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }

    return root;
}
struct Node *createNode(void *value) {
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
void *searchRecursive(struct Node *root, void *value) {
    if (!root || root->data == value)
        return root->data;
    return searchRecursive(value < root->data ? root->left : root->right, value);
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
    printf("%p ->", root->data);
    inorderTraversal(root->right);
}
void initTree(struct BinaryTree *tree) {
    tree->root = NULL;
    pthread_rwlock_init(&tree->lock, NULL);
}

void insert(struct BinaryTree *tree, void *value) {
    pthread_rwlock_wrlock(&tree->lock);
    tree->root = insertRecursive(tree->root, value);
    printf("Writer Thread %ld: Inserted %p\n", (long) pthread_self(), value);
    pthread_rwlock_unlock(&tree->lock);
}
void *search(struct BinaryTree *tree, void *value) {
    pthread_rwlock_rdlock(&tree->lock);
    struct Node *result = searchRecursive(tree->root, value);
    if (result)
        printf("Reader Thread %ld: Found %p\n", (long) pthread_self(), result);
    else
        printf("Reader Thread %ld: Not found\n", (long) pthread_self());
    pthread_rwlock_unlock(&tree->lock);
    return result;
}
