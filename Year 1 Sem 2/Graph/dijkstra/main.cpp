#include <queue>
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;
int visited[500001];
int roadVec[500001];
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("dijkstra.in");
    fout.open("dijkstra.out");
    int nodeCount, edgeCount;
    fin>>nodeCount>>edgeCount;
    vector<pair<int,int>>edges[50001];
    
    for(int i=1;i<=edgeCount;i++){
        int node1,node2,cost;
        fin>>node1>>node2>>cost;
        edges[node1].push_back(make_pair(cost*(-1), node2));
    }
    for(int i=1;i<=nodeCount;i++)
        roadVec[i] = INT_MAX;
    priority_queue<pair<int,int>>q;
    q.push(make_pair(0, 1));
    roadVec[1] = 0;
    while (!q.empty()) {
        auto thisNode = q.top();
        q.pop();
        if(visited[thisNode.second] == 1) continue;
        visited[thisNode.second] = 1;
        
        for(auto nextNode : edges[thisNode.second]){
            int cost = roadVec[thisNode.second] + nextNode.first*(-1);
            if(cost < roadVec[nextNode.second]){
                roadVec[nextNode.second] = cost;
                q.push(make_pair(cost*(-1), nextNode.second));
            }
        }
    }
    for(int i=2;i<=nodeCount;i++){
        if(roadVec[i]==INT_MAX) roadVec[i] = 0;
        fout<<roadVec[i]<<" ";
    }
    return 0;
}
