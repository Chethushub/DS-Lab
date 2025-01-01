#include <stdio.h>
void moveZeroes(int* nums, int numsSize) {
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
        }
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    moveZeroes(nums, numsSize);

    printf("\nModified array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}

