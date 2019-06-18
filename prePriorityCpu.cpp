#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n,i,wt[10],tat[10],total,awt,atat,st[10];

struct process
{
	int id;
	int bt;
	int at;
	int priority;
}p[10];

void calcWt()
{
	int rt[10],max=0,complete=0,t=0,shortest=0,finishtime;
	bool check=false;
	
	for(i=0;i<n;i++)
	rt[i]=p[i].bt;
	
	while(complete!=n)
	{
		for(i=0;i<n;i++)
		{
			if((rt[i]>0)&&(p[i].priority>max)&&(p[i].at<=t))
			{
				max=p[i].priority;
				check=true;
				shortest=i;
			}
		}
		
		if(check==false)
		{
			t++;
			continue;
		}
		
		rt[shortest]--;
		
		if(rt[shortest]==0)
		max=0;
		
		if(rt[shortest]==0)
		{
			complete++;
			finishtime=t+1;
			check=false;
			wt[shortest]=finishtime-p[shortest].bt-p[shortest].at;
			
			if(wt[shortest]<0)
			wt[shortest]=0;
		}
		t++;
	}
}

int main()
{
	
	cout<<"\n Enter number of processes : ";
	cin>>n;
	
	cout<<"\n Enter burst times : ";
	for(i=0;i<n;i++)
	cin>>p[i].bt;
	
	cout<<"\n Enter arrival time : ";
	for(i=0;i<n;i++)
	cin>>p[i].at;
	
	cout<<"\n Enter priority : ";
	for(i=0;i<n;i++)
	cin>>p[i].priority;
	
	for(i=0;i<n;i++)
	p[i].id=i;
	
	calcWt();
	
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
	cout<<(p[i].id+1)<<" "<<wt[i]<<"\n";
	cout<<"\n";
	cout<<"avg wt : "<<awt<<" avg tat : "<<atat;
}
