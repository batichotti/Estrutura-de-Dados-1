import matplotlib.pyplot as plt

# Dados ajustados
metodos = ["Busca Sequencial", "Busca Binária"]

# Tempo em nanosegundos (µs): 0.005997 s = 5_997_000 µs; busca binária = 1 µs
tempos_ns = [5997, 1]

# Número de comparações: busca sequencial = 1_000_000; busca binária = 20
comparacoes = [1000000, 20]

# Mapeamento das posições horizontais para cada método
posicoes_metodos = {
    "Busca Sequencial": 1,
    "Busca Binária": 2
}

# Preparar lista de posições
x_vals = [posicoes_metodos[m] for m in metodos]

# Primeiro gráfico: Tempo em nanosegundos
fig1, ax1 = plt.subplots(figsize=(8, 5))

# Linhas verticais de referência
for x in posicoes_metodos.values():
    ax1.axvline(x, color='gray', linestyle='--', linewidth=0.5)

# Plotar os tempos em nanosegundos
ax1.plot(x_vals, tempos_ns, marker='o', color='blue', linewidth=2, label="Tempo (µs)")

# Configurações de eixos e layout
ax1.set_ylabel("Tempo (µs)")
ax1.set_xlabel("Método de Busca")
ax1.set_xticks(x_vals)
ax1.set_xticklabels(metodos)
ax1.set_title("Comparação de Tempo de Busca (em µs)")
ax1.legend()
ax1.grid(axis='y', linestyle='--', alpha=0.5)
plt.tight_layout()
plt.show()

# Segundo gráfico: Número de comparações
fig2, ax2 = plt.subplots(figsize=(8, 5))

# Linhas verticais de referência
for x in posicoes_metodos.values():
    ax2.axvline(x, color='gray', linestyle='--', linewidth=0.5)

# Plotar o número de comparações
ax2.plot(x_vals, comparacoes, marker='o', color='green', linewidth=2, label="Comparações")

# Configurações de eixos e layout
ax2.set_ylabel("Número de Comparações")
ax2.set_xlabel("Método de Busca")
ax2.set_xticks(x_vals)
ax2.set_xticklabels(metodos)
ax2.set_title("Comparação de Número de Comparações por Método")
ax2.legend()
ax2.grid(axis='y', linestyle='--', alpha=0.5)
plt.tight_layout()
plt.show()
