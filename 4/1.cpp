#include<iostream>
using namespace std;
void WT(int p[], int n, int bt[],int wt[],int at[])
{
	int st[n];
	st[0]=0;
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		st[i]=st[i-1]+bt[i-1];
		wt[i]=st[i]-at[i];
		if(wt[i]<0)
		wt[i]=0;
	}
}
void TAT(int p[], int n, int bt[], int wt[], int tat[])
{
	for(int i=0;i<n;i++)
		tat[i]=bt[i] + wt[i];
}
void AT(int p[], int n, int bt[], int at[])
{
	int wt[n], tat[n];
	WT(p,n,bt,wt,at);
	TAT(p,n,bt,wt,tat);
	cout<<"Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time \n";
	int twt=0, ttat=0;
	for(int i=0;i<n;i++)
	{
		twt+=wt[i];
		ttat+=tat[i];
		int ct = tat[i] + at[i];
		cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<ct<<endl;
	}
	cout<<"Average Waiting Time: "<<(float)twt/(float)n<<endl;
	cout<<"Average Turn-Around Time: "<<(float)ttat/(float)n<<endl;
}
int main()
{
	int p[5];
	int n;
	int bt[5];
	int at[5];
	cout<<"Enter no of processes: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		p[i]=i+1;
		cout<<"Enter burst time "<<i+1<<": ";
		cin>>bt[i];
		cout<<"Enter arrival time "<<i+1<<": ";
		cin>>at[i];
	}
	AT(p,n,bt,at);
	return 0; 
}
