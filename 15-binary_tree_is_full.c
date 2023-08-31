#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_full - Determines whether a
 * binary tree is full.
 *
 * @tree: A pointer to the root node or subtree
 * in the binary tree.
 *
 * Return: The value 1 when @tree is a tree with
 * all nodes having exactly 2 or no children
 * otherwise 0.
 *
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;
	int is_left_subtree_full = 0, is_right_subtree_full = 0;

	if (!tree)
	{
		return (0);
	}

	if (!subtree->left && !subtree->right)
	{
		return (1);
	}

	if (subtree->left && subtree->right)
	{
		is_left_subtree_full = binary_tree_is_full(subtree->left);
		is_right_subtree_full = binary_tree_is_full(subtree->right);

		return (is_left_subtree_full && is_right_subtree_full);
	}

	return (0);
}
