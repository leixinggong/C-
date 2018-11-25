//
//  main.c
//  二维堆空间
//
//  Created by 龚磊星 on 2018/11/20.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void * allocWithZone(int unitSize,int row, int col)
{
    void * p = (void *)malloc(unitSize*row*col);
    
    return p;
}

int main(int argc, const char * argv[]) {
    
    
    int row = 3;
    int col = 4;
    
    int (*arr)[col] = (int(*)[col])allocWithZone(sizeof(int),row,col);
   
    if (NULL == arr)
        return -1;
    
    printf("%p \n",arr);
    printf("%p \n",arr+1);
    printf("%p \n",&arr);
    printf("%p \n",&arr+1);
    
    
    
    
    int * p =(int *)arr;
    
    int *pp = p;
    
    for (int i = 0; i < row*col; i++)
    {
        *p++ = i+1;
    }
    
    for (int i = 0; i < row*col; i++) {
        
        printf("%d ",*pp++);
    }
    
    putchar(10);
    
    
    for (int i = 0; i < row; i++) {
        
        for (int j = 0; j < col; j++) {
            
            printf("%d ",arr[i][j]);
        }
        putchar(10);
    }
    
    putchar(10);
    
    int a[10];
    
    printf("%p \n",a);
    printf("%p \n",&a+1);
    
    
    
    return 0;
}
