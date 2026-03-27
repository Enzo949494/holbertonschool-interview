# AVL Trees

Implementation of AVL tree validation in C.

## Description

An AVL Tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for any node.

## Files

| File | Description |
|------|-------------|
| `binary_trees.h` | Header file with the `binary_tree_t` struct and function prototypes |
| `0-binary_tree_is_avl.c` | Function to check if a binary tree is a valid AVL tree |

## Function

```c
int binary_tree_is_avl(const binary_tree_t *tree);
```

Checks if a binary tree is a valid AVL Tree.
- `tree`: pointer to the root node
- Returns `1` if valid AVL Tree, `0` otherwise
- Returns `0` if `tree` is `NULL`

### AVL Tree Properties checked:
1. It is a valid BST (all left values < node, all right values > node)
2. Height difference between left and right subtrees is at most 1
3. Both subtrees are also valid AVL trees

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl
```

## Example Output

```
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
```

## Repository

- **GitHub repository:** holbertonschool-interview
- **Directory:** avl_trees
- **File:** 0-binary_tree_is_avl.c
