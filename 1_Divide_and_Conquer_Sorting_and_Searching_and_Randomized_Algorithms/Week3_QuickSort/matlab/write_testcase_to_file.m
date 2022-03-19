function write_testcase_to_file(id,array)

folder = './test_cases/';
filename = sprintf('test_case%d.txt',id);

if(exist(folder,'file')~=7)
    mkdir(folder);
end

filenamefull = strcat(folder,filename);

fid = fopen(filenamefull,'w');

for n = 1:length(array)
    element = array(n);
    fprintf(fid,'%d\n',element);
end

fclose(fid);

end