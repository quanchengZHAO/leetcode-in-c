#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares_TimeLimitExceeded(int *nums, int numsSize, int *returnSize);

int *sortedSquares(int *nums, int numsSize, int *returnSize);

int main()
{
    int nums[5] = {-4,-1,0,3,10};
    int returnSize = 0;
    int *result = sortedSquares(nums, 5, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d : %d \n", i, *(result+i));
    }
    free(result);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/**
 * @brief Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 *
 * First solution uses classic bubble sort.  Test cases passed, but took too long.
 *
 * Time comlexcity: O(n²)
 *
 * Space complexity: O(1N)
 * @param nums
 * @param numsSize
 * @param returnSize
 * @return int*
 */
int *sortedSquares_TimeLimitExceeded(int *nums, int numsSize, int *returnSize)
{
    int *result = malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        result[i] = nums[i] * nums[i];
    }

    // Bubble sort
    for (int i = 0; i < numsSize - 1; i++)
    {
        // Last i elements are already in place
        for (int j = 0; j < numsSize - i - 1; j++)
            if (result[j] > result[j + 1])
                swap(&result[j], &result[j + 1]);
    }

    return result;
}

void absMerge(int *nums, int l, int m, int r)
{
    int i, j, k;
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int *leftArray = malloc(leftSize * sizeof(int));
    int *rightArray = malloc(rightSize * sizeof(int));

    for (i = 0; i < leftSize; i++)
    {
        leftArray[i] = abs(nums[l + i]);
    }
    for (j = 0; j < leftSize; j++)
    {
        rightArray[j] = abs(nums[m + 1 + j]);
    }
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            nums[k] = leftArray[i];
            i++;
        }
        else
        {
            nums[k] = rightArray[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < leftSize)
    {
        nums[k] = leftArray[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < rightSize)
    {
        nums[k] = rightArray[j];
        j++;
        k++;
    }
}

void absMergeSort(int *nums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        absMergeSort(nums, left, mid);
        absMergeSort(nums, mid + 1, right);

        absMerge(nums, left, mid, right);
    }
}

/**
 * @brief Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 *
 * Sort the array with divide and conquer
 *
 * Time comlexcity: O(n²)
 *
 * Space complexity: O(1N)
 * @param nums
 * @param numsSize
 * @param returnSize
 * @return int*
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int *result = malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    absMergeSort(nums, 0, numsSize - 1);

    for (int i = 0; i < numsSize; i++)
    {
        result[i] = nums[i] * nums[i];
    }
    return result;
}
