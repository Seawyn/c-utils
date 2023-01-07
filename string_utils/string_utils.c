#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

char* reverse_string(char* str){
    int str_length = strlen(str);
    char tmp;
    for (int i = 0; i < str_length / 2; i++){
        tmp = str[i];
        str[i] = str[str_length - i - 1];
        str[str_length - i - 1] = tmp;
    }

    return str;
}

int kmp(char *t, int s_t, char *s, int s_s){
    // Prefix array
    int prefix_array[s_s];
    prefix_array[0] = 0;
    prefix_array[1] = 0;

    for (int i = 2; i < s_s; i++){
        int previous = prefix_array[i - 1];
        prefix_array[i] = s[i-1] == s[previous] ? previous + 1 : 0;
    }

    int cursor = prefix_array[0];
    for (int i = 0; i < s_t; i++){
        if (t[i] == s[cursor]){
            cursor++;
            if (cursor >= s_s - 1) return (i - cursor) + 1;
        }
        else{
            cursor = prefix_array[cursor];
        }
    }
    return -1;
}

int main(){
    char text[] = "Some sample text";
    char str[] = "text";
    int match = kmp(text, LENGTH(text) - 1, str, LENGTH(str));
    if (match == -1) puts("No match");
    else {
        int s_s = LENGTH(str) - 2;
        printf("Substring:\n");
        printf("%s\n", str);
        printf("Characters %d to %d:\n", match, match + s_s);
        for (int i = match; i <= match + s_s; i++){
            printf("%c", text[i]);
        }
        printf("\n");
    }
    return 0;
}