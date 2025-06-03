import matplotlib.pyplot as plt

# Dados de Trocas/Deslocamentos
tamanhos_entrada = ["Pequena (21.700)", "Média (121.500)", "Grande (298.000)"]
metodos = [
    "Selection Sort",
    "Selection Sort Otimizado",
    "Bubble Sort",
    "Bubble Sort Otimizado",
    "Insertion Sort"
]

trocas = {
    "Selection Sort": [21699, 121499, 297999],
    "Selection Sort Otimizado": [21691, 121487, 297980],
    "Bubble Sort": [118128507, 3691889981, 22206496215],
    "Bubble Sort Otimizado": [118128507, 3691889981, 22206496215],
    "Insertion Sort": [118150206, 3692011480, 22206794214]
}

cores = ['green', 'blue', 'red', 'purple', 'orange']

# Mapeando posições horizontais para cada tamanho de entrada
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

# Plotar as séries de Trocas/Deslocamentos
for i, metodo in enumerate(metodos):
    valores_trocas = trocas[metodo]
    x_vals = list(posicoes_entrada.values())
    ax.plot(x_vals, valores_trocas, marker='o', label=metodo, color=cores[i], linewidth=2)

# Configurações de rótulos e layout
ax.set_ylabel("Trocas/Deslocamentos")
ax.set_xlabel("Tamanho da Entrada")
ax.set_xticks(list(posicoes_entrada.values()))
ax.set_xticklabels(tamanhos_entrada)
ax.set_title("Comparação de Trocas/Deslocamentos por Método de Ordenação")
ax.legend()
plt.tight_layout()
plt.grid(axis='y', linestyle='--', alpha=0.5)

plt.show()
