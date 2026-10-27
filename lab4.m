syms K1 K2 K3 alpha w1 w2 w3 w4 w5 w6 q

T=0.002
A=[0 1 0 0 0 0;0 0 0 0 0 0;0 0 0 1 0 0;0 0 0 0 0 0;0 0 0 0 0 1;K3 0 0 0 0 0]
B=[0 0;0 K1;0 0;K2 0;0 0;0 0]
C=eye(6)
D = zeros(6,2);
%sys = ss(A,B,C,D)
%sysDiscrete = c2d(sys,T,'zoh')
A_d=exp(A*T)
B_d=int(expm(A*alpha),alpha, 0, T)*B
C_d = C
D_d = D

G=eye(6)
Q_w= [w1 0 0 0 0 0;0 w2 0 0 0 0;0 0 w3 0 0 0;0 0 0 w4 0 0;0 0 0 0 w5 0;0 0 0 0 0 w6]
Q_w = q*eye(6)
van_loan = exp([A G*Q_w*G'; zeros(6,6) -A]*T)
A_loan = van_loan(1:6,1:6)
Q_dloan = van_loan(1:6,7:12)*A_loan'


