#include <stdio.h>
#include "queue.h"
#include "graph.h"
#include "BFS.h"

int main ()
{

    FILE *f=fopen("graph.in","rt");

    if(f == NULL){

        printf("NO INPUT FILE");
        return -1;
    }

    int V;
    int src,dest;

    fscanf(f,"%d",&V);

    GRAPH *graph = newGraph(V);

    while(!feof(f)){

        fscanf(f,"%d %d",&src,&dest);
        addEdge(graph,src,dest);

    }

    QUEUE *q=newQUEUE();
    BFS_SEARCH(graph,q,1);
    printf("\nADJ LIST:\n");
    printGraph(graph);

    freeGraph(graph);




    return 0;
}
