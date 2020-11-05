#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio()
{
}

void Laboratorio::agregarFinal(const Computadora &c)
{
    computadoras.push_back(c);
}

void Laboratorio::mostrar()
{
    cout<<left;
    cout<<setw(10)<<"SO";
    cout<<setw(10)<<"RAM";
    cout<<setw(8)<<"MARCA";
    cout<<setw(6)<<"COLOR";
    cout<<endl;
    for(size_t i=0; i<computadoras.size(); i++){
        Computadora &c = computadoras[i];
        cout<<c;
        /*cout<<"Sistema operativo: "<<c.getSistemaOperativo()<<endl;
        cout<<"Memoria RAM: "<<c.getMemoriaRam()<<endl;
        cout<<"Marca: "<<c.getMarca()<<endl;
        cout<<"Color: "<<c.getColor()<<endl;
        cout<<endl;*/
    } 
}

void Laboratorio::respaldar_tabla()
{
    ofstream archivo("computadoras_tabla.txt");
    if (archivo.is_open()) {
        archivo<<left;
        archivo<<setw(10)<<"SO";
        archivo<<setw(10)<<"RAM";
        archivo<<setw(8)<<"MARCA";
        archivo<<setw(6)<<"COLOR";
        archivo<<endl;
        for(size_t i=0; i<computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo<<c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar()
{
        ofstream archivo("computadoras.txt");
    if (archivo.is_open()) {
        for(size_t i=0; i<computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo<<c.getSistemaOperativo()<<endl;
            archivo<<c.getMemoriaRam()<<endl;
            archivo<<c.getMarca()<<endl;
            archivo<<c.getColor()<<endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar()
{
    ifstream archivo("computadoras.txt");
    if (archivo.is_open()) {
        string temp;
        Computadora c;

        while(true)
        {
            getline(archivo, temp);
            if(archivo.eof()) {
                break;
            }
            c.setSistemaOperativo(temp);

            getline(archivo, temp);
            c.setMemoriaRam(temp);

            getline(archivo, temp);
            c.setMarca(temp);

            getline(archivo, temp);
            c.setColor(temp);

            agregarFinal(c);
        }
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora& c, size_t pos)
{
    computadoras.insert(computadoras.begin()+pos, c);
}

size_t Laboratorio::size()
{
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t n)
{
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}

void Laboratorio::borrarFinal()
{
    computadoras.pop_back();
}

Computadora* Laboratorio::buscar(const Computadora &c)
{
    auto it = find(computadoras.begin(), computadoras.end(), c);
    if (it == computadoras.end())
        return nullptr;
    
    else
        return &(*it);
}