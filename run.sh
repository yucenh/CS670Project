#!/bin/bash

for((i=$2;i<=$3;i++));do python script.py $1 $i;done
