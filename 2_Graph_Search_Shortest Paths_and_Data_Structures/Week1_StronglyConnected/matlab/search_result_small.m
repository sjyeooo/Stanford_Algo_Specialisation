clc;clear;
addpath matlab

%%
DG = get_small_graph;

figure;
plot(DG);

%% 
dfs_result = dfsearch(DG,1);
bfs_result = bfsearch(DG,1);

%%
writematrix(dfs_result,'./matlab/dfs_result_small_matlab.txt');
writematrix(bfs_result,'./matlab/bfs_result_small_matlab.txt');