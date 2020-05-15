//
//  main.c
//  1
//
//  Created by Максим Стасевич on 5/5/20.
//  Copyright © 2020 Максим Стасевич. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;

struct  Node
{
    int value;
    Node* next;
};

struct Queue
{
    int count;
    Node *head, *tail;
};

void initialize(Queue* q);
int isempty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void display(Node* head);
void input(Queue* q);
void replay(Queue* q1, Queue* q2, Queue* done);
void sort(int* arr, int amountelement);


int main()
{
    Queue* q1 = (Queue*)malloc(sizeof(Queue));
    Queue* q2 = (Queue*)malloc(sizeof(Queue));
    Queue* done = (Queue*)malloc(sizeof(Queue));
    initialize(q1);
    initialize(q2);
    initialize(done);
    input(q1);
    input(q2);
    replay(q1, q2, done);
    system("cls");
    display(done->head);
    free(q1);
    free(q2);
    free(done);
}

void initialize(Queue* q)
{
    q->count = 0;
    q->head = NULL;
    q->tail = NULL;
}

int isempty(Queue* q)
{
    return (q->tail == NULL);
}

void enqueue(Queue* q, int value)
{
    Node* tmp;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    if (!isempty(q))
    {
        q->tail->next = tmp;
        q->tail = tmp;
    }
    else  q->head = q->tail = tmp;
    q->count++;
}

int dequeue(Queue* q)
{
    Node* tmp;
    int n = q->head->value;
    tmp = q->head;
    q->head = q->head->next;
    q->count--;
    free(tmp);
    return(n);
}

void display(Node* head)
{
    if (head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head->value);
        display(head->next);
    }
}

void input(Queue* q)
{
    int value = 0;
    printf("¬ведите элементы очереди\n");
    for (int i = 0; i < 10; i++)
    {
        scanf ("%d", &value);
        enqueue(q, value);
    }
}

void replay(Queue* q1, Queue* q2, Queue* done)
{
    int i = 0;
    int amountelement = q1->count + q2->count;
    int* arr = (int*)malloc(sizeof(amountelement * sizeof(int)));
    while (q1->count)
        arr[i++] = dequeue(q1);
    while (q2->count)
        arr[i++] = dequeue(q2);
    sort(arr, amountelement);
    for (int i = 0; i < amountelement - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            enqueue(done, arr[i]);
    }
    if (arr[amountelement - 1] != arr[amountelement - 2])
        enqueue(done, arr[amountelement - 1]);

}

void sort(int* arr, int amountelement)
{
    int left = 0, right = amountelement - 1, flag = 0;
    while (left < right && flag == 0)
    {
        flag = 1;
        for (int i = left; i < right; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                int buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
                flag = 0;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                int buf = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = buf;
                flag = 0;
            }
        }
        left++;
    }
}
