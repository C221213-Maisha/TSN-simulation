import pandas as pd
from sklearn.ensemble import RandomForestRegressor

# Load your collected data
data = pd.read_csv("simulation_data.csv")

# Train a simple model
X = data[['frame_size', 'queue_length']]
y = data['delay']

model = RandomForestRegressor()
model.fit(X, y)

# Save model
import joblib
joblib.dump(model, 'delay_predictor.joblib')