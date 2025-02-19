#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
            cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
        }
    }
    swap(&arr[i], &arr[high]);
    cout << " finally Swapping " << arr[i] << " and " << arr[high] << endl;
    return i;
}

int partitionLowPivot(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = high;

    for (int j = high; j > low; j--)
    {
        if (arr[j] > pivot)
        {
            swap(&arr[i], &arr[j]);
            i--;
            cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
        }
    }
    swap(&arr[i], &arr[low]);
    cout << " finally Swapping " << arr[i] << " and " << arr[low] << endl;
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pi = partitionLowPivot(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}