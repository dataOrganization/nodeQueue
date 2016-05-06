//
//  main.m
//  nodeQueue
//
//  Created by mac on 16/5/5.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef int QElemType;

typedef struct node{
    QElemType e;
    struct node *next;
    
}queueNode;

typedef struct{
    queueNode *front;
    queueNode *rear;
}linkQueue;

BOOL initQueue (linkQueue *q){
    q->front = q->rear = (queueNode *)malloc(sizeof(queueNode));
    if (!q->front) {
        exit(OVERFLOW);
    }
    q->front->next = NULL;
    return YES;
}

BOOL insertQueue (linkQueue *q ,QElemType e){
    queueNode *s = (queueNode *)malloc(sizeof(queueNode));
    if (!s) {
        exit(OVERFLOW);
    }
    s->e = e;
    s->next = NULL;
    
    q->rear->next = s;
    q->rear = s;
    return YES;
}

int queueLength (linkQueue *q){
    int num = 0;
    queueNode *s;
    s = q->front;
    while (s != q->rear) {
        num++;
        s = s->next;
    }
    return num;
}

BOOL deleteQueue (linkQueue *q ,QElemType e) {
    queueNode *s;
    if (q->front == q->rear) {
        return NO;
    }
    s = q->front->next;
    e = s->e;
    q->front->next = s->next;
    
    if (q->rear == s) {
        q->rear = q->front;
    }
    free(s);
    return YES;
}

void printfQueue (linkQueue *q) {
    queueNode *s;
    s = q->front->next;
    while (s) {
        printf("%d  ",s->e);
        s = s->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    linkQueue *queue = (linkQueue *)malloc(sizeof(linkQueue));
    initQueue(queue);
    printf("%d \n",queueLength(queue));
    for (int i = 0; i < 10;i++ ) {
        insertQueue(queue, i);
    }
    printfQueue(queue);
    deleteQueue(queue, 0);
    printfQueue(queue);
    deleteQueue(queue, 0);
    printfQueue(queue);
    deleteQueue(queue, 0);
    printfQueue(queue);
    deleteQueue(queue, 0);
    printfQueue(queue);
    deleteQueue(queue, 0);
    printfQueue(queue);
    insertQueue(queue, 10);
    printfQueue(queue);
    return 0;
}
