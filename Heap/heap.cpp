#include <bits/stdc++.h>
using namespace std;
#define int long long

class HeapMax
{
    vector<int>heap;

    int parent(int i)
    {
        return (i-1)/2;
    }

    int leftChild(int i)
    {
        return 2*i;
    }

    int rightChild(int i)
    {
        return 2*i + 1;
    }

    void heapify_up(int i)
    {

    }
};

int main() {
    
}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/