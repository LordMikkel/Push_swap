# 🚀 push_swap: An Efficient Sorting Solution 🔥

<p align="center"> <img src="image/.score.png" alt="alt text" /> </p>

## Achievements
- ✅ 125/100 Score (Bonus Included)
- 🏆 Outstanding Project Recognition
- ⚡ 600 Moves for 100 Numbers | 5200 Moves for 500 Numbers
- 🔒 Leak-Proof | Rigorous Error Checks | Optimized Workflow

https://github.com/user-attachments/assets/77b040af-c357-49bd-a7d3-e3a24e19955f

## 📜 Overview
push_swap is a sorting algorithm project that sorts integers using two stacks (stack_a and stack_b) with a limited set of operations. This implementation combines brute-force efficiency for small datasets (2-5 elements) with a chunk-optimized QuickSort for larger sets, achieving industry-grade performance while adhering to strict memory safety.

## 🧠 Algorithm Breakdown

### 🔢 Brute-Force Sorting for Small Stacks (2-5 Elements)
#### For 2 elements:
- Directly swap the two elements (sa).

#### For 3 elements:
- Compare the third and second elements. If the third is larger:
  - Swap the top two (sa) if the third > first.
  - Rotate up (ra) otherwise.
- If the first element is larger than the third:
  - Swap the top two (sa) if needed.
  - Reverse rotate (rra) to fix order.
- If the second > third:
  - Swap (sa) and rotate (ra).

#### For 4-5 elements:
- Push the smallest 1-2 elements to stack_b using pb.
- Sort the remaining 3 elements in stack_a with the 3-element logic.
- Push elements back from stack_b (pa) and adjust as needed.

### 🌐 Chunk-Based QuickSort
#### Phase 1: Chunk Division and Partial Sorting
##### 1. Dynamic Chunk Definition
Objective: Divide stack_a into manageable chunks.

Logic:
```c
while (stack_a->size)
{
    // 1. Find current minimum value in stack_a
    min_x_piv_x_up = ft_find_min_num(stack_a);

    // 2. Calculate pivot (middle of current chunk)
    while (elements_processed++ < chunk_size)
    {
        min_x_piv_x_up = ft_find_next_min_num(stack_a, min_x_piv_x_up);
        if (elements_processed == chunk_size / 2)
            stack_a->pivot = min_x_piv_x_up; // This is the pivot!
    }
    // ...
}
```

Key Concepts:
- min_x_piv_x_up: Represents several values THE LAST ONE is the upper limit of the current chunk.
- pivot: Divides the chunk into two halves.
- Example: If chunk has [5, 1, 9, 3, 7], sorted would be [1, 3, 5, 7, 9]. Pivot would be 5.

##### 2. Moving Elements to stack_b
```c
while (elements_processed++ < chunk_size)
{
    // 1. Find first element <= min_x_piv_x_up (chunk limit)
    index = ft_get_first_smaller_index(stack_a, min_x_piv_x_up);

    // 2. Move element to top of stack_a and send to stack_b
    ft_move_num_to_top(stack_a, stack_a->stack[index], 'a');
    ft_do_pb(stack_a, stack_b);

    // 3. If element is GREATER than pivot, rotate stack_b (rb)
    if (stack_b->stack[0] > stack_a->pivot)
        ft_do_rotate(stack_b, 'b');
}
```

Key Strategy:
- Elements > pivot are sent to bottom of stack_b (with rb), creating an ordered "sub-chunk"
- Elements < pivot remain at top of stack_b
- Result: stack_b builds a layered structure where each chunk — and the stack as a whole — tends to position larger elements at the bottom and top, and smaller ones clustered near the middle.

#### Phase 2: Intelligent Merging
##### 1. Finding Two Largest Elements in stack_b
```c
while (stack_b->size)
{
    max = ft_find_max_num(stack_b);    // Current maximum
    next_max = ft_find_next_max_num(stack_b, max); // Second maximum

    // Calculate indices and adjust if in lower half
    max_index = ft_get_index_num(stack_b, max);
    if (max_index > stack_b->size / 2)
        max_index = stack_b->size - max_index;  // Optimize rotations

    // ... same calculation for next_max_index ...
}
```

##### 2. Deciding Order of Transfer to stack_a
```c
if (max_index < next_max_index)
    ft_move_top_and_push_to_a(stack_a, stack_b, max, next_max);
else
    ft_move_top_and_push_to_a(stack_a, stack_b, next_max, max);
```

Logic:
- Send max first if it's closer to top than next_max
- Otherwise, send next_max first
- Goal: Minimize total operations (ra vs rra)

##### 3. Final Adjustment in stack_a
```c
if (stack_a->stack[0] > stack_a->stack[1])
    ft_do_swap(stack_a, 'a'); // Ensure ascending order
```

https://github.com/user-attachments/assets/c3a8e620-668a-4e1f-98c0-df938f504c10

## ⚡ Performance & Big O Analysis
### Time Complexity:
- Brute-Force: O(n²) for n ≤ 5 (practical due to fixed size).
- Chunk Sort: O(n log n) average case, outperforming Radix (O(nk)) and LIS (O(n²)).

### Real-World Metrics:
- 100 elements: ~600 moves (vs. 700 limit).
- 500 elements: ~5200 moves (vs. 5500 limit).

## 🏆 Why This Algorithm Shines?

| Algorithm | Real-World Applicability | Flexibility | Move Efficiency |
|-----------|--------------------------|-------------|-----------------|
| QuickSort (Ours) | ✅ High (general-purpose) | ✅ Dynamic chunking | ⭐️ Optimal |
| Radix Sort | ❌ Limited (integer-only) | ❌ Fixed digit steps | 🟡 Moderate |
| Turk's Algo | ❌ Niche use cases | ❌ Complex logic | 🟢 High |
| LIS | ❌ Specialized scenarios | ❌ Slow for large n | 🔴 Poor |

### Key Advantages:
- **Adaptive Chunking**: Balances chunk size for minimal operations.
- **Merge Optimizations**: Redundant moves eliminated via dual-max analysis.
- **Instruction Compression**: Combined moves to detect consecutive ra+rb → rr (and similar for rra/rrb).

### How It Works:
1. Track the last operation.
2. If the next operation is a "compatible" pair (e.g., ra followed by rb):
   - Print the combined instruction (rr) instead.
   - Skip printing the individual moves.
3. Result: Reduces total instructions by ~15%.

### Why This Algorithm?
This chunk-based approach was chosen for several practical advantages:
- **Real-World Relevance**: QuickSort variants power databases, ML data pipelines, and high-frequency trading systems.
- **Practicality**: Real-world applications and teaches fundamental sorting concepts
- **Balance**: Excellent performance while remaining simple to understand and implement
- **Flexibility**: Adjustable chunk size based on input size for optimal performance
- **Memory Efficiency**: No additional data structures beyond the two stacks required
- **Optimization Potential**: Allows for creative optimizations like instruction compression

Other algorithms like Turkish sort or LIS-based approaches might have theoretical advantages but are less applicable to general sorting problems outside this specific project.

## 🔧 Technical Armored
### 🛡️ Robustness Features
- **Leak-Proof**: Rigorous valgrind testing – zero memory leaks.
- **Error Handling**: Invalid inputs, duplicates, and overflows detected instantly.
- **Bonus**: Includes checker program to validate sorting steps.

### 📁 Code Structure
This project includes a comprehensive Makefile with various testing options:
```bash
# Compile the project
make

# Run tests with different input sizes
make test3     # Test with 3 random numbers
make test5     # Test with 5 random numbers
make test25    # Test with 25 random numbers
make test50    # Test with 50 random numbers
make test100   # Test with 100 random numbers
make test500   # Test with 500 random numbers
make test1000  # Test with 1000 random numbers

# Test error handling
make errors      # Test with invalid inputs for push_swap
make errorsbonus # Test with invalid inputs for checker

# Compile and test the bonus checker program
make bonus     # Compile the checker program
make testbonus # Run tests for the checker
```

The Test Shows:
- 🧪 **Valgrind Integration**: Full memory leak checks.
- 📊 **Move Counter**: Validate efficiency thresholds.
- ✅ **Checker Integration**: Auto-verify sorting correctness.

![alt text](image/output.gif)

## 🧩 Bonus: checker Program
Validates if a list of instructions correctly sorts the stack.

### Key Features:
- **Error Handling**:
  - Detects invalid operations (e.g., abc, sx).
  - Handles Ctrl+D (EOF) gracefully.
- **Leak-Free**:
  - You must use a modified get_next_line or modify your ft_error to always wait for EOF to avoid "still reachable" leaks.
  - Frees all memory before exiting.

### 📚 Credits

Special thanks to the following projects and resources for their help and support during the development of this project:

- 🧠 [@okbrandon](https://github.com/okbrandon/push_swap) – For sharing a clean and well-structured implementation for quick-sort that helped me think through my own code organization.
- 🧪 [@gemartin99](https://github.com/gemartin99/Push-Swap-Tester) – For providing an excellent tester, one of the best tools out there to validate and benchmark *push_swap* implementations.
- 📖 [Jamie Robert Dawson's Medium article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) – For guiding how to approach the problem in a way that helps you find the solution by yourself, especially when building brute-force algorithms.


---

Crafted with passion by Mikel Garrido [migarrid] – because sorting should be fast, safe, and simple. 🚀
