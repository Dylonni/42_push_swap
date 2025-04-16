# 42_push_swap
Push_swap is a project where you must sort given integers with the least possible movements/instructions.  
The sorting process requires two stacks , A and B. The instructions to sort them are listed as follows :  

```bash
 pb : push the first integer in stack A to stack B
 pa : push the first integer in stack B to stack A
 rb : rotate the stack B (meaning the first integer of the stack will become last)
 ra : rotate the stack A (meaning the first integer of the stack will become last)
 rrb: reverse rotate the stack B (meaning the last integer of the stack B will become first)
 rra: reverse rotate the stack A (meaning the last integer of the stack A will become first)
 sa : swap the first two integers of the stack A
 sb : swap the first two integers of the stack B
```

## How to use
Go to the project's root folder with a terminal , then

```bash
 $ make
```
The usage of the executable is as follows

```bash
 $ ./push_swap <your list of integers> (Ex : 1 59 -9 47 -665 -78 42 21 2)
```

## Output
The result in the terminal should look like this, these are the instructions that have been executed to sort the given list above

```bash
pb
pb
pb
pb
pb
pb
ra
sa
pa
pa
pa
rr
rb
rrb
ra
rra
pa
ra
ra
ra
pa
pa
rra
rra
```
