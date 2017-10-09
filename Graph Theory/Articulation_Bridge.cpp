/**
Name: Raihan Chowdhury
International Islamic University Chittagong 
Department of CSE, IIUC 
Topics: Articulation Bridge by dfs 
**/
#include <bits/stdc++.h>
using namespace std;
int dis[1000];
int low[1000];
bool visit[1000];
int parent[10000];
vector <int> node[1000];
vector<pair <int, int > > ap;
int timer;
void dfs(int u)
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


            if(low[v] > dis[u])
                ap.push_back(make_pair(u, v));
        }
        else if(v != parent[u])
            low[u] = min(low[u], dis[v]);
    }
}
int main()
{
    memset(parent, -1, sizeof parent);
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }


    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == false)
            dfs(i);
    }


    for(int i = 0; i < ap.size(); i++)
        cout<< ap[i].first  << " " << ap[i].second << endl;

    cout<< endl;
}

/*
    5 5

    1 2
    2 3
    3 1
    1 4
    4 5


    output 1 4

*/
