#include <bits/stdc++.h>
using namespace std;
struct node{
    node *next[10];

    bool endp;

    node()
    {
        //cout<<"FF"<< endl;
        for(int i = 0; i < 10; i++)
            next[i] = NULL;

        endp = false;
    }
} *root;
void inserts (char *s, int len)
{
    node *curr = root;

    for(int i = 0; i < len; i++)
    {
        int in =  s[i] - '0';
        if(curr -> next[in] == NULL)
        {
            curr->next[in] = new node();
        }
        curr  = curr->next[in];
    }
    curr->endp = true;

}
bool searchs (char *s, int len)
{
    node *curr = root;

    for(int i = 0; i < len; i++)
    {
        int in =  s[i] - '0';

        if(curr->next[in] == NULL)
        {
            return false;
        }
        curr = curr->next[in];
    }

    if(curr->endp == true)
    {
        for(int i = 0; i < 10; i++)
        {
            if(curr->next[i] != NULL)
            {
                return true;
            }
        }
    }
    return false;
}
void del(node *curr)
{
    for(int i = 0; i < 10; i++)
        if(curr->next[i])
           del(curr->next[i]);
    delete(curr);
}
char s[10005][505];


int main()
{
    int tes,o = 0;

    scanf("%d", &tes);
    while(tes--)
    {
        o++;
        int n;
        root = new node();

        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%s", s[i]);
            inserts(s[i], strlen(s[i]));
        }
        bool fl = 0;
        for(int i = 0; i < n; i++)
        {
            if(searchs(s[i] , strlen(s[i])) == true)
            {
                fl =1;
                break;
            }
        }
        if(fl)
            printf("Case %d: NO\n",o);
        else
            printf("Case %d: YES\n",o);
        del(root);

    }
}
