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

pb
pb
sb
sa
pb
pb
rra
rra
pa
rrb
pa
pa
pa

## Creating Ascending triangles

```ruby

# Cost: 2 - 3
def front2 stackA
    if stackA[0] < stackA[1] :
        add_cmd(SA)
    add_cmd(PB, PB)

# Cost: 2 - 3
def front2_sb stackB
    add_cmd(PB, PB)
    if stackA[0] < stackA[1] :
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

```

Optimization:

front2 front2 = PB PB size2_size2
rear1 rear1 = rear2

1. check 0 and -1
2. see if front1rear1 is possible
3. see if rear2 is possible
4. find first priority in top
5. find first priority in top
6. find first priority in rear

```ruby

def has_priority_in_front index, front_size, priority_group
    if index >= front_size
        return BACK
    if get_group(stackA[index]) == priority_group
        return FRONT
    return has_priority_in_front(index + 1, front_size, priority_group)

def move_priority front_size, rear_size, priority_group, group_size, forced_lookup, last_instruction
    if group_size == 0
        return
    # Checks if rear has priority
    if get_group(stackA[-1]) == priority_group
        if get_group(stackA[0]) == priority_group
            front1rear1(stackA, stackB)
            return 
        rear1(stackA, stackB)
        return move_priority(front_size, rear_size - 1, priority_group, group_size - 1, UNDEFINED, &rear1)
    # Checks if the front has priority
    if get_group(stackA[0]) == priority_group
        if get_group(stackA[1]) == priority_group
            front2(stackA, stackB)
            return
        add_cmd(PB)
        return move_priority(front_size - 1, rear_size, priority_group, group_size - 1, UNDEFINED, last_instruction)
    # Front lookup
    if forced_lookup == FRONT
        if get_group(stackA[1]) == priority_group && \
           priority_group_is_decreasing_after(stackA, 2, get_group(stackA[0]), front_size - 2)
                add_cmd(SA)
                return move_priority(front_size, rear_size, priority_group, group_size, FRONT, last_instruction)
        add_cmd(RA)
        return move_priority(front_size - 1, rear_size + 1, priroity_group, group_size, FRONT, last_instruction)
    # Back lookup
    if forced_lookup == BACK
        add_cmd(RRA)
        return move_priority(front_size + 1, rear_size - 1, priority_group, group_size, BACK, last_instruction)
    return move_priority(front_size, rear_size, priority_group, group_size, \
        has_priority_in_front(0, front_size, priority_group), last_instruction)
```

```ruby

def add_n_cmd cmd, amount
    while amount > 0
        add_cmd(cmd)
        amount--

def move_biggest_from_rear stackA, stackB, rear_size, priority_group
    i = -1
    while i >= rear_size
        if get_group(stackA[i]) == priority_group
            add_n_cmd(RRA, (i - 1) * -1)
            rear1(stackA, stackB)
            return true
        i--
    return false

def priority_group_is_decreasing_after stackA, index, target_priority_group, front_size
    while index < front_size
        group = get_group(stackA[index])
        if group > target_priority_group
            return false
        if group < target_priority_group
            target_priority_group = group
        index++
    return true

def move_biggest_from_front stackA, stackB, front_size, priority_group
    i = 0
    while i < front_size
        if get_group(stackA[i]) == priority_group
            if i > 0
                add_n_cmd(RA, i - 1)
                if priority_group_is_decreasing_after(stackA, i, get_group(stackA[i - 1]), front_size)
                    add_cmd(SA)
                else
                    add_cmd(RA)
            add(PB)
            return true
        i++
    return false

def sort_biggest_group stackA, stackB
    if stackB[0] > stackB[1]
        add_cmd(SB) 

def move_one_biggest_element stackA, stackB, front_size, rear_size, priority_group
    if move_biggest_from_front(stackA, stackB, front_size, priority_group)
        return FRONT
    else
        move_biggest_from_rear(stackA, stackB, rear_size, priority_group)
        return REAR

def move_biggest_group stackA, stackB, front_size, rear_size, priority_group
    if get_group(stackA[-1]) == priority_group
        if get_group(stackA[-2]) == priority_group
            rear2(stackA, stackB)
            return
        if get_group(stackA[0]) == priority_group
            front1rear1(stackA, stackB)
            return
        rear1(stackA, stackB)
        move_one_biggest_element(stackA, stackB, front_size, rear_size)
        return
    if move_one_biggest_element(stackA, stackB, front_size, rear_size) == FRONT
        move_one_biggest_element(stackA, stackB, front_size, rear_size)
    else
        move_biggest_from_rear(stackA, stackB, rear_size)

# The variables stackA, stackB, front_size and rear_size are always passed by reference and not by value.
# However, priority is passed by value
# For future me, note that in the C code, move_biggest_group actually change the triangle_size, so keep in mind that the original value of the triangle_size has to be saved in the C code.
def create_triangle stackA, stackB, front_size, rear_size, triangle_size
    priority_group = get_group(triangle_size - 1)
    while priority_group > 0
        move_biggest_group(stackA, stackB, front_size, rear_size, priority_group)
        priority_group--
    if triangle_size % 2 == 0
        if rear_size == 0
            size2size2(stackA)
        elsif rear_size == -1
            front1rear1(stackA, stackB)
        else
            rear2(stackA, stackB)
    else
        if rear_size == 0
            add_cmd(PB)
        else
            rear1(stackA, stackB)
```
