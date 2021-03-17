#include<pthread.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include <bits/stdc++.h> 
using namespace std; 
#define max 20 

#define Th_max 4 
int a[] = { 1, 7, 6, 5, 4, 3, 2, 8 }; 
int n = sizeof(a) / sizeof(a[0]);
int thread_no = 0;
void* sort(void* arg) 
{
	int i, j, t, num = thread_no++; 
	for (i = num * (max / 4); i < (num + 1) * (max / 4) && i < n; i++) 
	{
		for (j = i + 1; j < (num + 1) * (max / 4) && j < n; j++) 
		if(a[j]<a[i])
		{
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
} 
int main() 
{ 
	int i,j;
	pthread_t threads1[Th_max],threads2[Th_max];
	for (i = 0; i < Th_max; i++)
		pthread_create(&threads1[i], NULL, sort, (void*)NULL); 

	for (i = 0; i < Th_max; i++) 
		pthread_join(threads1[i], NULL);  
	for (i = 0; i < n; i++) 
	{ 
		cout<<a[i]<<" ";
	} 
	return 0; 
} 

