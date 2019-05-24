# FOR PYINSTALLER USE :
# ON MAC TYPE : pyinstaller --onefile --add-binary='/System/Library/Frameworks/Tk.framework/Tk':'tk' --add-binary='/System/Library/Frameworks/Tcl.framework/Tcl':'tcl' --hidden-import=tensorflow prediction.py

#tensorflow stuff
from tensorflow.keras.models import Sequential, Model
from tensorflow.keras.layers import Dense, Dropout, Flatten, concatenate
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.losses import sparse_categorical_crossentropy
from tensorflow.keras.activations import relu
from tensorflow.train import latest_checkpoint
from tensorflow.nn import softmax

#other librairies needed
from numpy import reshape, zeros, array
from os import getcwd
from os.path import dirname, join

path = "../resource/prediction"

def load_data(filename):

    filepath = join(path, filename)

    with open(filepath) as f:
        protein_size = int(f.readline())

        shapes = f.readline()
        input_shape = int(shapes.split(",")[1])

        distances_list = zeros((protein_size, input_shape))

        for i in range(0, protein_size):
            distances = f.readline()
            distances_list[i, :] = array([float(s) for s in distances.split(",")])

        return protein_size, distances_list


def write_data(outputs, protein_size):

    filepath = join(path, "predicted_protein.csv")

    with open(filepath, 'w') as f:

        f.write(str(protein_size))
        f.write("\n")

        for i in range(0, protein_size):
            for j in range(0, 22):
                f.write(str(outputs[i, j]))
                f.write(",")
            f.write("\n")


def single_input_model():
    # activation function: leaky ReLU
    leakyrelu = lambda x: relu(x, alpha=0.01, max_value=None, threshold=0)

    # creation du réseau de neurones
    model = Sequential([

        # hidden layer
        Dense(units = 105, activation = leakyrelu, input_shape = (105,)),
        Dropout(rate=0.2),
        Dense(units = 210, activation = leakyrelu),
        Dropout(rate=0.2),
        Dense(units = 210, activation = leakyrelu),
        Dropout(rate=0.2),
        Dense(units = 210, activation = leakyrelu),
        Dropout(rate=0.2),
        Dense(units = 100, activation = leakyrelu),
        Dropout(rate=0.2),
        Dense(units = 75, activation = leakyrelu),
        Dropout(rate=0.2),
        Dense(units = 53, activation = leakyrelu),
        Dropout(rate=0.2),

        # final layer
        Dense(units = 22, activation = softmax),
    ])

    model.compile(optimizer=Adam(),
                  loss=sparse_categorical_crossentropy,
                  metrics=['accuracy'])

    # Restoring
    single_input_checkpoint_path = join(path, "models/Single input model/checkpoints/checkpoint.ckpt")
    single_input_checkpoint_dir = dirname(single_input_checkpoint_path)
    single_input_latest = latest_checkpoint(single_input_checkpoint_dir)
    model.load_weights(single_input_latest)

    return model


def double_input_model():
    # activation function: leaky ReLU
    leakyrelu = lambda x: relu(x, alpha=0.01, max_value=None, threshold=0)

    # distances branch
    distancesBranch = Sequential([
        Dense(units=105, activation=leakyrelu, input_shape=(105,)),
        Dropout(rate=0.2),
        Dense(units=210, activation=leakyrelu),
        Dropout(rate=0.2),
        Dense(units=210, activation=leakyrelu),
        Dropout(rate=0.2),
        Dense(units=100, activation=leakyrelu),
        Dropout(rate=0.2),
        Dense(units=75, activation=leakyrelu),
        Dropout(rate=0.2),
        Dense(units=50, activation=leakyrelu),
        Dropout(rate=0.2)
    ])

    # residues branch
    residuesBranch = Sequential([
        Dense(units=7, activation=leakyrelu, input_shape=(7, 22)),
        Flatten(),
        Dense(units=50, activation=leakyrelu)

    ])

    # concatenation
    combinedInput = concatenate([distancesBranch.output, residuesBranch.output])

    x = Dense(units=30, activation=leakyrelu, input_shape=(100,))(combinedInput)
    x = Dense(units=22, activation=softmax)(x)

    model = Model(inputs=[distancesBranch.input, residuesBranch.input], outputs=x)

    model.compile(optimizer=Adam(),
                  loss=sparse_categorical_crossentropy,
                  metrics=['accuracy'])

    # Restoring
    double_input_checkpoint_path = join(path, "models/Double input model/checkpoints/checkpoint.ckpt")
    double_input_checkpoint_dir = dirname(double_input_checkpoint_path)
    double_input_latest = latest_checkpoint(double_input_checkpoint_dir)
    model.load_weights(double_input_latest)

    return model


input_data = load_data("distances_file.csv")
protein_size = int(input_data[0])
inputs = input_data[1]

# outputs : matrix of residues probabilities
outputs = zeros((protein_size, 22))

single_input_model = single_input_model()
double_input_model = double_input_model()

# PREDICTION

# predict the 7 first residues using the single input model
for i in range(0, 7):
    input = reshape(inputs[i, :], (105, 1)).T
    outputs[i, :] = single_input_model.predict(input)

# predict the following residues using the double input model
for i in range(7, protein_size):
    input = reshape(inputs[i, :], (105, 1)).T
    residues_input = reshape(outputs[i-7:i, :], (1, 7, 22))

    outputs[i, :] = double_input_model.predict([input,  residues_input])

## OUTPUT
write_data(outputs, protein_size)

