/**************************************************************************
* Class: CISS 285 Fall 2020
* Assignment : CW 16 - 11 - 2020
* Student: Louise Schmidtgen
* Professor Dr.M & M
* Date : 16 - 11- 2020
* Synopsis:
floodmap*/
#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#define SIZE 10

void print_terrain(double square[SIZE][SIZE], int size, double level);
int minarr(double square[SIZE][SIZE], int size);
int maxarr(double square[SIZE][SIZE], int size);
void get_terrain(double square[SIZE][SIZE]);
int main()
{
	/*declare variables*/
	double terrain[SIZE][SIZE];
	double level=0.0;
	int size = 10;
	double min = 0.0;
	double max = 0.0;
	double increase_level = 0.0;
	/*get terrain map*/
	get_terrain(terrain);
	/*get min max increase*/
	min = minarr(terrain, size);
	max = maxarr(terrain, size);
	increase_level = (max - min) / 10.0;
	/*print flood maps*/
	for (level = min; level <= max; level += increase_level)
	{
		printf("\nLevel: %.2f\n", level);
		print_terrain(terrain, size, level);
	}
	return 0;
}

void print_terrain(double square[SIZE][SIZE], int size, double level)
{
	int row = 0;
	int n = 0;
	for (row = 0; row < size; row++)
	{
		for (n = 0; n < size; n++)
		{
			/*if flooded print space*/
			if (square[row][n] <= level)
			{
				printf("%c",' ');
			}
			else
			{
				printf("%c", '*');
			}
		}
		printf("\n");
	}
}

int minarr(double square[SIZE][SIZE], int size)
{
	int row = 0;
	int n = 0;
	int min = square[0][0];
	for (row = 0; row < size; row++)
	{
		for (n = 0; n < size; n++)
		{
			if (square[row][n] < min)
			{
				min = square[row][n];
			}
		}
	}
	return min;
}
int maxarr(double square[SIZE][SIZE], int size)
{
	int row = 0;
	int n = 0;
	int max = square[0][0];
	for (row = 0; row < size; row++)
	{
		for (n = 0; n < size; n++)
		{
			if (square[row][n] > max)
			{
				max = square[row][n];
			}
		}
	}
	return max;
}

void get_terrain(double square[SIZE][SIZE])
{
	FILE* inp = NULL;
	/*get terrain map*/
	inp = fopen("terrain.txt", "r");
	int row = 0;
	int n = 0;
	double data = 0.0;
	for (row = 0; row < SIZE; row++)
	{
		for (n = 0; n < SIZE; n++)
		{
			fscanf(inp, " %lf", &data);
			square[row][n]= (double) data;
		}
	}
	fclose(inp);
}
