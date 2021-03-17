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
	WT(p,bt,wt,at);
	TAT(p,bt,wt,tat);
	cout<<"Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time \n";
	int twt=0, ttat=0;
	for(int i=0;i<n;i++)
	{
		twt+=wt[i];
		ttat+=tat[i];
		int ct = tat[i] + at[i];
		cout<<" "<<i+1<<"\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct<<endl;
	}
	cout<<"Average Waiting Time: "<<(float)twt/(float)n<<endl;
	cout<<"Average Turn-Around Time: "<<(float)ttat/(float)n<<endl;
}
int main()
{
	int p[] = {1,2,3};
	int n = sizeof(p)/sizeof(p[0]);
	int bt[] = {5,9,6};
	int at[] = {0,3,6);
	AT(p,n,bt,at);
	return 0; 
}
