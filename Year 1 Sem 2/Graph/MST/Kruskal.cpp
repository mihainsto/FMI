//KRUSKAL
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <fstream>
#include <climits>
using namespace std;

int visited[200001];
int fatherOf[200001];
vector<pair<int, int>>edges[200001];
priority_queue<pair<int, pair<int,int>> > q;
void merge(int node1, int node2)
{
	if (fatherOf[node1] == 0 && fatherOf[node2] == 0)
		fatherOf[node2] = node1, fatherOf[node1] = node1;
	else
		if (fatherOf[node1] == 0)
			fatherOf[node1] = fatherOf[node2];
		else
			if (fatherOf[node2] == 0)
				fatherOf[node2] = fatherOf[node1];
			else
				fatherOf[fatherOf[node1]] = node2;
}
int findFather(int node)
{
	if (node == fatherOf[node]) return node;
	fatherOf[node] = findFather(fatherOf[node]);
	return fatherOf[node];
}
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
		q.push(make_pair(cost*(-1), make_pair(node1, node2)));
	}
	queue<pair<int, pair<int, int>> > mst;
	int minCost = 0;
	while(!q.empty())
	{
		auto thisEdge = q.top();
		q.pop();
		if (findFather(thisEdge.second.first) == findFather(thisEdge.second.second) && fatherOf[thisEdge.second.first]!=0) continue;
		mst.push(thisEdge);
		minCost += thisEdge.first * (-1);
		merge(thisEdge.second.first, thisEdge.second.second);
	}
	fout << minCost<<"\n";
	fout << mst.size()<< "\n";
	//mst.pop();
	while (!mst.empty())
	{
		auto edge = mst.front();
		mst.pop();
		fout << edge.second.first << " " << edge.second.second << "\n";
	}
	return 0;
}