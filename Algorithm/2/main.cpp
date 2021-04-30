#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> Matrix, int Start, vector<bool> &Visited, vector<int> &Path)
{
  Visited[Start] = true;
  Path.push_back(Start);
  for (int i = 0; i < Matrix.size(); i++)
    if (Matrix[Start][i] != INT_MAX && !Visited[i])
    {
      DFS(Matrix, i, Visited, Path);
    }
}

int main()
{
  ifstream Input("input.txt");
  int N, M, Type, Start, Finish;
  Input >> Start >> Finish;
  Start--;
  Finish--;
  Input >> N >> M >> Type;
  vector<vector<int>> Matrix(N, vector<int>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      Matrix[i][j] = INT_MAX;
    }
  }
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
      Matrix[i][j] = 1;
    }
    else if (Type == 2)
    {
      Matrix[i][j] = k;
    }
    else if (Type == 3)
    {
      Matrix[i][j] = 1;
      Matrix[j][i] = 1;
    }
    else if (Type == 4)
    {
      Matrix[i][j] = k;
      Matrix[j][i] = k;
    }
  }
  Input.close();
  vector<bool> Visited(N, false);
  vector<int> Path;
  DFS(Matrix, Start, Visited, Path);
  ofstream Output("output.txt", ios::out | ios::trunc);
  Output << Visited[Finish] << endl;
  Output.close();
}