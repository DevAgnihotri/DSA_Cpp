# Stack in C

A **stack** is a linear data structure that follows the Last In First Out (LIFO) principle. This means the last element added to the stack will be the first one to be removed.

## Basic Operations on Stack (with Code)

1. **Push**  
   Adds (inserts) an element to the top of the stack.

   ```c
   void push(int value) {
         if (top == MAX - 1)
                printf("Stack Overflow\n");
         else
                stack[++top] = value;
   }
   ```

2. **Pop**  
   Removes (deletes) the top element from the stack.

   ```c
   int pop() {
         if (top == -1) {
                printf("Stack Underflow\n");
                return -1;
         } else
                return stack[top--];
   }
   ```

3. **Peek (Top)**  
   Returns the value of the top element without removing it.

   ```c
   int peek() {
         if (top == -1) {
                printf("Stack is Empty\n");
                return -1;
         } else
                return stack[top];
   }
   ```

4. **isEmpty**  
   Checks if the stack is empty.

   ```c
   int isEmpty() {
         return top == -1;
   }
   ```

5. **isFull**  
   Checks if the stack is full (for stacks with fixed size).

   ```c
   int isFull() {
         return top == MAX - 1;
   }
   ```

6. **Display**  
   Prints all elements in the stack from top to bottom.

   ```c
   void display() {
           if (top == -1) {
                    printf("Stack is Empty\n");
           } else {
                    printf("Stack elements:\n");
                    for (int i = top; i >= 0; i--)
                           printf("%d\n", stack[i]);
           }
   }
   ```

## Stack Implementation in C

A stack can be implemented using arrays or linked lists. The most common way is using arrays.

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

## Queue in C

A **queue** is a linear data structure that follows the First In First Out (FIFO) principle. This means the first element added to the queue will be the first one to be removed.

### Types of Queues

1. **Simple Queue (Linear Queue):**  
   Elements are inserted at the rear and removed from the front.

2. **Circular Queue:**  
   The last position is connected back to the first position to make a circle, allowing efficient use of space.

3. **Priority Queue:**  
   Each element is assigned a priority, and elements with higher priority are served before those with lower priority.

4. **Double-Ended Queue (Deque):**  
   Insertion and deletion can occur at both ends (front and rear).

---

## Basic Operations on Queue (with Code)

Below is a simple queue implementation using an array in C, with comments explaining each operation:

```c
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Adds an element to the rear of the queue
void enqueue(int value) {
     if (rear == MAX - 1)
          printf("Queue Overflow\n");
     else {
          if (front == -1) front = 0; // First element
          queue[++rear] = value;
     }
}

// Removes and returns the front element from the queue
int dequeue() {
     if (front == -1 || front > rear) {
          printf("Queue Underflow\n");
          return -1;
     } else
          return queue[front++];
}

// Returns the front element without removing it
int peek() {
     if (front == -1 || front > rear) {
          printf("Queue is Empty\n");
          return -1;
     } else
          return queue[front];
}

// Checks if the queue is empty
int isEmpty() {
     return (front == -1 || front > rear);
}

// Checks if the queue is full
int isFull() {
     return rear == MAX - 1;
}

// Displays all elements in the queue from front to rear
void display() {
     if (front == -1 || front > rear) {
          printf("Queue is Empty\n");
     } else {
          printf("Queue elements:\n");
          for (int i = front; i <= rear; i++)
                printf("%d\n", queue[i]);
     }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Front element: %d\n", value);
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

## Summary

- Queue is a FIFO data structure.
- Main operations: enqueue, dequeue, peek, isEmpty, isFull.
- Can be implemented using arrays or linked lists in C.
- Types include simple queue, circular queue, priority queue, and deque.
- Used in scheduling, buffering, and resource management.
