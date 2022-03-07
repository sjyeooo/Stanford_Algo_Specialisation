clc;clear;
close all;

n=linspace(1,100000,1000);

A = n.^2.*log(n);
B = 2.^n;
C = 2.^n;C=2.^C;
D = n.^log(n);
E = n.^2;

figure;
plot(n,A,n,B,n,C,n,D,n,E);
legend('A','B','C','D','E');
% EADBC