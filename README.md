# Sistema de Gestão de Vendas em C 📊

Este projeto foi desenvolvido como parte dos estudos de **Engenharia de Software**, com foco na implementação de algoritmos de ordenação e manipulação de estruturas de dados na linguagem **C**.

O sistema permite o registro de vendas por filial e gera um relatório mensal detalhado, aplicando técnicas de ordenação composta para organizar os dados por filial e, subsequentemente, por nome de vendedor.

## 🚀 Funcionalidades

* **Registro de Vendas:** Cadastro de filial, nome do vendedor e total vendido (limite de 20 registros).
* **Algoritmo Bubble Sort Otimizado:**
    * `bubbleSortFilial`: Agrupa as vendas pelo código da filial.
    * `bubbleSortNomes`: Critério de desempate que ordena vendedores alfabeticamente dentro da mesma filial.
* **Relatório com Quebra de Nível:** * Cálculo automático de **Subtotais por Filial**.
    * Cálculo do **Total Geral** de todas as operações.
    * Interface limpa utilizando `system("cls")` e formatação de colunas.

## 🛠️ Tecnologias e Conceitos

* **Linguagem:** C
* **Conceitos de Programação:**
    * `structs` para modelagem de dados.
    * Passagem de arrays por referência.
    * Manipulação de strings com `string.h` (`strcmp`, `strcpy`).
    * Lógica de acumulação e controle de loops aninhados.

## 📋 Lógica de Ordenação

Para garantir que o relatório apresente os dados agrupados corretamente, o sistema executa uma ordenação em dois níveis. Primeiro, as filiais são colocadas em ordem; depois, o algoritmo percorre a lista e, sempre que encontra a mesma filial, organiza os nomes dos vendedores.



## 💻 Como Executar

1.  Certifique-se de ter um compilador C (como o GCC) instalado.
2.  Clone o repositório:
    ```bash
    git clone [https://github.com/seu-usuario/nome-do-repositorio.git](https://github.com/seu-usuario/nome-do-repositorio.git)
    ```
3.  Compile o código:
    ```bash
    gcc main.c -o sistema_vendas
    ```
4.  Execute o programa:
    ```bash
    ./sistema_vendas
    ```

## 📄 Exemplo de Relatório Gerado

```text
***** RELATORIO MENSAL DE VENDAS       *****
                 ABRIL DE 2026      
-------------------------------------------------------
FILIAL          VENDEDOR                       VENDAS
-------------------------------------------------------
01
                Ana                           1500.00
                Bruno                         1200.00
                -------------------           2700.00
                Subtotal Filial             

02
                Carlos                         800.00
                -------------------            800.00
                Subtotal Filial             
-------------------------------------------------------
                TOTAL GERAL                   3500.00
-------------------------------------------------------
