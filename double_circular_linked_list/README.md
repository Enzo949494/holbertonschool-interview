# Double Circular Linked List

Implementation of a doubly circular linked list in C.

## Description

A doubly circular linked list is a linked list where:
- Each node has a `prev` and `next` pointer
- The last node's `next` points back to the head
- The head's `prev` points back to the last node

## Files

| File | Description |
|------|-------------|
| `list.h` | Header file with the `List` struct and function prototypes |
| `0-add_node.c` | Functions to add nodes at the end or beginning of the list |

## Data Structure

```c
typedef struct List
{
    char *str;
    struct List *prev;
    struct List *next;
} List;
```

## Functions

### `add_node_end`
```c
List *add_node_end(List **list, char *str);
```
Adds a new node at the **end** of the doubly circular linked list.
- `list`: pointer to the head of the list
- `str`: string to copy into the new node
- Returns: address of the new node, or `NULL` on failure

### `add_node_begin`
```c
List *add_node_begin(List **list, char *str);
```
Adds a new node at the **beginning** of the doubly circular linked list.
- `list`: pointer to the head of the list
- `str`: string to copy into the new node
- Returns: address of the new node, or `NULL` on failure

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
```

## Example Output

```
Added to the end:
Holberton
	->prev: Engineer
	->next: School
School
	->prev: Holberton
	->next: Full
Full
	->prev: School
	->next: Stack
Stack
	->prev: Full
	->next: Engineer
Engineer
	->prev: Stack
	->next: Holberton
Added to the beginning:
Engineer
	->prev: Holberton
	->next: Stack
Stack
	->prev: Engineer
	->next: Full
Full
	->prev: Stack
	->next: School
School
	->prev: Full
	->next: Holberton
Holberton
	->prev: School
	->next: Engineer
```

## Repository

- **GitHub repository:** holbertonschool-interview
- **Directory:** double_circular_linked_list
- **File:** 0-add_node.c
