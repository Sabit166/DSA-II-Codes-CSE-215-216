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
    double credits;
    Student()
    {
        
    }
};

bool compare(Student *a, Student *b)
{
    if(a->credits>=40 != b->credits>=40) return a->credits>=40;
    if(a->credits>=40) return a->dsa > b->dsa;
    return a->c > b->c;
}

void swap(Student *a, Student* b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}


int partition(Student arr[], int low, int high)
{
    Student pivot = arr[high];
    int i = low;

    for(int j=low; j<high; j++)
    {
        if(compare(&arr[j], &pivot))
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quickSort(int low, int high, Student arr[])
{
    if(low >= high) return;
    int pi = partition(arr, low, high);
    quickSort(low, pi-1, arr);
    quickSort(pi+1, high, arr);
}

int main()
{
    int inputSize;
    //cout << "Enter the number of students: ";
    cin >> inputSize;
    Student students[inputSize];
    for(int i=0;i<inputSize; i++)
    {
        //cout << "Enter in the format: Name Roll DSA Marks C Marks Credits" << endl;
        cin >> students[i].name >> students[i].roll >> students[i].dsa >> students[i].c >> students[i].credits;
    }
    quickSort(0, inputSize-1, students);
    for(int i=0;i<inputSize;i++)
    {
        cout << students[i].name << endl;
    }
    return 0;
}