#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void Menu_Principal();
void Cadastros();
void Menu_Cadastros_Clientes();
void Menu_Cadastros_Produtos();
void Menu_Vendas();
void Menu_NovaVenda();
void Retirada_de_caixa();
void Abertura_de_caixa();
void menuPagamento();
void pagamento_dinheiro();
void pagamento_cartao();
void fechamento_de_caixa();
void relatorios();
void ListagemClientes();
void ListagemProdutos();
void ListagemVendas();


typedef struct
{

    int Opcao;
    int Cont;
    char OpcaoChar;
    float sangria;
    float caixa[3];
    float valorpago;
    float valortroco;
    int quantidadevendida;
} Sistema;

Sistema Operacoes;

typedef struct
{

    int Codigo;
    char Nome_Completo[100];
    char Nome_Social[100];
    char Cpf[15];
    char Rua_Numero[100];
    char Bairro[50];
    char Celular[15];

} CadastrosClientes;

typedef struct
{

    int CodigoP;
    char Descricao[100];
    char Categoria[50];
    float Compra;
    float Venda;
    float Lucro;
    int QuantidadeE;
    int QuantidadeM;

} CadastrosProdutos;

typedef struct {
    int CodigoProduto;
    int QuantidadeVendida;
    float ValorVenda;
} RegistroVendas;

RegistroVendas *Vendas = NULL;
int numVendas = 0;


CadastrosClientes *Clientes = NULL;
int numClientes = 0;

CadastrosProdutos *Produtos = NULL;
int numProdutos = 0;

float totalVenda;

int main()
{

    system("cls");
    printf("\t\t\t\tSeja Bem Vindo ao sistema de vendas\n");

    Abertura_de_caixa();
    system("cls");
    Menu_Principal();

    return 0;
}

void Menu_Principal()
{

    printf("\t\t\t\t1. Cadastros\n\t\t\t\t2. Vendas\n\t\t\t\t3. Abertura de Caixa\n\t\t\t\t4. Fechamento de Caixa\n\t\t\t\t5. Relatorios\n\t\t\t\t6. Sair\n\t\t\t\tOpcao Desejada\n\t\t\t\t->  ");
    scanf(" %d", &Operacoes.Opcao);

    switch (Operacoes.Opcao)
    {
    case 1:
        system("cls");
        Cadastros();
        break;
    case 2:
        system("cls");
        Menu_Vendas();
        break;
    case 3:
        system("cls");
        Abertura_de_caixa();
        break;
    case 4:
        system("cls");
        fechamento_de_caixa();
        break;
    case 5:
        system("cls");
        relatorios();
        break;
    case 6:
        free(Clientes);
        free(Produtos);
        Operacoes.Cont = 2;
        break;
    default:
        printf("Valor invalido! Por favor digite um numero entre 1 e 6");
        break;
    }
}

void Cadastros()
{

    do
    {
        printf("\t\t\t\tVoce selecionou o  menu Cadastros\n\n");
        printf("\t\t\t\t1- Cadastros de clientes \n\t\t\t\t2- Cadastros de produtos\n\t\t\t\t3- Retornar ao menu principal\n\t\t\t\tOpcao Desejada\n\t\t\t\t->  ");
        scanf(" %d", &Operacoes.Opcao);

        switch (Operacoes.Opcao)
        {
        case 1:
            system("cls");
            Menu_Cadastros_Clientes();
            break;
        case 2:
            system("cls");
            Menu_Cadastros_Produtos();
            break;
        case 3:
            system("cls");
            Menu_Principal();
            break;
        default:
            break;
        }
    } while (Operacoes.Cont == 0);
}

void Menu_Cadastros_Clientes()
{

    printf("\t\t\t\tVoce selecionou o menu Cadastros de Clientes\n\n");

    do
    {
        if (numClientes == 0)
        {
            Clientes = malloc(sizeof(CadastrosClientes));
        }
        else
        {
            Clientes = realloc(Clientes, (numClientes + 1) * sizeof(CadastrosClientes));
        }

        if (Clientes == NULL)
        {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }

        CadastrosClientes *novoCliente = &Clientes[numClientes];

        printf("\t\t\t\tCodigo do cliente: ");
        scanf("%d", &novoCliente->Codigo);

        printf("\t\t\t\tNome completo: ");
        scanf(" %[^\n]", novoCliente->Nome_Completo);

        printf("\t\t\t\tNome social: ");
        scanf(" %[^\n]", novoCliente->Nome_Social);

        printf("\t\t\t\tCpf: ");
        scanf(" %[^\n]", novoCliente->Cpf);

        printf("\t\t\t\tRua/Numero: ");
        scanf(" %[^\n]", novoCliente->Rua_Numero);

        printf("\t\t\t\tBairro: ");
        scanf(" %[^\n]", novoCliente->Bairro);

        printf("\t\t\t\tCelular/Whats: ");
        scanf(" %[^\n]", novoCliente->Celular);

        do
        {
            printf("\t\t\t\tDeseja cadastrar outro cliente?\n\t\t\t\tDigite S para sim ou N para nao: ");
            scanf(" %c", &Operacoes.OpcaoChar);

            if (Operacoes.OpcaoChar != 's' && Operacoes.OpcaoChar != 'n')
            {
                printf("\n\t\t\t\tOpcao invalida! Por favor, digite S para sim ou N para nao.\n\t\t\t\t->");
            }
        } while (Operacoes.OpcaoChar != 's' && Operacoes.OpcaoChar != 'n');

        system("cls");

        numClientes++;

    } while (Operacoes.OpcaoChar == 's' || Operacoes.OpcaoChar == 'S');
}

void Menu_Cadastros_Produtos()
{

    printf("\t\t\t\tVoce selecionou o  menu Cadastros de Produtos\n\n");

    do
    {
        if (numProdutos == 0)
        {
            Produtos = malloc(sizeof(CadastrosProdutos));
        }
        else
        {
            Produtos = realloc(Produtos, (numProdutos + 1) * sizeof(CadastrosProdutos));
        }

        if (Produtos == NULL)
        {
            printf("Erro ao alocar memoria\n");
            exit(1);
        }

        CadastrosProdutos *novoProduto = &Produtos[numProdutos];

        printf("\t\t\t\tCodigo do produto: ");
        scanf("%d", &novoProduto->CodigoP);

        printf("\t\t\t\tDescricao do produto: ");
        scanf(" %[^\n]", novoProduto->Descricao);

        printf("\t\t\t\tCategoria: ");
        scanf(" %[^\n]", novoProduto->Categoria);

        printf("\t\t\t\tPreco da compra: ");
        scanf("%f", &novoProduto->Compra);

        printf("\t\t\t\tPreco da venda: ");
        scanf("%f", &novoProduto->Venda);

        printf("\t\t\t\tMargem de lucro: ");
        scanf("%f", &novoProduto->Lucro);

        printf("\t\t\t\tQuantidade em estoque: ");
        scanf("%d", &novoProduto->QuantidadeE);

        printf("\t\t\t\tQuantidade minima em estoque: ");
        scanf("%d", &novoProduto->QuantidadeM);

        do
        {
            printf("\t\t\t\tDeseja cadastrar outro produto?\n\t\t\t\tDigite S para sim ou N para nao->");
            scanf(" %c", &Operacoes.OpcaoChar);

            if (Operacoes.OpcaoChar != 's' && Operacoes.OpcaoChar != 'n')
            {
                printf("\n\t\t\t\tOpcao invalida! Por favor, digite S para sim ou N para nao.\n\t\t\t\t->");
            }
        } while (Operacoes.OpcaoChar != 's' && Operacoes.OpcaoChar != 'n');

        system("cls");

        numProdutos++;

    } while (Operacoes.OpcaoChar == 's' || Operacoes.OpcaoChar == 'S');
}

void Menu_Vendas()
{
    printf("\t\t\t\tVoce selecionou o  menu de vendas\n\n");

    printf("\t\t\t\t1. Nova Venda\n\t\t\t\t2. Retirada de caixa(Sangria)\n\t\t\t\t3. Pagamento\n\t\t\t\t4. Retornar ao menu principal\n\t\t\t\tOpcao Desejada\n\t\t\t\t-> ");
    scanf("%d", &Operacoes.Opcao);

    switch (Operacoes.Opcao)
    {
    case 1:
        system("cls");
        Menu_NovaVenda();
        break;
    case 2:
        system("cls");
        Retirada_de_Caixa();
        break;
    case 3:
        system("cls");
        menuPagamento();
        break;
    case 4:
        system("cls");
        Menu_Principal();
        break;
    default:
        printf("Opcao Invalida! Por favor digite um numero valido\n");
        break;
    }
}

void Menu_NovaVenda()
{

    printf("\t\t\t\tVoce selecionou o  menu de nova venda\n\n");

    printf("\t\tCodigo\tDescricao\t\tCategoria\tPreco Venda\tQuantidade no estoque\n");

    for (int i = 0; i < numProdutos; i++)
    {
        printf("\t\t%d\t%s\t\t%s\t\tR$%.2f\t\t%dunid\n", Produtos[i].CodigoP, Produtos[i].Descricao, Produtos[i].Categoria, Produtos[i].Compra, Produtos[i].QuantidadeE);
    }

    int codigoProduto;
    printf("\t\t\t\tDigite o codigo do produto para ser vendido\n\t\t\t\t-> ");
    scanf("%d", &codigoProduto);

    int produtoEncontrado = -1;
    for (int i = 0; i < numProdutos; i++)
    {
        if (Produtos[i].CodigoP == codigoProduto)
        {
            produtoEncontrado = i;
            break;
        }
    }

    if (produtoEncontrado == -1)
    {
        printf("\t\t\t\tProduto com codigo %d nao encontrado!\n", codigoProduto);
        return;
    }

    CadastrosProdutos *produtoSelecionado = &Produtos[produtoEncontrado];
    int quantidadeVenda;
    printf("\t\t\t\tDigite a quantidade a ser vendida do produto %s unid: ", produtoSelecionado->Descricao);
    scanf("%d", &quantidadeVenda);
    Operacoes.quantidadevendida += quantidadeVenda;

    if (quantidadeVenda > produtoSelecionado->QuantidadeE)
    {
        printf("\t\t\t\tQuantidade em estoque insuficiente!\n");
        printf("\t\t\t\tVoce deseja vender %d produtos. Ha somento %d\nVoce deseja continuar (s/n)\n\t\t\t\t->?", quantidadeVenda, produtoSelecionado->QuantidadeE);
        scanf(" %c", &Operacoes.OpcaoChar);

        if (Operacoes.OpcaoChar == 's' || Operacoes.OpcaoChar == 'S')
        {
            quantidadeVenda = produtoSelecionado->QuantidadeE;
        }
        else
        {
            printf("\t\t\t\tVenda Cancelada.\n");
            return;
        }
    }

    produtoSelecionado->QuantidadeE -= quantidadeVenda;
    totalVenda = quantidadeVenda * produtoSelecionado->Venda;
    printf("Venda realizada com sucesso! Total: R$%.2f\n", totalVenda);
        if (numVendas == 0)
    {
        Vendas = malloc(sizeof(RegistroVendas));
    }
    else
    {
        Vendas = realloc(Vendas, (numVendas + 1) * sizeof(RegistroVendas));
    }

    if (Vendas == NULL)
    {
        printf("Erro ao alocar memoria para registro de vendas\n");
        exit(1);
    }

    RegistroVendas *novaVenda = &Vendas[numVendas];
    novaVenda->CodigoProduto = codigoProduto;
    novaVenda->QuantidadeVendida = quantidadeVenda;
    novaVenda->ValorVenda = totalVenda;

    numVendas++;

    system("pause");
    system("cls");
    Menu_Vendas();
    system("pause");
    system("cls");
    Menu_Vendas();
}

void Retirada_de_Caixa()
{

    printf("\t\t\t\tVoce selecionou o menu de retirada de caixa\n\n");

    printf("\t\t\t\tQuantos voce quer retirar do caixa: R$\n");
    scanf("%f", &Operacoes.sangria);

    if (Operacoes.sangria <= Operacoes.caixa[2])
    {
        Operacoes.caixa[2] -= Operacoes.sangria;
        printf("\t\t\t\tSangria de R$%.2f realizada com sucesso.\n", Operacoes.sangria);
    }
    else
    {
        printf("\t\t\t\tValor da sangria excede o valor em caixa.\n");
    }

    system("cls");
    Menu_Vendas();
}

void Abertura_de_caixa()
{
    float valorAdicionar;
    printf("\t\t\t\tVoce selecionou o menu de abertura de caixa\n\n");
    printf("\t\t\t\tQuantos voce quer adicionar no caixa: R$");
    scanf("%f", &valorAdicionar);

    if (valorAdicionar >= 0)
    {
        Operacoes.caixa[0] += valorAdicionar; // Atualiza o saldo inicial do caixa
        Operacoes.caixa[1] += valorAdicionar; // Atualiza o saldo atual do caixa
    }
    else
    {
        printf("\t\t\t\tValor invalido! Tente novamente.\n");
        system("cls");
        Abertura_de_caixa();
    }
}

void menuPagamento()
{
    printf("\t\t\t\tVoce selecionou o menu de pagamento\n\n");
    printf("\t\t\t\tValor total a pagar: R$%.2f\n", totalVenda);

    printf("\t\t\t\tDeseja adicionar mais algum item na compra?(S/N)\n\t\t\t\t->");
    scanf(" %c", &Operacoes.OpcaoChar);

    if (Operacoes.OpcaoChar == 's' || Operacoes.OpcaoChar == 'S')
    {
        system("cls");
        Menu_NovaVenda();
    }
    else
    {
        printf("\t\t\t\tDeseja prosseguir ou cancelar com a compra? (S/N)\n\t\t\t\t->");
        scanf(" %c", &Operacoes.OpcaoChar);

        if (Operacoes.OpcaoChar == 's' || Operacoes.OpcaoChar == 'S')
        {
            printf("\t\t\t\tEscolha uma forma de pagamento\n\t\t\t\t1. Cartao\n\t\t\t\t2. Dinheiro\n\t\t\t\t\n\t\t\t\tOpcao desejada\n\t\t\t\t->");
            scanf("%d", &Operacoes.Opcao);

            switch (Operacoes.Opcao)
            {
            case 1:
                pagamento_cartao();
                break;
            case 2:
                pagamento_dinheiro();
                break;
            default:
                printf("\t\t\t\tValor invalido! Por favor digite um numero entre 1 e 2\n");
                break;
            }
        }
        else if (Operacoes.OpcaoChar == 'n' || Operacoes.OpcaoChar == 'N')
        {
            totalVenda = 0;
            Menu_Principal();
        }
    }
}

void pagamento_dinheiro()
{

    printf("\t\t\t\tVoce selecionou pagamento em dinheiro\n\n");
    printf("\t\t\t\tQuantos o cliente pagou R$");
    scanf("%f", &Operacoes.valorpago);

    if (Operacoes.valorpago < totalVenda)
    {
        printf("\t\t\t\tO restante sera pago no cartao? (S/N)\n\t\t\t\t->");
        scanf(" %c", &Operacoes.OpcaoChar);
        if (Operacoes.OpcaoChar == 's' || Operacoes.OpcaoChar == 'S')
        {
            Operacoes.caixa[3] += totalVenda;
            printf("\t\t\t\tValor pago com sucesso!");
            system("pause");

            Menu_Principal();
        }
        else if (Operacoes.OpcaoChar == 'n' || Operacoes.OpcaoChar == 'N')
        {
            system("pause");
            system("cls");
            menuPagamento();
        }
    }
    else if (Operacoes.valorpago >= totalVenda)
    {
        Operacoes.valortroco = Operacoes.valorpago - totalVenda;
        printf("\t\t\t\tO troco vai ser R$%.2f", Operacoes.valortroco);
        Operacoes.caixa[3] += totalVenda;
    }

    system("pause");
    system("cls");
    Menu_Principal();
}

void pagamento_cartao()
{

    printf("\t\t\t\tVoce selecionou pagamento em cartao\n\n");

    printf("\t\t\t\tMaquininha Ok (1) ou Maquininha nao Ok (2)\n\t\t\t\t->");
    scanf("%d", &Operacoes.Opcao);

    if (Operacoes.Opcao == 1)
    {
        printf("\t\t\t\tVenda efetuada com sucesso!");
        Operacoes.caixa[3] += totalVenda;
    }
    else if (Operacoes.Opcao == 2)
    {
        printf("\t\t\t\tPagamento via maquininha sem sucesso. Deseja escolher outra forma de pagamento(S/N)\n\t\t\t\t->");
        scanf(" %c", &Operacoes.OpcaoChar);
    }
    else if (Operacoes.OpcaoChar == 's' || Operacoes.OpcaoChar == 'S')
    {
        system("cls");
        menuPagamento();
    }
    else if (Operacoes.OpcaoChar == 'n' || Operacoes.OpcaoChar == 'N')
    {
        system("cls");
        printf("COMPRA CANCELADA!");
        sleep(4);
        Menu_Principal();
    }
}

void fechamento_de_caixa()
{

    float totalFaturamento = Operacoes.caixa[0] + Operacoes.caixa[1] + Operacoes.caixa[2];
    float valorAbertura = Operacoes.caixa[0];
    float valorDinheiro = Operacoes.caixa[1];
    float valorCartao = Operacoes.caixa[2];
    float valorTotalDinheiroCartao = valorDinheiro + valorCartao;

    if (totalFaturamento - valorAbertura - valorDinheiro - valorCartao - valorTotalDinheiroCartao == 0)
    {
        printf("\t\t\t\t“ATENÇÃO: O caixa não poderá ser fechado porque há divergência de valores.");
    }

    printf("\t\t\t\tFechamento de Caixa\n\n");
    printf("\t\t\t\tQuantidade de vendas realizadas: %d und\n", Operacoes.quantidadevendida);
    printf("\t\t\t\tTotal do faturamento no dia: R$%.2f\n", totalFaturamento);
    printf("\t\t\t\tValor da abertura de caixa: R$%.2f\n", valorAbertura);
    printf("\t\t\t\tValor pago em dinheiro: R$%.2f\n", valorDinheiro);
    printf("\t\t\t\tValor pago em cartao: R$%.2f\n", valorCartao);
    printf("\t\t\t\tValor total pago em dinheiro/cartao: R$%.2f\n", valorTotalDinheiroCartao);
    system("pause");
    exit(1);
}

void relatorios()
{
    printf("\t\t\t\tVoce selecionou relatorio\n\n");

    printf("\t\t\t\t1. Listagem de clientes\n\t\t\t\t2. Listagem de produtos\n\t\t\t\t3. Listagem de vendas\n\t\t\t\t 4. Retornar ao menu pricipal\n\t\t\t\tOpcao desejada\n\t\t\t\t->");
    scanf("%d", &Operacoes.Opcao);

    switch (Operacoes.Opcao)
    {
    case 1:
        system("cls");
        ListagemClientes();
        break;
    case 2:
        system("cls");
        ListagemProdutos();
        break;
    case 3:
        system("cls");
        ListagemVendas();
        break;
    case 4:
        system("cls");
        Menu_Principal();
        break;

    default:
        break;
    }
}

void ListagemClientes(){
         printf("\t\t\t\tVoce selecionou listagem de clientes\n\n");

        for (int i = 0; i < numClientes; i++)
        {
           printf("\t\t\t\tCodigo do cliente: %d\n\t\t\t\tNome completo do cliente: %s\n\t\t\t\tNome social do cliente: %s\n\t\t\t\tCpf do cliente: %s\n\t\t\t\tRua/Numero do cliente: %s\n\t\t\t\tBairro do cliente: %s\n\t\t\t\tCelular do cliente: %s", Clientes[i].Codigo, Clientes[i].Nome_Completo, Clientes[i].Nome_Social, Clientes[i].Cpf, Clientes[i].Rua_Numero, Clientes[i].Bairro, Clientes[i].Celular);
        }

        system("pause");
        system("cls");
        relatorios();
        

}

void ListagemProdutos(){
             printf("\t\t\t\tVoce selecionou listagem de produtos\n\n");
   
    printf("\t\tCodigo\tDescricao\t\tCategoria\tPreco Venda\tQuantidade no estoque\n");

    for (int i = 0; i < numProdutos; i++)
    {
        printf("\t\t%d\t%s\t\t%s\t\tR$%.2f\t\t%dunid\n", Produtos[i].CodigoP, Produtos[i].Descricao, Produtos[i].Categoria, Produtos[i].Compra, Produtos[i].QuantidadeE);
    }


        system("pause");
        system("cls");
        relatorios();

}
void ListagemVendas()
{
    printf("\t\t\t\tVoce selecionou listagem de vendas\n\n");

    printf("\t\tCodigo Produto\tQuantidade Vendida\tValor da Venda\n");

    for (int i = 0; i < numVendas; i++)
    {
        printf("\t\t%d\t\t%d\t\t\tR$%.2f\n", Vendas[i].CodigoProduto, Vendas[i].QuantidadeVendida, Vendas[i].ValorVenda);
    }

    system("pause");
    system("cls");
    relatorios();
}
