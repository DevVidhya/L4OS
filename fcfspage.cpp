#include<iostream>
using namespace std;

int main()
{
	int i,j,fs,pg[100],index=0,hit=0,miss=0,n;
	cout<<"\n Enter frame size : ";
	cin>>fs;
	cout<<"\n Enter number of references : ";
	cin>>n;
	cout<<"\n Enter page numbers : ";
	for(i=0;i<n;i++)
	cin>>pg[i];
	
	int frame[fs];
	for(i=0;i<fs;i++)
	frame[i]=-1;
	
	for(i=0;i<n;i++)
	{
		if(frame[index]==-1)
		{
			frame[index]=pg[i];
			miss++;
			index=(index+1)%fs;
		}
		else
		{
			int avail=0;
			for(j=0;j<fs;j++)
			if(frame[j]==pg[i])
			{
				hit++;
				avail=1;
			}
			if(avail==1)
			continue;
			    frame[index]=pg[i];
			    index=(index+1)%fs;
			    miss++;
		}
	}
	
	cout<<"hits : "<<hit<<"\t miss : "<<miss;
}
