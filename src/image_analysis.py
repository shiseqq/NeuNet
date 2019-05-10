import numpy as np
from keras.preprocessing import image
from keras.models import model_from_json


def analysis(img_path):
    fl = open("../CNN/model.json", "r")
    json = fl.read()
    fl.close()
    model = model_from_json(json)
    model.load_weights("../CNN/model_weights.h5")
    model.compile(loss="categorical_crossentropy",
                  optimizer="adam", metrics=["accuracy"])
    img = image.load_img(img_path, target_size=(
        28, 28), color_mode='grayscale')

    x = image.img_to_array(img)
    x = 255 - x
    x /= 255
    x = np.expand_dims(x, axis=0)

    prd = model.predict(x)
    prd = np.argmax(prd, axis=1)
    return int(prd)
