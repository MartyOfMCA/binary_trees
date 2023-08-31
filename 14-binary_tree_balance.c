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

	if (!tree || (!tree->left && !tree->right))
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
	return (binary_left_subtree_height(subtree) -
		binary_right_subtree_height(subtree));
}

/**
 * binary_left_subtree_height - Returns the height
 * of left subtree for @subtree. @subtree could
 * also be the root node in the binary tree.
 *
 * @subtree: A pointer to the subtree whose left
 * subtree needs to be determined.
 *
 * Return: The height of the left subtree.
 *
 **/
int binary_left_subtree_height(const binary_tree_t *subtree)
{
	if (!subtree->left)
	{
		return (0);
	}

	return (1 +
		binary_left_subtree_height(subtree->left));
}

/**
 * binary_right_subtree_height - Returns the height
 * of right subtree for @subtree. @subtree could
 * also be the root node in the binary tree.
 *
 * @subtree: A pointer to the subtree whose right
 * subtree needs to be determined.
 *
 * Return: The height of the right subtree.
 *
 **/
int binary_right_subtree_height(const binary_tree_t *subtree)
{
	if (!subtree->right)
	{
		return (0);
	}

	return (1 +
		binary_right_subtree_height(subtree->right));
}
