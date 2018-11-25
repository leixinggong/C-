//
//  main.c
//  序列加密
//
//  Created by 龚磊星 on 2018/11/21.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * encryptStr(char *str ,int num)
{
    int len = (int)strlen(str);
    int newLen = len;
    if (len % num != 0)
        newLen = len + num  - len%num;
    
    char *tmp = (char *)malloc(newLen + 1);
    memset(tmp, 0, newLen);
    
    char *sec = (char *)malloc(newLen + 1);
    char *ps = sec;
    
    strcpy(tmp, str);
    
    for (int i = len; i < newLen; i++)
    {
        tmp[i]='$';
    }
    
    char (*p)[num] = (char(*)[num])tmp;
    
    for (int i = 0; i < num; i++) {
        
        for (int j = 0;  j < newLen / num; j++) {
            
            *ps++ = p[j][i];
        }
    }
    
    for (int i = 0; i < newLen / num; i++) {
        
        for (int j = 0;  j <  num; j++) {
            
            printf("%c ",p[i][j]);
        }
        putchar(10);
    }
    
    *ps = '\0';
    
    free(tmp);
    return sec;
}

char * decryptStr(char *str,int num)
{
    int len = (int)strlen(str);
    char * sec = (char *)malloc(len + 1);
    
    char * ps = sec;
    
    
    char (*pstr)[num] =(char(*)[num]) str;
    
    
    for (int i = 0; i < num; i ++) {
        
        for (int j = 0;  j < len / num; j++)
        {
            *ps++ = pstr[j][i];
        }
    }
    
    *ps = '\0';
    while (*(--ps) == '$');
    *(++ps) = '\0';
    
    return sec;
}

int main(int argc, const char * argv[]) {
    
    char *str = "China is the first gonglx";
    
    str = encryptStr(str, 8);
    
    decryptStr(str, 4);
    
    
    int a[5] = {1,2,3,4,5};
    int *ptr1 = (int *)(&a + 1);
    
    printf("%d",*(ptr1 - 1));
    return 0;
}
