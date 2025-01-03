#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool wordEnd;
    Node *child[26];
    Node()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

void insert(Node* root, string s)
{
    Node *cur = root;
    for (auto &it : s)
    {
        if (!cur->child[it - 'a'])
        {
            Node *newNode = new Node();
            cur->child[it - 'a'] = newNode;
        }
        cur = cur->child[it - 'a'];
    }
    cur->wordEnd = true;
}

bool searchKey(Node* root, string s)
{
    if (!root)
        return false;

    Node *cur = root;
    for (auto &it : s)
    {
        cur = cur->child[it - 'a'];
        if (!cur)
            return false;
    }
    return cur->wordEnd;
}

bool isEmpty(Node* root)
{
    for(int i=0;i<26;i++)
    {
        if(root->child[i]) return false;
    }
    return true;
}

void display(Node* root, string s = "")
{
    if(root->wordEnd)
    {
        cout << s << endl;
    }

    for(int i=0;i<26;i++) if(root->child[i]) display(root->child[i], s+char('a' + i));
}

static Node *remove(Node* root, string s, int depth = 0)
{
    if(!root) return NULL;

    if(depth == s.size())
    {
        root->wordEnd = false;
        if(isEmpty(root))
        {
            delete root;
            root = NULL;
        }
        return root;
    }

    int index = s[depth] - 'a';
    root->child[index] = remove(root->child[index], s, depth+1);

    if(!root->wordEnd and isEmpty(root))
    {
        delete root;
        root = NULL;
    }
    return root;
}

void clear(Node* root)
{
    for(int i=0;i<26;i++) if(root->child[i]) clear(root->child[i]);
    delete root;
}


int main()
{
    Node* node = new Node();
    insert(node, "safi");
    //insert(node,"sabbir");

    if(searchKey(node, "mehu")) cout << "Word found.\n";
    else cout << "word not found.\n";

    //node = remove(node, "sabit");
    if(searchKey(node, "sabbir")) cout << "Word found.\n";
    else cout << "word not found.\n";
    insert(node, "sabit");

    display(node);
}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/