from keras.models import model_from_json
import teach_сnn
import os


def startcnn():
    if not os.path.isfile("../CNN/model.json") or not os.path.isfile("../CNN/model_weights.h5"):
        if not os.path.exists("../CNN"):
            os.mkdir("../CNN")
        teach_сnn.teach()
    fl = open("../CNN/model.json", "r")
    json = fl.read()
    fl.close()
    model = model_from_json(json)
    model.load_weights("../CNN/model_weights.h5")
    model.compile(loss="categorical_crossentropy",
                  optimizer="adam", metrics=["accuracy"])
    return model
