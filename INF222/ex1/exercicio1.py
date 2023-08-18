# Vetor de dados com idade das atrizes
atrizes = [
    22,37,28,63,32,26,31,27,27,28,30,26,29,24,38,25,29,41,30,35,35,33,29,38,54,24,25,46,41,28,40,39,29,27,31,38,29,25,35,60,43,35,34,34,17,37,42,41,36,32,41,33,31,74,33,50,38,61,21,41,26,80,42,19,33,35,45,49,39,34,26,25,33,35,35,28
]
# Vetor de dados com idade dos atores
atores = [
    44,41,62,52,41,34,34,52,41,37,38,34,32,40,43,56,41,39,49,57,41,38,42,52,51,35,30,39,41,44,49,35,47,31,47,37,57,42,45,42,44,62,43,42,48,49,56,38,60,30,40,42,36,76,39,53,45,36,62,43,51,32,42,54,52,37,38,32,45,60,46,40,36,47,29,43,
]

# Função que calcula média
def media(lista):
    soma = 0
    for i in lista:
        soma += i
    return soma / len(lista)


# Função que calcula mediana
def mediana(lista):
    lista.sort()
    meio = int(len(lista) / 2)
    if len(lista) % 2 == 0:
        return (lista[meio - 1] + lista[meio]) / 2
    else:
        return lista[meio]


# Função que calcula moda
def moda(lista):
    qtd_count = 0
    moda = 0
    for i in lista:
        if lista.count(i) > qtd_count:
            qtd_count = lista.count(i)
            moda = i
    return moda


# Função que calcula ponto médio
def ponto_medio(lista):
    lista.sort()
    return (lista[0] + lista[-1]) / 2


# Função que calcula amplitude
def amplitude(lista):
    lista.sort()
    return lista[-1] - lista[0]


# Função que calcula variância amostral
def variancia(lista):
    soma = 0
    for i in lista:
        soma += (i - media(lista)) ** 2
    return soma / (len(lista) - 1)


# Função que calcula desvio padrão
def desvio_padrao(lista):
    return variancia(lista) ** 0.5


# Função que calcula coeficiente de variação
def coeficiente_variacao(lista):
    return (desvio_padrao(lista) / media(lista)) * 100


# Print como tabela dos valores calculados
from tabulate import tabulate

tabela = [
    [
        "Atrizes",
        round(media(atrizes), 1),
        mediana(atrizes),
        moda(atrizes),
        ponto_medio(atrizes),
        amplitude(atrizes),
        round(desvio_padrao(atrizes), 2),
        round(variancia(atrizes), 2),
        f"{round(coeficiente_variacao(atrizes), 2)}%",
    ],
    [
        "Atores",
        round(media(atores), 1),
        mediana(atores),
        moda(atores),
        ponto_medio(atores),
        amplitude(atores),
        round(desvio_padrao(atores), 2),
        round(variancia(atores), 2),
        f"{round(coeficiente_variacao(atores), 2)}%",
    ],
]

print(
    tabulate(
        tabela,
        headers=[
            "Média",
            "Mediana",
            "Moda",
            "Ponto Médio",
            "Amplitude",
            "Desvio Padrão",
            "Variância",
            "Coeficiente de Variação",
        ],
    )
)


# Função que calcula a frequência absoluta
def frequencia_absoluta(lista, min, max):
    lista.sort()
    qtd = 0
    for i in lista:
        if i >= min and i <= max:
            qtd += 1
    return qtd


# Função que calcula a frequência relativa
def frequencia_relativa(lista, min, max):
    return round(frequencia_absoluta(lista, min, max) / len(lista) * 100)


# Função que calcula frequência acumulada
def frequencia_acumulada(lista, max):
    return frequencia_absoluta(lista, 0, max)


# Funcão que calcula frequência relativa acumulada
def frequencia_relativa_acumulada(lista, max):
    return round(frequencia_acumulada(lista, max) / len(lista) * 100)


# Print como tabela dos valores calculados
def tabela_frequencia(lista):
    tabela = [
        [
            "≤ 30",
            frequencia_absoluta(lista, 0, 30),
            f"{(frequencia_relativa(lista, 0, 30))}%",
            frequencia_acumulada(lista, 30),
            f"{(frequencia_relativa_acumulada(lista, 30))}%",
        ],
        [
            "31-40",
            frequencia_absoluta(lista, 31, 40),
            f"{(frequencia_relativa(lista, 31, 40))}%",
            frequencia_acumulada(lista, 40),
            f"{(frequencia_relativa_acumulada(lista, 40))}%",
        ],
        [
            "41-50",
            frequencia_absoluta(lista, 41, 50),
            f"{(frequencia_relativa(lista, 41, 50))}%",
            frequencia_acumulada(lista, 50),
            f"{(frequencia_relativa_acumulada(lista, 50))}%",
        ],
        [
            "51-60",
            frequencia_absoluta(lista, 51, 60),
            f"{(frequencia_relativa(lista, 51, 60))}%",
            frequencia_acumulada(lista, 60),
            f"{(frequencia_relativa_acumulada(lista, 60))}%",
        ],
        [
            "61-70",
            frequencia_absoluta(lista, 61, 70),
            f"{(frequencia_relativa(lista, 61, 70))}%",
            frequencia_acumulada(lista, 70),
            f"{(frequencia_relativa_acumulada(lista, 70))}%",
        ],
        [
            "≥ 71",
            frequencia_absoluta(lista, 71, 100),
            f"{(frequencia_relativa(lista, 71, 100))}%",
            frequencia_acumulada(lista, 100),
            f"{(frequencia_relativa_acumulada(lista, 100))}%",
        ],
        [
            "Total (Σ)",
            len(lista),
            "100%",
            "-",
            "-",
        ],
    ]

    print(
        tabulate(
            tabela,
            headers=[
                "Idade",
                "Frequência absoluta",
                "Frequência relativa",
                "Frequência acumulada",
                "Frequência relativa acumulada",
            ],
        )
    )


print("\nTabela de frequência para atrizes")
tabela_frequencia(atrizes)

print("\nTabela de frequência para atores")
tabela_frequencia(atores)
