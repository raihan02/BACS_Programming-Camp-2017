#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int cost[1005];
int wt[1005];
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
     int tes;
     cin >> tes;

     while(tes--)
     {
         memset(dp,-1,sizeof dp);
         int n;
         cin >> n;

         for(int i = 0; i < n; i++)
         {
             cin >> cost[i] >> wt[i];
         }
         int q,r;
         cin >> q>> r;
         int sum = 0;
         if(call(q,n) >=  r)
            cout<<"Missao completada com sucesso"<< endl;
         else
            cout<<"Falha na missao"<< endl;

     }
}

