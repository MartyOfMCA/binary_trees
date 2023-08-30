#include "binary_trees.h"

/**
 * binary_tree_node - Create a node in the binary
 * tree.
 *
 * @parent: The parent for the new node
 * @value: The value for the newly created node
 *
 * Return: A pointer to the newly created node
 * or NULL
 *
 **/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));
	if (node)
	{
		node->n = value;
		node->left = node->right = NULL;
		node->parent = parent;
	}

	return (node);
}
