# PUSH SWAP

## Creating triangles

These are the formula used for to push priority elements to stackB:

```ruby
# Cost: 2 - 3
def front2 stackA, stackB
    if last_instruction == SB
        if stackA[0] < stackA[1] :
            edit_last_cmd(SS)
        add_cmd(PB, PB)
        return
    add_cmd(PB, PB)
    if stackA[0] < stackA[1] :
        add_cmd(SB)

# Cost: 3
def front1rear1 stackA, stackB
    if stackA[0] > stackA[-1]
        add_cmd(PB, RRA)
    else
        add_cmd(RRA, PB)
    add_cmd(PB)

# Cost: 2
def rear1 stackA, stackB
    if last_formula == rear1
        edit_last_cmd(RRA)
        add_cmd(PB, PB)
    else
        add_cmd(RRA, PB)
```

This is the actual algorithm to create triangle:

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

# The variables stackA, stackB, front_size and rear_size are always passed by reference and not by value.
# However, priority is passed by value
# For future me, note that in the C code, move_biggest_group actually change the triangle_size, so keep in mind that the original value of the triangle_size has to be saved in the C code.
def create_triangle stackA, stackB, front_size, rear_size, triangle_size
    priority_group = get_group(triangle_size - 1)
    while priority_group > 0
        move_priority(stackA, stackB, front_size, rear_size, priority_group)
        priority_group--
    if triangle_size % 2 == 0
        if rear_size == 0
            size2size2(stackA)
        elsif rear_size == -1
            front1rear1(stackA, stackB)
        else
            rear1(stackA, stackB)
            rear1(stackA, stackB)
    else
        if rear_size == 0
            add_cmd(PB)
        else
            rear1(stackA, stackB)
```
