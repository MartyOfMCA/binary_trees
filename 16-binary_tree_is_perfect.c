#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Determines whether a
 * binary tree is perfect.
 *
 * @tree: A pointer to the root node or subtree
 * in the binary tree.
 *
 * Return: The value 1 when @tree is a tree with
 * all nodes having exactly 2 or no children
 * otherwise 0.
 *
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;
	int is_left_subtree_perfect = 0,
	    is_right_subtree_perfect = 0;

	if (!tree)
	{
		return (0);
	}

	if (binary_subtree_balance(tree) != 0)
	{
		return (0);
	}

	if (!subtree->left && !subtree->right)
	{
		return (1);
	}

	if (subtree->left && subtree->right)
	{
		is_left_subtree_perfect =
			binary_tree_is_perfect(subtree->left);
		is_right_subtree_perfect =
			binary_tree_is_perfect(subtree->right);

		return (is_left_subtree_perfect &&
			is_right_subtree_perfect);
	}

	return (0);

}

/**
 * binary_subtree_balance - Returns the balance
 * factor of a binary tree.
 *
 * @subtree: A pointer to the root node or subtree
 * in the binary tree.
 *
 * Return: The balance factor of the tree.
 *
 **/
int binary_subtree_balance(const binary_tree_t *subtree)
{
	if (!subtree)
	{
		return (0);
	}

	return (binary_subtree_height(subtree->left) -
		binary_subtree_height(subtree->right));
}

/**
 * binary_subtree_height - Returns the height
 * of subtree for @subtree. @subtree could
 * also be the root node in the binary tree.
 *
 * @tree: A pointer to the subtree whose height
 * needs to be determined.
 *
 * Return: The height of the subtree.
 *
 **/
int binary_subtree_height(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;
	size_t left_edges = 0, right_edges = 0;

	if (!tree || (!subtree->left && !subtree->right))
	{
		return (0);
	}

	left_edges = (1 + binary_subtree_height
			(subtree->left));
	right_edges = (1 + binary_subtree_height
			(subtree->right));

	return (left_edges > right_edges ? left_edges :
			right_edges);
}
