#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
int visited[100001];
using namespace std;
int main() {
    freopen("dfs.in","r",stdin);
    freopen("dfs.out","w",stdout);
    int nodeCount, edgeCount;
    vector<int>edges[100001];
    cin>>nodeCount>>edgeCount;
    for(int i = 1; i<=edgeCount;i++){
        int node1, node2;
        cin>>node1>>node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    queue<int> q;
    int conComponents=0;
    for(int node=1;node<=nodeCount;node++){
        if(visited[node]==0){
            conComponents++;
            q.push(node);
            while (!q.empty()) {
                int thisNode = q.front();
                q.pop();
                if(visited[thisNode] == 1) continue;
                visited[thisNode] = 1;
                for(auto nextNode:edges[thisNode]){
                    q.push(nextNode);
                }
            }
            
        }
    }
    cout<<conComponents;
    return 0;
}
