import matplotlib.pyplot as plt

# Dados
tamanhos_entrada = ["Pequena (21.700)", "Média (121.500)", "Grande (298.000)"]
metodos = [
    "Selection Sort",
    "Selection Sort Otimizado",
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort"
]

tempos = {
    "Selection Sort": [0.959995, 29.0447, 170.245],
    "Selection Sort Otimizado": [1.52307, 43.9174, 265.838],
    "Bubble Sort": [3.03869, 93.8633, 572.84],
    "Bubble Sort Otimizado": [2.67933, 83.2082, 511.696],
    "Insertion Sort": [0.86772, 10.1044, 156.565]
}

cores = ['green', 'blue', 'red', 'purple', 'orange']

# Mapeando posições horizontais
posicoes_entrada = {
    "Pequena (21.700)": 1,
    "Média (121.500)": 2,
    "Grande (298.000)": 3
}

# Criar gráfico
fig, ax = plt.subplots(figsize=(10, 6))

# Linhas verticais de referência
for x in posicoes_entrada.values():
    ax.axvline(x, color='gray', linestyle='--', linewidth=0.5)

# Plotar tempos
for i, metodo in enumerate(metodos):
    tempos_metodo = tempos[metodo]
    x_vals = list(posicoes_entrada.values())
    ax.plot(x_vals, tempos_metodo, marker='o', label=metodo, color=cores[i], linewidth=2)

# Eixos e layout
ax.set_ylabel("Tempo (s)")
ax.set_xlabel("Tamanho da Entrada")
ax.set_xticks(list(posicoes_entrada.values()))
ax.set_xticklabels(tamanhos_entrada)
ax.set_title("Comparação de Tempo por Método de Ordenação")
ax.legend()
plt.tight_layout()
plt.grid(axis='y', linestyle='--', alpha=0.5)

plt.show()