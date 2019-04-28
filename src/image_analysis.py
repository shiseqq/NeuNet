import numpy as np
from keras.models import model_from_json
from keras.preprocessing import image
import matplotlib.pyplot as plt
import sys
import os

if os.path.exists("../CNN/model.json") and os.path.exists("../CNN/model_weights.h5"):
    fl = open("../CNN/model.json", "r")
    json = fl.read()
    fl.close()
    model = model_from_json(json)
    model.load_weights("../CNN/model_weights.h5")
else:
    print("Missing file model.json and / or file model_weights.h5 in the folder CNN. Please run training сnn.")
    os.abort()

model.compile(loss="categorical_crossentropy",
              optimizer="adam", metrics=["accuracy"])


img_path = input("Enter the path to the image: ")
img = image.load_img(img_path, target_size=(28, 28), color_mode='grayscale')

x = image.img_to_array(img)
x = 255 - x
x /= 255
x = np.expand_dims(x, axis=0)

prd = model.predict(x)
prd = np.argmax(prd, axis=1)
print(int(prd))
plt.imshow(img, cmap='gray')
plt.show()
