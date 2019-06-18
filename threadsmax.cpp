#include<iostream>
#include<pthread.h>
using namespace std;

int part=0,result[4],t=4,n,arr[100];

void* maximum(void* arg)
{
	int low=part*n/4,high=((part+1)*n/4)-1;
	
	int max=arr[low];
	for(int i=low;i<=high;i++)
	{
		if(arr[i]>max)
		max=arr[i];
	}
	result[part]=max;
	part++;
}

int main()
{
	int i;
	cout<<"\n Enter number of elements : ";
	cin>>n;
	cout<<"\n Enter elements : ";
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	pthread_t threads[4];
	
	for(i=0;i<4;i++)
	pthread_create(&threads[i],NULL,maximum,(void*)NULL);
	
	for(i=0;i<4;i++)
	pthread_join(threads[i],NULL);
	
	int max=result[0];
	for(i=0;i<4;i++)
	{
		if(result[i]>max)
		max=result[i];
	}
	
	cout<<"\n maximum = "<<max;
	
}
