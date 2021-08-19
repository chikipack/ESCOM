//REPASO de POO en C++

#include <iostream>
#include <stdlib.h>>

using namespace std;

class Persona{
    private:    //atributos
        int age;
        string name;
    public:     //metodos
        Persona(int, string);//Constructor
        void leer();
        void correr();
};

//Constructor
Persona::Persona(int _age, string _name){
    age =_age;
    name=_name;
}

void Persona::leer(){
    cout<<"soy "<< name << " y estoy leyendo"<<endl;
}

void Persona::correr(){
    cout<<"soy "<< name << " y estoy corriendo"<<endl;
}
