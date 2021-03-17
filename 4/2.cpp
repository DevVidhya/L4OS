#include<bits/stdc++.h>
using namespace std;
int ab;
typedef struct process
{
	int pid, at, bt, ct, tat, wt;
}process;
bool comp(process a, process b)
{
	return a.at<b.at;
}
bool comp1(process a, process b)
{
	return a.bt<b.bt && a.at<=ab;
}
int main()
{
	process p[10];
	int n,i,j;
	cout<<"Enter no of processes: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter process ID: ";
		cin>>p[i].pid;
		cout<<"Enter Arrival time: ";		
		cin>>p[i].at;
		cout<<"Enter Burst time: ";
		cin>>p[i].bt;
	}
	sort(p,p+n,comp);
	p[0].ct=p[0].bt+p[0].at;
	p[0].tat=p[0].ct-p[0].at;
	p[0].wt=p[0].tat-p[0].bt;
	for(i=1;i<n;i++)
	{
		ab=p[i-1].ct;
		sort(p+i,p+n,comp1);
		if(p[i-1].ct<p[i].at)
			p[i].ct=p[i-1].ct+p[i].bt+(p[i].at-p[i-1].ct);
		else
			p[i].ct=p[i-1].ct+p[i].bt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
	cout<<"Processes  Arrival Time  Burst Time  Completion Time  Turn-Around Time  Waiting Time\n";
	for(i=0;i<n;i++)
		cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wt<<endl;
	return 0;
}
