#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < n && arr[leftchild] > arr[largest])
        largest = leftchild;

    if (rightchild < n && arr[rightchild] > arr[largest])
        largest = rightchild;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {7, 6, 2, 1, 9, 0, 5};
    int n = 7;
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}