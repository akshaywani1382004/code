#include <iostream>
#include <vector>
using namespace std;

class graph{
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;
    int edges, vertex;
    
    public:
    graph(int edge, int vertex){
        edges = edge;
        this -> vertex = vertex;
        adjList.resize(vertex);
        adjMatrix.resize(vertex, vector<int>(vertex,0));
    }

    void input(){
        int a,b;
        for(int i = 0; i<edges; i++){
            cout<<"Enter the Edge Points : ";
            cin>>a>>b;
            cout<<endl;

            adjMatrix[a][b] = 1;
            adjMatrix[b][a] = 1;

            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
    }

    void display_adjList(){
        cout<<"Adjacent List : "<<endl;
        for(int i = 0; i<vertex ; i++){
            cout<<i<<" >> ";
            int j = 0;
            for(int x : adjList[i]){
                cout << x << " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void display_adjMatrix(){
        cout<<"Adjacent Matrix : "<<endl;
        for(int i = 0; i<vertex ; i++){
            for(int j = 0; j<vertex ; j++){
                cout<<adjMatrix[i][j] << " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){

    graph g(3,3);

    g.input();
    g.display_adjList();
    g.display_adjMatrix();

    return 0;
}
