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

// Função para mesclar dois subvetores
void intercala(Musicas *v, int inicio, int meio, int fim) {
    Musicas *w;
    w = new Musicas[fim - inicio + 1];
    int i = inicio, j = meio + 1, k = 0;
    while (i <= meio && j <= fim) {
        // Comparando as strings de gênero em ordem alfabética
        if (v[i].genero.compare(v[j].genero) <= 0) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }

    while (i <= meio) {
        w[k++] = v[i++];
    }
    while (j <= fim) {
        w[k++] = v[j++];
    }
    for (k = 0; k < fim - inicio + 1; k++) {
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
void imprime(Musicas *musicas, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "------------------------------------" << endl;
        cout << "Musica numero " << musicas[i].id << endl;
        cout << "Nome da musica: " << musicas[i].nome << endl;
        cout << "Nome do autor: " << musicas[i].autor << endl;
        cout << "Ano na musica: " << musicas[i].ano << endl;
        cout << "Genero da musica: " << musicas[i].genero << endl;
        cout << "Nome do album: " << musicas[i].album << endl;
        cout << "------------------------------------" << endl;
        cout << endl;
    }
}

// Função para busca binária em arr[] pelo ID da música
int buscaPorId(const Musicas *v, int id, int inicio, int fim) {
    while (inicio <= fim) { // Condição de parada
        // Calcula o meio do sub-vetor
        int i = (inicio + fim) / 2;
        if (v[i].id == id) {
            return i; // Retorna o índice onde a música foi encontrada
        }
        if (v[i].id < id) {
            inicio = i + 1; // Item está no sub-vetor à direita
        } else {
            fim = i - 1; // Item está no sub-vetor à esquerda
        }
    }
    return -1; // Retorna -1 se a música não for encontrada
}

// Função para verificar se uma string contém apenas letras e espaços
bool validaString(const string &str) {
    for (char c : str) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            return false; // Se um caractere não for uma letra nem um espaço, retorna falso
        }
    }
    return true; // Se todos os caracteres forem letras ou espaços, retorna verdadeiro
}

// Função para verificar se uma string contém apenas letras e espaços
bool validaInt(const string &input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Função para inserir uma nova música
void insereMusica(Musicas *musicas, Musicas *novaMusica, int &size) {

    // Alocando novo espaço para a música
    Musicas *temp = new Musicas[size + 1];
    // Copiando músicas existentes para o novo espaço
    for (int i = 0; i < size; ++i) {
        temp[i] = musicas[i];
    }
    // Adicionando a nova música
    temp[size] = *novaMusica;
    ++size;
    // Liberando o espaço antigo e apontando para o novo espaço
    delete[] musicas;
    musicas = temp;
}