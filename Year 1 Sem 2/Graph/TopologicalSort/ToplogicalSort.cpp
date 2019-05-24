#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <fstream>
#include <climits>
using namespace std;

int visited[50001];
vector<int> edges[50001];
stack<int> sorted;
void visit(int thisNode)
{
	int ok = 0;
	visited[thisNode] = 1;
	for(auto nextNode : edges[thisNode])
		if(!visited[nextNode])
			visit(nextNode);

	sorted.push(thisNode);
}
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("sortaret.in");
	fout.open("sortaret.out");
	int nodeCount, edgeCount;
	
	fin >> nodeCount >> edgeCount;
	for(int i=1;i<=edgeCount;i++)
	{
		int node1, node2;
		fin >> node1 >> node2;
		edges[node1].push_back(node2);
	}
	
	for(int i=1;i<=nodeCount;i++)
	{
		if (!visited[i]) visit(i);
	}
	while(!sorted.empty())
	{
		fout << sorted.top()<<" ";
		sorted.pop();
	}
	return 0;
}