#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include "producto.h"

class Electronico : public Producto
{
private:
    QString modelo;
    QString garantia;
public:
    Electronico(const QString &nombre, double precio, const QString &descripcion, const QString &modelo, QString garantia);
    QString mostrarInfo() const override;
};

#endif // ELECTRONICO_H
