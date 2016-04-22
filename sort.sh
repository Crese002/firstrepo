#!/bin/sh
ARRAY=(1 3 4 2 5)
count=0
while [ "x${ARRAY[$count]}" != "x" ]
do
#	echo ${ARRAY[count]}
	count=$(( $count + 1))
done

echo Before Sorting
for(( i=0;i<$count;i++ ))
do
	min=$i
	for(( j=$i+1;j<$count;j++ ))
	do
		if [ ${ARRAY[$min]} -gt ${ARRAY[$j]} ];then
			min=$j
		fi
	done
	temp=${ARRAY[$min]}
	ARRAY[$min]=${ARRAY[$i]}
	ARRAY[$i]=$temp
done

echo After Sorting
for(( i=0;i<$count;i++ ))
do
	echo ${ARRAY[$i]}
done

