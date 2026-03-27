#include "binary_trees.h"
#include <limits.h>

/**
 * height - computes the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height of the tree, or 0 if NULL
 */
static int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return (1 + (left_h > right_h ? left_h : right_h));
}

/**
 * is_avl_helper - recursively checks if a tree is a valid AVL BST
 * @tree: pointer to the current node
 * @min: minimum allowed value (exclusive)
 * @max: maximum allowed value (exclusive)
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
static int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_h, right_h, diff;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);
	diff = left_h - right_h;
	if (diff < -1 || diff > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
