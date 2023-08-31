#include "binary_trees.h"

/**
 * binary_tree_balance - Returns the balance
 * factor of a binary tree.
 *
 * @tree: A pointer to the root node or subtree
 * in the binary tree.
 *
 * Return: The balance factor of the tree.
 *
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;

	if (!tree)
	{
		return (0);
	}

	/**
	 * A tree with balance factor of 0 means
	 * both left subtrees and right subtrees
	 * have the same height.
	 *
	 * A tree with a positive balance factor
	 * means the left subtree has a higher
	 * height than the right subtree.
	 *
	 * And finally, a negative balance factor
	 * means the right subtree has a higher height
	 * than the left subtree.
	 **/
	return (binary_subtree_height(subtree->left) -
		binary_subtree_height(subtree->right));
}

/**
 * binary_subtree_height - Returns the height
 * of subtree for @subtree. @subtree could
 * also be the root node in the binary tree.
 *
 * @subtree: A pointer to the subtree whose height
 * subtree needs to be determined.
 *
 * Return: The height of the subtree.
 *
 **/
int binary_subtree_height(const binary_tree_t *subtree)
{
	int left_subtree_height = 0, right_subtree_height = 0;

	if (!subtree)
	{
		return (-1);
	}

	left_subtree_height = (1 + binary_subtree_height(subtree->left));
	right_subtree_height = (1 + binary_subtree_height(subtree->right));

	return (left_subtree_height > right_subtree_height ?
		left_subtree_height : right_subtree_height);
}
