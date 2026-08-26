from matplotlib import pyplot as plt
import pandas as pd
import numpy as np;


DATASET_TAG = "UNSTABLE_VALUES.csv"; # Namnet på CSV-fila du ynskjar å lesa frå
Dataframe = pd.read_csv(f"Dataseries/{DATASET_TAG}", header=None);

# Hent ut dei relevante radane frå CSV-fila
Time = Dataframe.iloc[0, :].values;
Pitch = Dataframe.iloc[1, :].values;

PitchSV = np.heaviside(Time-40, 0) * (np.pi/18); # Referanse signalet


plt.figure(figsize=(10, 4)) # Dimensjon på plottet

plt.plot( Time, Pitch, label=r'$p(t)$', linewidth=0.7 );
plt.plot( Time, PitchSV, label=r'$p_c(t)$', linewidth=1.5, linestyle="dashed" );

# Trenger r strenger for å kunna bruka LaTeX
plt.xlabel(r'$t$ / Sekunder');
plt.ylabel(r'$Radianer$');

plt.legend();

plt.title(r"Sprangrespons til $p(t)$ gitt referansen $p_c(t)$");
plt.grid();

plt.savefig('Plot Eksempler/UNSTABLE_RESPONSE - Python.png', dpi=300, bbox_inches='tight')

plt.show();