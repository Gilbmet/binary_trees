#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node, *old_left_child;

    if (!parent)
        return (NULL);

    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    old_left_child = parent->left;
    parent->left = new_node;

    if (old_left_child)
    {
        new_node->left = old_left_child;
        old_left_child->parent = new_node;
    }

    return (new_node);
}
