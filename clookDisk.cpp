#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
	return a<b;
}

int main()
{
	int n,req[100],current,i,sum=0,pos;
	cout<<"\n Enter the current position of the header : ";
	cin>>current;
	cout<<"\n Enter number of requests : ";
	cin>>n;
	cout<<"\n Enter the requests : ";
	req[0]=current;
	for(i=1;i<=n;i++)
	cin>>req[i];
	
	int m=n+1;
	sort(req,req+m,compare);
	
	for(i=0;i<=n;i++)
	if(req[i]==current)
	break;
	pos=i;
	
	for(i=pos;i<n;i++)
	{
		cout<<"\n"<<req[i]<<"->"<<req[i+1]<<"\t"<<abs(req[i]-req[i+1]);
		sum+=abs(req[i]-req[i+1]);
	}
	
	cout<<"\n"<<req[n]<<"->"<<req[0]<<"\t"<<abs(req[n]-req[0]);
	sum+=abs(req[n]-req[0]);
	
	for(i=0;i<(pos-1);i++)
	{
		cout<<"\n"<<req[i]<<"->"<<req[i+1]<<"\t"<<abs(req[i]-req[i+1]);
		sum+=abs(req[i]-req[i+1]);
	}
	
	
	cout<<"\n Total distance head traversed = "<<sum;
}
