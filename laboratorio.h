#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <vector>

class Laboratorio
{
    private:
        vector<Computadora> computadoras;

    public:
        Laboratorio();
        void agregarFinal(const Computadora&);
        void mostrar();
        void respaldar_tabla();
        void respaldar();
        void recuperar();

        void insertar(const Computadora&, size_t);
        size_t size();
        void inicializar(const Computadora&, size_t);
        void eliminar(size_t);
        void ordenar();
        void borrarFinal();
        Computadora* buscar(const Computadora&);

        friend Laboratorio& operator<<(Laboratorio &l, const Computadora &c)
        {
            l.agregarFinal(c);

            return l;
        }
};
#endif