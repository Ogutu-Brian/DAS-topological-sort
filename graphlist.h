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
            headArray[i] = new ListNode [numVertices];
        }
        for(int i = 0; i < numVertices; i++){
            for(int k = 0; k < numVertices; k++){
                headArray[i][k].value = -1;
                headArray[i][k].next = NULL;
            }
        }
    }

    ~GraphList(){
        delete [] headArray;
    }

    void addEdge(int vertex1,int vertex2){
        ListNode *node = new ListNode;
        node->value = vertex2;
        node->next = NULL;

        headArray[vertex1][vertex2].value = vertex1;
        headArray[vertex1][vertex2].next = node;
        numEdges += 1;
    }

    void printGraph(){
        for(int i = 0; i < numVertices; i++){
            std::cout<<i;
            for(int k = 0; k < numVertices; k++){
                if(headArray[i][k].value != -1){
                    std::cout<<"-->"<<headArray[i][k].next->value;
                }
            }
            std::cout<<"-->NULL\n";
            std::cout<<std::endl;
        }
    }

private:
    struct ListNode{
        int value;
        ListNode* next;
    };
    ListNode **headArray;
    int numVertices;
    int numEdges = 0;
};
#endif // GRAPHLIST_H
