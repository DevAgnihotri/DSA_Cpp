# Stack in C

A **stack** is a linear data structure that follows the Last In First Out (LIFO) principle. This means the last element added to the stack will be the first one to be removed.

### Example: Stack using Array

```c
#define MAX 100
int stack[MAX];
int top = -1;

// (Operations as shown above)
```

## Summary

- Stack is a LIFO data structure.
- Main operations: push, pop, peek, isEmpty, isFull.
- Can be implemented using arrays or linked lists in C.
- Used in function calls, expression evaluation, undo features, etc.

## Complete Stack Program in C

Below is a complete example of a stack implementation in C using an array, including a simple menu-driven interface:

```c
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else
        return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    } else
        return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
```

---

## Reverse a String Using Stack

### Logic

1. **Push each character of the string onto the stack.**
2. **Pop characters from the stack and overwrite the string.**
   - Since stack is LIFO, popping gives characters in reverse order.

#### Dry Run Example

Suppose the input string is `"ABC"`:

| Step      | Stack Content | String Content |
| --------- | ------------- | -------------- |
| Initial   | (empty)       | "ABC"          |
| Push 'A'  | A             | "ABC"          |
| Push 'B'  | A, B          | "ABC"          |
| Push 'C'  | A, B, C       | "ABC"          |
| Pop → 'C' | A, B          | "C"            |
| Pop → 'B' | A             | "CB"           |
| Pop → 'A' | (empty)       | "CBA"          |

- After all pops, the string is reversed to `"CBA"`.

**Summary:**

- Push all characters to stack → stack holds ['A', 'B', 'C'] (top is 'C').
- Pop and overwrite string → get 'C', 'B', 'A' in order.
- Result: string is reversed.

### Code

```c
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push character onto stack
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

// Pop character from stack
char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

void reverseString(char str[]) {
    int len = strlen(str);
    // Push all characters onto stack
    for (int i = 0; i < len; i++)
        push(str[i]);
    // Pop all characters and put back into str
    for (int i = 0; i < len; i++)
        str[i] = pop();
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
```

**How it works:**

- Each character of the string is pushed onto the stack.
- When popping from the stack, characters come out in reverse order, thus reversing the string.

## Recursion in C

### What is Recursion?

**Recursion** is a programming technique where a function calls itself directly or indirectly to solve a problem. Each recursive call solves a smaller instance of the original problem, and the process continues until a base case (a condition to stop recursion) is reached.

### When is Recursion Used?

Recursion is used when a problem can be solved by breaking it down into smaller versions of the same problem. This is helpful when each step of the solution looks similar to the whole problem.

**When to use recursion:**

- When a problem can be divided into smaller, similar subproblems.
- When the solution to a problem depends on solutions to smaller instances of the same problem.
- When the problem has a clear stopping condition (base case).

**Example: Calculating Factorial**

Suppose you want to calculate the factorial of a number `n` (written as `n!`). The factorial of 5 is:

```
5! = 5 × 4 × 3 × 2 × 1 = 120
```

Notice that `5! = 5 × 4!`, and `4! = 4 × 3!`, and so on. Each step is a smaller version of the same problem.

**How recursion works here:**

- To find `5!`, you ask for `4!`
- To find `4!`, you ask for `3!`
- This continues until you reach `1!`, which is just `1` (the base case).

**Code Example:**

```c
int factorial(int n) {
    if (n == 0) // base case
        return 1;
    else
        return n * factorial(n - 1); // recursive call
}
```

**Summary:**  
Use recursion when a problem can be naturally split into smaller, similar problems, and you can define a clear stopping point.

### How Recursion Works

A recursive function has two main parts:

1. **Base Case:** The condition under which the function stops calling itself.
2. **Recursive Case:** The part where the function calls itself with a smaller or simpler input.

### Good Uses of Recursion

- **Tree Traversals:** Navigating hierarchical data like file systems or expression trees.
- **Divide and Conquer Algorithms:** Such as quicksort, mergesort, and binary search.
- **Problems with Unknown or Variable Depth:** Like exploring all possible paths in a maze.

#### Example: Fibonacci Sequence

```c
int fibonacci(int n) {
    if (n == 0) return 0; // Base case
    if (n == 1) return 1; // Base case
    return fibonacci(n-1) + fibonacci(n-2); // Recursive calls
}
```

### When Recursion is Not Good

- **When the problem can be solved more efficiently with loops:** Recursion can lead to high memory usage and slower performance due to repeated function calls.
- **When the recursion depth is very large:** This can cause a stack overflow error.
- **When the same subproblems are solved repeatedly:** This leads to inefficiency (e.g., naive Fibonacci).

#### Example: Bad Use of Recursion

Calculating Fibonacci numbers recursively without memoization is inefficient because it recalculates the same values many times.

```c
// Inefficient for large n
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
```

For large `n`, this approach is very slow and can crash due to too many recursive calls.

### Pros and Cons of Recursion

**Advantages:**

- Code is often simpler and easier to read for problems with recursive structure.
- Reduces complex problems to simpler subproblems.

**Disadvantages:**

- Uses more memory (stack space) due to function calls.
- Can be slower than iterative solutions.
- Risk of stack overflow if recursion is too deep.

### Summary Table

| Good for...                 | Bad for...                         |
| --------------------------- | ---------------------------------- |
| Tree/graph traversals       | Problems with large input sizes    |
| Divide and conquer          | Problems with repeated subproblems |
| Problems with unknown depth | When loops are more efficient      |

### Conclusion

Recursion is a powerful tool for solving problems that can be divided into similar subproblems. It makes code cleaner and easier to understand for certain tasks, but should be used carefully to avoid inefficiency and stack overflow. Always ensure there is a clear base case, and consider iterative solutions for performance-critical code.

---
