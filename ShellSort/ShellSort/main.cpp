#include "sort.h"
using namespace std;

int main() {
    string arr[] = {"Shevchenko", "Ovcharenko", "Ardrusil", "Bulgakov", "Anohin", "Duadar", "Nesterenko", "Bilous", "Bondar", "Delieva", "Afanasuk", "Lenska", "Karkadim", "Drake", "As"};
    cout<< "Not sorted array:"<< endl;
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    cout << endl << endl;
    ShellsSort(arr, n);
    cout<< "Sorted array:"<< endl;
    printArray(arr, n);
    cout << endl << endl;
    return 0;
}
