#include "binary_trees.h"

/**
 * binary_tree_size - Returns the size of a
 * binary tree.
 *
 * @tree: A pointer to the root node or subtree
 * in the binary tree.
 *
 * Return: The size of @tree.
 *
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;
	size_t size = 0;

	if (!tree)
	{
		return (0);
	}

	if (!subtree->left && !subtree->right)
	{
		return (1);
	}

	size += (binary_tree_size(subtree->left));
	size += (binary_tree_size(subtree->right));

	return (1 + size);
}
