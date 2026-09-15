% Plot a figure with some Latex in the labels
set(0, 'DefaultTextInterpreter', "latex"); % Formater text om til LaTeX

fig1 = figure(1);

VALT_DATASETT_VERDIER = Saturation;


% Visualiser steppet på referansen
t = VALT_DATASETT_VERDIER(1, :);
%pitch_ref = (heaviside(t)-heaviside(t-40))*0 + heaviside(t-40)*(pi/18); % Vis referansen i plottet.


% Plot data
plot( VALT_DATASETT_VERDIER(1, :), VALT_DATASETT_VERDIER(2, :), 'LineWidth', 1.5 );
hold on
plot( VALT_DATASETT_VERDIER(1, :), VALT_DATASETT_VERDIER(3, :), 'LineWidth', 1.5 );
plot( VALT_DATASETT_VERDIER(1, :), VALT_DATASETT_VERDIER(4, :), 'LineWidth', 1.5 );
plot( VALT_DATASETT_VERDIER(1, :), VALT_DATASETT_VERDIER(5, :), 'LineWidth', 1.5 );
hold off
grid on;
legend("p_c(t)", "p(t)")


xlabel('$Tid$ / Sekunder');
ylabel('Radianer');

title("Sprangrespons til p(t) gitt referansen $p_c(t)$");

% Lag CSV fil av verdiane frå datasettet for bruk i Python
writematrix( VALT_DATASETT_VERDIER, "UNSTABLE_VALUES.csv");


% Eksportert plottet
opts = hgexport('factorystyle');
opts.Resolution = 300;
hgexport(fig1, 'VALT_DATASETT_VERDIER.png', opts, 'Format', 'png');

% Ekstra lagring av plot for vidare bruk, frå GIT-sida.
% optional: save the fig, for later customization: 
% saveas(fig1,'heading_plot.fig')
% optional: save the data, for later plot reproduction:
% save('myAwesomeData.mat','t','y1','y2');