//
//  Nov2.c
//  CTest
//
//  Created by apple on 11/2/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include <stdio.h>

int makeOdd(int a) {
    return a | 1;
}

float roundDown(float b) {
    return (float)((int)(b + 0.5));
}
