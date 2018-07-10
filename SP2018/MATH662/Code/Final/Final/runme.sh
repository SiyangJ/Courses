#!/bin/sh

#  MakeFile
#  HW4
#
#  Created by apple on 2/26/18.
#  Copyright © 2018 UNC. All rights reserved.

g++ -std=c++14 -c main.cpp -I/Users/wq/Desktop/SP2018/MATH662/DTSource -I/Users/wq/Desktop/SP2018/MATH662/eigen
g++ -std=c++14 -o main main.o /Users/wq/Desktop/SP2018/MATH662/DTSource/libDT.a -framework Accelerate
