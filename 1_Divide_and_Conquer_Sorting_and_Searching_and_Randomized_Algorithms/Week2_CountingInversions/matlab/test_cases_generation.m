clc;clear;

for n = 1:100
    array = n:-1:1;
    write_testcase_to_file(n,array);
    write_result_to_file(n);
end