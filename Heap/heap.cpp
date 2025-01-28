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
        int largest = i;
        if(left(i) < heap.size() && heap[left(i)] > heap[largest])
        {
            largest = left(i);
        }
        if(right(i) < heap.size() && heap[right(i)] > heap[largest])
        {
            largest = right(i);
        }

        if(i != largest)
        {
            swap(heap[i], heap[largest]);
            heapify_down(largest);
        }
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
    Heap h;
    int choice, value;
    while (true) {
        cout << "1. Insert\n2. Delete Max\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                h.insert(value);
                break;
            case 2:
                h.delete_max();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/