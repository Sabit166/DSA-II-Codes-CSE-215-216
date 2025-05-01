#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;
    bool isMinHeap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        if (index > 0 && compare(heap[index], heap[parent(index)])) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int smallestOrLargest = index;

        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && compare(heap[left], heap[smallestOrLargest])) {
            smallestOrLargest = left;
        }

        if (right < size && compare
            (heap[right], heap[smallestOrLargest])) {
            smallestOrLargest = right;
        }

        if (smallestOrLargest != index) {
            swap(heap[index], heap[smallestOrLargest]);
            heapifyDown(smallestOrLargest);
        }
    }

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;
    }

public:
    Heap(bool minHeap = true) : isMinHeap(minHeap) {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractTop() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return top;
    }

    int peekTop() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap minHeap(true); // Min-Heap
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);

    cout << "Min-Heap: ";
    minHeap.printHeap();

    cout << "Extracted Top: " << minHeap.extractTop() << endl;
    cout << "Min-Heap after extraction: ";
    minHeap.printHeap();

    Heap maxHeap(false); // Max-Heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);

    cout << "Max-Heap: ";
    maxHeap.printHeap();

    cout << "Extracted Top: " << maxHeap.extractTop() << endl;
    cout << "Max-Heap after extraction: ";
    maxHeap.printHeap();

    return 0;
}