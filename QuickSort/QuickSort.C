#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void QuickSort (int d[], int s, int f)
{
	if(s < f)
	{
		int l = s;
		int r = f;
		int m = l + r / 2;
		int k = 0;
		while(k == 0)
		{
			while(d[r] > d[m])
			{
				r--;
			}
			while(d[l] < d[m])
			{
				l++;
			}
			if(l <= r)
			{
				int t = d[l];
				d[l] = d[r];
				d[r] = t;
				l++;
				r--;
			}
			if(l > r)
			{
				k = 1;
			}
		}
		QuickSort (d, s, r);
		QuickSort (d, l, f);
	}
}

int main(void)
{
	char *InputFileName = (char*)malloc(sizeof(char)*12); 
    char *OutputFileName = (char*)malloc(sizeof(char)*12);
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
    clock_t StartTime, EndTime;
    StartTime = clock();
    QuickSort(d, 0, n - 1);
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
    free(InputFileName);
    free(OutputFileName);
    return 0;
}