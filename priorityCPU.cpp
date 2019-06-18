#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct process
{
	int id;
	int bt;
	int at;
	int priority;
};

bool compare(process a,process b)
{
	return (a.priority>b.priority);
}

int main()
{
	process p[10];
	int n,i,wt[10],tat[10],total,awt,atat,st[10];
	
	cout<<"\n Enter number of processes : ";
	cin>>n;
	
	cout<<"\n Enter burst times : ";
	for(i=0;i<n;i++)
	{
		cin>>p[i].bt;
	}
	
		
	cout<<"\n Enter arrival time : ";
	for(i=0;i<n;i++)
	cin>>p[i].at;
	
	cout<<"\n Enter priority : ";
	for(i=0;i<n;i++)
	{
		cin>>p[i].priority;
	}
	
	for(i=0;i<n;i++)
	p[i].id=i;
	
	sort(p,p+n,compare);
	
	st[0]=0;
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		st[i]=st[i-1]+p[i-1].bt;
		wt[i]=st[i]-p[i].at;
		
		if(wt[i]<0)
		wt[i]=0;
	}
	
	for(i=0;i<n;i++)
	tat[i]=wt[i]+p[i].bt;
	
	total=0;
	for(i=0;i<n;i++)
	total+=wt[i];
	
	awt=total/n;
	
	total=0;
	for(i=0;i<n;i++)
	total+=tat[i];
	
	atat=total/n;
	
	cout<<"\n order : ";
	for(i=0;i<n;i++)
	cout<<(p[i].id+1)<<" ";
	cout<<"\n";
	cout<<"avg wt : "<<awt<<" avg tat : "<<atat;
}
