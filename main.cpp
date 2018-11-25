#include <stack.h>
#include <graphlist.h>
#include <graphmatrix.h>
#include <algorithm>
struct edge{
    int origin;
    int final;
};
int main()
{
    fstream file;
    std::string file_name,line;
    int count = 1,number_vertices;
    std::vector<edge *> edges;
    Stack<int> stack;
    std::vector<int> sorted_vertices;
    bool is_cyclic = false;

    std::cout<<"Enter the name of your file that contains the graph vertices:";
    std::cin>>file_name;
    file.open(file_name);
    if(file.is_open()){
        while(!file.eof()){
            edge *point_edge = new edge;
            getline(file,line);
            if(!isdigit(line[0])){
                std::cout<<"Not a digit"<<std::endl;
            }
            if(count == 1){
                number_vertices = std::stoi(line);
            }else{
                if(isdigit(line[0])){
                    point_edge->origin = (int)(line[0]) - 48;
                    point_edge->final = (int)(line[2]) - 48;
                    edges.push_back(point_edge);
                }
            }
            count += 1;
        }
    }
    else{
        cout<<"The file you entered could not be opened"<<endl;
    }
    file.close();

    GraphMatrix graph_matrix(number_vertices);

    for(edge* e:edges){
        graph_matrix.addEdge(e->origin,e->final);
    }
    graph_matrix.printGraph();

    std::cout<<"Now topologically sorting graph\n"<<std::endl;


    for(int i = 0; i < number_vertices; i++){
        int first_vertex = graph_matrix.getFirstVertex(is_cyclic);
        if(is_cyclic){
            std::cout<<"Ah shooty poorty. This graph has a cycle.\n"<<std::endl;
            std::cout<<"The graph can't be topologically sorted because it is not a DAG\n"<<std::endl;
            return 0;
        }
        sorted_vertices.push_back(first_vertex);
    }

    std::reverse(sorted_vertices.begin(),sorted_vertices.end());

    for(int vertex: sorted_vertices){
        stack.push(vertex);
    }

    std::cout<<"The graph topologically sorted are: ";
    while(!stack.isEmpty()){
        int top;
        stack.pop(top);
        std::cout<<top<<" ";
    }
    std::cout<<"\n"<<std::endl;
}
