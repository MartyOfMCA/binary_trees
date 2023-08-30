#include "binary_trees.h"

/**
 * binary_tree_insert_right - Add a new node as the
 * right child of @parent.
 *
 * @parent: The parent for the new node
 * @value: The value for the newly created node
 *
 * Return: A pointer to the newly created node
 * or NULL.
 *
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right)
	{
		parent->right->parent = node;
	}
	node->right = parent->right;
	parent->right = node;

	return (node);

}
