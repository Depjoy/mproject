#!/bin/bash
:<< !
if [ $# -lt 2 ];then
    echo " please input number you wanted to compare"
    exit;
fi
if [ $1 -lt $2 ];then
   echo "the first is less than the second"
else 
    if [ $1 -eq $2 ];then
        echo "the first input is equal to the second"
    else
        if [ $1 -gt $2 ];then
            echo "the first input is more than the second"
        fi
    fi
fi
!
if [[ $1 > $2 ]];then
    echo "$1 > $2"
else
    if [[ $1 = $2 ]];then
        echo "$1 = $2"
    else
        if [[ $1 < $2 ]];then
            echo "$1 < $2"
        fi
    fi
fi
