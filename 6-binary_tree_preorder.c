#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a tree using
 * the pre-order traversal.
 *
 * @tree: A pointer to the root node of the tree
 * @func: A pointer to a function to call for each
 * node in @tree
 *
 **/
void binary_tree_preorder(const binary_tree_t *tree,
			void (*func)(int))
{
	const binary_tree_t *subtree = tree;

	if (tree && func)
	{
		func(subtree->n);
		binary_tree_preorder(subtree->left, func);
		binary_tree_preorder(subtree->right, func);
	}
}
