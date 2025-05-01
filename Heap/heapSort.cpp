#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void heapify_down(int i, int n) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && heap[l] > heap[largest])
            largest = l;

        if (r < n && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify_down(largest, n);
        }
    }

    void buildHeap(vector<int>& arr) {
        heap = arr;
        int n = heap.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify_down(i, n);
        }
    }

public:
    void heapSort(vector<int>& arr) {
        buildHeap(arr);
        int n = heap.size();
        for (int i = n - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapify_down(0, i);
        }
        arr = heap;
    }
};

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    Heap h;
    h.heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);
    return 0;
}