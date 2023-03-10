# PUSH SWAP

Triangles:

a a b
1 2 3 rrr pb pb
2 3 1 rra pb pb rrb   rrr pb sb pb sb
3 1 2 pb rrr pb
1 3 2 rra pb rrb pb   rrr pb sb pb
2 1 3 rrb pb rra pb   rrr sa pb pb
3 2 1 pb rra pb rrb   pb rrr pb sb

a a b b
1 2 3 4 rrr rrb pb pb
1 2 4 3 rrr rrb sb pb pb
1 3 2 4 rrr pb rrb pb
1 3 4 2 rrr rrb sb pb sb pb
1 4 2 3 
1 4 3 2 
2 1 3 4 
2 1 4 3 
2 3 1 4 
2 3 4 1 
2 4 1 3 
2 4 3 1 
3 1 2 4 
3 1 4 2 
3 2 1 4 
3 2 4 1 
3 4 1 2 
3 4 2 1 
4 1 2 3 
4 1 3 2 
4 2 1 3 
4 2 3 1 
4 3 1 2 
4 3 2 1

## Creating Ascending triangles

```ruby

def get_biggest_element stack, indexes, length
    biggest_index = *indexes
    biggest_val = stack[index]
    indexes++
    while length-- > 0
        if stack[*indexes] > biggest_val
            biggest_index = *indexes
            biggest_val = stack[biggest_index]
        indexes++
    return biggest_index

# Cost: 2 - 3
def size2 stackA
    if stackA[0] < stackA[1] :
        add_cmd(SA)
    add_cmd(PB, PB)

# Cost: 2 - 3
def size2_sb stackB
    add_cmd(PB, PB)
    if stackA[0] > stackA[1] :
        add_cmd(SB)

# Cost: 3 - 6
def size3 stackA, stackB
    if get_biggest_element(stackA, [0, 1, 2], 3) == 2
        # gets element from the rear of stackA
        if get_biggest_element(stackA, [0, 1, -1], 3) == -1
            add_cmd(RRA, PB)
            size2_sb(stackB)
            return
        else
            size2(stackA)
            add_cmd(RRA, PB)
    else
        size2(stackA)
        add_cmd(PB)
    if stackB[0] > stackB[1]
        add_cmd(SB)

# Cost: 2 - 3
def size2_size2 stackA, stackB
    if stackB[0] > stackB[1]
        if stackA[1] > stackA[0]
            add_cmd(SS)
        else
            add_cmd(SB)
    add_cmd(PB, PB)
    if stackB[0] > stackB[1]
        add_cmd(SB)


def size4 stackA, stackB

```

