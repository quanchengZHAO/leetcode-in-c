#include<stdlib.h>
#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(numsSize*sizeof(int));
    int sum = 0;

    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        result[i] = sum;
    }
    return result;
}

int main() {
    int nums[5] = {1,1,1,1,1};
    runningSum(nums, 5, nums);
}

