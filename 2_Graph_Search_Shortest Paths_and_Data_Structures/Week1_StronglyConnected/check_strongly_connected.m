clc;clear;

%%
DG = get_scc_graph();

fprintf('Num Edges = %d\n',DG.numedges);
fprintf('Num Vertex = %d\n',DG.numnodes);

has_duplicate_edge = ismultigraph(DG);

[bins,binsizes] = conncomp(DG);

coursera_answer = sort(binsizes,'descend');

%%
num_print = 5;
n=1;
fid = fopen('matlab_scc_answer.txt','w');
while(true)
    fprintf(fid,'%d',coursera_answer(n));
    if(n==num_print)
        break;
    else
        n=n+1;
        fprintf(fid,',');
    end
end