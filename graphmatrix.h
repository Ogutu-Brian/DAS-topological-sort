#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
class GraphMatrix
{
public:
    GraphMatrix(int num_vertices) {
        numvertices = num_vertices;
        vertextMatrix = new int*[numvertices];
        for(int i = 0;i < numvertices;i++){
            vertextMatrix[i] = new int[numvertices];
        }
        for(int i = 0; i < numvertices;i++){
            for(int k = 0; k < numvertices; k++){
                vertextMatrix[i][k] = 0;
            }
        }
    }

    ~GraphMatrix(){
        delete [] vertextMatrix;
    }

    void addEdge(int vertex1,int vertext2){
        vertextMatrix[vertex1][vertext2] = 1;
        numEdges += 1;
    }

    void printGraph(){
        std::cout<<"Adjacency Matrix:"<<std::endl;
        for(int i = 0; i < numvertices; i++){
            for(int k = 0; k < numvertices; k++){
                std::cout<<vertextMatrix[i][k]<<" ";
            }
            std::cout<<"\n";
        }
    }

    int getFirstVertex(bool &is_cyclic){
        bool is_first = false;
        int first_vertex = 0;

        while(!is_first && first_vertex < numvertices){
            is_first = true;
            for(int i = 0; i < numvertices;i++){
                if(vertextMatrix[i][first_vertex] == 1){
                    is_first = false;
                }
            }
            first_vertex += 1;
        }

        if(!is_first){
            //the graph has a cycle hence no first
           is_cyclic = true;
        }

        for(int i = 0; i < numvertices; i++){
            vertextMatrix[first_vertex - 1][i] = 0;
            vertextMatrix[i][first_vertex - 1] = 1;
        }

        return first_vertex - 1;
    }

    bool isThereAnEdge(int row,int column){
        if(vertextMatrix[row][column] == 1){
            return true;
        }
        return false;
    }

private:
  int **vertextMatrix;
  int numvertices;
  int numEdges = 0;
};
#endif // GRAPHMATRIX_H
