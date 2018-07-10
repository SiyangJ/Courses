#!/usr/bin/env bash

echo "Start\n"

for i in 1 2 3 4
do
    echo "Is doing $i\n"
    #python3 MakeInput2_${i}.py > Input2_${i}
    #python3 MakeOutput2_${i}.py > Output2_${i}
    #python3 FTP2Server.py < Input2_${i} > MyOutput2_${i}
    python3 ServerInt.py < Input2_${i} > MyOutput2_${i}
    diff Output2_${i} MyOutput2_${i}
    read -p "Done for number ${i}\n"
done