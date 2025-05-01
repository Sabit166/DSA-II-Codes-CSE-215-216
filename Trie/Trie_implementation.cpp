#include <bits/stdc++.h>
using namespace std;

struct Node
{
       bool EoW;
       Node *children[26];

       Node()
       {
              EoW = false;
              for (int i = 0; i < 26; i++)
              {
                     children[i] = nullptr;
              }
       }
};

class Trie
{
public:
       Node *root;

       Trie()
       {
              root = new Node();
       }

       void insert(string s)
       {
              Node *cur = root;
              for (int i = 0; i < s.size(); i++)
              {
                     int j = s[i] - 'a'; // relative position
                                         // small a a - a = 0
                                         // b, b - a = 1
                     if (cur->children[j] == nullptr)
                     { // dont have an edge for corrosponding alphabet, will have to create one
                            cur->children[j] = new Node();
                     }
                     cur = cur->children[j];
              }
              cur->EoW = true; // after whole string iteration done, word set so EoW set
       }

       void printt(Node *cur, string s = " ")
       {
              // like DFS
              // trie traverse and print all of the word
              // lexicographic order
              if (cur->EoW)
              {
                     // reached at the end of the word, so print the word
                     cout << s << endl;
              }
              for (int i = 0; i < 26; i++)
              { // iterate through all children
                     if (cur->children[i] == nullptr)
                            continue; // if null found skip

                     char ch = i + 'a'; // relative position of current char
                     // recursively call to print
                     printt(cur->children[i], s + ch);
              }
       }

       bool search(string s)
       {
              Node *cur = root;
              for (int i = 0; i < s.size(); i++)
              {
                     int j = s[i] - 'a';
                     if (cur->children[j] == nullptr)
                     {
                            return false;
                     }
                     cur = cur->children[j];
              }
              return cur->EoW;
       }

       bool delHelper(string s, Node *cur, int curSize)
       {
              if (!cur)
                     return false; // current node null, word not found
              if (curSize == s.size())
              { // reached at the end of the word
                     if (!cur->EoW)
                            return false; // word does not exist
                     if (!isLeaf(cur))
                     {                        // if current node not a leaf
                            cur->EoW = false; // unmark the word
                            return false;
                     }
                     return true; // current is leaf node
              }

              int j = s[curSize] - 'a'; // relative index for current
              if (delHelper(s, cur->children[j], curSize + 1))
                     removeEdge(cur, s[curSize], true); // remove the edge to the child node                        // recursively call delHelper for the next characters

              return !isJunction(cur); // if current node is a junction, can't be deleted
       }

       bool isLeaf(Node *cur)
       {
              for (int i = 0; i < 26; i++)
              {
                     if (cur->children[i])
                            return false; // child exists so not leaf
              }
              return true; // no child exists so leaf
       }

       bool isJunction(Node *cur)
       {
              if (cur->EoW == 1)
                     return true; // if at the end of the word then junction
              if (isLeaf(cur))
                     return false; // leaf not junction
              return true;
       }

       void removeEdge(Node *cur, char c, int flag)
       {
              if (flag == 0)
                     return;                // do nothing
              int j = c - 'a';              // relative index
              Node *del = cur->children[j]; // retrive the child node
              cur->children[j] = nullptr;   // remove edge to the child node
              delete del;                   // delete the child node
       }

       int deleteWord(string s)
       {
              return delHelper(s, root, 0); // call delete helper starting from root node
       }
};

int main()
{
       Trie t;
       int c;
       while (1)
       {
              cout << "1.Insert" << endl;
              cout << "2.Print" << endl;
              cout << "3.Search" << endl;
              cout << "4.Delete" << endl;
              cout << "Press any other to terminate." << endl;

              cout << "Enter your choice:" << endl;

              cin >> c;
              if (c == 1)
              {
                     string s;
                     cout << "Enter the word to be inserted:" << endl;
                     cin >> s;
                     t.insert(s);
              }
              else if (c == 2)
              {
                     t.printt(t.root);
              }
              else if (c == 3)
              {
                     cout << "Enter the word to be searched:";
                     string s;
                     cin >> s;
                     if (t.search(s))
                            cout << "Found" << endl;
                     else
                            cout << "Not found" << endl;
              }
              else if (c == 4)
              {
                     cout << "Enter the word to be deleted:" << endl;
                     string s;
                     cin >> s;
                     t.deleteWord(s);
              }
              else
              {
                     cout << "terminated";
                     break;
              }
       }
       return 0;
}