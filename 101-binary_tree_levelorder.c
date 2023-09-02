#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a tree using
 * the level-order traversal.
 *
 * @tree: A pointer to the root node of the tree
 * @func: A pointer to a function to call for each
 * node in @tree
 *
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *subtree = tree;
	int tree_height = 0, level = 0;

	if (!tree || !func)
	{
		return;
	}

	tree_height = binary_subtree_height(subtree);
	while (level <= tree_height)
	{
		print_nodes_at(level, subtree, func);
		level++;
	}
}

/**
 * print_nodes_at - Prints the value for node with
 * the level same as @level.
 *
 * @level: The level for nodes whose values
 * must be printed.
 * @subtree: A pointer to the root node of the
 * binary tree.
 * @func: A pointer to a function to call for each
 * node in @tree having the same level as @level.
 *
 **/
void print_nodes_at(int level, const binary_tree_t *subtree, void (*func)(int))
{
	if (!subtree)
	{
		return;
	}

	if (level == 0)
	{
		func(subtree->n);
		return;
	}

	print_nodes_at(level - 1, subtree->left, func);
	print_nodes_at(level - 1, subtree->right, func);
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
