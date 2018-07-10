//
//  main.c
//  COMP411
//
//  Created by apple on 10/6/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#define POW2(E) (1 << E)

#include <stdio.h>

int main() {
    int x, y, z;

    x = POW2(0);
    y = POW2(10);
    z = POW2(7) - POW2(3);
    
    printf("x=%d\ny=%d\nz=%d\n",x,y,z);
    
}