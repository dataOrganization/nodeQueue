//
//  main.c
//  queueLink
//
//  Created by mac on 16/6/1.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int  ElemType;

typedef struct queueNode{
    ElemType data;
    struct queueNode *next;
}QueueNode;
typedef struct {
    QueueNode *front;
    QueueNode *rear;
}QueueLink;

void initQueue (QueueLink *q) {
    q->rear = (QueueNode *)malloc(sizeof(QueueNode));
    q->front = (QueueNode *)malloc(sizeof(QueueNode));
    q->front->next = q->rear;
    q->rear->next = NULL;
}

void insertQueue (QueueLink *q ,ElemType data) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    
    node->data = data;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
    printf("%d ",data);
}

void printfQueue (QueueLink q) {
    printf("\n");
    QueueNode *temp = q.front->next->next;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int countOfQueue(QueueLink queue) {
    int count = 0;
    while (queue.front != NULL) {
        queue.front = queue.front->next;
        count++;
    }
    return count;
}

void clearQueue(QueueLink *queue) {
    QueueNode *node = NULL;
    while (queue->front != NULL) {
        node = (QueueNode *)malloc(sizeof(QueueNode));
        node = queue->front;
        queue->front = queue->front->next;
        free(node);
    }
}

void deleteQueue(QueueLink *queue ,int number) {
    if (countOfQueue(*queue) <= number) {
        clearQueue(queue);
        return;
    }
    QueueNode *node = NULL;
    for (int i = 0; i < number; i++) {
        node = (QueueNode *)malloc(sizeof(QueueNode));
        node = queue->front;
        queue->front = queue->front->next;
        free(node);
    }
}


int main(int argc, const char * argv[]) {
    QueueLink *queue = (QueueLink *)malloc(sizeof(QueueLink));
    initQueue(queue);
    for (int i = 0; i < 10; i++) {
        insertQueue(queue, arc4random() % 100 + 1);
    }
    printf("\n%d",countOfQueue(*queue));
    printfQueue(*queue);
    deleteQueue(queue,2);
    printfQueue(*queue);
    printf("\n%d",countOfQueue(*queue));
    return 0;
}
