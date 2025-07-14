import pandas as pd
import matplotlib.pyplot as plt
fd="monthly_sales.csv"
df=pd.read_csv(fd)
print(df)

df.plot(x='Month',y='Sales',kind='line',title='Monthly_sales')
plt.show()

df.plot(x='Month',y='Sales',kind='bar',title='Monthly_sales')
plt.show()

df.plot(x='Month',y='Sales',kind='pie',title='Monthly_sales')
plt.show()

df.plot(x='Month',y='Sales',kind='scatter',title='Monthly_sales')
plt.show()


