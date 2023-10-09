import pandas as pd
import matplotlib.pyplot as plt

#url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
down= 'iris.data'
names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'class']
df = pd.read_csv(url, names=names)
print(df.head())
print(df.dtypes)
print(df.describe())
df.hist()
plt.show()