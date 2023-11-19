#include<iostream>
#include<vector>
using namespace std;

int solve(int index,int wt,vector<int>&value,vector<int>&weight,vector<vector<int > >&dp)

{
	if(index==0)
	{
		if(wt-weight[0]>=0)
		{
			return value[0];
		}
		else
		{
			return 0;
		}
	}

	if(dp[index][wt]!=-1)
	{
		return dp[index][wt];
	}

	int nontake,take=INT_MIN;
	nontake=solve(index-1,wt,value,weight,dp);

	if(wt-weight[index]>=0)
	{
		take=value[index]+solve(index-1,wt-weight[index],value,weight,dp);
	}
	return dp[index][wt]=max(nontake,take);
}
int main()
{
	
	int n,wt;
	cout<<"Enter the number of items:\n";
	cin>>n;

	cout<<"Enter the weight of the bag:\n";
	cin>>wt;

	vector<int>weight(n),value(n);
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
    }

	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}

	vector<vector<int > >dp(n,vector<int>(wt+1,-1));
	int maxi=solve(n-1,wt,value,weight,dp);
	cout<<"Maximum value is: "<<maxi;
	return 0;

}
