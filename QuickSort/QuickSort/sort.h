#include <iostream>
#include <string>
using namespace std;

void swap(string* a, string* b)
{
    string t = *a;
    *a = *b;
    *b = t;
}


int partition (string arr[], int low, int high)
{
    string pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high- 1; j++)
    {if (arr[j] <= pivot)
    {
        i++;
        swap(&arr[i], &arr[j]);
    }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(string arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(string arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << endl;
}
