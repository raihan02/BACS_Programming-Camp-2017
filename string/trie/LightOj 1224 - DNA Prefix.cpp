#include <bits/stdc++.h>
using namespace std;
map <char, int> mp;
int freq[100002] = {0};
struct node
{
    node *next[4];
    bool endp;
    int cnt;
    node()
    {
        cnt = 0;
        for(int i = 0; i < 4; i++)
            next[i] = NULL;

        endp = false;
    }
} *root;

void inserts (char *s, int len)
{
    node *curr = root;

    for(int i = 0; i < len; i++)
    {
        int in =  mp[s[i]];

        //cout<<in<< endl;
        if(curr->next[in] == NULL)
        {
            curr->next[in] = new node();
        }
        curr = curr->next[in];
    }

    curr->endp = true;
}
set <int> st;
int sp = 0, ans = 0;
int searchs (char *s, int len)
{
    node *curr = root;
    int x = 0,p;
    int mx = -1;
    int cnt = 0;
    for(int i = 0; i < len; i++)
    {

        int id = mp[s[i]];

        if(curr->next[id] == NULL)
        {
            return 0;
        }
        curr = curr->next[id];
        cnt++;
        curr->cnt++;
        x = curr->cnt;
       mx = (i + 1)*x;
       ans = max(ans, mx);

    }

    sp = max(len, ans);
    return sp;

}
void del(node *curr)
{
    for(int i = 0; i < 4; i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}
char s[50005][52];
int main()
{

    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;

    int tes,  o  =0;
    scanf("%d", &tes);
    while(tes--)
    {
        memset(freq,0,sizeof freq);
        o++;
        root = new node();
        int n;
        scanf("%d", &n);
        st.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%s",s[i]);

            inserts(s[i], strlen(s[i]));
        }
        int len = -1;
        sp = 0,ans = 0;
        for(int i = 0; i < n; i++)
        {

            searchs(s[i], strlen(s[i]));
            int x = strlen(s[i]);
            if(len < x)
                len = strlen(s[i]);
        }

        printf("Case %d: %d\n",o, ans);
        del(root);



    }
}
