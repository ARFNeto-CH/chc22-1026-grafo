#include <stdio.h>

#include <stdlib.h>

#include <locale.h>

#include <string.h>

int opcao = 0;

void tela_login()
{

    char login[15] = "2264585";

    char login1[15];

    char senha[15] = "2264585";

    char senha1[15];

    int login_efetuado = 0;

    while (!login_efetuado)
    {

        printf("LOGIN: \n");

        scanf("%s", login1);

        printf("SENHA: \n");

        scanf("%s", senha1);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0)
        {

            printf("\n\nLOGADO!\n\n");

            login_efetuado = 1;
        }

        else
        {

            printf("\n\nDADOS INVALIDOS!\n\n");
        }
    }
}

void mostrar_menu()
{

    printf("*************\n\n");

    printf("***SEJA BEM-VINDO***\n\n");

    printf("*************\n\n");

    printf("1) - CADASTRO DE PACIENTES\n");

    printf("2) - SAIR DO SISTEMA\n\n");

    printf("DIGITE A OPCAO DESEJADA: ");

    scanf("%d", &opcao);

    getchar();
}

char *remove_nova_linha(char *texto)
{

    char *pos;

    if ((pos = strchr(texto, '\n')) != NULL)

        *pos = '\0';

    return texto;
}

void verificar_grupo_risco(char *data_de_nascimento, char *comorbidade, char *endereco)
{

    if (strcmp(comorbidade, "") == 0)

        return;

    // TODO: Calcular a idade

    int idade = 0;

    // TODO: pegar o CEP do endereco

    char cep[20] = "";

    if (idade > 65)
    {

        FILE *ponteiro = fopen("grupo_risco.txt", "a+");

        fprintf(ponteiro, "%d, %s\n", idade, cep);

        fclose(ponteiro);
    }
}

void cadastro_pacientes()
{

    char nome[255];

    char cpf[255];

    char telefone[255];

    char endereco[255];

    char data_de_nascimento[255];

    char email[255];

    char data_do_diagnostico[255];

    char comorbidade[255];

    int contador;

    FILE *ponteiro;

    printf("\n\nAdicione os dados do Cliente\n");

    ponteiro = fopen("pacientes.txt", "a+");

    do
    {

        printf("Digite o nome do Paciente: \n");

        fgets(nome, 255, stdin);

        printf("Digite o CPF do Paciente: \n");

        fgets(cpf, 255, stdin);

        printf("Digite o Telefone do Paciente: \n");

        fgets(telefone, 255, stdin);

        printf("Digite o Endereco do Paciente: \n");

        fgets(endereco, 255, stdin);

        printf("Digite a Data de Nascimento do Paciente: \n");

        fgets(data_de_nascimento, 255, stdin);

        printf("Digite o Email do Paciente: \n");

        fgets(email, 255, stdin);

        printf("Digite a Data do Diagnostico do Paciente: \n");

        fgets(data_do_diagnostico, 255, stdin);

        printf("Digite a Comorbidade do Paciente: \n");

        fgets(comorbidade, 255, stdin);

        printf("Deseja cadastrar mais Paciente? Digite 1 (SIM), Digite qualquer numero (não): \n");

        scanf("%d", &contador);

        fprintf(ponteiro, "Paciente: %s, ", remove_nova_linha(nome));

        fprintf(ponteiro, "CPF: %s, ", remove_nova_linha(cpf));

        fprintf(ponteiro, "Telefone: %s, ", remove_nova_linha(telefone));

        fprintf(ponteiro, "Endereço: %s, ", remove_nova_linha(endereco));

        fprintf(ponteiro, "Data de Nascimento: %s, ", remove_nova_linha(data_de_nascimento));

        fprintf(ponteiro, "Email: %s, ", remove_nova_linha(email));

        fprintf(ponteiro, "Data do Diagnóstico: %s, ", remove_nova_linha(data_do_diagnostico));

        fprintf(ponteiro, "Comorbidade: %s\n", remove_nova_linha(comorbidade));

        verificar_grupo_risco(data_de_nascimento, comorbidade, endereco);

        /*

            calcular a idade do paciente

            verifique se possui comorbidade

            verifique se é 65+



            salva em um arquivo de texto o CEP e a idade

        */

    } while (contador == 1);

    fclose(ponteiro);

    system("pause");
}

void cadastro_corretores()
{

    printf("\n\nAdicione os dados do Corretor\n");
}

int main()
{

    setlocale(LC_ALL, "");

    tela_login();

    mostrar_menu();

    switch (opcao)
    {

    case 1: // Gravar Pacientes

        cadastro_pacientes();

        break;

    case 2: // Sair

        break;

    default:

        printf("Opção Invalida!");

        break;
    }

    return 0;
}
