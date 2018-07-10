//
//  Final.c
//  CTest
//
//  Created by apple on 12/9/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a[] = {1,2,3,5,6,7,8,9,10};
    
    int i = 2;
    
    int *ptr = &a[i];
    
    //ptr[0] = ptr[1]-ptr[0];
    
    *ptr = *(ptr+4)-*ptr;
    
}