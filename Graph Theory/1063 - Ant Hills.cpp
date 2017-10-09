

/**
Name: Raihan Chowdhury
International Islamic University Chittagong 
Department of CSE, IIUC 
Topics: Articulation Point by dfs 
**/

#include <bits/stdc++.h>
using namespace std;
bool visit[20005];
int dis[20005];
int low[20005];
vector <int> node[20005];
int timer;
int parent[20005];
set <int> ap;
int cnt;

void dfs (int u)
{
    dis[u] = low[u] = ++timer;
    visit[u] = true;
    int v;
    int children = 0;
    for(int i = 0; i < node[u].size(); i++)
    {
        v = node[u][i];
        if(!visit[v])
        {
            children++;
            parent[v] = u;
            dfs(v);
            /// if backedge is found

            low[u] = min(low[u], low[v]);

            /// special condition , if u is root  and u has many child , then u is AP
            if(parent[u] == -1 && children > 1){
               // ap.push_back(u);
                ap.insert(u);
                cnt++;

            }
            /// if root has not many child

            if(parent[u] != -1 && low[v] >= dis[u]){
                ap.insert(u);
              cnt++;
            }
        }
        else if(v != parent[u])
            low[u] = min(low[u], dis[v]);
    }

}

int main()
{
    int tes, o =0;
    scanf("%d", &tes);
    while(tes--)
    {
        memset(visit, false, sizeof visit);
        memset(low, 0, sizeof low);
        memset(dis, 0, sizeof dis);
        memset(parent, -1, sizeof parent);
        o++;
        int n, e;
        scanf("%d %d", &n, &e);
        for(int i = 1; i <= e; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            node[u].push_back(v);
            node[v].push_back(u);
        }
        timer= 0;
        cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(visit[i] == false){
                dfs(i);
            }
        }

        printf("Case %d: %d\n", o, ap.size());
        ap.clear();

        for(int i = 1; i <= n; i++)
            node[i].clear();


    }
}
