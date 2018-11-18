//
//  main.c
//  C-Language-senior
//
//  Created by 龚磊星 on 2018/11/16.
//  Copyright © 2018 龚磊星. All rights reserved.
//  数组指针

#include <stdio.h>

/// 一维数组
void foo(int arr[] ,int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ",arr[i]);
    }
    putchar(10);
}


void foo2(int(*arr)[4],int len)
{
    
    for (int i = 0; i < len; i++) {
        
        for (int j = 0; j < 4; j++) {
            
            printf("%d  ",arr[i][j]);
        }
        putchar(10);
    }
}


void foo3(int(*arr)[2],int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 2; j++)
        {
//          printf("%d ", *((*(arr+i))+j));
            printf("%p ",&arr[i][j]);
        }
        putchar(10);
    }
}


void foo4(int * arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ",arr[i]);
    }
    putchar(10);
}

int main(int argc, const char * argv[]) {
    
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    
    foo(array, sizeof(array)/sizeof(int));
    
    putchar(10);
    
    /// 数组指针 数组指针的本质 是一个指向数组的指针
    foo2((int(*)[4])array,sizeof(array) / sizeof(int[4]));
    
    putchar(10);
    
    ///数组指针偏移法
    foo3((int(*)[2])array, sizeof(array)/sizeof(int[2]));
    
    putchar(10);
    
    /// 二维数组 用一维的方式去访问
    int array2[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    foo4((int *)array2,sizeof(array)/sizeof(int));
    
    
    return 0;
}
