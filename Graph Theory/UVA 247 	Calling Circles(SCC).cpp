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

    int n, e,tt=0;
    while(cin >> n >> e)
    {


        if(n == 0 && e == 0)
            break;

        if(tt)
            printf("\n");
        printf("Calling circles for data set %d:\n", ++tt);
        init();
        map <string, int> mp;
        map <string, int> :: iterator it;
        int o = 0;
        for(int i = 0; i < e; i++)
        {
            string a, b;
            cin >> a >> b;
            if(mp.find(a) == mp.end())
                mp[a] = o++;
            if(mp.find(b) == mp.end())
                mp[b] = o++;
            g[mp[a]].push_back(mp[b]);
            rev[mp[b]].push_back(mp[a]);

        }
        map <int, string> mp1;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            //cout<<it->first << " " <<it ->second << endl;
            mp1[it->second] = it->first;
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
        int f = 0;
        for(int i = 1; i <= cnt; i++)
        {
            f = 0;
            for(int j = 0; j < vv[i].size(); j++)
            {
                if(f)
                    printf(", ");

                cout<<mp1[vv[i][j]];
                f++;

            }

            cout<< endl;

        }
        mp1.clear();
        mp.clear();
        tt =1;
    }

}
