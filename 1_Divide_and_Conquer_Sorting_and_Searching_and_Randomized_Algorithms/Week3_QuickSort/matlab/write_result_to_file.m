function write_result_to_file(id,array)
% Write out sorted array

%% Sort the array
array_sorted = sort(array);

%% Write to file
folder = './test_cases/results_matlab/';
filename = sprintf('test_case_result%d.txt',id);

if(exist(folder,'file')~=7)
    mkdir(folder);
end

filenamefull = strcat(folder,filename);

fid = fopen(filenamefull,'w');

for n = 1:length(array_sorted)
    element = array_sorted(n);
    fprintf(fid,'%d\n',element);
end

fclose(fid);

end