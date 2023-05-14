#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int top1 = -1, top2 = -1;
int stack1[MAXSIZE], stack2[MAXSIZE];

void push1(int data) {
    if (top1 == MAXSIZE - 1) {
        printf("Error: Queue is full.\n");
        return;
    }
    stack1[++top1] = data;
}

void push2(int data) {
    if (top2 == MAXSIZE - 1) {
        printf("Error: Queue is full.\n");
        return;
    }
    stack2[++top2] = data;
}

int pop1() {
    if (top1 == -1) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return stack1[top1--];
}

int pop2() {
    if (top2 == -1) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return stack2[top2--];
}

void enqueue(int data) {
    push1(data);
    printf("Enqueued element: %d\n", data);
}

int dequeue() {
    int data;
    if (top1 == -1 && top2 == -1) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            data = pop1();
            push2(data);
        }
    }
    data = pop2();
    printf("Dequeued element: %d\n", data);
    return data;
}

void display() {
    int i;
    if (top1 == -1 && top2 == -1) {
        printf("Error: Queue is empty.\n");
        return;
    }
    printf("Elements in the queue are:\n");
    for (i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    for (i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
