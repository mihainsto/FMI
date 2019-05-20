#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
using namespace std;
int visited[100001];
int minDistance[100001];
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("bfs.in");
    fout.open("bfs.out");
    int nodeCount, edgeCount, startingNode;
    fin>>nodeCount>>edgeCount>>startingNode;
    vector<int> edges[100001];
    
    for(int i=1;i<=edgeCount;i++){
        int node1,node2;
        fin>>node1>>node2;
        edges[node1].push_back(node2);
    }
    for(int i=1;i<=nodeCount;i++)
        minDistance[i] = INT_MAX;
    
    queue<int> st;
    st.push(startingNode);
    minDistance[startingNode] = 0;
    while(!st.empty()){
        int thisNode = st.front();
        st.pop();
        if(visited[thisNode]==1) continue;
        visited[thisNode]=1;
        for(auto nextNode:edges[thisNode]){
            st.push(nextNode);
            if(minDistance[nextNode] > minDistance[thisNode] + 1)
                minDistance[nextNode] = minDistance[thisNode] + 1;
        }
    }
    for(int i=1;i<=nodeCount;i++){
        if(minDistance[i] == INT_MAX) minDistance[i] = -1;
        cout<<minDistance[i]<<" ";
    }
    return 0;
}
