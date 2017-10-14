#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int cost[100];
int wt[100];
int call (int cap , int n)
{
    if(n == 0 || cap == 0)
        return 0;
    if(dp[n][cap] != -1)
        return dp[n][cap];
    if(cap < wt[n - 1])
       dp[n][cap] =  call(cap, n - 1);
    else
        dp[n][cap] = max(cost[n - 1] + call(cap - wt[n - 1], n -1) , call(cap, n - 1));

     return dp[n][cap];
}
int main()
{
   memset(dp,-1,sizeof dp);

   int n;
   cin >> n;

   for(int i = 0; i < n; i++)
   {
       cin >> wt[i] >> cost[i];
   }
   int cap = 10;


   cout<<call(cap, n) << endl;
}

