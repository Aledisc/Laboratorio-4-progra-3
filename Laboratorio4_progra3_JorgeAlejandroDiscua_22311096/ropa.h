#ifndef ROPA_H
#define ROPA_H

#include "producto.h"

class Ropa : public Producto
{
private:
    QString tamaño;
    QString color;

public:
    Ropa(const QString &nombre, double precio, const QString &descripcion, const QString &tamaño, const QString &color);
    QString mostrarInfo() const override;
};

#endif // ROPA_H
