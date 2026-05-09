*This project has been created as part of the 42 curriculum by berhugue, ugutierr*

# Push_swap

## Description

`push_swap` is a sorting algorithm project focused on sorting a stack of integers using a limited set of operations and the lowest possible number of moves.

The program uses two stacks (`a` and `b`) and implements multiple sorting strategies depending on the disorder of the input:
- Simple algorithm — `O(n²)`
- Medium algorithm — `O(n√n)`
- Complex algorithm — `O(n log n)`
- Adaptive algorithm based on disorder metrics

The goal of the project is to understand:
- algorithm complexity
- optimization
- stack manipulation
- adaptive sorting strategies

We divided the project into two parts: the parsing and the algorithms. ugutierr did the parsing and berhugue did the algorithms.

### Contents

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| sa  | swap a                              | swaps the 2 top elements of stack a                    |
| sb  | swap b                              | swaps the 2 top elements of stack b                    |
| ss  | swap a + swap b                     | both sa and sb                                     |
| pa  | push a                              | moves the top element of stack b at the top of stack a |
| pb  | push b                              | moves the top element of stack a at the top of stack b |
| ra  | rotate a                            | shifts all elements of stack a from bottom to top      |
| rb  | rotate b                            | shifts all elements of stack b from bottom to top      |
| rr  | rotate a + rotate b                 | both ra and rb                                     |
| rra | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| rrb | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| rrr | reverse rotate a + reverse rotate b | both rra and rrb                                   |

---

## Explanation

### Simple Algorithm — O(n²)

The simple strategy is based on a selection sort adaptation. A selection-sort adaptation was chosen because it is easy to implement, efficient for small or nearly sorted inputs, and minimizes unnecessary complexity.

The algorithm repeatedly:
- finds the smallest element
- rotates the stack to move it to the top
- pushes it to stack `b`

Once only 3 numbers remain in stack `a`, a dedicated `sort_3` optimization handles all possible cases with the minimum number of operations.

Finally, all elements are pushed back from stack `b` to stack `a` in sorted order.

### Medium Algorithm — O(n√n)

The medium strategy uses a chunk-based sorting approach. A chunk-based strategy was chosen because dividing the stack into `√n` ranges significantly reduces operations compared to quadratic approaches while remaining relatively simple.

The stack is divided into chunks of size `√n`.
Elements belonging to the current chunk range are pushed from stack `a` to stack `b`, while the remaining elements are rotated.

Once all chunks are moved to stack `b`, the algorithm rebuilds stack `a` by always moving the largest indexed element back to the top before pushing it.

### Complex Algorithm — O(n log n)

The complex strategy uses a binary radix sort adapted to the Push Swap constraints. Binary radix sort was chosen because it scales efficiently on large datasets, is reliable under Push Swap constraints, and consistently achieves good benchmark results.

Each number is first indexed, then sorted bit by bit starting from the least significant bit (LSD).

For each bit:
- numbers with bit `0` are pushed to stack `b`
- numbers with bit `1` are rotated in stack `a`

After processing all elements for a bit position, elements from stack `b` are pushed back to stack `a`.

This process repeats until all bits of the maximum index have been processed.

---

## Instructions

### Compile

First we need to compile the program:

```bash
make
```
Once it's finished, we can either run it without any flags, which will use the adaptive strategy by default:
```bash
./push_swap 2 1 3 6 5 8
```
Or we can manually select a strategy:
```bash
./push_swap --simple 5 4 3 2 1

./push_swap --medium 5 4 3 2 1

./push_swap --complex 5 4 3 2 1

./push_swap --adaptive 5 4 3 2 1
```
For the bonus part, we can compile the checker with:
```bash
make bonus
```
And run it with:
```bash
ARG="4 67 3 87 23"

./push_swap $ARG | ./checker $ARG
```

---

## Resources

For this project we have used a few resources such as youtube videos, stackoverflow posts, blogs and help from our peers in 42. Here are some of them:
- [Article about implementation of the project.](https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f)
- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Push_swap video explanation](https://www.youtube.com/watch?v=4dMsuxfqufg&t=2s&pp=ygUJcHVzaCBzd2Fw)

Related to AI, we made use of it when we couldn't understand an explanation or example we saw on a page, stackoverflow comment or YouTube video, so the AI could rephrase it in another way easier for beginners or give us a visual example to better understand that topic. We used it as a tool to help us learn and better visualize what is the exercise asking to us, not to do it for us.