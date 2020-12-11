#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ShellSort (int d[], int n)
{
	for (int i = n / 2; i > 0; i /= 2)
		for (int j = i; j < n; j++) 
			for (int h = j - i; h >= 0 && d[h] > d[h + i]; h -= i)
			{
				int t = d[h];
				d[h] = d[h + i];
				d[h + i] = t;
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
	ShellSort(d, n);
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