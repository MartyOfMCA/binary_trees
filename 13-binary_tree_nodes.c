#include "binary_trees.h"

/**
 * binary_tree_nodes - Returns the number of nodes
 * with at least a child node in a binary tree.
 *
 * @tree: A pointer to the root node or subtree
 * in the binary tree.
 *
 * Return: The number of nodes with cild nodes.
 *
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	const binary_tree_t *subtree = tree;
	size_t nodes_count = 0;

	if (!tree || (!subtree->left && !subtree->right))
	{
		return (0);
	}

	nodes_count += (binary_tree_nodes(subtree->left));
	nodes_count += (binary_tree_nodes(subtree->right));

	return (1 + nodes_count);
}
