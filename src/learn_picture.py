from keras.preprocessing import image
from keras.utils import np_utils
import numpy as np


def lerarnpicture(img_path, target, model):
    img = image.load_img(img_path, target_size=(
        28, 28), color_mode='grayscale')

    x = image.img_to_array(img)
    x = 255 - x
    x /= 255
    x = np.expand_dims(x, 0)

    target = np_utils.to_categorical(target, 10)
    tagret = np.expand_dims(target, 0)

    for i in range(7):
        model.train_on_batch(x, tagret)

    model.save_weights("../CNN/model_weights.h5")
