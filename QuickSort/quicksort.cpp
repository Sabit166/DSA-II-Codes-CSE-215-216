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

int partition_first(int arr[], int low, int high)
{
    int pivot = arr[low]; // First element as pivot
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

int partition_middle(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]); // Move pivot to end
    int pivot = arr[high]; 
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int median_of_three(int arr[], int a, int b, int c)
{
    if ((arr[a] > arr[b]) != (arr[a] > arr[c])) return a;
    else if ((arr[b] > arr[a]) != (arr[b] > arr[c])) return b;
    else return c;
}

int partition_median_of_three(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    int pivotIndex = median_of_three(arr, low, mid, high);
    swap(arr[pivotIndex], arr[high]); // Move pivot to end
    int pivot = arr[high]; 
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

#include <cstdlib> // For rand()

int partition_random(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]); // Move pivot to end
    int pivot = arr[high]; 
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int partition_one_third_ratio(int arr[], int low, int high)
{
    int len = high - low + 1;
    int pivotIndex = low + len / 3; // Choose a pivot that gives a 1:2 ratio

    swap(arr[pivotIndex], arr[high]); // Move pivot to end
    int pivot = arr[high]; 
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}


void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pi = partition(arr, low, high);
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