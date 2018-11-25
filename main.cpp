#include <stack.h>
#include <graphlist.h>
#include <graphmatrix.h>
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
    GraphMatrix grap_matrix;
    GraphList graph_list;
    Stack stack;

    std::cout<<"Enter the name of your file that contains the graph vertices:";
    std::cin>>file_name;
    file.open(file_name);
    if(file.is_open()){
        while(!file.eof()){
            edge *point_edge = new edge;
            getline(file,line);
            if(count == 1){
                number_vertices = std::stoi(line);
            }else{
                point_edge->origin = (int)(line[0]) - 48;
                point_edge->final = (int)(line[2]) - 48;
                edges.push_back(point_edge);
            }
            count += 1;
        }
    }
    else{
        cout<<"The file you entered could not be opened"<<endl;
    }
    edges.pop_back();
    for(edge* e:edges){
        std::cout<<e->origin<<" "<<e->final<<std::endl;
    }
    file.close();
}
