#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <iostream>
class GraphMatric
{
public:

    GraphMatric(int num_vertices) {
        numvertices = num_vertices;
        //dynamically initializing the vertice of the matrix
        vertextMatrix = new int*[numvertices];
        for(int i = 0;i < numvertices;i++){
            vertextMatrix[i] = new int[2];
        }
        //setting the values of the matrix to 0
        for(int i = 0; i < numvertices;i++){
            for(int k = 0; k < 2; k++){
                vertextMatrix[i][k] = 0;
            }
        }
    }
    //using the destructor free up dynamically allocated memory
    ~GraphMatric(){
        for(int i = 0; i < numvertices;i++){
            for(int k = 0; k < 2;k++){
                delete vertextMatrix[i][k];
            }
        }
    }
    //setting the value to one when adding the edge
    void addEdge(int vertex1,int vertext2){
        vertextMatrix[vertex1][vertext2] = 1;
    }
    //print ing the graph
    void printGraph(){
        for(int i = 0; i < numvertices; i++){
            for(int k = 0; k < 2; k++){
                std::cout<<vertextMatrix[i][k];
            }
        }
    }
    void getFirstVertex(){

    }

private:
  int **vertextMatrix;
  int numvertices;
  int numEdges;
};
#endif // GRAPHMATRIX_H
