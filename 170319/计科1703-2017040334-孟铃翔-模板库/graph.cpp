#include <iostream>
#include "Jeffrey's_queue.hpp"
//#include<queue>
using namespace std;

//����㶨��
struct ArcNode
{
	int weight;       //���ϵ���Ϣ����
	int adj;          //�ڽӵ������λ��
	ArcNode* nextarc; //ָ����һ��������ָ��
};

//�����㶨��
struct VertexNode
{
	int info;          //�����ϵ���Ϣ����
	ArcNode* firstarc; //����ͷָ��
};

//�����ڽӱ��洢��ͼ�Ķ���
struct Graph
{
	VertexNode* vertexes; //ͼ�ϸ�������ڵ��Ӧ�����Ա�
	int vertexnumber;     //ͼ�ϵĶ�����Ŀ
};

int InitGraph(Graph& g, int vertexnumber)
{
	g.vertexes = new VertexNode[vertexnumber];
	g.vertexnumber = vertexnumber;
	for (int i = 0; i < vertexnumber; i++)
	{
		g.vertexes[i].firstarc = new ArcNode;
		g.vertexes[i].firstarc->nextarc = nullptr;
	}
	return 0;
}

int DestroyGraph(Graph& g)
{
	for (int i = 0; i < g.vertexnumber; i++)
	{
		while (g.vertexes[i].firstarc != nullptr)
		{
			ArcNode* p;
			p = g.vertexes[i].firstarc;
			g.vertexes[i].firstarc = p->nextarc;
			delete p;
		}
	}
	g.vertexnumber = 0;
	delete[] g.vertexes;
	g.vertexes = nullptr;
	return 0;
}

int BFS(Graph& g, int loc, int visited[])
{
	queue<int> q;
	q.push(loc);
	visited[loc] = 1;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << g.vertexes[v].info << " ";
		for (ArcNode* p = g.vertexes[v].firstarc->nextarc; p != nullptr; p = p->nextarc)
		{
			if (!visited[p->adj])
			{
				q.push(p->adj);
				visited[p->adj] = 1;
			}
		}
	}
	return 0;
}

int BFSTraverse(Graph& g)
{
	int* visited;
	visited = new int[g.vertexnumber];
	for (int i = 0; i < g.vertexnumber; i++)
		visited[i] = 0;
	for (int i = 0; i < g.vertexnumber; i++)
	{
		if (!visited[g.vertexes[i].info])
			BFS(g, i, visited);
	}
	return 0;
}

int ArraytoList(Graph& g, int* a)
{
	//������Ĭ��ͼ�Ĵ��淽ʽΪ�ڽӱ�����ʱ��Ҫ���ڽӾ���ת��Ϊ�ڽӱ�
	int n = g.vertexnumber;
	for (int i = 0; i < n; i++)
	{
		ArcNode* p, * q;
		p = g.vertexes[i].firstarc;
		for (int j = 0; j < n; j++)
		{
			if (a[i * n + j] == 1)
			{
				q = new ArcNode;
				q->adj = j;
				q->weight = j;
				q->nextarc = nullptr;
				q->nextarc = p->nextarc;
				p->nextarc = q;
				p = p->nextarc;
			}
		}
	}
	return 0;
}

int main()
{
	//nΪͼ�ϵĶ��������a����ͼ���ڽӾ���
	int n, * a;
	cin >> n;

	//�½�������ͼ���ڽӾ���
	a = new int[n * n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i * n + j];
	}

	//����Ҫ��ͼ���г�ʼ��
	Graph g;
	InitGraph(g, n);
	for (int i = 0; i < n; i++)
		g.vertexes[i].info = i;

	//���ڽӾ���ת��Ϊ�ڽӱ�
	ArraytoList(g, a);

	//������ͼ���й�����ȱ���
	BFSTraverse(g);

	//�ڱ��������󣬽�ͼ�������٣��ͷ��ڴ�ռ�
	DestroyGraph(g);
	cout << endl;
	delete[] a;

	return 0;
}