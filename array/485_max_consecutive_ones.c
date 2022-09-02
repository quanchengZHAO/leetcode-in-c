#include<stdlib.h>
#include<stdio.h>
int findMaxConsecutiveOnes(int* nums, int numsSize);

int main() {
    int nums[6] = {1,1,0,1,1,1};
    printf("nums size is %d\n", findMaxConsecutiveOnes(nums, 6));
    return 0;
}

/**
 * @brief 
 * Given a binary array nums, return the maximum number of consecutive 1's in the array.
 * 
 * @param nums 
 * @param numsSize 
 * @return int 
 */
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int currentMax = 0;
    int lastMax = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 1) {
            currentMax++;
        } else if (currentMax > lastMax) {
            lastMax = currentMax;
            currentMax = 0;
        } else {
            currentMax = 0;
        }
    }
    return currentMax > lastMax ? currentMax : lastMax;
}