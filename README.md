O código implementa um sistema de vendas completo em C, utilizando estruturas de dados, alocação dinâmica de memória e funções para organizar as diferentes funcionalidades. O sistema permite o gerenciamento de cadastros de clientes e produtos, registro de vendas, controle de caixa e geração de relatórios.

Estrutura do Sistema

O código é estruturado em diversas funções, cada uma responsável por uma parte específica do sistema:

Menu Principal: Exibe o menu principal com opções para cadastros, vendas, abertura/fechamento de caixa e relatórios.
Cadastros: Gerencia os cadastros de clientes e produtos, permitindo a inserção, edição e exclusão de dados.
Vendas: Permite o registro de novas vendas, incluindo a seleção de produtos, quantidade e cálculo do valor total.
Abertura de Caixa: Registra o valor inicial do caixa no início do dia.
Retirada de Caixa: Permite a retirada de valores do caixa.
Pagamento: Gerencia o pagamento das vendas, aceitando dinheiro ou cartão.
Fechamento de Caixa: Calcula e exibe o total de vendas em dinheiro, cartão e o valor geral do caixa.
Relatórios: Gera relatórios de clientes, produtos e vendas.
Armazenamento de Dados

O sistema utiliza estruturas de dados para armazenar as informações de clientes, produtos e vendas:

CadastrosClientes: Estrutura que armazena os dados de cada cliente (código, nome completo, nome social, CPF, endereço e celular).
CadastrosProdutos: Estrutura que armazena os dados de cada produto (código, descrição, categoria, preço de compra, preço de venda, lucro, quantidade em estoque e quantidade mínima).
RegistroVendas: Estrutura que armazena os dados de cada venda (código do produto, quantidade vendida e valor da venda).
Alocação Dinâmica de Memória

O sistema utiliza alocação dinâmica de memória (malloc e realloc) para criar listas de clientes, produtos e vendas que podem crescer conforme necessário, evitando o desperdício de memória.
