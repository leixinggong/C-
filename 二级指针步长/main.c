//
//  main.c
//  二级指针步长
//
//  Created by 龚磊星 on 2018/11/18.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu
{
    char *name;
    char *sex;
    int *age;
    int *score;
};

enum StuStatus{
    Alloc_Error = -1,
    Success,
    NameErr,
    SexErr,
    AgeErr,
    ScoreErr
};

int allocWithZone(struct Stu **stu)
{
    *stu = (struct Stu *)malloc(sizeof(struct Stu));
    
    if (NULL == *stu)  return Alloc_Error;
    
    (*stu)->age = (int *)malloc(sizeof(*((*stu)->age)));
    if ((*stu)->age == NULL) return AgeErr;
    
    (*stu)->name = (char *)malloc(sizeof(100));
    if ((*stu)->name == NULL) return NameErr;
    
    (*stu)->sex = (char *)malloc(sizeof(*((*stu)->sex)));
    if ((*stu)->sex == NULL) return SexErr;
    
    (*stu)->score = (int *)malloc(sizeof(*((*stu)->score)));
    if ((*stu)->score == NULL) return ScoreErr;
    
    return Success;
}


int main(int argc, const char * argv[],char **evn)
{
  
    while (*evn)
    {
        printf("%s \n",*evn++);
    }
    
    struct Stu * stu = NULL;
    
    int ret = allocWithZone(&stu);
    
    if (Success == ret) { printf("stu error"); }
    
    *(stu->age) = 18;
    strcpy(stu->name, "gongleixing");
    
    printf("");
    
    
    
    return 0;
}
