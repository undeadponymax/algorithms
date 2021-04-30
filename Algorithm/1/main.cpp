#include <bits/stdc++.h>
using namespace std;

int BFS(vector<vector<int>> Matrix, int Start, int Finish, int N)
{
  queue<int> Queue;
  vector<int> Destination(N, INT_MAX);
  Queue.push(Start);
  Matrix[Start][Start] = 1;
  Destination[Start] = 0;
  while (!Queue.empty())
  {
    int v = Queue.front();
    Queue.pop();
    for (int i = 0; i < N; i++)
    {
      if (Matrix[v][i] != 0 && (!Matrix[i][i]))
      {
        Matrix[i][i] = 1;
        Queue.push(i);
        Destination[i] = Destination[v] + 1;
      }
    }
  }
  return (Destination[Finish] == INT_MAX) ? -1 : Destination[Finish];
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
  for (int Temp = 0; Temp < M; Temp++)
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
  int Length = BFS(Matrix, Start, Finish, N);
  ofstream Output("output.txt", ios::out | ios::trunc);
  Output << Length << endl;
  Output.close();
}