import tensorflow as tf
import keras
#import keras_applications
from keras.applications.VGG16 import VGG16, preprocess_input, decode_predictions
from keras.preprocessing import image

print(tf.__version__)

# Load the VGG16 model
#model = VGG16(weights='imagenet')

# # Load the image
# img_path = 'image.jpg'
# img = image.load_img(img_path, target_size=(224, 224))

# # Preprocess the image
# x = image.img_to_array(img)
# x = preprocess_input(x)
# x = np.expand_dims(x, axis=0)

# # Predict the class of the image
# preds = model.predict(x)
# print('Predicted:', decode_predictions(preds, top=3)[0])
