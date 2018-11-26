//
//  main.c
//  读取文件到堆中
//
//  Created by 龚磊星 on 2018/11/24.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int getFileText(char ***str ,char *filePath)
{
    
    int row = 0;
    FILE *fp = fopen(filePath, "r+");
    char strfile[1024] = {};
    while (fgets(strfile, sizeof(strfile) - 1, fp))
        row++;
    
    *str = (char **)malloc(sizeof(void *) * (row+1));
    rewind(fp);
    for (int i = 0; i < row; i++)
    {
        char *buf = fgets(strfile, sizeof(strfile) - 1, fp);
        char *tmp = (char *)malloc(strlen(buf)+1);
        strcpy(tmp, buf);
        *((*str)+i) = tmp;
    }
    *((*str)+row) = NULL;
    return 0;
}


int main(int argc, const char * argv[]) {

    char **str = NULL;
    getFileText(&str, "/Users/gongleixing/Desktop/C-Language-senior/读取文件到堆中/pass.txt");
    
    while (*str)
    {
        printf("%s",*str++);
    }

    return 0;
}
