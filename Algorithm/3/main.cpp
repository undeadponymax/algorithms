#include <bits/stdc++.h>
using namespace std;
const int Infinity = 10000000;

struct edge
{
  edge(int i, int j, int w) : Source(i), Destination(j), Weight(w) {}
  int Source;
  int Destination;
  int Weight;
};

int BellmanFord(vector<edge> Matrix, int N, int M, int Start, int Finish)
{
  vector<int> Distances(N, Infinity);
  Distances[Start] = 0;
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j < M; j++)
    {
      int u = Matrix[j].Source;
      int v = Matrix[j].Destination;
      int Weight = Matrix[j].Weight;
      if (Distances[u] != Infinity && Distances[u] + Weight < Distances[v])
      {
        Distances[v] = Distances[u] + Weight;
      }
    }
  }
  for (int j = 0; j < M; j++)
  {
    int u = Matrix[j].Source;
    int v = Matrix[j].Destination;
    int weight = Matrix[j].Weight;
    if (Distances[u] + weight < Distances[v])
    {
      return -1;
    }
  }
  return Distances [Finish];
}

int main()
{
  ifstream Input("input.txt");
  int N, M, Type, Start, Finish;
  Input >> Start >> Finish;
  Start--;
  Finish--;
  Input >> N >> M >> Type;
  vector<edge> Matrix;
  for (int l = 0; l < M; l++)
  {
    int i, j, k;
    Input >> i >> j;
    i--;
    j--;
    if (Type == 2 || Type == 4)
    {
      Input >> k;
    }
    if (Type == 1)
    {
      Matrix.push_back(edge(i, j, 1));
    }
    else if (Type == 2)
    {
      Matrix.push_back(edge(i, j, k));
    }
    else if (Type == 3)
    {
      Matrix.push_back(edge(i, j, 1));
      Matrix.push_back(edge(j, i, 1));
    }
    else if (Type == 4)
    {
      Matrix.push_back(edge(i, j, k));
      Matrix.push_back(edge(j, i, k));
    }
  }
  Input.close();
  int cost = BellmanFord(Matrix, N, M, Start, Finish);
  ofstream Output("output.txt", ios::out | ios::trunc);
  if (cost == Infinity)
    cost = 0;
  Output << cost << endl;
  Output.close();
}