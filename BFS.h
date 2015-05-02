#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED
#include "queue.h"
#include "graph.h"
#define INF 999999


// bfs search that takes start as the root node
void BFS_SEARCH(GRAPH *g , QUEUE *q , int start){

    ADJNODE *temp,*t;
    int i,v;



    for(i = 1; i < g->V; i++){

        temp=g->nlist[i];

        while(temp){

            temp->color=WHITE;
            markNodeAs(g,temp->dest,WHITE);
            NodeParent_SRC(g,temp->dest,-1,INF);// node is infinitely distanced from source and has -1 as a parent
            temp=temp->next;
        }
    }


    markNodeAs(g,start,GREY);
    NodeParent_SRC(g,start,-1,0);
    enqueue(q,start);

    while(!isEmpty(q)){

        v = dequeue(q);
        temp=g->nlist[v];
        t=g->nlist[v];

        while(temp){

            if( temp->color == WHITE ){
                markNodeAs(g,temp->dest,GREY); // Mark node as in process
                NodeParent_SRC(g,temp->dest,v,t->source_dist);
                enqueue(q,temp->dest);
                printQueue(q);

            }

            temp=temp->next;
        }


        markNodeAs(g,v,BLACK); // Finished visiting all neighbors
    }

}

#endif // BFS_H_INCLUDED
