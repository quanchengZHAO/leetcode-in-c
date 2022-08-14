
#include<stdlib.h>
#include<stdio.h>

#define DEFAULT_SIZE 1000

int numberOfSteps(int num);
int numberOfSteps_bitwise(int num);

int main(int argc, char* argv[]) {
    int n = DEFAULT_SIZE;
    if (argc > 1) {
        n = strtol(argv[1], NULL, 10);
    }
    printf("After %d steps, the number %d goes to 0.\n", numberOfSteps_bitwise(n), n);
    return 0;
}

/**
 * @brief
 * Given an integer num, return the number of steps to reduce it to zero.

 * In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
 * Input: num = 14
 * Output: 6
 * Explanation: 
 * Step 1) 14 is even; divide by 2 and obtain 7. 
 * Step 2) 7 is odd; subtract 1 and obtain 6.
 * Step 3) 6 is even; divide by 2 and obtain 3. 
 * Step 4) 3 is odd; subtract 1 and obtain 2. 
 * Step 5) 2 is even; divide by 2 and obtain 1. 
 * Step 6) 1 is odd; subtract 1 and obtain 0.
 * 
 * Time complexity: O(logn)
 * Space complexity: O(1)
 *
 * @param num
 * @return int
 */
int numberOfSteps(int num){
    int step = 0;
    while (num != 0) {
        if (num%2==0) {
            // number is even
            num /= 2;
        } else {
            // number is odd
            num--;
        }
        step++;
    }
    return step;
}

int numberOfSteps_bitwise(int num) {
    int step = 0;
    while (num != 0) {
        if ((num&1)==0) {
            // number is even
            num >>= 1; // All number bits shifts right by 1 place
        } else {
            // number is odd
            num--;
        }
        step++;
    }
    return step;
}