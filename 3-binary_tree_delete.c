#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary
 * tree.
 *
 * @tree: A pointer to the root of the tree
 *
 **/
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *subtree = tree;

	if (!tree)
	{
		return;
	}

	binary_tree_delete(subtree->left);
	binary_tree_delete(subtree->right);

	free(subtree);
}
