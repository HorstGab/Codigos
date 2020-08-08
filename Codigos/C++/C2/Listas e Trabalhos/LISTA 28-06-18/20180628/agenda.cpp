#include "agenda.h"

agenda::agenda(){
    for(int i = 0; i < 10; i++) this->p[i] = 0;
    this->nome = "";
    this->nascimento = NULL;
    this->altura = 0;
}

void agenda::armazenarPessoa(string nome, data *nascimento, float altura){

    for(int i = 0; i < 10; i++){
        if(this->p[i]){
            pessoa* Pessoa = new pessoa(nome, nascimento, altura);
            this->p[i] = Pessoa;
            break;
        }
    }
}

void agenda ::removePessoa(string nome){

    for(int i = 0; i < 10; i++){
        if(this->nome == nome){
            this->p[i] = NULL;
        }
    }
}

int agenda::buscaPessoa(string nome){

    for(int i = 0; i < 10; i++){
        if(this->nome == nome){
            return i+1;
        }
    }
    return 0;
}

void agenda::mostraAgenda(){

    for(int i = 0; i < 10; i++){
        cout << "agenda: " << this->p[i]->getNome() << endl;
    }
}

void agenda::mostraPessoa(int index){

    if(this->p[index]){
        data* date = this->p[index]->getNascimento();
        cout << "Nome: " << this->p[index]->getNome() << endl;
        cout << "Nascimento: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
        cout << "Altura: " << this->p[index]->getAltura() << endl;
    }
}

agenda ::~agenda(){
    cout << "Destruindo Agenda ..." << endl;
}
