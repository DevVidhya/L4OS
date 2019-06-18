#include<iostream>
using namespace std;

int n,part=0,t=4,a[100],result[4],k;

void* prime(void* arg)
{
	int low=part*n/4,high=((part+1)*n/4)-1;
	
	result[part]=1;
	for(int i=low;i<=high;i++)
	{
		if(k%a[i]==0)
		{
			result[part]=0;
			break;
		}
	}
	part++;
}

int main()
{
	pthread_t threads[4];
	cout<<"\n Enter a number : ";
	cin>>k;
	
	for(int i=0;i<k-2;i++)
	{
		a[i]=i+2;
	}
	n=k-2;
	
	for(int i=0;i<4;i++)
	pthread_create(&threads[i],NULL,prime,(void*) NULL);
	
	for(int i=0;i<4;i++)
	pthread_join(threads[i],NULL);
	
	for(int i=0;i<4;i++)
	{
		if(result[i]==0)
		{
			cout<<"\n Not prime ";
			return 0;
		}
	}
	cout<<"\n Prime ";
}
