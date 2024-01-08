#!/bin/bash

rm -f data.csv
touch data.csv
echo "grainsize,time" >> data.csv

make
echo "Collecting data"
for ((i = 1; i < 100000; i += 10 ))
do
  echo $i
  echo -n "$i," >> data.csv
  ./vecAdd.out $i >> data.csv
done
