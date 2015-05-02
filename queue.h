#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdlib.h>

// Structure of a queue node
typedef struct q_node{

    int data;
    struct q_node *next;

} NODE;

// Structure of the queue
typedef struct queue{

    NODE *rear;
    NODE *front;

} QUEUE;

/* Example of a queue


        *|DATA|HEAD| --->|DATA|ELEM1|--->|DATA|ELEM2|--->|DATA|ELEM3|--->|DATA|TAIL|--->NULL

        *HEAD is the first one to be dequeued
        *TAIL is the place where enqueuing takes place
*/


//Returns a pointer to the new node
NODE *newNode(int i){


    NODE* new_node = (NODE*)malloc(sizeof(QUEUE));

    new_node->next=NULL;
    new_node->data=i;
    return new_node;
}

// Initializes  queue
QUEUE *newQUEUE(){


    QUEUE *q=(QUEUE*)malloc(sizeof(QUEUE));

    q->front=NULL;
    q->rear=NULL;

    return q;
}

// Adds an element to the rear of the queue
void enqueue(QUEUE *q,int i){

    NODE *node= malloc(sizeof(NODE));
    node->next=NULL;
    node->data=i;

    if(q->front == NULL && q->rear == NULL ){

        q->front=node;
        q->rear=node;
        return;
    }

    q->rear->next=node;
    q->rear=node;


}

// Returns the first element fromt the queue then removes it
int dequeue(QUEUE *q){

    int val;
    if(q->front == NULL && q->rear == NULL)
    {

        printf("Empty queue ");
        return -1;
    }

    if(q-> front == q->rear )
    {
        val=q->front->data;
        q->front = NULL;
        q->rear= NULL;
        return val;

    }
    val=q->front->data;
    NODE *temp=q->front;

    q->front=q->front->next;
    free(temp);
    return val;
}




// Returns the first element without dequeueing
int front(QUEUE *q){

    if(q->front == NULL && q->rear == NULL){

        printf("QUEUE HAS NO ELEMENTS ");
        return -1;
    }

    return q->front->data;

}

//If queue is empty returns 1 otherwise 0

int isEmpty(QUEUE *q){

    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// Prints all the elements of the queue
void printQueue(QUEUE *q){

    printf("\n");
    if(q->front== NULL && q->rear == NULL){

        printf("QUEUE HAS NO ELEMENTS\n");
        return;

    }
    NODE *temp=q->front;

    while(temp){

        printf("%d ",temp->data);
        temp=temp->next;

    }

    printf("\n");
}

#endif // QUEUE_H_INCLUDED
