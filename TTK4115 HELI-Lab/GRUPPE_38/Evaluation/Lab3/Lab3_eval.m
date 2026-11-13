%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.40; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.65; % Motor mass [kg]
ELEV_OFFSET = -0.475; %Offset for keeping the 0-point at horizontal
V_s_0 = 6.5;
p_c_0 = -0.08;
imu_t_dot_bias = 0.5;


%% Tuning constants
Kf = 0.2058; % equilibrium gain with input =1
J_e=m_c*l_c^2+2*m_p*l_h^2;
J_lambda=(m_c*l_c^2 + 2*m_p*(l_h^2+l_p^2));
L3=l_h*Kf;
L4=l_h*Kf;

K1= Kf/(2*m_p*l_p);
K2= L3/J_e;
K3= L4*V_s_0/J_lambda;

%% LQR calc

A=[0,1,0, 0, 0;0,0,0,0,0;0,0,0,0,0;-1,0,0,0,0;0,0,-1,0,0]
B = [0,0; 0, K1; K2,0; 0,0;0,0]
C = [1,0,0,0,0;0,0,1,0,0]
D = [0,0;0,0];

%%% Better Controller
Q =diag([64/pi^2,1/pi^2, 20, 9/(4*pi^2), 256/pi^2])
R=diag([1/12.25,1/25])

SYS = ss(A,B,C,D)
[K, S, E] =lqr(SYS, Q, R)
F=K*transpose(C)


%% Luenberger setup
PORT = 3 % the port for the Accelerometer. 
A_est = [0 1 0 0 0 ; 0 0 0 0 0 ;0 0 0 1 0 ;0 0 0 0 0 ;K3 0 0 0 0]
B_est = [0 0;0 K1;0 0;K2 0;0 0]
C_est = [1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 0 1]

%%% Recomended poles (Cinda noicy)
poless =([-10 -11 -12 -13 -14])'

%%% Complex and slower
poless = ([-3 -3.2 -3.4 -3.6 -3.8])'


L_est = place(A_est', C_est', poless)'



