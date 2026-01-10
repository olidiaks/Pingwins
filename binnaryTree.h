//
// Created by olidiaks on 10.01.2026.
//

#ifndef PROJECT_BINNARYTREE_H
#define PROJECT_BINNARYTREE_H

#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
 * @brief Represents a thread-safe binary tree container.
 *
 * This structure serves as the main handler for the binary tree. It maintains
 * a pointer to the root node and includes a synchronization primitive to
 * allow safe concurrent access.
 *
 * The inclusion of a read-write lock (pthread_rwlock_t) suggests that this
 * tree is designed to support multiple simultaneous readers (e.g., for lookups
 * or traversals) while ensuring exclusive access for writers (e.g., for insertions
 * or deletions).
 */
struct BinaryTree {
    struct Node *root;
    pthread_rwlock_t lock;
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
struct Node *insertRecursive(struct Node *root, void *value);

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
void *searchRecursive(struct Node *root, void *value);

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

/**
 * @brief Initializes a binary tree structure.
 *
 * This function sets up a binary tree by initializing its root to NULL
 * and preparing a read-write lock for managing concurrent access.
 *
 * After initialization, the tree will be empty and ready to use.
 * The lock ensures thread safety for operations involving the tree.
 *
 * @param tree A pointer to the BinaryTree structure to be initialized.
 *             This pointer must not be NULL.
 */
void initTree(struct BinaryTree *tree);

/**
 * @brief Inserts a value into a binary tree.
 *
 * This function inserts a new value into the binary tree while ensuring
 * thread-safe operations using a read-write lock. The binary tree is updated
 * by adding the new value in its appropriate position, maintaining the binary
 * search tree property. If the tree is empty, it initializes the root node
 * with the provided value. Data comparison is performed using pointer values,
 * and the caller is responsible for ensuring proper comparison logic.
 *
 * @param tree A pointer to the binary tree structure where the value will be inserted.
 *             The tree must be properly initialized before calling this function.
 * @param value A pointer to the value to be inserted into the tree.
 *              The caller is responsible for managing the memory and ensuring the validity of the data.
 */
void insert(struct BinaryTree *tree, void *value);

/**
 * @brief Searches for a value in a binary tree in a thread-safe manner.
 *
 * This function performs a search operation on a binary tree to locate a specific value.
 * It uses a read-write lock to ensure mutual exclusion and safe access in multi-threaded
 * environments while allowing multiple readers at the same time. The function delegates
 * the recursive lookup to an internal helper function.
 *
 * @param tree Pointer to the BinaryTree structure representing the binary tree to be searched.
 *             The binary tree must be initialized and must not be NULL.
 * @param value Pointer to the value being searched for in the binary tree.
 *              The value must be comparable with the `data` values in the nodes.
 * @return A pointer to the found value if it exists in the tree, or NULL if the value
 *         does not exist in the tree.
 */
void *search(struct BinaryTree *tree, void *value);

#endif // PROJECT_BINNARYTREE_H
