import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("simulation_data.csv")

plt.figure(figsize=(10,5))
plt.plot(data['timestamp'], data['delay'])
plt.xlabel('Time (s)')
plt.ylabel('Delay (ns)')
plt.title('TSN Network Delay Over Time')
plt.grid()
plt.savefig('delay_plot.png')
plt.show()