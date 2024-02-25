#include <iostream>
#include <string>
#include "funcoes.cpp"

using namespace std;

// Variável global para controlar o ID das músicas
int proximoId = 1;

int main() {
    int size = 3;
    int opcao;
    Musicas *novaMusica = new Musicas();
    Musicas *musicas = new Musicas[size]{
        {proximoId++, "big jet plane", "Angus e Julia Stone", "2010", "indie", "Down the Way"},
        {proximoId++, "What I wouldn't Do", "Serena Ryder", "2012", "Pop", "Harmony(Deluxe)"},
        {proximoId++, "Requiem In D Minor, K.626: 3.Sequentia: Lacrimosa ", "Mozart", "1987", "Classica", "Mozart: Requiem"}
    };

    
    cout << "_________BEM VINDO AO BANCO DE MUSICAS!!!_________" << endl;
    do {
        cout << "Digite o numero referente a tarefa que deseja." << endl;
        cout << endl;
        cout << "1- Imprimir todas as musicas" << endl;
        cout << "2- Inserir nova musica" << endl;
        cout << "3- Buscar musica pelo ID" << endl;
        cout << "4- Ordenar musicas por genero" << endl;
        cout << "5- Sair" << endl;

        cin >> opcao;

        switch (opcao) {
            case 1:{
                if (size > 0) {
                    cout << "Listando todas as musicas:" << endl;
                    imprime(musicas, size);
                } else {
                    cout << "Nenhuma musica para imprimir." << endl;
                    cout << endl;
                }
                break;
            }
            case 2:{
                novaMusica->id = proximoId++;
                cout << "Nome da musica: ";
                cin >> ws;
                getline(cin, novaMusica->nome);
                cout << endl;

                cout << "Nome do autor: ";
                cin >> ws;
                getline(cin, novaMusica->autor);
                cout << endl;

                // Loop até que o nome do autor seja válido
                while (!validaString(novaMusica->autor)) {
                    cout << "Nome do autor invalido. Deve conter apenas letras." << endl;
                    cout << endl;
                    cout << "Nome do autor: ";
                    cin >> ws;
                    getline(cin, novaMusica->autor);
                    cout << endl;
                }

                // Loop até que o ano seja válido
                cout << "Ano da musica: ";
                cin >> novaMusica->ano;
                cout << endl;
                while (!validaInt(novaMusica->ano)) {
                    cout << "Ano invalido. Insira um ano valido." << endl;
                    cout << endl;
                    cout << "Ano da musica: ";
                    cin >> novaMusica->ano;
                    cout << endl;
                }

                // Loop até que o gênero seja válido
                cout << "Qual genero: ";
                getline(cin >> ws, novaMusica->genero);
                cout << endl;
                while (!validaString(novaMusica->genero)) {
                    cout << "Nome do Genero invalido. Deve conter apenas letras." << endl;
                    cout << endl;
                    cout << "Qual genero: ";
                    getline(cin >> ws, novaMusica->genero);
                    cout << endl;
                }

                 // Loop até que o nome do álbum seja válido
                cout << "Nome do album: ";
                cin >> ws;
                getline(cin, novaMusica->album);
                cout << endl;
                while (!validaString(novaMusica->album)) {
                    cout << "Nome do album invalido. Deve conter apenas letras." << endl;
                    cout << endl;
                    cout << "Nome do album: ";
                    cin >> ws;
                    getline(cin, novaMusica->album);
                    cout << endl;
                }
                
                cout << endl;
                insereMusica(musicas, novaMusica, size);
                delete novaMusica;
                break;
            }
            case 3:{
                if (size > 0) {
                    int idMusica;
                    cout << "Digite o ID da musica que deseja buscar: ";
                    cin >> idMusica;
                    int resultado = buscaPorId(musicas, idMusica, 0, size - 1);
                    cout << endl;
                    if (resultado != -1) {
                        cout << "Musica encontrada " << ":" << endl;
                        imprime(&musicas[resultado], 1);
                        cout << endl;
                    } else {
                        cout << "Musica nao encontrada." << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Nenhuma musica para buscar." << endl;
                    cout << endl;
                }
                break;
            }
            case 4:{
                Musicas *copiaMusicas = new Musicas[size];
                for (int i = 0; i < size; ++i) {
                    copiaMusicas[i] = musicas[i];
                }

                mergeSort(copiaMusicas, 0, size - 1);

                cout << "Vetor ordenado por genero:" << endl;
                imprime(copiaMusicas, size);
                delete[] copiaMusicas;
                break;
            }
            case 5:{
                cout << "Encerrando o programa." << endl;
                break;
            }
            default:{
                cout << "Opcao invalida." << endl;
            }
        }
    } while (opcao != 5);


    delete[] musicas; // Liberando a memória alocada para o array de músicas
    return 0;
}
