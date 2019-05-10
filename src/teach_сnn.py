from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D, MaxPooling2D
from keras.utils import np_utils
from keras.models import model_from_json
import os


def teach():
    model = Sequential()
    input_shape = (28, 28, 1)
    model.add(Conv2D(75, (5, 5), padding="valid",
                     activation="relu", input_shape=input_shape))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.2))
    model.add(Conv2D(100,  (5, 5), activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.2))
    model.add(Flatten())
    model.add(Dense(500, activation='relu'))
    model.add(Dropout(0.5))
    model.add(Dense(10, activation='softmax'))

    model.compile(loss="categorical_crossentropy",
                  optimizer="adam", metrics=["accuracy"])
    print(model.summary())

    (x_train, y_train), (x_test, y_test) = mnist.load_data()

    x_train = x_train.reshape(x_train.shape[0], 28, 28, 1)
    x_test = x_test.reshape(x_test.shape[0], 28, 28, 1)

    x_train = x_train.astype('float32')
    x_test = x_test.astype('float32')
    x_train /= 255
    x_test /= 255

    y_train = np_utils.to_categorical(y_train, 10)
    y_test = np_utils.to_categorical(y_test, 10)

    model.fit(x_train, y_train, batch_size=200,
              epochs=10, validation_split=0.2, verbose=1)

    score = model.evaluate(x_test, y_test, verbose=0)
    print("Точность на тестовых наборах: %.2f%%" % (score[1]*100))

    json = model.to_json()
    fl = open("../CNN/model.json", "w")
    fl.write(json)
    fl.close()
    model.save_weights("../CNN/model_weights.h5")
