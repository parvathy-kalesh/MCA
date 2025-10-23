import pandas as pd 
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix, accuracy_score, classification_report

# Step 1: Load dataset
df = pd.read_csv("iris.csv")

# Drop 'Id' column if it exists
if "Id" in df.columns:
    df = df.drop("Id", axis=1)

# Step 2: Separate features and target
X = df.drop("Species", axis=1)
y = df["Species"]

# Step 3: Split dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 4: Create and train kNN model
knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, y_train)

# Step 5: Evaluate the model
y_pred = knn.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)

print("✅ Model Evaluation Results:")
print("----------------------------")
print("Accuracy:", accuracy)
print("\nConfusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))

# Step 6: Predict a new instance
new_instance = [[5.1, 3.5, 1.4, 0.2]]
prediction = knn.predict(new_instance)
print("\n🌼 Prediction for new instance:", prediction[0])

