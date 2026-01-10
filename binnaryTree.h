//
// Created by olidiaks on 10.01.2026.
//

#ifndef PROJECT_BINNARYTREE_H
#define PROJECT_BINNARYTREE_H

#include <stddef.h>

/**
 * @brief Represents a node in a binary tree.
 *
 * This structure is used as the fundamental building block for a binary tree.
 * Each node contains a pointer to an integer value, as well as pointers to
 * its left and right child nodes. The left and right pointers allow the
 * formation of a binary tree structure by linking multiple nodes.
 *
 * The data pointer must point to a valid integer. The child pointers
 * may be NULL to indicate that the node does not have children in that
 * direction.
 */
struct Node {
    int *data;
    struct Node *left;
    struct Node *right;
};

struct Node *insertNode(struct Node *root, int *value);

void searchNode(struct Node *treeBranch, int *value);

/**
 * @brief Creates a new node for a binary tree.
 *
 * This function allocates memory for a new binary tree node,
 * initializes its data with the provided value, and sets its
 * left and right child pointers to NULL. If memory allocation
 * fails, the function will print an error message and terminate
 * the program.
 *
 * @param value Pointer to the integer value to be assigned to the node.
 * @return Pointer to the newly created Node structure.
 */
struct Node *createNode(int *value);

#endif // PROJECT_BINNARYTREE_H
