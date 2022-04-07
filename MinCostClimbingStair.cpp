#include<iostream>
#include<vector>
#include<climits>
using namespace std;
/*
//BRUTE FORCE
int minCostClimbingStairsHelper(int *cost,int n)
{
    if(n<=0)
    {
        return 0;
    }
    if(n==1)
    {
        return cost[n-1];
    }
    int ans1=minCostClimbingStairsHelper(cost+1,n-1);
    int ans2=minCostClimbingStairsHelper(cost+2,n-2);
    return min(ans1,ans2)+cost[0];

}
int minCostClimbingStairs(int *cost,int n)
{
    return min(minCostClimbingStairsHelper(cost,n),minCostClimbingStairsHelper(cost+1,n-1));
}
*/




//DP

int minCostClimbingStairs(int *cost,int n)
{
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=cost[n-1];
    for(int i=2;i<=n;i++)
    {
        ans[i]=cost[n-i]+min(ans[i-1],ans[i-2]);
    }
    return min(ans[n],ans[n-1]);
}

int main()
{
    int n;
    cin>>n;
    int cost[n];
    int i=0;
    while(i<n)
    {
        cin>>cost[i];
        i++;
    }
    cout<<minCostClimbingStairs(cost,n)<<endl;
    return 0;

}
