//
//  main.c
//  堆上的二维空间
//
//  Created by 龚磊星 on 2018/11/20.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int allocWhit2DZone(void *** p,int row ,int col,int unitSize)
{
    *p = (void **)malloc(row * sizeof(void *));
    if (NULL == *p)
        return -1;
    
    for (int i = 0; i < row; i++)
    {
        (*p)[i] = (void *)malloc(col * unitSize);
        printf("%p \n",&((*p)[i]));
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    

    int **p = NULL;
    int row = 7;
    int col = 4;
    int unitSize = sizeof(int);
    
    int ret = allocWhit2DZone((void ***)&p,row, col, unitSize);
    if (ret < 0)
        return -1;
    
    printf("%p \n",p);
    
    
    for (int i = 0; i < row; i++) {
        
        for (int j = 0; j < col; j++) {
            
            p[i][j] = i+j;
        }
    }
    
    
    for (int i = 0; i < row; i++) {
        
        for (int j = 0; j < col; j++) {
            
            printf("%d  ",p[i][j]);
        }
        
        putchar(10);
    }
    
    

    
    
    
    
    
    return 0;
}
