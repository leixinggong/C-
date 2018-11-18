//
//  main.c
//  二级指针
//
//  Created by 龚磊星 on 2018/11/17.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>

void foo(int(*arr)[] ,int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ",(*arr)[i]);
    }
    putchar(10);
}

void foo2(char **str , int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s ",str[i]);
    }
    putchar(10);
}


int main(int argc, const char * argv[]) {

#if  0
    int a = 10;
    
    int b = 20;
    
    int * pa = &a;
    
    int **ppa = &pa;
    
    *ppa = &b;
    
    printf("%d \n",**ppa);

#endif
    
    
    
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    
    int *pa = array;
    printf("%p %d \n",pa,*pa);
    
    foo(&array, sizeof(array)/sizeof(array[0]));
    
    putchar(10);
    
    char * strAry[] = {"apple","google","FaceBook","IBM","Zhongan","Alibaba"};
    
    
    foo2(strAry, sizeof(strAry)/sizeof(strAry[0]));
    
    putchar(10);
    
    int a1  = 1;
    int a2  = 2;
    int a3  = 3;
    int a4  = 4;
    int a5  = 5;
    int a6  = 6;
    int a7  = 7;
    int a8  = 8;
    int a9  = 9;
    int a10 = 10;

    int* array3[] = {&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10};
    
    int* (*p)[] = &array3;
    
    int **qq = array3;
    
    

    return 0;
}
