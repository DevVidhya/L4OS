#include<iostream>
using namespace std;

int main()
{
	int bt[100],i,j,n,wt[100],tat[100],at[10],st[10];
	cout<<"\n ENter number of processes : ";
	cin>>n;
	cout<<"\n Enter burst time : ";
	for(i=0;i<n;i++)
	cin>>bt[i];
	cout<<"\n Enter arrival time : ";
	for(i=0;i<n;i++)
	cin>>at[i];
	
	st[0]=0;
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		st[i]=st[i-1]+bt[i-1];
		wt[i]=st[i]-at[i];
		
		if(wt[i]<0)
		wt[i]=0;
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
	
	 for (int i = 0 ; i < n ; i++) 
    {  
        int compl_time = tat[i] + at[i]; 
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i]  <<  "\t\t " << compl_time << endl; 
    } 
	
	cout<<"\n";
	cout<<"avg wt : "<<awt<<" avg tat : "<<atat;
}
