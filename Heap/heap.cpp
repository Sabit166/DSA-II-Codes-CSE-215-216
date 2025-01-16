#include <bits/stdc++.h>
using namespace std;
#define int long long


class Heap
{
    vector<int>heap;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2*i + 1;
    }

    int right(int i)
    {
        return 2*i + 2;
    }

    void heapify_up(int i)
    {
        if(i && heap[i] > heap[parent(i)])
        {
            swap(heap[i], heap[parent(i)]);
            heapify_up(parent(i));
        }
    }

    void heapify_down(int i)
    {
        int largest = heap[i];
        if(left(i) < heap.size() && )
    }

    public:
    void insert(int n)
    {
        heap.push_back(n);
        heapify_up(heap.size() -1 );
    }

    void delete_max()
    {
        if(!heap.size())
        {
            cout << "Heap empty.\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }
};

signed main() {

}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/