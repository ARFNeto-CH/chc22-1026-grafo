
# Import necessary libraries
import numpy as np
import tensorflow as tf
#import keras
import keras.applications
from keras.applications.vgg16 import VGG16, preprocess_input, decode_predictions
from keras.preprocessing import image
from keras.preprocessing.image import load_img,  img_to_array
from keras import layers

from IPython.display import display
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image, ImageFilter
import io
import ipywidgets as widgets

# Load the VGG16 model
model = VGG16(weights='imagenet')
# Display the model architecture
model.summary()
# Load and preprocess an image
def load_and_preprocess_image(image_path):
    # Load the image
    img = load_img(image_path, target_size=(224, 224))

    # Convert the image to a numpy array
    img_array = img_to_array(img)

    # Expand dimensions to fit the model input
    img_array = np.expand_dims(img_array, axis=0)

    # Preprocess the image
    img_array = preprocess_input(img_array)

    return img, img_array

# Load and preprocess a sample image
sample_image, processed_image = load_and_preprocess_image('image.jpg')

# Display the sample image
plt.imshow(sample_image)
plt.show()
