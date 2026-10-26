syms K1 K2 K3 alpha

T=0.002
A=[0 1 0 0 0 0;0 0 0 0 0 0;0 0 0 1 0 0;0 0 0 0 0 0;0 0 0 0 0 1;K3 0 0 0 0 0]
B=[0 0;0 K1;0 0;K2 0;0 0;0 0]
C=eye(6)
D = zeros(6,2);
%sys = ss(A,B,C,D)
%sysDiscrete = c2d(sys,T,'zoh')
A_d=exp(A*T)
B_d=int(expm(A*alpha),alpha, 0, T)
C_d = C
D_d = D


