import pandas as pd
from keras.layers import Dense, Dropout, Activation, Input
from keras.models import Model

base = pd.read_csv('games.csv')
base = base.drop('Other_Sales', axis = 1)
base = base.drop('NA_Sales', axis = 1)
base = base.drop('EU_Sales', axis = 1)
base = base.drop('JP_Sales', axis = 1)
base = base.loc[base['Global_Sales'] > 1]
base = base.dropna(axis = 0)
nome_jogos = base.Name
base = base.drop('Name', axis = 1)

previsores = base.iloc[:, [0,1,2,3,5,6,7,8,9,10]].values

from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.compose import ColumnTransformer

labelencoder = LabelEncoder()
previsores[:, 0] = labelencoder.fit_transform(previsores[:, 0])
previsores[:, 2] = labelencoder.fit_transform(previsores[:, 2])
previsores[:, 3] = labelencoder.fit_transform(previsores[:, 3])
previsores[:, 8] = labelencoder.fit_transform(previsores[:, 8])
previsores[:, 9] = labelencoder.fit_transform(previsores[:, 9])
vendas_global = base.iloc[:,4].values

onehotencoder =  ColumnTransformer(
    [('one_hot_encoder', OneHotEncoder(), [0,2,3,8,9])],
    remainder='passthrough' )
previsores = onehotencoder.fit_transform(previsores).toarray()

act_sigmoid = Activation('sigmoid')
act_linear  = Activation('linear')
camada_entrada = Input(shape=(463,))
camada_oculta1 = Dense(units = 233, activation = act_sigmoid)(camada_entrada)
dropout1 = Dropout(0.3)(camada_oculta1)
camada_oculta2 = Dense(units = 233, activation = act_sigmoid)(camada_oculta1)
dropout2 = Dropout(0.3)(camada_oculta2)
camada_saida = Dense(units = 1,activation = act_linear)(camada_oculta2)

regressor = Model(inputs = camada_entrada,
                  outputs = [camada_saida])
regressor.compile(optimizer = 'adam',
                  loss = 'mse')
regressor.fit(previsores, [vendas_global],
              epochs = 5000, batch_size = 100)
previsao_global = regressor.predict(previsores)





























