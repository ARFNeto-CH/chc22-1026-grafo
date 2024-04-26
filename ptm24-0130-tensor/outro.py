import numpy as np
import keras
from keras.preprocessing.image import load_img
from keras.preprocessing.image import img_to_array

# Load the image
img_path = 'image.jpg'
img = load_img(img_path, target_size=(224, 224))

# Convert the image to a NumPy array
img_array = img_to_array(img)

# Print the shape of the array
print(img_array.shape)
