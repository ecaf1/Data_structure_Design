import pandas as pd
import matplotlib.pyplot as plt

# Ler dados do CSV
df = pd.read_csv('dados1.csv')

# Criar a figura e os eixos (um para cada gráfico)
fig, axs = plt.subplots(1, 2, figsize=(14, 6))

# Primeiro gráfico: insert_AVL x tree_size
axs[0].plot(df['tree_size'], df['insert_AVL'], label='AVL')
axs[0].set_title('insert_AVL x tree_size')
axs[0].set_xlabel('tree_size')
axs[0].set_ylabel('insert_AVL')

# Segundo gráfico: insert_BinaryTree x tree_size
axs[1].plot(df['tree_size'], df['insert_BinaryTree'], label='Binary Tree', color='r')
axs[1].set_title('insert_BinaryTree x tree_size')
axs[1].set_xlabel('tree_size')
axs[1].set_ylabel('insert_BinaryTree')

y_min = min(df['insert_AVL'].min(), df['insert_BinaryTree'].min())
y_max = max(df['insert_AVL'].max(), df['insert_BinaryTree'].max())

axs[0].set_ylim([y_min, y_max])
axs[1].set_ylim([y_min, y_max])
# Mostrar a legenda
for ax in axs:
    ax.legend()

# Mostrar os gráficos
plt.savefig('Plot_AVLvsBynaryTree.png')
