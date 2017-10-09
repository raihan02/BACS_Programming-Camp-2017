/**
Name: Raihan Chowdhury
International Islamic University Chittagong 
Department of CSE, IIUC 
Topics: Articulation Bridge by dfs 
boundery case , u = min(u,v) , v = max(u,v) because of bi directional graph 
**/ 

#include <bits/stdc++.h>
using namespace std;
int dis[100005];
int low[100005];
bool visit[100005];
int parent[100005];
vector <int> node[100005];
vector<pair <int, int > > ap;
int timer;
void dfs(int u)
{
    dis[u] = low[u] = ++timer;
    visit[u] = true;
    int v;
    //int children = 0;
    for(int i = 0; i < node[u].size(); i++)
    {
        v = node[u][i];
        if(!visit[v])
        {
            //children++;
            parent[v] = u;
            dfs(v);
            /// if backedge is found

            low[u] = min(low[u], low[v]);


            if(low[v] > dis[u])
                ap.push_back(make_pair(min(u,v), max(u,v)));
        }
        else if(v != parent[u])
            low[u] = min(low[u], dis[v]);
    }
}
int main()
{
    int tes,o=0;
    scanf("%d", &tes);

    while(tes--)
    {
        o++;
        int n;

        scanf("%d", &n);

        if(n == 0)
        {

            printf("Case %d:\n",o);
            printf("0 critical links\n");
            continue;
        }
        memset(parent, -1 ,sizeof parent);
        memset(low, 0, sizeof low);
        memset(visit, false , sizeof visit);
        memset(dis, 0, sizeof dis);
        int a, b;
        string s;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            cin >> s;

            int sum = 0;

           for(int j = 0; j < s.size(); j++)
           {
               if(isdigit(s[j]))
               {
                   sum = sum * 10 + s[j] - '0';
               }
           }
           for(int i = 0; i < sum; i++)
           {
               scanf("%d", &b);
               node[a].push_back(b);
               node[b].push_back(a);
           }
        }
        timer = 0;
        for(int i = 0; i <= n; i++)
        {
            if(visit[i] == false)
                dfs(i);
        }
        printf("Case %d:\n",o);

        printf("%d critical links\n", ap.size());
         sort(ap.begin(), ap.end());
        for(int i = 0; i < ap.size(); i++)
        {
            cout<<ap[i].first << " - " << ap[i].second << endl;

        }
        ap.clear();

        for(int i = 0; i <= n; i++)
            node[i].clear();


    }


}

