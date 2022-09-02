#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findNumbers(int *nums, int numsSize);

bool isEven(int i)
{
    return (i ^ 1) == (i + 1);
}

int countDigits(int num)
{
    int digits = 0;
    while (num != 0)
    {
        num /= 10;
        digits++;
    }
    return digits;
}

int main()
{
    int num[5] = {12, 345, 2, 6, 7896};
    printf("Idems = %d \n", findNumbers(num, 5));
}

/**
 * @brief
 * Given an array nums of integers, return how many of them contain an even number of digits.
 * 
 * Time complexity O(n) 
 * Space complexity O(1) 
 * @param nums
 * @param numsSize
 * @return int
 */
int findNumbers(int *nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int digits = countDigits(nums[i]);
        if (isEven(digits))
        {
            result++;
        }
    }
    return result;
}
