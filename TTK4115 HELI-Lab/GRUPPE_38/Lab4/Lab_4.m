% FOR HELICOPTER NR 1-2
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.40; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.65; % Motor mass [kg]
e_0 = -0.475; %Offset for keeping the 0-point at horizontal


%%%%%%%%%%% Tuning constants
Kf = 0.2058; % equilibrium gain with input =1
V_s_0 = 6.5;
K1=Kf/(2*m_p*l_p); %
Kpp = 9/K1; % proportional gain  
Kpd = 6/K1; % derivatgain
K1= Kf/(2*m_p*l_p);
J_e=m_c*l_c^2+2*m_p*l_h^2;
J_lambda=(m_c*l_c^2 + 2*m_p*(l_h^2+l_p^2));
L3=l_h*Kf;
L4=l_h*Kf;
K2= L3/J_e;
K3= L4*V_s_0/J_lambda;

%%%%%%%%%%% LQR calc

A=[0,1,0, 0, 0;0,0,0,0,0;0,0,0,0,0;-1,0,0,0,0;0,0,-1,0,0]
B = [0,0; 0, K1; K2,0; 0,0;0,0]
C = [1,0,0,0,0;0,0,1,0,0]
D = [0,0;0,0];
Q =diag([64/pi^2,1/pi^2,15, 9/(4*pi^2), 16^2/(pi^2)])
R=diag([1/12.25,1/25])
SYS = ss(A,B,C,D)
[K, S, E] =lqr(SYS, Q, R)
F=K*transpose(C)

%%%%%%%%%% poles
Aa=[0,1,0;0,0,0;0,0,0];
Ba = [0,0; 0, K1; K2,0];
Ca = [0,1,0;0,0,1];
sys = ss(Aa,Ba,Ca,D);


p=pole(sys)
%%%%%%%%%%% Luenberger setup
PORT = 3 % the port for the Accelerometer. 
A_est = [0 1 0 0 0 ; 0 0 0 0 0 ;0 0 0 1 0 ;0 0 0 0 0 ;K3 0 0 0 0]
B_est = [0 0;0 K1;0 0;K2 0;0 0]
C_est = eye(5);%[1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 0 1] 
poless =([-0.6 -0.7+0.1j -0.7-0.1j -0.5-0.3j -0.5+0.3j])'
L_est = place(A_est', C_est', poless)'


%%%%% offsets on p_c:
p_c_offset = -0.08;

% Estimating R_d
%task1_1 = load('prob1_1.mat').ans;
%task1_2 = load('task1_2.mat').ans;
%M_1=task1_1(2:6,1000:10000);
%M_2 = task1_2(2:6,10000:25000);

%var_R_1= var(M_1')
%var_R_2= var(M_2')
%cov_R_2 = cov(M_2')
R_d = [0.0020    0.0054    0.0069   -0.0025   -0.0017;0.0054    0.0393    0.0536   -0.0061   -0.0093;0.0069    0.0536    0.0753   -0.0065   -0.0115;-0.0025   -0.0061   -0.0065    0.0056    0.0031;-0.0017   -0.0093   -0.0115    0.0031    0.0084]
%R_d=diag(var_R_2);%[0.0015 0 0 0 0;0 0.0270 0 0 0;0 0 0.0733 0 0;0 0 0 0.0035 0;0 0 0 0 0.0018]%

%%%%% Kalman Filter
T=0.002
A_bar = [0 1 0 0 0 0;0 0 0 0 0 0;0 0 0 1 0 0;0 0 0 0 0 0;0 0 0 0 0 1;K3 0 0 0 0 0]
B_bar = [0 0;0 K1;0 0;K2 0;0 0;0 0]
C_bar=[1 0 0 0 0 0;0 1 0 0 0 0;0 0 1 0 0 0;0 0 0 1 0 0;0 0 0 0 0 1]
D_bar=zeros(5,2)
kal_sys = ss(A_bar, B_bar, C_bar, D_bar);
disc_sys = c2d(kal_sys, T);
[A_d,B_d,C_d,D_d]=ssdata(disc_sys)

%syms alpha %FUNK iT
%A_d = exp(A_bar*T)
%B_d = int(expm(A_bar*alpha),alpha, 0, T)*B
%C_d = C_bar
%D_d = D_bar

%R_d = eye(5)*0.1
q=0.000001;     % Bra q verdi
r=0.0001;       % resonsns verdi
p=0.00000001;   % Funker akkuratt
Q_w = eye(6)*q;
q1=0.0000001;
q2=0.00001;
q3=0.0000001;
q4=0.00001;
q5=0.0000001;
q6=0.00001;
%Q_w=diag([q1 q2 q3 q4 q5 q6])

% Van loan
G=eye(6);
van_loan = exp([A_bar G*Q_w*G';zeros(6,6) -A_bar']*T)
A_loan = van_loan(1:6,1:6)
Q_d = van_loan(1:6,7:12)*A_loan'


