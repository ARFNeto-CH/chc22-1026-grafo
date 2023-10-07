#include<stdio.h>
#include<locale.h>
#include<string.h>
int login() {
    char login[15] = "teste"; //Tem que ter mais espaço que a string. Pelo menos 1 a mais que a palavra.
    char login1[15]; //Pode ser do mesmo tamanho que o login
    char senha[15] = "teste";
    char senha1[15];

    printf("LOGIN: ");
    scanf("%s", login1); //String se lê com %s
    if (strcmp(login, login1) == 0) //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
    {
        printf("Logado\n");
    }
    else
    {
        printf("error\n");
    }

    return 0;
}
struct cadastro
{
    char CPF[200];
    char telefone[200];
    char nome[200];
    char endereco[200];
    char data[200];
    char Email[200];
    char dataDiaginostico[200];
    char comobidade[200];
    char datanacimento[200];
    char idade[200];
    int vazio, cod;

}log[200];
//AQUI DECLARO AS FUNÇÕES A SEREM USADAS
int verifica_pos(void);
int verifica_cod(int cod);
int opt;
void cadastroP(int cod, int pos);
void list();
void consultaCod(void);
void excluirPaciente(void);

int main(void) {//INICIO DO MAIN
    int i, Opcao, OpcaoPaciente, posicao, retorno;
    int codaux;
    do
    {
        printf("1 - Cadastrar Novo Paciente\n");
        printf("2 - Pacientes Cadastrados\n");
        printf("3 - Alterar Dados do Paciente\n");
        printf("4 - Excluir Dados do Paciente\n");
        printf("5 - Sair\n");
        printf(" Selecione uma opcao por favor: ");
        scanf("%d", &Opcao);
        getchar();
        if (Opcao == 1)
        {
            printf("voce selecionou a opcao 1 - Cadastrar Novo Paciente\n");
            posicao = verifica_pos();

            if (posicao != -1)
            {

                printf("\nNumero para cadastro do paciente: \n");
                scanf("%d", &codaux); fflush(stdin);

                retorno = verifica_cod(codaux);

                if (retorno == 1)
                    cadastroP(codaux, posicao);
                else {
                    printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                    getchar();
                    system("cls");
                    main();
                }

            }
            else
                printf("\nNao e possível realizar mais cadastros!\n");

            break;

        }
        else if (Opcao == 2)
        {
            system("cls");
            do {
                printf("voce selecionou a opcao 2 - Pacientes\n\n");
                printf("1 - Pesquisar Paciente por codigo\n");
                printf("2 - Listar todos os Pacientes\n");
                printf("3 - Voltar ao menu principal\n");
                printf("Selecione uma opcao por favor: ");
                scanf("%d", &OpcaoPaciente);
                getchar();
                if (OpcaoPaciente == 1) {
                    consultaCod();
                }
                else if (OpcaoPaciente == 2) {
                    list();
                }
                else if (OpcaoPaciente == 3) {
                    printf("voce selecionou voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else
                    printf("Opcao Invalida\n\n");
            } while (OpcaoPaciente = !3 || OpcaoPaciente > 3 || OpcaoPaciente < 0 || OpcaoPaciente == 0);
        }
        else if (Opcao == 3)
        {
            printf("voce selecionou a opcao 3 - Alterar Paciente\n");
        }
        else if (Opcao == 4)
        {
            printf("voce selecionou a opcao 4 - Excluir Paciente\n");
            excluirPaciente();
        }

        else if (Opcao == 5)
        {
            printf("voce selecionou a opcao 5 - Sair\n");
        }
        else {
            printf("Opcao invalida, favor pressione enter para voltar ao menu principal");
            getchar();
            system("cls");
        }
    } while (Opcao != 5 || Opcao < 5);

} // FIM DO MAIN
void list() { // Lista os usuarios cadastrados.
    int i, j;
    for (i = 0; i < 200; i++) {
        if (log[i].cod != NULL) {
            printf("\nCodigo: %d \nNome: %s\nCPF: %s\nIdade: %s\nDatadenacimento: %s\nEndereco: %s\nTelefone: %s\nEmail: %s\ncomorbidade: %s\n\n", log[i].cod,
                log[i].nome,
                log[i].CPF, log[i].idade, log[i].datanacimento,
                log[i].endereco, log[i].telefone, log[i].Email, log[i].comobidade);
        }
    }
    printf("Pressione enter para volta ao menu principal");
    getchar();
    system("cls");

} //FIM DO LIST
void cadastroP(int cod, int pos) { //Cadastro das pessoas
    int i;
    do {
        pos = verifica_pos();
        log[pos].cod = cod;
        printf("\nDigite o nome do Paciente: ");
        gets(log[pos].nome);
        printf("\nDigite o CPF do Paciente: ");
        gets(log[pos].CPF);
        printf("\nDigite a Idade do Paciente: ");
        gets(log[pos].idade);
        printf("\nDigite a Data de nacimento do Paciente: ");
        gets(log[pos].datanacimento);
        printf("\nDigite o Endereco do Paciente: ");
        gets(log[pos].endereco);
        printf("\nDigite o Telefone do Paciente: ");
        gets(log[pos].telefone);
        printf("\nDigite o Email do Paciente: ");
        gets(log[pos].Email);
        printf("\nDigite a comobidade do Paciente: ");
        gets(log[pos].comobidade);
        log[pos].vazio = 1;
        //printf("\nDigite enter para efetuar novo cadastro ou qualquer outra tecla para volar ao menu principal");
        //scanf("%d", &opt);
        opt == 1;
        getchar();
    } while (opt == 1);
    system("cls");
    main();

} // FIM DO CADASTRO DE PESSOAS
int verifica_pos(void) //VERIFICADOR DA POSIÇÃO
{
    int cont = 0;

    while (cont <= 200)
    {

        if (log[cont].vazio == 0)
            return(cont);

        cont++;

    }

    return(-1);

} // FIM DO VERIFICADOR
int verifica_cod(int cod) // VERIFICADOR DE CÓDIGO
{
    int cont = 0;

    while (cont <= 200)
    {
        if (log[cont].cod == cod)
            return(0);

        cont++;
    }

    return(1);

} // FIM DO VERIFICADOR

void consultaCod(void) // CONSULTAR 1 CADASTRADO QUALQUER VIA CÓDIGO DADO POR USUÁRIO.
{
    int cont = 0, cod;

    printf("\nEntre com o codigo\n");
    scanf("%d", &cod);
    fflush(stdin);
    system("cls");

    while (cont <= 200)
    {

        if (log[cont].cod == cod)
        {
            if (log[cont].vazio == 1)
            {

                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nIdade: %s\nDatadenacimento: %s\nEndereco: %s\nTelefone: %s\nEmail: %s\ncomorbidade: %s\n\n",
                    log[cont].cod,
                    log[cont].nome, log[cont].CPF, log[cont].idade, log[cont].datanacimento, log[cont].endereco, log[cont].telefone, log[cont].Email, log[cont].comobidade);


                system("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if (cont > 200) {
            printf("\nCodigo não encontrado, pressione enter para volar ao menu principal\n");
            getchar();
            system("cls");
        }

    }
} // FIM DA FUNÇÃO CONSULTAR
void excluirPaciente(void)  // EXCLUI Paciente
{
    int cod, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod);

    while (cont <= 200)
    {

        if (log[cont].cod == cod)
        {

            if (log[cont].vazio == 1)
            {
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nIdade: %s\nDatadenacimento: %s\nEndereco: %s\nTelefone: %s\nEmail: %s\ncomorbidade: %s\n\n", log[cont].cod, log[cont].nome, log[cont].CPF, log[cont].endereco, log[cont].telefone);
                getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s", &resp);

                if ((resp == 'S') || (resp == 's'))
                {
                    log[cont].vazio = 0;
                    log[cont].cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ((resp == 'N') || (resp == 'n'))
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if (cont > 200)
            printf("\nCodigo não encontrado\n");

    }

    system("pause");
    system("cls");

}