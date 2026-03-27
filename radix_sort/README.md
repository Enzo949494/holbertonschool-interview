# Radix Sort

Implementation of the LSD (Least Significant Digit) Radix sort algorithm in C.

## Description

Radix sort is a non-comparative integer sorting algorithm that sorts data by processing individual digits. The LSD variant starts from the least significant digit and moves toward the most significant digit.

**Time complexity:** O(d × (n + k)) where d is the number of digits, n is the number of elements, and k is the base (10).

## Files

| File | Description |
|------|-------------|
| `sort.h` | Header file with function prototypes |
| `0-radix_sort.c` | LSD radix sort implementation |
| `print_array.c` | Helper to print an array of integers |

## Function

```c
void radix_sort(int *array, size_t size);
```

Sorts an array of integers in ascending order using LSD radix sort.
- Only works with numbers >= 0
- Prints the array after each pass (each significant digit increase)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

## Example Output

```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Repository

- **GitHub repository:** holbertonschool-interview
- **Directory:** radix_sort
- **File:** 0-radix_sort.c
