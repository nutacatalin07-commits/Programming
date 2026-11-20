#include <stdio.h>

#include <string.h>

size_t my_strlen(const char *s){
    size_t len = 0;
    while(s[len] != 0){
        len++;
    }
    return len;
}

char *my_strcpy(char *dst, const char *src){
    size_t i = 0;
    while(src[i] != '\0'){
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char *my_strcat(char *dst, const char *src){
    size_t dst_len = my_strlen(dst);
    size_t i = 0;
    while(src[i] != '\0'){
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return dst;
}


int main(){
    printf("strlen of hello = %zu\n", my_strlen("hello"));
    printf("strlen of ""= %zu\n", my_strlen(""));
    printf("strlen of      = %zu\n", my_strlen("     "));
    

}