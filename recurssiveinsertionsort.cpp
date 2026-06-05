#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    if(n <= 1)
        return;

    insertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while(j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int main()
{
    int arr[] = {5, 3, 4, 1, 2};
    int n = 5;

    insertionSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
