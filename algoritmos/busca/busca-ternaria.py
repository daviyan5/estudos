""" 
O algoritmo de busca ternária encontra máximos ou mínimos de funções unimodais, isto é, funções que possuem "seções" crescentes e decrescentes.

"""

import numpy as np                                                      # Importa a biblioteca numpy para calcular o seno
import matplotlib.pyplot as plt                                         # Importa a biblioteca matplotlib para plotar o gráfico

def ternary_search(l, r, f, eps, is_max):
    while l - r > eps:                                                  # Enquanto a diferença entre os limites for maior que a precisão
        m1 = l + (r - l) / 3                                            # Calcula o primeiro terço
        m2 = r - (r - l) / 3                                            # Calcula o segundo terço
        if not (is_max ^ (f(m1) > f(m2))):                              # Se o primeiro terço for maior que o segundo
            r = m2                                                      # Atualiza o limite direito
        else:                                                           # Se o segundo terço for maior que o primeiro
            l = m1                                                      # Atualiza o limite esquerdo
    return (l + r) / 2                                                  # Retorna a média dos limites


def main():
    t = int(input())                                                    # Lê o número de casos de teste
    for i in range(t):
        l, r = map(int, input().split())                                # Lê os limites do intervalo
        f_name = input()                                                # Lê o nome da função
        match f_name:                                                   # Seleciona a função
            case "sen":
                f = np.sin  
            case "cos":
                f = np.cos
            case "saw":
                f = lambda x: x % 2
            case "sqr":
                f = lambda x: (-x ** 2) % 10                                     
        eps = float(input())                                            # Lê a precisão
        is_max = bool(input())                                          # Lê se é máximo ou mínimo

        ans = ternary_search(l, r, f, eps, is_max)                      # Chama a função de busca ternária
        plt.plot(np.linspace(l, r, 100), f(np.linspace(l, r, 100)))     # Plota a função
        plt.plot(ans, f(ans), 'ro')                                     # Plota o ponto de máximo ou mínimo
