#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle of @node.
 *
 * @node: A pointer to the node whose uncle is
 * needed.
 *
 * Return: The uncle node.
 *
 **/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent = NULL;

	if (!node || !node->parent)
	{
		return (NULL);
	}

	grand_parent = node->parent->parent;

	return (((!grand_parent) ?
		NULL :
		((grand_parent->right == node->parent) ?
		 grand_parent->left : grand_parent->right)));
}
