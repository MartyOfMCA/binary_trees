#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_trees_ancestor - Fidns the lowest common
 * ancestor for two given nodes.
 *
 * @first: The first node given.
 * @second: The second node given.
 *
 * Return: A pointer to the lowest common ancestor
 * node of @first and @second. NULL is returned
 * if no common ancestor is found.
 *
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int first_node_depth = 0, second_node_depth = 0;

	if (!first || !second ||
		(!first->parent && !second->parent))
	{
		return (NULL);
	}

	first_node_depth = binary_subtree_depth(first);
	second_node_depth = binary_subtree_depth(second);

	if (is_direct_descendant(first, second) ||
		is_direct_descendant(second, first))
	{
		return (first_node_depth <= second_node_depth ?
			(binary_tree_t *)first : (binary_tree_t *)second);
	}

	return (find_immediate_ancestor(first, second,
		first_node_depth, second_node_depth));
}

/**
 * find_immediate_ancestor - Finds the closest ancestor
 * of @first and @second.
 *
 * @first: The first node.
 * @second: The second node.
 * @first_node_depth: The depth of the first node.
 * @second_node_depth: The dept of the second node.
 *
 * Return: The closest ancestor node.
 *
 **/
binary_tree_t *find_immediate_ancestor(
		const binary_tree_t *first,
		const binary_tree_t *second,
		int first_node_depth,
		int second_node_depth)
{
	while (first != second)
	{
		if (first->parent &&
		first_node_depth >= second_node_depth)
		{
			first_node_depth--;
			first = first->parent;
		}
		if (second->parent &&
		second_node_depth >= first_node_depth + 1)
		{
			second_node_depth--;
			second = second->parent;
		}

		if (!first->parent && !second->parent &&
			first != second)
		{
			return (NULL);
		}
	}

	return ((binary_tree_t *)first);
}

/**
 * is_direct_descendant - Checks whether the two
 * nodes are direct descendants. Either @node is
 * a node found under @assumed_ancestor.
 *
 * @node: The search node.
 * @assumed_ancestor: A node assumed to be the
 * ancestor for @node.
 *
 * Return: 1 if @assumed_ancestor is indeed an
 * ancestor of @node. Otherwise 0.
 *
 **/
int is_direct_descendant(const binary_tree_t *node,
			const binary_tree_t *assumed_ancestor)
{
	if (!node)
	{
		return (0);
	}

	if (node == assumed_ancestor)
	{
		return (1);
	}

	return (is_direct_descendant(node->parent, assumed_ancestor));
}

/**
 * binary_subtree_depth - Returns the depth of
 * the given subtree.
 *
 * @subtree: A pointer to the node whose depth
 * or level needs to obtained.
 *
 * Return: The depth of @subtree
 *
 **/
int binary_subtree_depth(const binary_tree_t *subtree)
{
	int depth = 0;

	if (!subtree->parent)
	{
		return (0);
	}

	depth = (1 + binary_subtree_depth(subtree->parent));

	return (depth);
}
