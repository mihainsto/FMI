#include "Graph.hpp"

node::node(int key = 0, int cost = 0)
{
	m_cost = cost;
	m_key = key;
}
int  node::getKey()
{
	return m_key;
}
int  node::getCost()
{
	return m_cost;
}
std::ostream &operator<<(std::ostream &output, const node N)
{
	output << "cost = " << N.m_cost << " ";
	output << "node = " << N.m_key << " ";
	return output;
}

std::istream &operator>>(std::istream &input, graph &G)
{
	int a, b, c, i;
	input >> G.m_nodes >> G.m_vertices;
	for (i = 1; i <= G.m_vertices; i++)
	{
		input >> a >> c >> b;
		G.m_adjList[a].push_back(node(b, c));
	}
	return input;
}
std::ostream &operator<<(std::ostream &output, graph G)
{
	int i;
	output << "Nodes: " << G.m_nodes <<" ";
	output << "Vertices: " << G.m_vertices <<" ";
	output << "\n";
	for (i = 1; i <= G.m_nodes; i++)
	{
		if (!G.m_adjList[i].empty())
		{
			for (size_t j=0; j < G.m_adjList[i].size(); j++)
			{
				output << "Node= " << i << " ";
				output << G.m_adjList[i][j];
				output << "\n";
				
			}
		}
	}

	return output;
}
int graph::getNodes()
{
	return m_nodes;
}
int graph::getVertices()
{
	return m_vertices;
}