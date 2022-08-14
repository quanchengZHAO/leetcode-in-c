#include<stdlib.h>
#include<stdio.h>

#define DEFAULT_SIZE 1000

static char *fizz = "Fizz";
static char *buzz = "Buzz";
static char *fizz_buzz = "FizzBuzz";

char ** fizzBuzz(int n, int* returnSize);

int main(int argc, char* argv[]) {
    int n = DEFAULT_SIZE;
    if (argc > 1) {
        n = strtol(argv[1], NULL, 10);
    }

    int returnSize;
    char** arr = fizzBuzz(n, &returnSize);
    for(int i = 0;  i < returnSize; i++) {
        printf("%d : %s\n", i, arr[i]);
    }

    for (int i = 0; i < returnSize; i++ )
    {
        free(arr[i]);
    }

    free(arr);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i (as a string) if none of the above conditions are true.
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char **arr = (char**) calloc(n, sizeof(char*));
    for (int i = 1; i <= n; i++) {
        int divisibleBy3 = i%3 == 0;
        int divisibleBy5 = i%5 == 0;
        if (divisibleBy3 && divisibleBy5) {
            arr[i-1] = fizz_buzz;
        } else if (divisibleBy3) {
            arr[i-1] = fizz;
        } else if (divisibleBy5) {
            arr[i-1] = buzz;
        } else {
            char *number = (char*) malloc(sizeof(int)+1);
            sprintf(number, "%d", i);
            arr[i-1] = number;
        }
    }
    return arr;
}