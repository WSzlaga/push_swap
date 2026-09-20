*This project has been created as part of the 42 curriculum by <wszlaga>.*

# push_swap

Sort a stack of integers using two stacks and a limited set of operations,
in as few operations as possible.

## Description

push_swap sorts a stack of unique integers using two stacks (`a` and `b`)
and eleven allowed operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr`). Stack `a` starts with the input numbers, stack
`b` starts empty, and the program must print the shortest possible sequence
of operations that sorts `a` in ascending order. The project is graded
partly on correctness and partly on efficiency — operation counts for
100 and 500 random numbers are compared against fixed thresholds.

Depending on stack size, sorting uses either a direct comparison (2–3
elements) or a cost-based algorithm known as the "Turk Algorithm",
originally devised by A. Yigit Ogun (former 42 Heilbronn student). I
learned it from a YouTube walkthrough of his approach (linked below) and
built this project's sorting logic on that basis: for each value in `a`,
the cheapest destination in `b` is found (the closest smaller value,
keeping `b` sorted descending), and the combined rotation cost for both
stacks is calculated so the cheapest move is always taken, reusing `rr`/
`rrr` when both stacks rotate the same direction.

## Instructions

**Compilation:**
```bash
make
```
Builds `libft` and links it with the project sources into an executable
named `push_swap`. `make clean`, `make fclean`, and `make re` are also
available.

**Usage:**
```bash
./push_swap 3 1 2
./push_swap "3 1 2"
```
Both a list of separate arguments and a single quoted, space-separated
string are accepted. No arguments prints nothing and returns normally.
Invalid input (non-integers, values outside `int` range, or duplicates)
prints `Error` to standard error and nothing else.

**Testing against the school-provided checker:**
```bash
ARG="3 1 2"
./push_swap $ARG | ./checker $ARG
```

## Project Structure

push_swap/
├── main.c # argument handling, entry point
├── parse_args.c # splitting/looping over input, in original order
├── check_arguments.c # validation: digits, overflow, duplicates
├── build_stack.c # stack (doubly linked list) construction
├── sort_three.c # fixed 3-element sort
├── swap_op.c / rotate_op.c / rev_rot_op.c / push_op.c
│ # the 11 required operations + their print output
├── turk.c # entry point for the >3-element algorithm
├── push_to_b.c # phase 1: cost-based push from a to b
├── push_to_a.c # phase 2: cost-based push back from b to a
├── cost_utils.c # shared cost/rotation helpers
├── utils1.c / utils2.c # stack_size, is_sorted, free_stack, etc.
├── libft/ # custom C library
└── Makefile


### Errors

`push_swap` prints `Error` to standard error and produces no other output
in these cases:
- One or more arguments is not a valid integer.
- An argument is outside the range of `int` (below `INT_MIN` or above
  `INT_MAX`).
- The input contains duplicate values.

No output at all (not even `Error`) is printed when no arguments are given
— the program simply returns.

## Known edge cases handled

- Arguments passed as one quoted string vs. multiple separate arguments
- Numbers exceeding `INT_MIN`/`INT_MAX`
- Duplicate values
- `INT_MIN`/`INT_MAX` themselves as valid, sortable input values (these
  initially broke the cost-comparison logic, since they were reused
  internally as sentinel/"not found" markers — fixed by tracking a found/
  not-found flag instead of a magic number)

## Resources

- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/push_swap.en.pdf)
- [Ayogun, "Push swap" (Medium)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [YouTube: push_swap algorithm walkthrough](https://youtu.be/wRvipSG4Mmk) —
  main resource for understanding the Turk algorithm's "target node" and
  combined-rotation-cost concept, which `push_to_b`/`push_to_a` are based on

### AI usage

AI tools were used for conceptual research (understanding the Turk algorithm and data structures) and to assist in drafting this README. All code implementation and final documentation were reviewed and verified by the author.
---
All code in this repository was written, typed, and understood by the author.

## License

School project - 42 network