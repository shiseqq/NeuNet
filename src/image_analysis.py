import numpy as np
from keras.preprocessing import image


def analysis(img_path, model):
    img = image.load_img(img_path, target_size=(
        28, 28), color_mode='grayscale')
        
    x = image.img_to_array(img)
    x = 255 - x
    x /= 255
    x = np.expand_dims(x, axis=0)

    prd = model.predict(x)
    prd = np.argmax(prd, axis=1)
    return int(prd)
