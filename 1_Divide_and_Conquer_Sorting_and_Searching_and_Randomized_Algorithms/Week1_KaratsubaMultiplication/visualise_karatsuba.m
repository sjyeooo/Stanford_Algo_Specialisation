clc;clear;

x0=7;x1=7;
y0=1;y1=70;

[z0,z1,z2,z1_z2_z0] = compute_params(x0,x1,y0,y1);


function [z0,z1,z2,z1_z2_z0] = compute_params(x0,x1,y0,y1)
z0 = x1*y1;
z1 = (x0+x1)*(y0+y1);
z2 = x0*y0;

z1_z2_z0 = z1-z2-z0;

end