#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define DEFAULT_SIZE 2
const int default_nums[DEFAULT_SIZE] = {10, 2};

/**
 * @brief From an array with not negative numbers, then combine all
 * number together and print out a minimum number
 *
 * Inout: [10,2]
 * Output: "102"
 *
 * Inout: [3,30,34,5,9]
 * Output: "3033459"
 *
 * @param nums
 * @param numsSize
 * @return char*
 */
char *minNumber(int *nums, int numsSize);

int main(int argc, int *argv[])
{
    if (argc > 1)
    {
        int *nums = malloc(sizeof(int) * (argc - 1));
        for (int i = 1; i < argc; i++)
        {
            nums[i - 1] = *argv[i];
        }
        printf(minNumber(nums, argc - 1));
    }
    else
    {
        printf(minNumber(default_nums, DEFAULT_SIZE));
    }
    return 0;
}

bool needToSwap(char *p1, char *p2)
{
    return (*p1 + *p2) > (*p2 + *p1);
}

void swap(char *xp, char *yp)
{
    char *temp = *xp;
    *xp = *yp;
    *yp = *temp;
}

char *minNumber(int *nums, int numsSize)
{
    bool swapped = true;

    char *ptrs = malloc(sizeof(char) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        char c = nums[i];
        char *p = &c;
        ptrs[i] = *p;
    }

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (!swapped)
            break;

        swapped = false;
        for (int j = 0; j < numsSize - i - 1; j++)
        {
            if (needToSwap(ptrs[j], ptrs[j + 1]))
            {
                swap(ptrs[j], ptrs[j + 1]);
                swapped = true;
            }
        }
    }
}