#include "binary_trees.h"

/**
 * binary_tree_depth - Returns the depth of a
 * node in a binary tree.
 *
 * @node: A pointer to a node in the tree
 * whose depth needs to be measured.
 *
 * Return: The depth of @node.
 *
 **/
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (!node || !node->parent)
	{
		return (0);
	}

	return (1 + binary_tree_depth(node->parent));
}
