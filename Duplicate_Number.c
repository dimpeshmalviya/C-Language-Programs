#include <stdio.h>

int findDuplicate(int *nums, int n) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    int nums[] = {3, 1, 3, 4, 2};
    int n = sizeof(nums)/sizeof(nums[0]) - 1;
    printf("%d\n", findDuplicate(nums, n));
}