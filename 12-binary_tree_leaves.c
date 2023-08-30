#include "binary_trees.h"

/**
 * binary_tree_leaves - Retusn the number of leaves
 * in a binary tree.
 *
 * @tree: A pointer to the root node or subtree
 * in the binary tree.
 *
 * Return: The number of leaf nodes.
 *
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;
	size_t leaves_count = 0;

	if (!tree)
	{
		return (0);
	}

	if (!subtree->left && !subtree->right)
	{
		return (1);
	}
	leaves_count += binary_tree_leaves(subtree->left);
	leaves_count += binary_tree_leaves(subtree->right);

	return (leaves_count);
}
