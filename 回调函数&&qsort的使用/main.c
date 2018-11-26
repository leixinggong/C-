//
//  main.c
//  回调函数&&qsort的使用
//
//  Created by 龚磊星 on 2018/11/25.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int foo(int a, int b, int(*fun)(int fa,int fb))
{
    return fun(a,b);
}

int callback(int a,int b)
{
    return a * b;
}



int main(int argc, const char * argv[]) {

    
    int a =5;
    int b =6;
    
    int sum = foo(a, b, callback);
    printf("%p \n",callback);
    printf("%d \n",sum);
    
    sum = foo(2, 3, callback);
    
    //(*(void(*) (void)) 0)(); //将一串地址强转成 一个函数进行调用
    sum = (*(int(*)(int , int))0x100000d30)(5,5);
    printf("%d \n",sum);
    
    
    int array[] = {12,2,34,16,76,35,32,78,13};
    
    qsort_b(array, sizeof(array)/sizeof(int), sizeof(int), ^int(const void * a, const void * b) {
        
//      return *((int *)a) > *((int *)b) ? 1 : -1;
        return *((int *)a) - *((int *)b);
    });
    
    for (int i = 0; i < sizeof(array) /sizeof(array[0]); i++)
    {
        printf("%d  ",array[i]);
    }
    putchar(10);
    
    
    
    
    
    return 0;
}
