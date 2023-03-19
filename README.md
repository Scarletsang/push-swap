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
def front2 stackA
    if stackA[0] < stackA[1] :
        add_cmd(SA)
    add_cmd(PB, PB)

# Cost: 2 - 3
def front2_sb stackB
    add_cmd(PB, PB)
    if stackA[0] > stackA[1] :
        add_cmd(SB)

# Cost: 4
def rear2 stackA, stackB
    add_cmd(RRA)
    front1rear1(stackA, stackB)

# Cost: 3
def front1rear1 stackA, stackB
    if stackA[0] > stackA[-1]
        add_cmd(PB, RRA)
    else
        add_cmd(RRA, PB)
    add_cmd(PB)

def rear1 stackA
    add_cmd(RRA, PB)

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

def move_biggest_group stackA, stackB
    i = 0
    while i < 6
        if get_group(stackA[i++]) == BIGGEST_GROUP
            add_cmd(PB)
            break
        add_cmd(RA)
    j = i
    while j < 6 && get_group(stackA[j]) != BIGGEST_GROUP
        j++
    d = j - i
    while d > 2
        add_cmd(RA)
        d--
    if d == 2
        add_cmd(SA)
    add(PB)

def sort_biggest_group stackA, stackB
    if stackB[0] > stackB[1] :
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

def size4 stackA, stackB
    if get_group_size(stackA[0]) == BIGGEST
        add_cmd(PB)
        if get_group_size(stackA[0]) == BIGGEST
            add_cmd(PB)
        else

```

Optimization:

front2 front2 = PB PB size2_size2

1. check 0 and -1
2. see if rear2 is possible
3. find first priority in top
4. find first priority in top
4. find first priority in rear