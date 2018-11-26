//
//  main.c
//  二分查找迭代和递归
//
//  Created by 龚磊星 on 2018/11/25.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>

int search2index(int *array, int low ,int higt , int find)
{
    int mid = 0;
    while (low <= higt)
    {
        mid = (low+higt)/2;
        if (array[mid] == find)
        {
            return mid;
        }
        else if (array[mid] > find)
        {
            return search2index(array, low, mid - 1, find);
        }
        else
        {
            return search2index(array, mid+1, higt, find);
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
  
    
    int array[] ={2,3,5,7,12,26,34,76,87,90,91};
    int len = sizeof(array)/sizeof(array[0]);
    int find = 76;
    int index = search2index(array, 0, len -1, find);
    if (index == -1) {
        printf("element none");
    }
    printf("array[%d] = %d \n",index,array[index]);
    
    return 0;
}
