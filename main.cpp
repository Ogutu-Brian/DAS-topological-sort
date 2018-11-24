#include <stack.h>
#include <iostream>
#include <fstream>
#include <vector>
int main()
{
    fstream file;
    string file_name,line;
    vector<string> vertices;
    int count = 1,number_vertices;

    std::cout<<"Enter the name of your file that contains the graph vertices:";
    std:cin>>file_name;
    file.open(file_name);
    if(file.is_open()){
        while(!file.eof()){
            getline(file,line);
            if(count == 1){
                number_vertices = std::stoi(line);
            }
            //vertices.push_back(line);
            std::cout<<line<<endl;
            count += 1;
        }
    }
    else{
        cout<<"The file you entered could not be opened"<<endl;
    }
    std::cout<<"The number of vertices are"<<number_vertices<<std::endl;
    file.close();
}
