#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
class GraphList
{
public:
    GraphList(int num_vertices){
        numVertices = num_vertices;
        headArray = new ListNode* [numVertices];
        for(int i = 0; i < numVertices; i++){
            headArray[i] = new ListNode;
        }
        for(int i = 0; i < numVertices;i++){
            headArray[i]->next = NULL;
            headArray[i]->value = i;
        }
    }

    ~GraphList(){
        delete [] headArray;
    }

    void addEdge(int vertex1,int vertex2){
        headArray[vertex1]->next = headArray[vertex2];
        numEdges += 1;
    }

    void printGraph(){
        for(int i = 0; i < numVertices; i++){
            if(headArray[i]->next != NULL){
                std::cout<<headArray[i]->value<<" "<<headArray[i]->next->value<<std::endl;
            }
        }
    }

private:
    struct ListNode{
        int value;
        ListNode* next;
    };
    ListNode **headArray;
    int numVertices;
    int numEdges;
};
#endif // GRAPHLIST_H
