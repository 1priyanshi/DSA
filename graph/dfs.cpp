//DFS starts with a root node or a start node and then explores the adjacent nodes of the current node by going deeper 
//into the graph or a tree. This means that in DFS the nodes are explored depth-wise until a node with no children is encountered.
//Unlike BFS in which we explore the nodes breadthwise, in DFS we explore the nodes depth-wise.
#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>>l;

    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void dfs_helper(T src, map<T,bool> &visited){
            cout<<src<<" ";
            visited[src]=true;
            //go to all nbr of that node that is not visited
            for(T nbr: l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited);
                }
            }
        }

        void dfs(T src){
            map<T,bool> visited;
            for(auto p:l){
                //Mark all nodes not visited
                T node= p.first;
                visited[node]=false;
            }
            //call helper function
            dfs_helper(src,visited);
        }
};

int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,0);

    g.dfs(0);
    return 0;
}