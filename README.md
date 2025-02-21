# Cálculo de Deslocamento e Amplitudes de Pêndulos

Este repositório contém o código-fonte do trabalho prático 02 na área de Métodos Numéricos I. O projeto foi desenvolvido em **C++** e é projetado para sistemas operacionais **Linux**. A aplicação visa calcular os deslocamentos e as amplitudes de pêndulos oscilantes com base em sistemas lineares, utilizando métodos como **Gauss**, **Gauss-Jordan** e **Regra de Cramer**.

O programa implementa uma análise de pêndulos, calculando deslocamentos e amplitudes para diferentes matrizes de coeficientes \(C\) e vetores de termos independentes \(v\).

# Informações Técnicas

## Organização de pastas
O projeto está organizado da seguinte forma:

```
C:.
│   .gitignore         # Arquivo de exclusão para versionamento no Git
│   README.md          # Documentação do projeto
│   Makefile           # Arquivo de build
│
├───bin                # Contém os executáveis gerados
│       main           # Executável principal
│
├───itens              # Implementação das questões específicas do trabalho
│       itemA.cpp      # Código para o cálculo de d pelo método de Gauss
│       itemB.cpp      # Código para o cálculo de d pelo método de Gauss-Jordan
│       itemC.cpp      # Código para o cálculo de d pela Regra de Cramer
│       itemD.cpp      # Análise de pêndulos, cálculos de amplitudes e verificações
│
└───src                # Código fonte e implementação dos métodos
        sistemas.cpp   # Implementações dos métodos Gauss, Gauss-Jordan, Cramer e cálculos auxiliares
        sistemas.hpp   # Cabeçalhos dos métodos numéricos
        main.cpp       # Arquivo principal para execução interativa
```

## Dados de Entrada e Saída

### Dados de Entrada
- **\(n\)**: Número de pêndulos.
- **\(a\)**: Parâmetro multiplicativo para calcular a amplitude (valor fornecido pelo usuário).
- **Matriz \(C\)**: Matriz de coeficientes \(n x n\).
- **Vetor \(v\)**: Vetor de termos independentes \(n x 1\).

### Dados de Saída
- **Vetor de deslocamentos \(d\)**: Vetor contendo os deslocamentos de cada pêndulo.
- **Amplitudes**: Vetores contendo as amplitudes de cada pêndulo calculadas como \(a $\cdot$ d_i\).
- **Quadro de Respostas**: Tabelas com os resultados dos cálculos para cada método e para diferentes valores de \(C\) e \(v\).

## Funcionalidades

A aplicação implementa as seguintes funcionalidades:

1. **Cálculo de deslocamentos \(d\) pelo método de Gauss**:  
   - Implementa a eliminação gaussiana para resolver o sistema linear \(C $\cdot$ d = v\).

2. **Cálculo de deslocamentos \(d\) pelo método de Gauss-Jordan**:  
   - Utiliza o método de Gauss-Jordan para reduzir a matriz \(C\) até a matriz identidade e obter as soluções.

3. **Cálculo de deslocamentos \(d\) pela regra de Cramer**:  
   - Utiliza determinantes para calcular os deslocamentos de cada pêndulo, usando a fórmula \(d_i = $\frac{\text{det}(C_i)}{\text{det}(C)}$\).

4. **Calibração do sistema**:  
   - Executa testes com valores padrão para \(a = 1\), \(C\) e \(v\) fornecidos, e calcula os deslocamentos e amplitudes resultantes.

5. **Execução de testes variando os parâmetros**:  
   - Permite ao usuário inserir valores personalizados para a matriz \(C\) e o vetor \(v\), e calcula os deslocamentos e amplitudes com diferentes métodos.

6. **Análise dos resultados**:  
   - Verifica se as amplitudes ultrapassam 3 cm, sinalizando se algum pêndulo pode romper.

7. **Quadro comparativo de resultados**:  
   - Exibe uma comparação entre os métodos de Gauss e Gauss-Jordan para diferentes entradas.

# Como Rodar

### Pré-requisitos
- Sistema operacional **Linux**.
- Compilador **g++** instalado.
- Terminal para executar os comandos.

### Passos para execução

1. **Clone o repositório**:
   ```bash
   git clone <https://github.com/EstherMart/MN01_Sistemas_Equacoes-.git>
   cd <local/que/foi/salvo/MN01_Sistemas_Equacoes>

2. **Navegue até a pasta `bin`**:
    ```bash
    cd bin
    ```

3. **Execute o programa:**
    ```bash
    ./main
    ```

O programa exibirá um menu no terminal para escolher entre usar a matriz padrão ou inserir novos valores para para a matriz \(C\) e o vetor \(v\). Os resultados dos cálculos de deslocamento e amplitude serão apresentados, e a conclusão se os pêndulos irão romper ou não, levando em consideração a matriz da questão, serão debatidos durante a apresentação (mas podem ser observados compilando e executando o `item_a.cpp` e o `item_b.cpp` onde fizemos a análise no output).

