import random

precisao = [4 / 6, 5 / 6]
probabilidade = [12 / 17, 5, 17]


def duelo(rodadas):
    surv = [0 for _ in range(len(precisao))]

    for _ in range(rodadas):
        while True:
            for i, p in enumerate(precisao):
                if random.random() < p:
                    surv[i] += 1
                    break

    return surv


def print_duelo(rodadas):
    resultado = duelo(rodadas)
    print("\n=== SIMULAÇÃO DE ", rodadas, " DUELOS ===")
    print("Sobrevivente A: ", round(resultado[0] / rodadas, 3))
    print("Sobrevivente B: ", round(resultado[1] / rodadas, 3))


# Precisão de A e B
print("=== PRECISÃO ===")
print("Precisão de A: ", round(precisao[0], 3))
print("Precisão de B: ", round(precisao[1], 3))

# Precisão de A e B
print("\n=== PROBABILIDADE DE SOBREVIVER ===")
print("Probabilidade de A: ", round(12 / 17, 3))
print("Probabilidade de B: ", round(5 / 17, 3))

print_duelo(100)
print_duelo(1000)
print_duelo(10000)
