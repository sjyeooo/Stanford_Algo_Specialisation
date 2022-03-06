clc;clear;

max_number_arr = [100.*ones(30,1);
                  10000.*ones(30,1);
                  100000.*ones(40,1);
                  2147483648.*ones(100,1);];
          

% Generate input numbers and 
for n = 1:length(max_number_arr)
    max_number = max_number_arr(n);
    
    gen_num = abs(floor(max_number.*rand(2,1)));
    
    % Write to file
    filename = sprintf('./test_cases/test_case%d.txt',n);
    fid = fopen(filename,'w');
    fprintf(fid,'%d\n',gen_num(1));
    fprintf(fid,'%d\n',gen_num(2));
    fclose('all');
end