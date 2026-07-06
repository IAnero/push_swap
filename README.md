# push_swap

A sorting algorithm implementation in C that arranges integers across two stacks using a restricted set of operations, designed to minimize the total number of moves.

## Overview

This project is a solution to the 42 School push_swap challenge. Given a set of integers, the program outputs the minimal sequence of operations required to sort stack A in ascending order.

### Problem Constraints

- Two stacks: A (input) and B (auxiliary)
- Limited instruction set: `pa`, `pb`, `sa`, `sb`, `ss`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- No intermediate data structures or sorting functions
- Optimization for efficiency (operation count)

## Algorithm

The implementation uses a **divide-and-conquer strategy with chunking**:

1. **Small stacks (≤3 elements)**: Hardcoded optimal solutions
2. **Medium stacks (4-5 elements)**: Targeted rotation and insertion
3. **Large stacks**: 
   - Divide elements into chunks by value ranges
   - Push chunks to stack B sequentially
   - Retrieve elements from B to A in reverse order (highest first)
   - Minimize intermediate rotations

## Building

```bash
make              # Compile the program
make clean        # Remove object files
make fclean       # Remove all build artifacts
make re           # Clean and rebuild
```

## Usage

```bash
./push_swap 3 2 1 6 5 8
./push_swap 2 1 3 6 5 4
./push_swap 5
```

The program outputs a newline-separated list of operations that sort stack A.

## Features

- **Input validation**: Detects syntax errors and duplicate values
- **Error handling**: Exits with status 1 on invalid input
- **Standard compliance**: Adheres to 42 School coding standards (5 function maximum per file, rigid naming conventions)

## Project Structure

| File | Purpose |
|------|---------|
| `push_swap.c` | Main entry point and orchestration |
| `sort_stacks.c` | Divide-and-conquer sorting algorithm |
| `sort_three.c` | Hardcoded solutions for ≤3 elements |
| `init_a_to_b.c`, `init_b_to_a.c` | Node initialization and cost calculation |
| `stack_init.c`, `stack_utils.c` | Stack management utilities |
| `{push,swap,rotate,rev_rotate}.c` | Stack operation implementations |
| `errors.c` | Input validation and error reporting |
| `split.c` | Argument parsing for quoted input |
| `libft/` | Custom C standard library implementation |

## Technical Details

### Stack Representation

Doubly-linked list with index tracking:
```c
typedef struct s_stack_node {
    int value;
    int index;           // Position in sorted order
    int push_cost;       // Operations to push this element
    bool above_median;   // Relative position to stack middle
    bool cheapest;       // Flag for optimal move selection
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;
```

### Operations Reference

| Op | Action |
|----|--------|
| `sa`, `sb` | Swap top two elements |
| `ss` | `sa` and `sb` simultaneously |
| `pa`, `pb` | Push top element between stacks |
| `ra`, `rb` | Rotate stack (top → bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra`, `rrb` | Reverse rotate (bottom → top) |
| `rrr` | `rra` and `rrb` simultaneously |

## Performance

Typical operation counts for random inputs:
- 3 elements: 2-3 operations
- 5 elements: 8-12 operations
- 100 elements: ~700-900 operations
- 500 elements: ~5,500-7,000 operations

## License

Academic project for 42 School.
