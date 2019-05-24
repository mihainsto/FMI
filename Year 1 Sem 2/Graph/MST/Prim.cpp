#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <fstream>
#include <climits>
using namespace std;

int visited[200001];
vector<pair<int, int>>edges[200001];
priority_queue<pair<int, pair<int,int>> > q;
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("apm.in");
	fout.open("apm.out");
	int nodeCount, edgeCount;
	
	fin >> nodeCount >> edgeCount;
	for(int i=1;i<=edgeCount;i++)
	{
		int node1, node2, cost;
		fin >> node1 >> node2 >> cost;;
		edges[node1].push_back(make_pair(cost*(-1), node2));
		edges[node2].push_back(make_pair(cost*(-1), node1));
	}
	
	q.push(make_pair(0, make_pair(0,1)));
	queue<pair<int,pair<int,int>> > mst;
	int totalCost = 0;
	while(!q.empty())
	{
		auto thisNode = q.top();
		q.pop();
		if(visited[thisNode.second.second])continue;
		visited[thisNode.second.second] = 1;
		mst.push(thisNode);
		totalCost += thisNode.first*(-1);
		for (auto nextNode : edges[thisNode.second.second])
			q.push(make_pair(nextNode.first, make_pair(thisNode.second.second, nextNode.second)));
	}
	fout << totalCost << "\n";
	fout << mst.size()-1 << "\n";
	mst.pop();
	while(!mst.empty())
	{
		auto edge = mst.front();
		mst.pop();
		fout << edge.second.first << " " << edge.second.second << "\n";
	}
	
	return 0;
}