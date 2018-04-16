#include<iostream>
#include<stdio.h>
#include<omp.h>
#include <time.h>
#include<random>
using namespace std;

struct Compare { int val; int index; };


void selectionSort1(int ilgi[], int n,  int bas[])
{
	clock_t t1, t2;

	t1 = clock();
#pragma omp parallel for num_threads(16)
	for (int x = 0; x < n - 1; x++)
	{
		struct Compare min;
		min.val = ilgi[x];
		min.index = x;
	
		for (int y = x + 1; y < n; y++)
		{
			if (ilgi[y] < ilgi[min.val])
				min.val = ilgi[y];
			min.index = y;
		}

		int temp = ilgi[x];
		ilgi[x] = min.val;
		ilgi[min.index] = temp;

		

		int temp2 = bas[x];
		bas[x] = bas[min.index];
		bas[min.index] = temp2;
		
	}
	t2 = clock();

	double total_clock;
	total_clock = t2 - t1;
	cout << endl << "Kucukten ilgi " << total_clock << "mm" << endl;
	

}

void selectionSort2(int ilgi[], int n, int bas[])
{
	clock_t t1, t2;

	t1 = clock();
#pragma omp parallel for num_threads(3)
	for (int x = 0; x<n - 1; x++)
	{
		int iMin = x;
		for (int y = x + 1; y < n; y++)
		{
			if (ilgi[y] > ilgi[iMin])
				iMin = y;
		}
		int temp = ilgi[x];
		ilgi[x] = ilgi[iMin];
		ilgi[iMin] = temp;

	

		int temp2 = bas[x];
		bas[x] = bas[iMin];
		bas[iMin] = temp2;
	}
	t2 = clock();

	double total_clock;
	total_clock = t2 - t1;
	cout << endl << "Buyukten ilgi " << total_clock << "mm" << endl;
	
}

void selectionSort3(int ilgi[], int n,  int bas[])
{
	clock_t t1, t2;

	t1 = clock();
#pragma omp parallel for num_threads(3)
	for (int x = 0; x<n - 1; x++)
	{
		int iMin = x;
		for (int y = x + 1; y < n; y++)
		{
			if (bas[y] < bas[iMin])
				iMin = y;
		}
		int temp = ilgi[x];
		ilgi[x] = ilgi[iMin];
		ilgi[iMin] = temp;

		

		int temp2 = bas[x];
		bas[x] = bas[iMin];
		bas[iMin] = temp2;
	}
	t2 = clock();

	double total_clock;
	total_clock = t2 - t1;
	cout << endl <<"Kucukten bas " << total_clock << "mm" << endl;
	
}

void selectionSort4(int ilgi[], int n,  int bas[])
{
	clock_t t1, t2;

	t1 = clock();
#pragma omp parallel for num_threads(3)
	for (int x = 0; x<n - 1; x++)
	{
		int iMin = x;
		for (int y = x + 1; y < n; y++)
		{
			if (bas[y] > bas[iMin])
				iMin = y;
		}
		int temp = ilgi[x];
		ilgi[x] = ilgi[iMin];
		ilgi[iMin] = temp;

		

		int temp2 = bas[x];
		bas[x] = bas[iMin];
		bas[iMin] = temp2;
	}
	t2 = clock();

	double total_clock;
	total_clock = t2 - t1;
	cout << endl << "Buyukten bas " << total_clock << "mm" << endl;

}
int main()
{

	const unsigned int s = 100000;
	clock_t t1, t2;
	
	t1 = clock();
	
	int ilgi[s] ;

	int bas[s] ;
	
	for (int i = 0; i < s; i++) {
		int rond = rand() % 100 + 1;
		ilgi[i] = rond;
		
	}
	for (int i = 0; i < s; i++) {
		int rond = rand() % 100 + 1;
		bas[i] = rond;

	}
	
	selectionSort1(ilgi, size(ilgi), bas);

	
	selectionSort2(ilgi, size(ilgi), bas);


	selectionSort3(ilgi, size(ilgi), bas);

	selectionSort4(ilgi, size(ilgi), bas);

	t2 = clock();

	double total_clock;
	total_clock = t2 - t1;
	cout << endl << "Total time " << total_clock << "mm"<< endl;
	getchar();
	return 0;
}
