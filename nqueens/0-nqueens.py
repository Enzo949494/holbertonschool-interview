#!/usr/bin/python3
"""
N Queens Problem Solver
Solves the N queens puzzle using backtracking algorithm
"""
import sys


def is_safe(board, row, col, n):
    """
    Check if it's safe to place a queen at board[row][col]

    Args:
        board: List of queen positions [row, col]
        row: Current row to check
        col: Current column to place queen
        n: Size of the board

    Returns:
        True if safe to place queen, False otherwise
    """
    # Check if any previously placed queen attacks this position
    for queen in board:
        # Same column
        if queen[1] == col:
            return False
        # Same diagonal (difference of rows equals difference of columns)
        if abs(queen[0] - row) == abs(queen[1] - col):
            return False
    return True


def solve_nqueens(n, row, board, solutions):
    """
    Recursively solve N Queens using backtracking

    Args:
        n: Size of the board
        row: Current row to place queen
        board: Current board state (list of queen positions)
        solutions: List to store all solutions
    """
    # Base case: all queens placed successfully
    if row == n:
        solutions.append(board[:])  # Add a copy of the solution
        return

    # Try placing queen in each column of current row
    for col in range(n):
        if is_safe(board, row, col, n):
            board.append([row, col])  # Place queen
            solve_nqueens(n, row + 1, board, solutions)  # Recurse
            board.pop()  # Backtrack: remove queen


def main():
    """Main function to handle input and print solutions"""
    # Check number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Validate N is an integer
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Validate N is at least 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Solve and print solutions
    solutions = []
    solve_nqueens(n, 0, [], solutions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
