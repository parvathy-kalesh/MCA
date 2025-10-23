# ==========================
# Naive Bayes on Iris Dataset
# ==========================

# 1️⃣ Import Libraries
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from sklearn.datasets import load_iris

# 2️⃣ Load Dataset
iris = load_iris()
df = pd.DataFrame(data=iris.data, columns=iris.feature_names)
df['Species'] = iris.target

# 3️⃣ Prepare Features and Labels
X = df.drop('Species', axis=1)
y = df['Species']

# 4️⃣ Split Dataset into Training and Test sets
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# 5️⃣ Create and Train Naive Bayes Model
model = GaussianNB()
model.fit(X_train, y_train)

# 6️⃣ Make Predictions
y_pred = model.predict(X_test)

# 7️⃣ Evaluate Model
print("✅ Accuracy:", accuracy_score(y_test, y_pred))
print("\n✅ Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\n✅ Classification Report:\n", classification_report(y_test, y_pred))

# 8️⃣ Predict for a New Sample
sample = [[5.1, 3.5, 1.4, 0.2]]  # replace with your own values
pred_class = model.predict(sample)
print("✅ Predicted Class for sample:", pred_class[0])
