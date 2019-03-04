#pragma once
#include <map>
#include <vector>
#include <iostream>
class node
{
	int m_cost;
	int m_key;
public:
	node(int key, int cost);
	int getKey();
	int getCost();
	friend std::ostream &operator<<(std::ostream &output, const node N);
};
class graph
{
	std::map<int, std::vector<node> > m_adjList;
	int m_nodes;
	int m_vertices;
public:
	friend std::istream &operator>>(std::istream &input, graph &G);
	friend std::ostream &operator<<(std::ostream &output, const graph G);
	int getNodes();
	int getVertices();
};

