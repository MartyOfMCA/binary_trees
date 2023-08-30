#include "binary_trees.h"

/**
 * binary_tree_insert_left - Add a new node as the
 * left child of @parent.
 *
 * @parent: The parent for the new node
 * @value: The value for the newly created node
 *
 * Return: A pointer to the newly created node
 * or NULL.
 *
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
	{
		return (NULL);

	}

	node = binary_tree_node(parent, value);
	if (!node)
	{
		return (NULL);
	}

	if (parent->left)
	{
		parent->left->parent = node;
	}
	node->left = parent->left;
	parent->left = node;

	return (node);
}
