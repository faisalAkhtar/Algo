/*
Given a set of +ve integers and a sum S, find out if there exists a subset whose sum is equal to given sum S using Dynamic Programming
*/

#include<iostream>

using namespace std;

bool issubset(int set[],int count,int sum)
{
	bool subset[count+1][sum+1];

	for(int i=0;i<=count;i++)
		subset[i][0]=true;

	for(int i=1;i<=sum;i++)
		subset[0][i]=false;

	for(int i=1;i<=count;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<set[i-1])
			subset[i][j]=subset[i-1][j];
			if(j>=set[i-1])
			subset[i][j]=subset[i-1][j]||subset[i-1][j-set[i-1]];
		}
	}

	for(int i=1;i<=count;i++)
	{
		for(int j=1;j<=sum;j++)
		cout<<subset[i][j];
		cout<<"\n";
	}
	return subset[count][sum];
}

int main()
{
	int count, sum=0;
	
	cout<<"\nEnter the count of numbers in a set:\n";
	cin>>count;
	int set[count];

	cout<<"\nEnter the elements in a set:\n";
	for(int i=0;i<count;i++)
	{
		cin>>set[i];
	}

	cout<<"The elements in a set are={ ";
	for(int i=0;i<count-1;i++)
	{
		cout<<set[i]<<",";
	}
	cout<<set[count-1]<<"}";

	cout<<"\nEnter the sum which you want to find:\n";
	cin>>sum;

	if(issubset(set,count,sum)==true)
		cout<<"Found a subset with a given sum";
	else
		cout<<"Subset not found";
	return 0;
}
