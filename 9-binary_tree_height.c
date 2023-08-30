#include "binary_trees.h"

/**
 * binary_tree_height - Returns the height of a
 * binary tree.
 *
 * @tree: A pointer to the root node of the tree
 * whose height needs to be measured.
 *
 * Return: The height of @tree.
 *
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;
	size_t left_edges = 0, right_edges = 0;

	if (!tree || (!subtree->left && !subtree->right))
	{
		return (0);
	}

	left_edges = (1 + binary_tree_height(subtree->left));
	right_edges = (1 + binary_tree_height(subtree->right));

	return (left_edges > right_edges ? left_edges : right_edges);
}
