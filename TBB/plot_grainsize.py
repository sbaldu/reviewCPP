
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

# Read in the data
data = pd.read_csv('data.csv')
sns.lineplot(x='grainsize', y='time', data=data)
plt.show()
