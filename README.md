*This project has been created as part of the 42 curriculum by rpanetta.*

# push_swap

## Description

**push_swap** is a sorting algorithm project that requires sorting a list of random integers using a limited set of operations on two stacks (stack A and stack B). The objective is to sort the numbers in ascending order in stack A while producing the minimum possible number of operations.

### Project Objectives
- Sort a sequence of integers in ascending order using only stacks A and B
- Use only the allowed stack operations defined by the subject
- Minimize the total number of operations
- Correctly handle invalid input, duplicates, and integer overflows

### Key Features
- **Input Validation**: Validates that all arguments are integers within INT_MIN to INT_MAX, with no duplicates
- **Stack Implementation**: Linked list-based stack structure for simplified push/pop operations
- **Radix Sort Algorithm**: Implements a radix sort algorithm adapted to stack operations for efficient sorting of large inputs
- **Optimized Small Sorts**: Specific sorting logic for inputs of 2, 3, 4, or 5 elements
- **Index Compression**: Maps integer values to indices between 0 and (n - 1) for efficient bit manipulation

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This command generates the \push_swap\ executable.

To clean object files and the executable:

```bash
make clean
```
Removes object files
```bash
make fclean
```
Removes object files and the executable
```bash
make re
```
Rebuilds everything


### Execution

Run the program by passing a list of integers as command-line arguments:
<pre>./push_swap 23 2 50 1 4 </pre>

Or with quoted input:
<pre>./push_swap "23 2 50 1 4" </pre>

The list of integers represent the values in stack A (from top to bottom)

The program outputs a sequence of instructions (one per line) that, when executed, will sort stack A.

### Testing with checker

To start the checker_linux:

<pre> chmod +x checker_linux </pre>

<pre>ARG="23 2 50 1 4"; ./push_swap $ARG | ./checker_linux $ARG</pre>

### Output:
- `OK` if the stack is correctly sorted
- `KO` if the stack is not sorted or operations are invalid
- `Error` if ivalid input is provided

**Allowed Operations:**

| Operations | Descripcion |
|------------|-------------|
| `sa` | Swap the top two elements of stack A |
| `sb` | Swap the top two elements of stack B |
| `sb` | Swap the top two elements of stack B |
| `sb` | Swap the top two elements of stack B |
| `ss` | Perform `sa` and `sb` at the same time |
| `pa` | Push the first element of stack B to stack A |
| `pb` | Push the first element of stack A to stack B |
| `ra` | Shift up all elements of stack A by 1. The first element becomes the last one |
| `rb` | Shift up all elements of stack B by 1. The first element becomes the last one |
| `rr` | Perform `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (move bottom to top) |
| `rrb` | Reverse rotate stack B (move bottom to top) |
| `rrr` | Perform `ra` and `rb` at the same time |

### Error Handling

The program outputs `Error` followed by '\n' to the standard error and exits with status `1` if:
- An argument is not a valid integer
- A value is outside the `INT_MIN` / `INT_MAX` range
- Duplicate integers are found in the input

## Algorithm Overview

### Radix Sort
The main sorting strategy is a binary radix sort, adapted to work with stack operations

1. **Index Compression**: All values are mapped to indices based on their sorted order
2. **Bit-by-Bit Processing**: Elements are processed bit by bit, from the least significant bit (LSB) to the most significant bit (MSB)
3. **Stable Partitioning**: For each bit position, values are distributed between stacks A and B based on whether the bit is `0` or `1`
4. **Reconstruction**: Elements are pushed back to stack A

### Small Input Optimization
For small inputs, specialized fuctions reduce the number of operations:
- **2 elements**: Maximum of 1 operation
- **3 elements**: Maximum of 2 operations
- **4-5 elements**: Rotate or reverse rotate stack A in search for the min integer being closest to the top/bottom of the stack respectively. Push min to B until A is left with 3 elements. Reuse the specialized function to sort 3 elements in A. Push elements in B, back to A

### Testing
```bash
# Test with 3 numbers
./push_swap 3 1 2 | ./checker_linux 3 1 2

# Test with 5 numbers
./push_swap 4 1 3 5 2 | ./checker_linux 4 1 3 5 2

# Test with 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG |./checker_linux $ARG

# Test with 500 random numbers
ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```
### Counting operations
```bash
# Count operations for 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Count operations for 500 random numbers
ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Error Test
```bash
# Test with duplicates (should show Error)
./push_swap 1 2 3 2

# Test with non-numeric input (should show Error)
./push_swap 1 2 abc

# Test with overflow (should show Error)
./push_swap 1 2 2147483648
```

## Resources

### References
- **Sorting Algorithms**: [GeeksforGeeks - Radix Sort](https://www.geeksforgeeks.org/radix-sort/)
- **Radix Sort**: [GeeksforGeeks - Radix Sort](https://www.youtube.com/watch?v=nu4gDuFabIM)
- **Stack Data Structure**: [Wikipedia - Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- **Bit Manipulation**: [Medium - Bit Manipulation in C](https://medium.com/@bouali.mohamed.amin/bit-manipulation-in-c-3e18f8bfde0c)

## AI Usage

- Review input validation logic and integer overflow handling
- Assisted in refining the \is_int()\ function to properly handle `INT_MIN` and `INT_MAX` boundaries
