/*
Amarzone, a Bangladeshi child company of the giant Amazon, is recruiting students from MIST, CSE. To help with the recruitment, they have structured the information of the students in a very specific way and decided to sort the students based on “how good of a programmer” they are.

Structure of a student includes:
Name
Roll
Marks in DSA Course (in 100%)
Marks in C programming course (in 100%)
Total earned credits

The students with total credits >=40 are considered better programmers than those with <40. Among the students whose total earned credits is <40, sort based on the “Marks in C programming course”. Among the students whose total earned credits is >=40, sort based on the “Marks in DSA Course”.

Take necessary information of N such students as input. Then print the “Name” of the students in ascending/descending order as output.

Note: Input/Output Case is not mentioned so assume input/output format.
*/
#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int roll;
    int dsa;
    int c;
    int credits;
};

bool compare(Student* a, Student* b)
{
    if(a->credits >= 40 != b->credits >= 40) return a->credits >=40;
    if(a->credits>=40) return a->dsa > b->dsa;
    return a->c > b->c;
}

void merge(Student arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Student left[n1], right[n2];

    for(int i=0;i<n1;i++)
    {
        left[i] = arr[low+i];
    }

    for(int i=0;i<n2;i++)
    {
        right[i] = arr[mid+1+i];
    }
    int i=0, j=0, k = low;

    while(i<n1 && j<n2)
    {
        if(compare(&left[i], &right[j]))
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(Student arr[], int low, int high)
{
    if(low >= high) return;
    int mid = low + (high - low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int n;
    cin >> n;
    Student s[n];
    for(int i=0;i<n;i++)
    {
        cin >> s[i].name >> s[i].roll >> s[i].dsa >> s[i].c >> s[i].credits;
    }
    mergeSort(s, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout << s[i].name << endl;
    }
}