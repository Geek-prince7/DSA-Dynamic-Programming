#include <iostream>
using namespace std;
//brute force
/*
int countWaysToMakeChange(int *denominations, int numDenominations, int value,bool *arr){
	//Write your code here
	if(value==0)
    {
        return 1;
    }
    if(value<0)
    {
        return 0;
    }
    int ans=0;
    for(int i=0;i<numDenominations;i++)
    {
        int j=i-1;
        while(j>=0)
        {
            arr[j]=true;
            j--;
        }
        if(!arr[i])
        {
            ans+=countWaysToMakeChange(denominations,numDenominations,value-denominations[i],arr);
        }
        j=i-1;
        while(j>=0)
        {
            arr[j]=false;
            j--;
        }
    }
    return ans;
}
int countWaysToMakeChange(int *denominations, int numDenominations, int value)
{
    bool *arr=new bool[numDenominations];
    for(int i=0;i<numDenominations;i++)
    {
        arr[i]=false;
    }
    return countWaysToMakeChange(denominations,numDenominations,value,arr);
}
*/
int countWaysToMakeChange(int *denominations, int numDenominations, int value)
{
    int *dp=new int[value+1];
    dp[0]=1;
    for(int i=1;i<=value;i++)
    {
        dp[i]=0;
    }
    for(int j=0;j<numDenominations;j++)
    {
        for(int i=1;i<=value;i++)
        {
            int k=i-denominations[j];
            if(k>=0)
            {
                dp[i]+=dp[k];
            }
        }
    }

    return dp[value];

}
int main()
{

	int numDenominations;
	cin >> numDenominations;

	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}
