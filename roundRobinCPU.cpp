#include<iostream>
using namespace std;

int main()
{
	int quantum=2,bt[10],n,i,j,rem[10],time=0,wt[10],tat[10];
	cout<<"\n Enter number of processes : ";
	cin>>n;
	cout<<"\n Enter burst times : ";
	for(i=0;i<n;i++)
	cin>>bt[i];
	
	for(i=0;i<n;i++)
	rem[i]=bt[i];
	
	int check;
	while(1)
	{
		check=1;
		for(i=0;i<n;i++)
		{
			if(rem[i]>0)
			{
				check=0;
				if(rem[i]>quantum)
				{
					time+=quantum;
					rem[i]-=quantum;
				}
				else
				{
					time+=rem[i];
					wt[i]=time-bt[i];
					rem[i]=0;
				}
			}
		}
		if(check==1)
		break;
	}
	
	for(i=0;i<n;i++)
	tat[i]=wt[i]+bt[i];
	
	int total=0,awt,atat;
	for(i=0;i<n;i++)
	total+=wt[i];
	
	awt=total/n;
	
	total=0;
	for(i=0;i<n;i++)
	total+=tat[i];
	
	atat=total/n;
	
	cout<<"\n";
	cout<<"avg wt : "<<awt<<" avg tat : "<<atat;
}
