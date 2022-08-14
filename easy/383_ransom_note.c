#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

#define RANSON_NOTE "a"
#define MAGAZINE "ab"

bool canConstruct(char * ransomNote, char * magazine);

int main(int argc, char* argv[]){
    char *ransomNote = RANSON_NOTE;
    char *magazine = MAGAZINE;
    if(argc>1) {
        ransomNote = argv[1];
    }
    if(argc > 2){
        magazine = argv[2];
    }
    
    canConstruct(ransomNote, magazine);
     free(ransomNote);
     free(magazine);
}

/** * @brief 
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

 * Each letter in magazine can only be used once in ransomNote.
 * 
 * @param ransomNote 
 * @param magazine 
 * @return true 
 * @return false 
 */
bool canConstruct(char *ransomNote, char *magazine) {
    if(sizeof(ransomNote) > sizeof(magazine)) {
        return false;
    }

    int arr[26] = {0};
    for(char c = *magazine; c; c=*++magazine) {
        arr[c -'a']++;  
    }
    for(char c = *ransomNote; c; c=*++ransomNote) {
        arr[c -'a']--;
        if( arr[c -'a'] < 0) {
            return false;
        }
    }
    return true;
}