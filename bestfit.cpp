#include<iostream>
using namespace std;

int main()
{
	int bs[10],ps[10],m,n,i,j;
	cout<<"\n Enter number of blocks : ";
	cin>>m;
	cout<<"\n Enter sizes of blocks : ";
    for(i=0;i<m;i++)
    cin>>bs[i];
    cout<<"\n Enter number of processes : ";
	cin>>n;
	cout<<"\n Enter sizes of processes : ";
    for(i=0;i<n;i++)
    cin>>ps[i];
    
    int allot[10];
    for(i=0;i<n;i++)
    allot[i]=-1;
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
    	{
    		if(bs[j]>=ps[i])
    		{
    			if(allot[i]==-1)
    			allot[i]=j;
    			else if(bs[j]<=bs[allot[i]])
    			allot[i]=j;
			}
		}
		if(allot[i]!=-1)
		bs[allot[i]]-=ps[i];
	}
	
	for(i=0;i<n;i++)
	{
		if(allot[i]==-1)
		cout<<"\n Not alloted ";
		else
		cout<<"\n"<<allot[i]+1;
	}
}
