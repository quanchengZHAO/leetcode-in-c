#include <stdio.h>
int main()
{
    char *str0 = "c.biancheng.net";
    char *str1 = "C语言中文网";
    char *str2 = "C Language";
    printf("size of %d\n", sizeof(*str2));
    char *str[3] = {str0, str1, str2};
    printf("%s\n%s\n%s\n", str[0], str[1], str[2]);

    int num = 321;
    char snum[5];

    // convert 123 to string [buf]
    itoa(num, snum, 10);

    // print our string
    printf("snum %s\n", snum);
    return 0;
}