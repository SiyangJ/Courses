//
//  Dec1.c
//  CTest
//
//  Created by apple on 12/1/17.
//  Copyright © 2017 UNC. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct place {
    char *description;
    struct place *dir[4];
} place;

place* place_factory(char* description)
{
    place* ret = (place*) malloc(sizeof(place));
    ret->description = description;
    for (int i =0;i<4;i++)
        ret->dir[i]=NULL;
    return ret;
}

void clear_input() {
    int max = 10;
    char *throwout = (char*) malloc(max + 1);
    getline(&throwout, &max, stdin);
}


void free_place(place* initial)
{
    // description==NULL means already freed
    if (!initial || !initial->description)
        return;
    initial->description=NULL;
    for (int i=0;i<4;i++)
        free_place(initial->dir[i]);
    free(initial);
}

int main()
{
    int direction;
    place *here;
    
    here = place_factory("You are standing in an open field west of a white house.\n");
    direction = 0;
    while (direction < 5) {
        printf("%s", here->description);
        printf("1) Go north\n");
        printf("2) Go south\n");
        printf("3) Go east\n");
        printf("4) Go west\n");
        printf("5) Exit\n");
        printf("Command: ");
        scanf("%d", &direction);
        clear_input();
        int size=50;
        if (direction==1)
        {
            if (!here->dir[0])
            {
                char* desc = (char*)malloc(size + 1);
                //scanf("%s",desc);
                getline(&desc, &size,  stdin);
                here->dir[0] = place_factory(desc);
                here->dir[0]->dir[1] = here;
                here = here->dir[0];
            }
            else
                here = here->dir[0];
        }
        
    }
    free_place(here);
    free(here);
}
