
# push_swap

## Description
This project is a solution to the 42 school push_swap challenge. The goal is to sort a stack of integers using a limited set of operations, with the minimum number of moves. The program takes a list of integers as arguments and outputs the sequence of operations to sort them.

## Concept
The main concept is to manipulate two stacks (A and B) using specific operations: push, swap, rotate, and reverse rotate. The challenge is to sort the stack efficiently, minimizing the number of operations.

## Algorithms Used
- **Simple sort for small stacks**: For 2 or 3 elements, a hardcoded solution is used.
- **Divide and conquer**: For larger stacks, the algorithm splits the stack into smaller parts, pushes elements between stacks, and sorts them recursively.
- **Chunking**: The stack is divided into chunks to optimize the sorting process and reduce the number of moves.

## Files
- `push_swap.c`: Main program logic.
- `sort_stacks.c`, `sort_three.c`: Sorting algorithms.
- `stack_init.c`, `stack_utils.c`: Stack initialization and utilities.
- `push.c`, `swap.c`, `rotate.c`, `rev_rotate.c`: Stack operations.
- `errors.c`: Error handling.
- `libft/`: Custom standard library functions.

## Usage
```
make
./push_swap 3 2 1 6 5 8
```

## Notes
- Only allowed operations are used.
- Input validation and error handling are included.
- The project is coded in C following 42 school standards.
