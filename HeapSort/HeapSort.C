#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void HeapSortIteration(int d[], int n, int i)
{ 
	int m = i;
	int l = 1 + i * 2;
	int r = 2 + i * 2;
	if(l < n && d[l] > d[m])
	{
		m = l;
	}
	if(r < n && d[r] > d[m])
	{
		m = r;
	}
	if(m != i)
	{
		int t = d[i];
		d[i] = d[m];
		d[m] = t;
		HeapSortIteration(d, n, m);
	}
}

void HeapSort(int d[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
	{
		HeapSortIteration(d, n, i);
	}
	for(int i = n - 1; i >= 0; i--)
	{
		int t = d[i];
		d[i] = d[0];
		d[0] = t;
		HeapSortIteration(d, i, 0);
	}
}

int main(void)
{
  clock_t StartTime, EndTime;
  char *InputFileName = (char*)malloc(12*sizeof(char)); 
  char *OutputFileName = (char*)malloc(12*sizeof(char));
  FILE *CommandFile = fopen("command.txt", "r");
  fscanf(CommandFile, "%s", &*InputFileName);
  fscanf(CommandFile, "%s", &*OutputFileName);
  fclose(CommandFile);
	FILE *InputFile = fopen(InputFileName, "r");
	int n;
	fscanf(InputFile, "%d", &n);
	int d[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(InputFile, "%d", &d[i]);
	}
  fclose(InputFile);
  StartTime = clock();
	HeapSort(d, n);
  EndTime = clock();
  FILE *OutputFile = fopen(OutputFileName, "w");
  fprintf(OutputFile, "%f\n", (double) (EndTime - StartTime) / CLOCKS_PER_SEC);
  fprintf(OutputFile, "%d\n", n);
  for(int i = 0; i < n; i++)
  {
    fprintf(OutputFile, "%d ", d[i]);
  }
  fclose(OutputFile);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", d[i]);
	}
	return 0;
}