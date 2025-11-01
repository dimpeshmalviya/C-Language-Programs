#include <iostream>
using namespace std;

void Merge(int arr[], int s, int e) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;

    for (int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }
    for (int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    int index1 = 0;
    int index2 = 0;
    int mainArrayIndex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] > second[index2]) {
            arr[mainArrayIndex++] = second[index2++];
        } else {
            arr[mainArrayIndex++] = first[index1++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void MergeSort(int arr[], int s, int e) {
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    MergeSort(arr, s, mid);
    MergeSort(arr, mid + 1, e);

    Merge(arr, s, e);
}

int main() {
    int arr[] = {7, 6, 2, 1, 9, 0, 5};
    int n = 7;
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}