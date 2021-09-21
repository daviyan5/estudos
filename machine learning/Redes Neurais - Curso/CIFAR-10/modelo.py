from keras.models import Sequential
from keras.layers import Dense, Flatten, Dropout
from keras.layers import Conv2D, MaxPooling2D
from tensorflow.keras.layers import BatchNormalization
from keras.datasets import cifar10
from keras.utils import np_utils

nome_classes = {0 :'airplane', 1 :'automobile',
                2 :'bird',     3 :'cat',
                4 :'deer',     5 :'dog',
                6 :'frog',     7 :'horse',
                8 :'ship',     9 :'truck'}

def cria_modelo():
    
    classificador = Sequential()
    classificador.add(Conv2D(64, (4,4), input_shape=(32, 32, 3),activation = 'relu'))
    classificador.add(BatchNormalization())
    classificador.add(MaxPooling2D(pool_size = (3,3)))
    classificador.add(Conv2D(64, (4,4), activation = 'relu'))
    classificador.add(BatchNormalization())
    classificador.add(MaxPooling2D(pool_size = (3,3)))
    classificador.add(Flatten())
    classificador.add(Dense(units = 128, activation = 'relu'))
    classificador.add(Dropout(0.2))
    classificador.add(Dense(units = 128, activation = 'relu'))
    classificador.add(Dropout(0.2))
    classificador.add(Dense(units = 10, activation = 'softmax'))
    classificador.compile(loss = 'categorical_crossentropy',optimizer = 'adam', metrics = ['accuracy'])
    return classificador


def main():
    (data_treino, classe_treino), (data_teste, classe_teste) = cifar10.load_data()
    
    data_treino = data_treino.astype('float32')
    data_teste = data_teste.astype('float32')
    
    data_treino /= 255
    data_teste /= 255
    
    classe_teste = np_utils.to_categorical(classe_teste)
    classe_treino = np_utils.to_categorical(classe_treino)
    
    modelo = cria_modelo()
    modelo.fit(data_treino, classe_treino,
               batch_size = 128, epochs = 2,
               validation_data = (data_teste,classe_teste))
    
    resultado = modelo.evaluate(data_teste, classe_teste)
    print(resultado)
    
if __name__ == "__main__" :
    main()