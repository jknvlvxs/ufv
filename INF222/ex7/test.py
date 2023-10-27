from scipy import stats
import numpy as np


# @title Função para exibir intervalo de confiança de uma amostra
def intervalo_confianca(amostra, valor):
    media = np.mean(amostra)
    desvio_padrao_amostra = stats.tstd(amostra)
    n = len(amostra)

    t = stats.t.ppf(valor, n - 1)
    erro_padrao = desvio_padrao_amostra / n**0.5
    intervalo = t * erro_padrao

    print(
        f"Intervalo de Confiança ({valor*100}%): ({media - intervalo:.4f}, {media + intervalo:.4f})"
    )


# Teste de hipótese por outro método além do valor-p
def teste_hipotese(amostra, alfa, media_pop):
    media = np.mean(amostra)
    desvio_padrao_amostra = stats.tstd(amostra)
    n = len(amostra)

    t = (media - media_pop) / (desvio_padrao_amostra / n**0.5)
    t_alfa = stats.t.ppf(alfa, n - 1)

    print(t, t_alfa)

    if t < t_alfa:
        print("Rejeita H0")
    else:
        print("Não rejeita H0")


us_presidents_height = [
    170,
    178,
    182,
    180,
    183,
    178,
    182,
    188,
    175,
    179,
    185,
    192,
    182,
    183,
    177,
    185,
    188,
    189,
]

print("Intervalo de confiança:", intervalo_confianca(us_presidents_height, 0.95))
print("Teste de hipótese:", teste_hipotese(us_presidents_height, 0.05, 175.3))
