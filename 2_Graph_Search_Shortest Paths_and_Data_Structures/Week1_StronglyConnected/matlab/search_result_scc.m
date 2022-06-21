clc;clear;
addpath matlab

%%
DG = get_scc_graph();

%% 
dfs_result = dfsearch(DG,1);
bfs_result = bfsearch(DG,1);

%%
writematrix(dfs_result,'./matlab/dfs_result.txt');
writematrix(bfs_result,'./matlab/bfs_result.txt');