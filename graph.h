#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <stdlib.h>

#define WHITE 0 // not visited
#define GREY 1 // in process
#define BLACK 2 // visited

typedef struct adjNode{

    int color;
    int source_dist;
    int dest;
    int parent;
    struct adjNode *next;
} ADJNODE;



typedef struct graph{

    int V; // Number of vertices
    ADJNODE **nlist; // the list of lists that makes up the node linking
} GRAPH;

// Returns a pointer to be inserted in the adjacency list
ADJNODE* newListNode(int dest){

    ADJNODE *temp=malloc(sizeof(ADJNODE));
    if(temp == NULL)
    {
        printf("DYNAMIC ALLOCATION FAILED");
        exit(1);
    }
    temp->next=NULL;
    temp->dest=dest;

    return temp;
}

// Returns a pointer for a graph with V vertices
GRAPH* newGraph(int V){

    int i;
    GRAPH* graph=malloc(sizeof(GRAPH));
    graph->V=V;

    //Create the adjacency list for each vertice , from 1 to V

    graph->nlist=(ADJNODE**)malloc(V*sizeof(ADJNODE*));

    // For each vertice , make the head node equal to NULL
    for(i=0 ; i<V ; i++)
        graph->nlist[i]=NULL;


    return graph;


}


/*Adds new edges to the newly created graph ,from source to destination
 * and from destination to source
 * considering a unoriented graph
 */
void addEdge(GRAPH *graph, int source , int destination){


    ADJNODE* new_node=newListNode(destination);

    // the Destination -> Source edge

    new_node->next=graph->nlist[source];
    graph->nlist[source]=new_node;



    // the Source -> Destination edge

    new_node=newListNode(source);

    new_node->next=graph->nlist[destination];
    graph->nlist[destination]=new_node;

    return;
}


void printGraph(GRAPH *g){

    int i;
    ADJNODE *temp;

    for(i=1 ; i<g->V ; i++){

        temp=g->nlist[i];
        printf("%d  ",i);

        while(temp){

            printf("- > %d " , temp->dest);

            temp=temp->next;
        }

        printf("\n");

    }

}

// Marks a node with a certain color , throughout the whole adjacency list
void markNodeAs(GRAPH *g,int node_nr,int COLOR){

    int i;
    ADJNODE *temp;

    for(i=0 ; i < g->V ; i++){

        temp=g->nlist[i];

        while(temp){

            if(temp->dest == node_nr)
                temp->color=COLOR;

            temp=temp->next;
        }


    }

}


// Sets a node parent and distance from source
void NodeParent_SRC(GRAPH *g ,int node_nr , int parent , int source_distance){

    int i;
    ADJNODE *temp;

    for(i=0 ; i < g->V ; i++){

        temp=g->nlist[i];

        while(temp){

            if(temp->dest == node_nr){
                temp->parent=parent;
                temp->source_dist=source_distance;
            }

            temp=temp->next;
        }


    }

}

// free the memory dinamically allocated by the graph structure
void freeGraph(GRAPH *graph){

    int v;

    for(v=0; v<graph->V; v++)
        free(graph->nlist[v]);

    free(graph);

    return;
}
#endif // GRAPH_H_INCLUDED
