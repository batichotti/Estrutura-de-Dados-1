import matplotlib.pyplot as plt

# Nomes dos métodos de ordenação
metodos = [
    "Selection Sort",
    "Selection Sort Otimizado",
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort"
]

# Número de trocas (Insertion Sort com 0 trocas conforme solicitado)
trocas = [
    10000,  # Selection Sort
    0,      # Selection Sort Otimizado
    0,      # Bubble Sort
    0,      # Bubble Sort Otimizado
    0       # Insertion Sort
]

# Criar gráfico de barras
plt.figure(figsize=(10, 6))
plt.bar(metodos, trocas, color=["green", "blue", "red", "purple", "orange"])

# Títulos e rótulos
plt.title("Número de Trocas por Método de Ordenação (vetor já ordenado)")
plt.ylabel("Número de Trocas")
plt.xticks(rotation=20)
plt.grid(axis='y', linestyle='--', alpha=0.7)

# Mostrar o gráfico
plt.tight_layout()
plt.show()
