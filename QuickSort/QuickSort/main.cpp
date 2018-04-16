#include "sort.h"

using namespace std;

int main()
{
    string arr[] = {"Shevchenko", "Ovcharenko", "Ardrusil", "Bulgakov", "Anohin", "Duadar", "Nesterenko", "Bilous", "Bondar", "Delieva", "Afanasuk", "Lenska", "Karkadim", "Drake", "As"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< "Not sorted array:"<< endl;
    printArray(arr, n);
    cout << endl << endl;
    quickSort(arr, 0, n-1);
    cout<< "Sorted array:"<< endl;
    printArray(arr, n);
    cout << endl << endl;
    return 0;
}
