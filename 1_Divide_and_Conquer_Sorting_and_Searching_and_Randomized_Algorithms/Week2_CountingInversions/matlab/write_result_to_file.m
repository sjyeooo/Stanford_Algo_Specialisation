function write_result_to_file(n)
% Function for perfectly decreasing array:
% result = n*(n-1)/2

%% Compute results
result = n*(n-1)/2;

%% Write to file
folder = './test_cases/results_matlab/';
filename = sprintf('test_case_result%d.txt',n);

if(exist(folder,'file')~=7)
    mkdir(folder);
end

filenamefull = strcat(folder,filename);

fid = fopen(filenamefull,'w');

fprintf(fid,'%d',result);

fclose(fid);

end