#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    bool isEnd;
    Node* children[26];
    int count;
    int maxcount;
    int maxcountindex;
    Node()
    {
        isEnd = false;
        count = 0;
        maxcount = 0;
        maxcountindex = -1;
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
    }
};

void insert(Node* root, string s)
{
    Node* temp = root;
    for(auto &it: s)
    {
        if(!temp->children[it - 'a'])
        {
            Node* newNode = new Node();
            temp->children[it - 'a'] = newNode;
        }
        temp->children[it - 'a']->count++;
        if(temp->children[it - 'a']->count >= temp->maxcount)
        {
            temp->maxcount = temp->children[it - 'a']->count;
            temp->maxcountindex = it - 'a';
        }
        temp = temp->children[it - 'a'];
    }
    temp->isEnd = true;
}

string best_DNA(Node* root)
{
    string ans = "";
    Node* temp = root;
    while(temp->maxcount == root->maxcount)
    {
        //cout << temp->maxcount << endl;;
        ans += (char)(temp->maxcountindex + 'a');
        temp = temp->children[temp->maxcountindex];
        if(!temp) break;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    Node* root = new Node();
    while(n--)
    {
        int type;
        string s;
        cin >> type;
        if(type == 1)
        {
            cin >> s;
            insert(root, s);
        }
        else{
            cout << best_DNA(root) << endl;
        }
    }
}