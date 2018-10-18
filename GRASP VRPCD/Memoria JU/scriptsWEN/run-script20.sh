#!/bin/bash

seedList="129 137 279 672 195 666 429 762 821 483 999 729 318 349 287 241 476 555 581 573"

for i in $seedList; do
    .././grasp ../instances_WEN/transformed_Data20_a.txt 3 300 100 3000 100 0.5 1 $i >> ../Final-results/wen20a.txt
done
echo "Termine 20a"
for i in $seedList; do
    .././grasp ../instances_WEN/transformed_Data20_b.txt 3 300 100 3000 100 0.5 1 $i >> ../Final-results/wen20b.txt
done
echo "Termine 20b"
for i in $seedList; do
    .././grasp ../instances_WEN/transformed_Data20_c.txt 3 300 100 3000 100 0.5 1 $i >> ../Final-results/wen20c.txt
done
echo "Termine 20c"
for i in $seedList; do
    .././grasp ../instances_WEN/transformed_Data20_d.txt 3 300 100 3000 100 0.5 1 $i >> ../Final-results/wen20d.txt
done
echo "Termine 20d"
for i in $seedList; do
    .././grasp ../instances_WEN/transformed_Data20_e.txt 3 300 100 3000 100 0.5 1 $i >> ../Final-results/wen20e.txt
done
echo "Termine 20e"
