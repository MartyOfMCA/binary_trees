#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a tree using
 * the post-order traversal.
 *
 * @tree: A pointer to the root node of the tree
 * @func: A pointer to a function to call for each
 * node in @tree
 *
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *subtree = tree;

	if (tree && func)
	{
		binary_tree_postorder(subtree->left, func);
		binary_tree_postorder(subtree->right, func);
		func(subtree->n);
	}
}
