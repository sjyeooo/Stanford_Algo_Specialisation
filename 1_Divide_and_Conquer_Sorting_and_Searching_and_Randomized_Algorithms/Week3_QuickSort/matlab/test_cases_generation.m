clc;clear;

% Set seed to be specific number so that we always generate same arrays and
% same results
rng(10000);

% Set configurations
num_test_cases = 200;

num_element_min = 1000;
num_element_max = 10000;

for n = 1:10
    arrays = randperm(20);
    
    write_testcase_to_file(n,arrays);
    write_result_to_file(n,arrays);
end

for n = 11:num_test_cases
    num_elements = floor(num_element_min + (num_element_max-num_element_min) .* rand);
    
    arrays = randperm(num_elements);
    
    write_testcase_to_file(n,arrays);
    write_result_to_file(n,arrays);
end