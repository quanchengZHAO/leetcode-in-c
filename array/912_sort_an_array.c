#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int numsSize, int *returnSize);

int main()
{
    //int nums[6] = {5,1,1,2,0,0};
    int nums[3] = {5,1,0};
    int returnSize = 0;
    int *result = sortArray(nums, 3, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d : %d \n", i, *(result+i));
    }
    free(result);
}

void merge(int *nums, int l, int m, int r)
{
    int i, j, k;
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int *leftArray = malloc(leftSize * sizeof(int));
    int *rightArray = malloc(rightSize * sizeof(int));
    printf("l : %d  - m : %d - r : %d\n",l, m, r);
    printf("leftSize : %d  - rightArray : %d\n",leftSize, rightSize);

    for (i = 0; i < leftSize; i++)
    {
        leftArray[i] = nums[l + i];
    }
    for (j = 0; j < rightSize; j++)
    {
        rightArray[j] = nums[m + 1 + j];
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

void mergeSort(int *nums, int left, int right)
{
    //printf("left : %d  - right : %d\n",left, right);
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

/**
 * @brief Given an array of integers nums,
 * sort the array in ascending order.
 *
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * @param nums
 * @param numsSize
 * @param returnSize
 * @return int*
 */
int *sortArray(int *nums, int numsSize, int *returnSize)
{
    printf("numSize is %d\n", numsSize);
    int *result = malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    for(int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }

    mergeSort(result, 0, numsSize - 1);

    return result;
}