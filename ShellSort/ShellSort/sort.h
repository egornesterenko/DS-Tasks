#include <iostream>
#include <string>

using namespace std;

void ShellsSort(string *arr, int N)
{
    int i,j,k;
    string t;
    for(k = N/2; k > 0; k /=2)
        for(i = k; i < N; i++){
            t = arr[i];
            for(j = i; j>=k; j-=k){
                if(t < arr[j-k])
                    arr[j] = arr[j-k];
                else
                    break;
            }
            arr[j] = t;
        }
}
void printArray(string *arr, int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
}
