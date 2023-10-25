# 0x1B. C - Sorting algorithms & Big O

**Author:** Samari Hamza ([GitHub](https://github.com/himza25)) - ALX ID: samari25

## Overview

This repository contains various sorting algorithms implemented in C, as well as analyses of their time complexities (Big O notations).

## Repo Contents

- **Sorting Algorithms:** Bubble Sort, Insertion Sort, Selection Sort, Quick Sort, Shell Sort (Knuth Sequence), Cocktail Shaker Sort, Counting Sort, Merge Sort, Heap Sort, Radix Sort, Bitonic Sort, Quick Sort (Hoare Partition scheme), and a card deck sorting algorithm.
- **Big O Notations:** Best, Average, and Worst case time complexities are provided for each algorithm.
- **Example Codes and Outputs:** Demonstrations of each algorithm in action.

## File Structure

- Source files are named according to their corresponding task number (e.g., `0-bubble_sort.c` for Bubble Sort).
- Big O notations are contained in files named with the task number followed by `-O` (e.g., `0-O` for Bubble Sort's time complexity).

## Compilation

Your files will be compiled on Ubuntu 20.04 LTS using `gcc`, with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.

## Usage

1. Clone this repository: `git clone https://github.com/himza25/sorting_algorithms.git`
2. Navigate to the repository directory: `cd sorting_algorithms`
3. Compile the source files with `gcc` as described above.
4. Run the compiled executable to see a particular sorting algorithm in action.

## Task Summaries

### Bubble Sort
- Sorts an array of integers in ascending order.
- Prints the array after each swap.
- Files: `0-bubble_sort.c`, `0-O`

### Insertion Sort
- Sorts a doubly linked list of integers in ascending order.
- Prints the list after each swap.
- Files: `1-insertion_sort_list.c`, `1-O`

### Selection Sort
- Sorts an array of integers in ascending order.
- Prints the array after each swap.
- Files: `2-selection_sort.c`, `2-O`

### Quick Sort
- Sorts an array of integers in ascending order.
- Prints the array after each swap.
- Files: `3-quick_sort.c`, `3-O`

### Shell Sort - Knuth Sequence
- Sorts an array of integers using the Shell sort algorithm with the Knuth sequence.
- Prints the array each time the interval decreases.
- Files: `100-shell_sort.c`

### Cocktail Shaker Sort
- Sorts a doubly linked list of integers in ascending order.
- Prints the list after each swap.
- Files: `101-cocktail_sort_list.c`, `101-O`

### Counting Sort
- Sorts an array of integers in ascending order.
- Prints the counting array once set up.
- Files: `102-counting_sort.c`, `102-O`

### Merge Sort
- Sorts an array of integers in ascending order.
- Prints the merging process.
- Files: `103-merge_sort.c`, `103-O`

### Heap Sort
- Sorts an array of integers in ascending order.
- Prints the array after each swap.
- Files: `104-heap_sort.c`, `104-O`

### Radix Sort
- Sorts an array of integers in ascending order using the LSD radix sort algorithm.
- Prints the array each time the significant digit increases.
- Files: `105-radix_sort.c`

### Bitonic Sort
- Sorts an array of integers in ascending order.
- Prints the array each time two elements are swapped.
- Files: `106-bitonic_sort.c`, `106-O`

### Quick Sort - Hoare Partition scheme
- Sorts an array of integers in ascending order using the Hoare partition scheme.
- Prints the array after each swap.
- Files: `107-quick_sort_hoare.c`, `107-O`

### Dealer
- Sorts a deck of cards.
- Uses the C standard library function `qsort`.
- Files: `1000-sort_deck.c`, `deck.h`

## Contact

For inquiries or issues, please contact Samari Hamza via [GitHub](https://github.com/himza25).

