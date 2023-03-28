# PUSH SWAP

The project aims to generate the shortest sequence of instructions that sorts elements using two stacks. The instructions are as follows:

- sa: swap the order of first 2 elements on stack A
- sb: swap the order of first 2 elements on stack B
- ss: executes sa and sb at the same time
- ra: rotate the first element of stack A to the end of stack A
- rb: rotate the first element of stack B to the end of stack B
- rr: executes ra and rb at the same time
- rra: rotate the last element of stack A up the start of stack A
- rrb: rotate the last element of stack B up the start of stack B
- rrr: executes rra and rrb at the same time
- pa: pushes the first element of stack A to the starts of stack B
- pb: pushes the first element of stack B to the starts of stack A

## Compilation

```bash
git submodule update --init
make && make clean && make bonus
```

This will compile the push_swap executable as well as the checker executable.

## Usage

All of the following is valid inputs. The rule is simply as long as you pass in non-repeating numbers.

```bash
./push_swap 1 3 2 -10 13 99
./push_swap "1 3 2 -10 13 99"
./push_swap "1 3 2" -10 "13 99"
```

Then it will generate instructions like this:

```
pb
ra
ra
pb
ra
ra
ss
pa
pa
```

The checker is used to check whether the instruction generated is correct.

It can be used like this in general:

```bash
NUMBERS="1 3 2 -10 13 99"; ./push_swap $NUMBERS | ./checker $NUMBERS
```
