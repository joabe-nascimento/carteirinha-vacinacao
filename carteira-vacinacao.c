#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Identificacao {
    char nome[50];
    int idade;
};

struct Endereco {
    char rua[50];
    char cidade[50];
};

struct Vacina {
    char nomeVacina[50];
    int semanasIdade;
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void incluirIdentificacao(struct Identificacao *identificacao) {
    printf("Digite o nome da crianca: ");
    scanf("%49s", identificacao->nome);
    printf("Digite a idade da crianca: ");
    scanf("%d", &identificacao->idade);
    limparBuffer();
}

void incluirEndereco(struct Endereco *endereco) {
    printf("Digite a rua: ");
    fgets(endereco->rua, sizeof(endereco->rua), stdin);
    endereco->rua[strcspn(endereco->rua, "\n")] = '\0'; 

    printf("Digite a cidade: ");
    fgets(endereco->cidade, sizeof(endereco->cidade), stdin);
    endereco->cidade[strcspn(endereco->cidade, "\n")] = '\0'; 
}

void incluirVacina(struct Vacina *vacina) {
    printf("Digite o nome da vacina: ");
    fgets(vacina->nomeVacina, sizeof(vacina->nomeVacina), stdin);
    vacina->nomeVacina[strcspn(vacina->nomeVacina, "\n")] = '\0'; // Remove a quebra de linha

    printf("Digite em quantas semanas a vacina deve ser tomada: ");
    scanf("%d", &vacina->semanasIdade);
    limparBuffer();
}

void listarDados(struct Identificacao identificacao, struct Endereco endereco, struct Vacina vacina) {
    printf("### Dados da Crianca ###\n");
    printf("Nome: %s\n", identificacao.nome);
    printf("Idade: %d\n", identificacao.idade);

    printf("\n### Endereco da Crianca ###\n");
    printf("Rua: %s\n", endereco.rua);
    printf("Cidade: %s\n", endereco.cidade);

    printf("\n### Registro de Vacina ###\n");
    printf("Nome da Vacina: %s\n", vacina.nomeVacina);
    printf("Semanas de vida para tomar: %d\n", vacina.semanasIdade);
}

int main() {
    struct Identificacao identificacao = {"", -1};
    struct Endereco endereco;
    struct Vacina vacina = {"", -1};

    int opcao;

    do {
        printf("\n### Menu ###\n");
        printf("1. Incluir dados de identificacao\n");
        printf("2. Incluir endereco da crianca\n");
        printf("3. Incluir registro de vacina\n");
        printf("4. Listar todos os dados\n");
        printf("5. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer(); 

        switch (opcao) {
            case 1:
                incluirIdentificacao(&identificacao);
                break;
            case 2:
                incluirEndereco(&endereco);
                break;
            case 3:
                incluirVacina(&vacina);
                break;
            case 4:
                if (identificacao.idade > 0 && strlen(endereco.rua) > 0 && strlen(endereco.cidade) > 0 && strlen(vacina.nomeVacina) > 0 && vacina.semanasIdade > 0) {
                    listarDados(identificacao, endereco, vacina);
                } else {
                    printf("Por favor, preencha todos os dados antes de listar.\n");
                }
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

