import matplotlib.pyplot as plt

# Nomes dos métodos de ordenação
metodos = [
    "Selection Sort",
    "Selection Sort Otimizado",
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort"
]

# Tempos em microsegundos
tempos_us = [
    195419,
    323100,
    305183,
    0,
    0
]

# Criar o gráfico
plt.figure(figsize=(10, 6))
plt.bar(metodos, tempos_us, color=["green", "blue", "red", "purple", "orange"])

# Títulos e rótulos
plt.title("Tempo de Execução por Método de Ordenação (vetor já ordenado)")
plt.ylabel("Tempo (µs)")
plt.xticks(rotation=20)
plt.grid(axis='y', linestyle='--', alpha=0.7)

# Mostrar o gráfico
plt.tight_layout()
plt.show()
