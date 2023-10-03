# Projeto de Conclusão de Curso de Estrutura de Dados

## Principais Tópicos

### 1. Construir um Compactador de Arquivos Utilizando a Estrutura Huffman
Neste tópico, o foco é na implementação de um compactador de arquivos baseado na codificação de Huffman. O objetivo é otimizar o armazenamento através da compressão eficiente de arquivos.

### 2. Apresentar Seminário Sobre um Algoritmo Específico
Aqui, o objetivo é apresentar um seminário detalhado sobre um algoritmo específico relacionado ao projeto. Isso pode envolver discussões aprofundadas sobre a teoria, aplicações práticas e possíveis limitações do algoritmo escolhido.

### 3. Comparação Entre Árvores AVL e Árvores Binárias Não Balanceadas

#### Introdução

Este tópico tem como objetivo realizar uma análise comparativa entre a inserção em duas diferentes estruturas de dados: Árvores AVL e Árvores Binárias Não Balanceadas. A análise considera os cenários de melhor e pior caso para entender as eficiências e ineficiências inerentes a cada estrutura.

#### Metodologia

Foram gerados dados aleatórios para a inserção em ambas as estruturas. O número de interações necessárias para completar cada inserção foi contabilizado e armazenado. O conjunto de dados foi então analisado para determinar os tempos de inserção médios, mínimos e máximos para cada estrutura.

#### Resultados

Os resultados obtidos estão apresentados no gráfico abaixo, que compara o número médio de interações necessárias para a inserção em cada estrutura de dados.

![Inserção Comparativa](./Unbalanced_tree_vs_AVL/Plot_AVLvsBynaryTree.png)

#### Conclusões

A análise comparativa claramente aponta para as vantagens e desvantagens intrínsecas de cada estrutura de dados examinada. A Árvore AVL, com sua propriedade de balanceamento, assegura uma eficiência de tempo de inserção em \(O(log n)\). Isso foi empiricamente validado durante o experimento.

Por outro lado, a Árvore de Busca Binária não balanceada (BST) pode, no pior caso, degradar para uma eficiência de \(O(n)\) em suas operações de inserção, transformando-se essencialmente em uma lista ligada.

Em resumo, a eficiência na inserção de novos elementos é significativamente melhor na Árvore AVL em comparação com a BST não balanceada, o que se reflete na complexidade de tempo de cada estrutura. A escolha entre as duas deve, portanto, considerar o equilíbrio entre a complexidade de implementação e a eficiência de operação, especialmente em contextos onde inserções frequentes são requeridas.



### 4. Construir Casos de Teste Para Estruturas Primitivas Usadas no Compactador
Finalmente, o objetivo é construir uma suíte robusta de casos de teste para avaliar a eficácia e eficiência das estruturas de dados primitivas usadas no compactador. Isso ajudará a validar a integridade do sistema de compressão.

