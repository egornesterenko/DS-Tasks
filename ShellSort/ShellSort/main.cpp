#include "sort.h"
using namespace std;

int main() {
    string arr[] = {"Shevchenko", "Ovcharenko", "Ardrusil", "Bulgakov", "Anohin", "Budda", "Aria", "Arai"};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    cout << endl;
    ShellsSort(arr, n);
    printArray(arr, n);
    return 0;
}
