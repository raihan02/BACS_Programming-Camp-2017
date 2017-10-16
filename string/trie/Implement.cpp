#include <bits/stdc++.h>
using namespace std;
struct node{
   node *next[26];

   bool endofword;

   node()
   {
       for(int i = 0; i < 26; i++)
        next[i] = NULL;
       endofword = false;
   }

} *root;

void insertword (char *str , int len)
{
    node *curr = root;
    for(int i = 0; i < len; i++)
    {
        int key = str[i] - 'a';
        if(curr -> next[key] == NULL)
        {
            curr->next[key] = new node();
        }
        curr = curr -> next[key];
    }
    curr ->endofword = true;
}
bool searchword(char *str, int len)
{
    node *curr = root;
    for(int i = 0; i < len; i++)
    {
        int key = str[i] - 'a';

        if(curr -> next[key] == NULL)
        {
            return false;
        }
        curr = curr ->next[key];

    }
    return curr->endofword;
}

char ss[50000];
int id = 0;
void pp (node *curr)
{
    if(curr->endofword)
    {
        ss[id] = '\0';

        if(ss[0] != '\0')
            printf("%s\n",ss);
    }
    for(int i = 0; i < 26; i++)
    {
        if(curr -> next[i])
        {
            ss[id++] = i + 'a';
            pp(curr->next[i]);
            id--;
            ss[id] = '\0';
        }
    }
}
void del(node *curr)
{
    for(int i = 0; i < 26; i++)
    {
        if(curr-> next[i])
            del(curr -> next[i]);
    }
    delete(curr);
}
int main()
{
     root = new node();
     int n;
     cin >> n;
     char s[50000];

     for(int i = 0; i < n; i++)
     {
         scanf("%s", s);

         for(int j = 0; j < strlen(s); j++)
         {
             if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] = s[j] + 32;
         }

         insertword(s, strlen(s));
     }
     pp(root);
     int q;
     cin >> q;

     while(q--)
     {
         char s1[50000];
         scanf("%s", s1);

         if(searchword(s1, strlen(s1))== true )
            printf("Found\n");
         else
            printf("Not Found\n");
     }
