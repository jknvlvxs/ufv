import random

pA = 4 / 6  # Precisão de A
pB = 5 / 6  # Precisão de B
pC = 2 / 6  # Precisão de C


def busca_vivo_de_maior_precisao(alive):
    if alive[0] and alive[1] and alive[2]:
        if pA > pB and pA > pC:
            return 0
        elif pB > pA and pB > pC:
            return 1
        else:
            return 2
    elif alive[0] and alive[1]:
        if pA > pB:
            return 0
        else:
            return 1
    elif alive[0] and alive[2]:
        if pA > pC:
            return 0
        else:
            return 2
    elif alive[1] and alive[2]:
        if pB > pC:
            return 1
        else:
            return 2
    elif alive[0]:
        return 0
    elif alive[1]:
        return 1
    else:
        return 2


def duelo_1(rodadas):
    survA = 0
    survB = 0
    survC = 0

    for _ in range(rodadas):
        alive = [True, True, True]
        while True:
            if random.random() < pA:
                alive[busca_vivo_de_maior_precisao(alive)] = False

            if random.random() < pB:
                alive[busca_vivo_de_maior_precisao(alive)] = False

            if random.random() < pC:
                alive[busca_vivo_de_maior_precisao(alive)] = False

            if alive[0] and not alive[1] and not alive[2]:
                survA += 1
                break

            if not alive[0] and alive[1] and not alive[2]:
                survB += 1
                break

            if not alive[0] and not alive[1] and alive[2]:
                survC += 1
                break

    return survA, survB, survC
