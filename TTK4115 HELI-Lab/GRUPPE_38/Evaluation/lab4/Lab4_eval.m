%% Calibration of the encoder and the hardware for the specific
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


%%%%%%%%%%% Tuning constants
e_0 = -0.475; %Offset for keeping the 0-point at horizontal
p_c_offset = -0.08; % offsets on p_c to keep it sort of level
V_s_0 = 6.5;

%%%%%%%%%% Tuning constants
Kf = 0.2058; % equilibrium gain with input =1
K1= Kf/(2*m_p*l_p);
J_e=m_c*l_c^2+2*m_p*l_h^2;
J_lambda=(m_c*l_c^2 + 2*m_p*(l_h^2+l_p^2));
L3=l_h*Kf;
L4=l_h*Kf;
K2= L3/J_e;
K3= L4*V_s_0/J_lambda;

%% LQR calc uten integral

A=[0,1,0;0,0,0;0,0,0]
B = [0,0; 0, K1; K2,0]
C = [1,0,0;0,0,1]
D = [0,0;0,0];

% Bryson's rule of thumb
Q =diag([64/pi^2;1/pi^2;15])
R=diag([1/12.25,1/25])

SYS = ss(A,B,C,D)
[K, S, E] =lqr(SYS, Q, R)

F=K*[1,0;0,0;0,1]

%% LQR calc
A=[0,1,0, 0, 0;0,0,0,0,0;0,0,0,0,0;-1,0,0,0,0;0,0,-1,0,0]
B = [0,0; 0, K1; K2,0; 0,0;0,0]
C = [1,0,0,0,0;0,0,1,0,0]
D = [0,0;0,0];
Q =diag([64/pi^2,1/pi^2,15, 9/(4*pi^2), 16^2/(pi^2)])
R=diag([1/12.25,1/25])
SYS = ss(A,B,C,D)
[K, S, E] =lqr(SYS, Q, R)
F=K*transpose(C)


%% Kalman Filter
R_d = [0.0020    0.0054    0.0069   -0.0025   -0.0017;0.0054    0.0393    0.0536   -0.0061   -0.0093;0.0069    0.0536    0.0753   -0.0065   -0.0115;-0.0025   -0.0061   -0.0065    0.0056    0.0031;-0.0017   -0.0093   -0.0115    0.0031    0.0084]

%%% Discrete system
T=0.002
A_bar = [0 1 0 0 0 0;0 0 0 0 0 0;0 0 0 1 0 0;0 0 0 0 0 0;0 0 0 0 0 1;K3 0 0 0 0 0]
B_bar = [0 0;0 K1;0 0;K2 0;0 0;0 0]
C_bar=[1 0 0 0 0 0;0 1 0 0 0 0;0 0 1 0 0 0;0 0 0 1 0 0;0 0 0 0 0 1]
D_bar=zeros(5,2)
kal_sys = ss(A_bar, B_bar, C_bar, D_bar);
disc_sys = c2d(kal_sys, T);
[A_d,B_d,C_d,D_d]=ssdata(disc_sys)


%% Setting Q_w
q=0.000001;     % Bra q verdi
r=0.0001;       % resonsns verdi
p=0.00000001;   % Funker akkuratt
Q_d = eye(6)*q;

%% Setting Q_d using van loan:
q=0.01;         % Bra med van loan
r=1;            % resonans med Van loan
p=0.0001;       % Treg med van loan

Q_w=eye(6)*q;

%Q_w = diag([0.0001 0.01 0.001 0.001 0.001 0.01]) % Bra Q_w for å bruke med

%%% Van loan for getting Q_d
G=eye(6);
van_loan = expm([A_bar G*Q_w*G';zeros(6,6) -A_bar']*T)
A_loan = van_loan(1:6,1:6)
Q_d = van_loan(1:6,7:12)*A_loan'


