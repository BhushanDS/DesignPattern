import tensorflow as tf
from tensorflow.keras.preprocessing import image
import numpy as np

# Load the trained model
model = tf.keras.models.load_model('D:\Projects\FinalYearProject\mp.h5')

# Load and preprocess the image
img_path = 'D:\Projects\FinalYearProject\NM01_01.jpg'  # Replace with the path to your image
img = image.load_img(img_path, target_size=(300, 300))  # Adjust target size based on your model's input size
img_array = image.img_to_array(img)
img_array = np.expand_dims(img_array, axis=0)
img_array = img_array / 255.0  # Normalize the pixel values

# Make predictions
predictions = model.predict(img_array)

# Assuming the model predicts probabilities for multiple classes, you can print the class with the highest probability
predicted_class = np.argmax(predictions)
print(f"Predicted Class: {predicted_class}")

# If you have a mapping of class indices to class names, you can print the class name
# class_names = {0: 'Class1', 1: 'Class2', ...}
# predicted_class_name = class_names[predicted_class]
# print(f"Predicted Class Name: {predicted_class_name}")
