// trapping_rain_water.c
#include <stdio.h>

int trap(int* height, int n) {
    if (n <= 2) return 0;
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) leftMax = height[left];
            else water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax) rightMax = height[right];
            else water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

int main() {
    int arr[] = {4,2,0,3,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Trapped water = %d\n", trap(arr,n)); // should print 9
    return 0;
}