#include <iostream>

using namespace std;

typedef struct {
    int id;
    string nome;
    string autor;
    string ano;
    string genero;
    string album;
} Musicas;

// Variável global para controlar o ID das músicas
int proximoId = 1;

// Função para mesclar dois subvetores
void intercala(Musicas *v, int inicio, int meio, int fim) {
    Musicas *w;
    w = new Musicas[fim - inicio];
    int i = inicio, j = meio, k = 0;
    while (i < meio && j < fim) {
        if (v[i].nome < v[j].nome) {
            w[k] = v[i];
            i++;
        } else {
            w[k] = v[j];
            j++;
        }
        k++;
    }

    while (i < meio) {
        w[k] = v[i];
        i++;
        k++;
    }
    while (j < fim) {
        w[k] = v[j];
        j++;
        k++;
    }
    for (k = 0; k < fim - inicio; k++) {
        v[inicio + k] = w[k];
    }
    delete[] w;
}

// Função para realizar o Merge Sort
void mergeSort(Musicas *v, int inicio, int fim) {
    if (inicio < (fim - 1)) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio, fim);
        intercala(v, inicio, meio, fim);
    }
}

// Função para imprimir as músicas
<<<<<<< HEAD
void imprime(Musicas *musicas, int i) {
=======
void imprime(Musicas *musicas, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "------------------------------------"<<endl;
>>>>>>> main
        cout << "Musica numero " << i + 1 << endl;
        cout << "Nome da musica: " << musicas[i].nome << endl;
        cout << "Nome do autor: " << musicas[i].autor << endl;
        cout << "Ano na musica: " << musicas[i].ano << endl;
        cout << "Genero da musica: " << musicas[i].genero << endl;
        cout << "Nome do album: " << musicas[i].album << endl;
        cout << "------------------------------------"<<endl;
        cout << endl;
}

// Função para busca binária em arr[] pelo ID da música
int buscaPorId(const Musicas *v, int id, int inicio, int fim) {
    while(inicio <= fim){ //Condição de parada
    //calcula o meio do sub-vetor
    int i = (inicio + fim) / 2;
    if (v[i].id == id){
        return id; //Item encontrado
    }
    if (v[i].id < id){
    inicio = id+1; //Item está no sub-vetor à direita
    }
    else{
        fim = i; //v[i] > x //Item está no sub-vetor à esquerda
    }
    }
    return -1;
}

// Função para inserir uma nova música
void insereMusica(Musicas *&musicas, int &size) {
    Musicas novaMusica;
    novaMusica.id = proximoId++; // Atribuindo o próximo ID e incrementando o contador
    cout << "Nome da musica: ";
    cin >> novaMusica.nome;
    cout << "Nome do autor: ";
    cin >> novaMusica.autor;
    cout << "Ano da musica: ";
    cin >> novaMusica.ano;
    cout << "Qual genero: ";
    cin >> novaMusica.genero;
    cout << "Nome do album: ";
    cin >> novaMusica.album;

    // Alocando novo espaço para a música
    Musicas *temp = new Musicas[size + 1];
    // Copiando músicas existentes para o novo espaço
    for (int i = 0; i < size; ++i) {
        temp[i] = musicas[i];
    }
    // Adicionando a nova música
    temp[size] = novaMusica;
    ++size;
    // Liberando o espaço antigo e apontando para o novo espaço
    delete[] musicas;
    musicas = temp;
    // Ordenando as músicas após a inserção da nova música
    mergeSort(musicas, 0, size - 1);

    // Atribuindo IDs conforme a sequência ordenada
    for (int i = 0; i < size; ++i) {
        musicas[i].id = proximoId++;
    }
}

int main() {
    Musicas *musicas = nullptr;
    int size = 0;
    int opcao;

    do {
        cout << "_________Bem vindo ao banco de musicas!!!_________" << endl;
        cout << "Digite o numero referente a tarefa que deseja." << endl;
        cout << endl;
        cout << "1- Imprimir todas as musicas" << endl;
        cout << "2- Inserir nova musica" << endl;
        cout << "3- Buscar musica pelo ID" << endl;
        cout << "5- Sair" << endl;

        cin >> opcao;

        switch (opcao) {
            case 1:
                if (size > 0) {
                    cout << "Listando todas as musicas:" << endl;
                    for (int i = 0; i < size; ++i) {
                        imprime(musicas,i);
                    }
                } else {
                    cout << "Nenhuma musica para imprimir." << endl;
                    cout << endl;
                }
                break;
            case 2:
                insereMusica(musicas, size);
                break;
            case 3:
                if (size > 0) {
                    int idMusica;
                    cout << "Digite o ID da musica que deseja buscar: ";
                    cin >> idMusica;
                    int resultado = buscaPorId(musicas, idMusica, 0, size - 1);
                    if (resultado != -1) {
                        cout << "Musica encontrada na posicao " << resultado << ":" << endl;
                        imprime(&musicas[resultado], 1);
                    } else {
                        cout << "Musica nao encontrada." << endl;
                    }
                } else {
                    cout << "Nenhuma musica para buscar." << endl;
                }
                break;
            case 5:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 5);
   
}