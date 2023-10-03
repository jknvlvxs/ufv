import numpy as np
import scipy.stats as stats

from scipy.stats import norm
from scipy.stats import binom
from scipy.stats import poisson

# A rede de um laboratório com 20 computadores recebeu ataque de vírus de computador.
# O vírus entra em cada computador com probabilidade 0.3 independente dos demais computadores.
# Qual a probabilidade do vírus entrar em mais de 10 computadores?
value = 1 - binom.cdf(10, 20, 0.3)
print(np.round(value, 4))

# 5% dos voos de um aeroporto são cancelados por mau tempo.
# Qual a probabilidade de, num conjunto de 16 voos, mais de 2 serem cancelados?
value = 1 - binom.cdf(2, 16, 0.05)
print(np.round(value, 4))

# Certo call-center recebe, em média, 9 chamadas por hora.
# Qual a probabilidade dele receber pelo menos 5 chamadas na próxima hora?
value = 1 - poisson.cdf(4, 9)
print(np.round(value, 4))

# Certo call-center recebe, em média, 9 chamadas por hora.
# Qual a probabilidade dele receber exatamente 5 chamadas na próxima hora?
value = poisson.pmf(5, 9)
print(np.round(value, 4))

# Uma ferramenta de busca procura por uma palavra-chave em uma sequência de websites de forma independente.
# Acredita-se que 30% deles possuem esta palavra-chave.
# Qual a probabilidade de pelo menos 5 dos 10 primeiros websites possuírem a palavra-chave?
value = 1 - binom.cdf(4, 10, 0.3)
print(np.round(value, 4))

# E de visitar pelo menos 5 websites até achar o primeiro que tenha a palavra-chave?
value = 1 - binom.cdf(4, 10, 0.7)
print(np.round(value, 4))

# Falhas na conexão de um provedor são eventos raros e inesperados que ocorrem a cada 3 semanas, em média.
# Qual a probabilidade de haver mais de 5 falhas num período de 21 semanas?
value = 1 - poisson.cdf(5, 7)
print(np.round(value, 4))
