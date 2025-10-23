import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load CSV
df = pd.read_csv("iris.csv")

# 1️⃣ Countplot
sns.countplot(x='Species', data=df)
plt.title('Count of Each Species')
plt.show()

# 2️⃣ Boxplot
sns.boxplot(x='Species', y='SepalLengthCm', data=df)
plt.title('Boxplot of Sepal Length by Species')
plt.show()

# 3️⃣ Violinplot
sns.violinplot(x='Species', y='SepalWidthCm', data=df)
plt.title('Violin Plot of Sepal Width by Species')
plt.show()

# 4️⃣ Correlation heatmap (numerical columns only)
numeric_df = df.drop(['Id'], axis=1).select_dtypes(include='number')
corr = numeric_df.corr()
sns.heatmap(corr, annot=True, cmap='coolwarm')
plt.title('Correlation Heatmap')
plt.show()

# 5️⃣ Pairplot (drop Id)
sns.pairplot(df.drop('Id', axis=1), hue='Species', palette='bright')
plt.show()

# 6️⃣ Scatterplot
sns.scatterplot(x='SepalLengthCm', y='SepalWidthCm', hue='Species', data=df)
plt.title('Sepal Length vs Sepal Width')
plt.show()


