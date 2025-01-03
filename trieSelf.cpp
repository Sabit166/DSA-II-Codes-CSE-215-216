#include<bits/stdc++.h>
using namespace std;

struct Node{
       bool EoW;
       Node* children[26]; 

       Node(){
              //Node* n = (Node*)malloc(sizeof(Node));
              EoW = false;
              for(int i = 0; i < 26; i++) {
                     children[i] = nullptr;
              }
       }

};


class Trie {
       public:
       Node* root;

       Trie() {
              root = new Node();
       }

       void insert(string s) {
              Node* cur = root;
              for(int i = 0; i < s.size(); i++) {
                     int j = s[i] - 'a'; // relative position
              // small a a - a = 0
              // b, b - a = 1
                     if(cur -> children[j] == nullptr) { // dont have an edge for corrosponding alphabet, will have to create one
                            cur -> children[j] = new Node();
                     }
                     cur = cur -> children[j];
              }
              cur -> EoW = true;// after whole string iteration done, word set so EoW set
       }

       void printt(Node* cur, string s = " ") {
               //like DFS
       //trie traverse and print all of the word
       //lexicographic order
              if(cur -> EoW) { 
                     // reached at the end of the word, so print the word
                     cout << s << endl;
              }
              for(int i = 0; i < 26; i++) { // iterate through all children
                     if(cur -> children[i] == nullptr) continue; // if null found skip

                     char ch = i + 'a'; // relative position of current char
                     //recursively call to print
                     printt(cur -> children[i], s + ch);
              }

       }

       bool search(string s) {
              Node* cur = root;
              for(int i = 0; i < s.size(); i++) {
                     int j = s[i] - 'a';
                     if(cur -> children[j] ==nullptr) {
                            return false;
                     }
                     cur = cur -> children[j];
              }
              return cur -> EoW;
       }

       int delHelper(string s, Node* cur, int curSize) {
              if(cur == nullptr) return 0; //current node null, word not found
              if(curSize == s.size()) { // reached at the end of the word
                     if(cur -> EoW == false) return 0; //word does not exist
                     if(isLeaf(cur) == false) { // if current node not a leaf
                      // unmark the word
                      // so the word does not exist anymore
                      // in this way the word is deleted and the prefix which is same for other word is not destroyed
                            cur -> EoW = false;
                            return 0;
                     } 
                     return 1; // means that current is leaf node
              }

              int j = s[curSize] - 'a'; // relative index for current 
              // recursively call delHelper for the next characters
              int flag = delHelper(s, cur -> children[j], curSize + 1); 
              if(flag == 1) { // if child node can be deleted
                     removeEdge(cur, s[curSize], flag); // remove the edge to the child node
              }

              if(isJunction(cur)) return 0; // if current node is a junction, cant be deleted, so return 0;
              return flag; // flag will indicated how it will be deleted
       }

       bool isLeaf(Node* cur) {
              for(int i = 0; i < 26; i++) {
                     //child exists so not leaf
                     if(cur -> children[i] != nullptr) return false;

              }
              return true; // no child exists so leaf
       }

       bool isJunction(Node* cur) {
              if(cur -> EoW == 1) return true; // if at the edn of the word then junction
              if(isLeaf(cur)) return false; // leaf not junction
              return true;
       }

       void removeEdge(Node* cur, char c, int flag) {
              if(flag == 0) return; // do nothing
              int j = c - 'a'; // relative index
              Node* del = cur -> children[j]; //retrive the child node
              cur -> children[j] = nullptr; //remove edge to the child node
              delete del; // delete the child node

       }

       int deleteWord(string s) {
              return delHelper(s,root,0); // call delete helper starting from root node
       }


       

};

int main() {
       Trie t;
       int c;
       while(1) {
              cout << "1.Insert" << endl;
              cout << "2.Print" << endl;
              cout << "3.Search" << endl;
              cout << "4.Delete" << endl;
              cout << "Press any other to terminate." << endl;

              cout << "Enter your choice:" << endl;

              cin >> c;
              if(c == 1) {
                     string s;
                     cout << "Enter the word to be inserted:" << endl;
                     cin >> s;
                     t.insert(s);
              } else if( c == 2) {
                     t.printt(t.root);
              } else if(c == 3) {
                     cout << "Enter the word to be searched:";
                     string s;
                     cin >> s;
                    if( t.search(s)) cout << "Found" <<endl;
                    else cout << "Not found" << endl;
              }  else if(c == 4) {
                     cout << "Enter the word to be deleted:" << endl;
                     string s;
                     cin >> s;
                     t.deleteWord(s);

              } else {
                     cout << "terminated";
                     break;
                     
              }



       }
       return 0;
}