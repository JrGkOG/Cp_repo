#!/bin/bash

mkdir -p final-output
mkdir -p assembly

files=(
07_unreachable_code_elimination
08_dead_code_elimination
09_loop_invariant_code_motion
10_strength_reduction_in_loops
11_induction_variable_elimination
12_loop_unrolling
13_loop_peelingc
14_loop_fusion
15_function_inlining
16_function_cloning
17_peephole_optimization
18_local_optimization
19_global_optimization
20_inter_procedural_optimization
)

for file in "${files[@]}"
do

output_file="final-output/${file}.txt"

echo "=========================================" > $output_file
echo "FILE: $file.c" >> $output_file
echo "=========================================" >> $output_file

echo "" >> $output_file
echo "CURRENT DIRECTORY:" >> $output_file
pwd >> $output_file

echo "" >> $output_file
echo "================ SOURCE CODE ================" >> $output_file
cat $file.c >> $output_file

gcc -O0 $file.c -o ${file}_O0
gcc -O3 $file.c -o ${file}_O3

gcc -O0 -S $file.c -o assembly/${file}_O0.s
gcc -O3 -S $file.c -o assembly/${file}_O3.s

echo "" >> $output_file
echo "================ OUTPUT BEFORE OPTIMIZATION (O0) ================" >> $output_file
./${file}_O0 >> $output_file

echo "" >> $output_file
echo "================ OUTPUT AFTER OPTIMIZATION (O3) ================" >> $output_file
./${file}_O3 >> $output_file

echo "" >> $output_file
echo "================ TIME BEFORE OPTIMIZATION ================" >> $output_file
(time ./${file}_O0) >> $output_file 2>&1

echo "" >> $output_file
echo "================ TIME AFTER OPTIMIZATION ================" >> $output_file
(time ./${file}_O3) >> $output_file 2>&1

echo "" >> $output_file
echo "================ ASSEMBLY DIFFERENCE ================" >> $output_file
diff assembly/${file}_O0.s assembly/${file}_O3.s >> $output_file

echo "Completed $file"

done

echo "All outputs stored in final-output/"
