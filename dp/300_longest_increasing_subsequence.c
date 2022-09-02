#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int lengthOfLIS(int *nums, int numsSize);

int main()
{
    int nums[6] = {0, 1, 0, 3, 2, 3};
    printf("Longest Increasing Subsequence %d\n", lengthOfLIS(nums, 6));
    return 0;
}

int recursionLIS(int *nums, int i, int *dp)
{
    if (dp[i] != 0)
    {
        return dp[i]; // subproblem has been solved
    }
    int a = 1; // By default, it has one incresing subsequence
    for (int j = 0; j < i; j++)
    {
        if (nums[j] < nums[i])
        {
            a = MAX(a, recursionLIS(nums, j, dp) + 1);
        }
    }
    dp[i] = a;
    return a;
}

int lengthOfLIS(int *nums, int numsSize)
{
    int result = 0;
    int *dp = malloc(numsSize * sizeof(int));
    memset(dp, 0, numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        result = MAX(result, recursionLIS(nums, i, dp));
    }
    free(dp);
    return result;
}
