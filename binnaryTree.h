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
    void *data;
    struct Node *left;
    struct Node *right;
};

/**
 * @brief Inserts a new value into a binary tree.
 *
 * This function inserts a new value into the binary tree, maintaining the
 * properties of a binary search tree. If the root is NULL, a new node is
 * created and returned. Otherwise, the function recursively determines the
 * correct position for the new value and inserts it into the appropriate
 * subtree.
 *
 * @param root Pointer to the root node of the binary tree. It may be NULL if the tree is empty.
 * @param value Pointer to the value to be inserted into the binary tree. This must not be NULL.
 * @return Pointer to the root node of the binary tree after the value has been inserted.
 */
struct Node *insertNode(struct Node *root, void *value);

/**
 * @brief Searches for a node in a binary tree containing the specified value.
 *
 * This function traverses a binary search tree starting from the root, looking
 * for a node that contains the given value. The search follows the properties
 * of a binary search tree: if the target value is less than the current node's
 * value, the function continues the search to the left child, while if the
 * value is greater, the search moves to the right child.
 *
 * @param root A pointer to the root node of the binary tree.
 *             If NULL, the tree is empty, and the search will return NULL.
 * @param value A pointer to the value being searched for in the tree.
 *              The value serves as the key for traversal and lookup.
 *
 * @return A pointer to the data in the node that matches the provided value
 *         or NULL if no such node exists in the tree.
 */
void *searchNode(struct Node *root, void *value);

/**
 * @brief Creates a new node for a binary tree.
 *
 * This function allocates memory for a new binary tree node,
 * initializes its data with the provided value, and sets its
 * left and right child pointers to NULL. If memory allocation
 * fails, the function will print an error message and terminate
 * the program.
 *
 * @param value Pointer to the value to be assigned to the node.
 * @return Pointer to the newly created Node structure.
 */
struct Node *createNode(void *value);

/**
 * @brief Frees all memory associated with a binary tree.
 *
 * This function deallocates the memory used by a binary tree, starting from
 * the specified root node and traversing recursively to its children. Each
 * node in the tree is freed, including its data and child pointers.
 *
 * @param root A pointer to the root node of the binary tree to be freed.
 *             If the root is NULL, the function does nothing.
 */
void freeTree(struct Node *root);

/**
 * @brief Performs an in-order traversal of a binary tree.
 *
 * This function recursively traverses the binary tree in in-order:
 * visiting the left subtree, the current node, and then the right subtree.
 * During the traversal, the value of each node is printed in sequence.
 *
 * If the root node is NULL, the function returns without performing any operation.
 *
 * @param root Pointer to the root node of the binary tree to be traversed.
 */
void inorderTraversal(struct Node *root);

#endif // PROJECT_BINNARYTREE_H
