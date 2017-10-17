#include <bits/stdc++.h>
using namespace std;
vector <int> g[2005];
vector<int> rev[2005];
vector <int> dc;
vector <int> vv[2005];
bool vis[2005] = {0};
int com[2005];
int in[2005];
int n;
void init ()
{
    for(int i = 0; i <= n; i++)
    {
        rev[i].clear();
        g[i].clear();
        vv[i].clear();

    }
    memset(com,0, sizeof com);
    dc.clear();
    memset(in,0,sizeof in);
}
void dfs (int u)
{
    vis[u] =1;

    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];

        if(vis[v] == 0)
            dfs(v);
    }
    dc.push_back(u);
}

void dfs1 (int u, int cnt)
{
    vis[u] = 1;
    com[u] = cnt;
    for(int i = 0;  i < rev[u].size(); i++)
    {
        int v = rev[u][i];

        if(vis[v] == 0)
            dfs1(v, cnt);
    }
}

int main()
{

    int  e,tt=0;
    while(cin >> n >> e)
    {
        if(n == 0 && e == 0)
            break;
        init();
        int o = 0;
        for(int i = 0; i < e; i++)
        {
             int a, b , p;
             cin >>a >> b >> p;
             if(p == 1)
             {
                 g[a].push_back(b);
                 rev[b].push_back(a);
             }
             if(p == 2)
             {
                 g[a].push_back(b);
                 rev[b].push_back(a);
                 g[b].push_back(a);
                 rev[a].push_back(b);
             }

        }

        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; i++)
        {
            if(vis[i] == 0)
                dfs(i);
        }
        reverse(dc.begin(), dc.end());
        int cnt = 0;
        memset(vis, false, sizeof vis);
        for(int i = 0; i < dc.size(); i++)
        {
            if(vis[dc[i]] == 0)
            {
                dfs1(dc[i], ++cnt);
            }
        }

        if(cnt == 1)
            cout<<1<< endl;
        else
            cout<<0<< endl;

    }

}
