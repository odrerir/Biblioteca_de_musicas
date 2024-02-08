#include <iostream>

using namespace std;
#define n = 5;

typedef struct{
    string nome;
    string autor;
    string ano;
    string genero;
    string album;

} Musicas;

void insere(Musicas musica) {
    cout << "Nome da musica: ";
    cin >> musica->nome;
    cout << endl;
    cout << "Nome do autor: ";
    cin >> musica->autor;
    cout << endl;
    cout << "Ano da musica: ";
    cin >> musica->ano;
    cout << endl;
    cout << "Qual genero: ";
    cin >> musica->genero;
    cout << endl;
    cout << "Nome do album: ";
    cin >> musica->album;
    cout << endl;
}

void imprime(Musicas musica) {
    cout << "Nome da musica: " << musica->nome << endl;
    cout << "Nome do autor: " << musica->autor << endl;
    cout << "Ano na musica: " << musica->ano << endl;
    cout << "Genero da musica: " << musica->genero << endl;
    cout << "Nome do album: " << musica->album << endl;
}

int main(){
    int p;
    Musicas musica[n];
    do{
        cout << "Bem vindo ao banco de musicas!!!" << endl;
        cout << "Digite o numero referente a tarefa que deseja." << endl;
        cout << "1- Imprimir todas as musicas" << endl;
        cout << "2- inserir nova musica" << endl;

        switch (p)
        {
        case 1:
            break;
            imprime(musica);
        case 2:
            insere(musica);
            break;
        case 6:
            break;
        default:
            break;
        }
    }while (p == 6);
    
    
}
