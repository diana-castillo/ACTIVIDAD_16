#include <iostream>
#include "laboratorio.h"
using namespace std;

int main() {
    Laboratorio lab;
    string op;

    while (true)
    {
        cout<<endl<<"1) Agregar computadora"<<endl;
        cout<<"2) Mostrar"<<endl;
        cout<<"3) Respaldar"<<endl;
        cout<<"4) Recuperar"<<endl;
        cout<<"5) Insertar"<<endl;
        cout<<"6) Inicializar"<<endl;
        cout<<"7) Eliminar"<<endl;
        cout<<"8) Ordenar"<<endl;
        cout<<"9) Borrar ultimo"<<endl;
        cout<<"10) Buscar"<<endl;
        cout<<"0) Salir"<<endl;
        getline(cin, op);

        if(op == "1") {
            Computadora c;
            cin>>c;

            lab.agregarFinal(c); //cin.ignore();
        }

        else if (op == "2") {
            lab.mostrar();
        }

        else if(op == "3") {
            lab.respaldar();
        }

        else if(op == "4") {
            lab.recuperar();
        }

        else if(op == "5") {
            Computadora c;
            cin>>c;
            
            size_t pos;
            cout<<"Posicion: ";
            cin>>pos;
            cin.ignore();

            if(pos >= lab.size())
                cout<<"Posicion invalida"<<endl;
            
            else
                lab.insertar(c, pos);
        }

        else if(op == "6") {
           Computadora c;
            cin>>c;

            size_t n;
            cout<<"n: ";
            cin>>n;
            cin.ignore();

            lab.inicializar(c, n); 
        }

        else if(op == "7") {
            size_t pos;
            cout<<"Posicion: ";
            cin>>pos;
            cin.ignore();

            if(pos >= lab.size())
                cout<<"Posicion invalida"<<endl;
            
            else
                lab.eliminar(pos);
        }

        else if(op == "8") {
            lab.ordenar();
        }

        else if(op == "9") {
            lab.borrarFinal();
        }

        else if(op == "10") {
            Computadora c;
            cin>>c;

            Computadora *ptr = lab.buscar(c);

            if(ptr == nullptr)
                cout<<"No encontrado"<<endl;

            else
                cout<<*ptr<<endl;
        }
        
        else if(op == "0") {
            cout<<"Hasta luego."<<endl;
            break;
        }
    }
    

    return 0;
}