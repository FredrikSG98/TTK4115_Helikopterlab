% Plot a figure with some Latex in the labels
clf
set(0, 'DefaultTextInterpreter', "latex"); % Formater text om til LaTeX

fig1 = figure(1);

LQR_DATASETT = LQR_GOOD_CONTROL_DATA;


% Visualiser steppet på referansen
t = LQR_DATASETT(1, :);
PITCH_SV = LQR_DATASETT(6, :);
ELEVATION_RATE_SV = LQR_DATASETT(7, :);

% Plot data
PITCH_MAALINGAR = LQR_DATASETT(2, :);
PITCH_RATE_MAALINGAR = LQR_DATASETT(3, :);
ELEVATION_MAALINGAR = LQR_DATASETT(4, :);
ELEVATION_RATE_MAALINGAR = LQR_DATASETT(5, :);



% Plot p mot p_c
subplot(2, 1, 1);
plot( t, PITCH_MAALINGAR, 'LineWidth', 1.5 );
hold on
plot( t, PITCH_SV, 'LineWidth', 2, "LineStyle","--" );
hold off
xlim([60, 110])
grid on;
legend("p_c(t)", "p(t)")
title("Sprangrespons til p(t) gitt referansen $p_c(t)$");

%{
% Plot pitch rate
subplot(2, 2, 2);
plot( t, PITCH_RATE_MAALINGAR, 'LineWidth', 1.5 );
grid on;
legend("$\dot{p}(t)$", "Interpreter", "latex");
title("$\dot{p}(t)$ over tid", "Interpreter", "latex");
%}

%{
% Plot elevation
subplot(2, 2, 3);
plot( t, ELEVATION_MAALINGAR, 'LineWidth', 1.5);
grid on;
legend("e(t)");
title("e(t) over tid");
%}

% Plot elevation rate mot edot_c
subplot(2, 1, 2);
plot(t, ELEVATION_RATE_MAALINGAR, 'LineWidth', 1.5);
hold on
plot(t, ELEVATION_RATE_SV, 'LineWidth', 1.5, 'LineStyle', "--");
ylim([-0.5, 0.5]);
xlim([ 26.5, 60 ]);
hold off
grid on;
legend("$\dot{e}(t)$", "$\dot{e}_c(t)$", "Interpreter", "latex");
title("Sprangrespons til $\dot{e}(t)$ gitt referansen $\dot{e}_c(t)$", "Interpreter", "latex");

xlabel('Tid / Sekunder');
ylabel('Radianer');


%{ 
EKSPORTER VIA GRENSESNITTET  TIL PLOTTET, VEL FØLGJANDE DIMENSJON
2X2 -> W = 19 | H = 9
2X1 -> W = 12 | H = 5
1X1 -> W = 8 | H = 5
%}

% Lag CSV fil av verdiane frå datasettet for bruk i Python
%writematrix( VALT_DATASETT_VERDIER, "OVERDAMPED_VALUES.csv");


%{
% Eksportert plottet
opts = hgexport('factorystyle');
opts.Resolution = 300;
opts.Width = 7;
opts.Height = 3;
hgexport(fig1, 'VALT_DATASETT_VERDIER.svg', opts, 'Format', 'svg');

% Ekstra lagring av plot for vidare bruk, frå GIT-sida.
% optional: save the fig, for later customization: 
% saveas(fig1,'heading_plot.fig')
% optional: save the data, for later plot reproduction:
% save('myAwesomeData.mat','t','y1','y2');
%}