// median_of_two_sorted_arrays.c
#include <stdio.h>
#include <limits.h>

// Return median of two sorted arrays
double findMedianSortedArrays(int* A, int m, int* B, int n) {
    // Ensure A is smaller
    if (m > n) return findMedianSortedArrays(B, n, A, m);

    int low = 0, high = m;
    while (low <= high) {
        int i = (low + high) / 2;      // partition A
        int j = (m + n + 1) / 2 - i;  // partition B

        int Aleft = (i == 0) ? INT_MIN : A[i-1];
        int Aright = (i == m) ? INT_MAX : A[i];
        int Bleft = (j == 0) ? INT_MIN : B[j-1];
        int Bright = (j == n) ? INT_MAX : B[j];

        if (Aleft <= Bright && Bleft <= Aright) {
            // found correct partition
            if ((m + n) % 2 == 0) {
                int leftMax = (Aleft > Bleft) ? Aleft : Bleft;
                int rightMin = (Aright < Bright) ? Aright : Bright;
                return ((double)leftMax + (double)rightMin) / 2.0;
            } else {
                int leftMax = (Aleft > Bleft) ? Aleft : Bleft;
                return (double)leftMax;
            }
        } else if (Aleft > Bright) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0; // should never reach here if inputs are valid
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    double median = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("Median = %.1f\n", median); // output 2.0

    int a[] = {1,2};
    int b[] = {3,4};
    printf("Median = %.1f\n", findMedianSortedArrays(a,2,b,2)); // 2.5
    return 0;
}