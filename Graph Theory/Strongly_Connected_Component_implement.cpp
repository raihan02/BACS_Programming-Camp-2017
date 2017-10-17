#include <bits/stdc++.h>
using namespace std;
vector <int> g[100];
vector<int> rev[100];
vector <int> dc;
vector <int> vv[100];
bool vis[100] = {0};
int com[100];
int in[100];
void init ()
{
    for(int i = 0; i < 100; i++)
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
    init();
    int n, e;
    cin >> n >> e;


    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rev[b].push_back(a);

    }

    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; i++)
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

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            int v = g[i][j];

            if(com[i] != com[v])
                in[com[v]]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        vv[com[i]].push_back(i);
    }

    for(int i = 1; i <= cnt; i++)
    {
        cout<<i << " ";
        for(int j = 0; j < vv[i].size(); j++)
        {
            cout<< vv[i][j] << " ";

            if(j == vv[i].size() - 1)
                cout<<"Indegree = " << in[i];
        }
        cout<< endl;
    }

}
