#include "electronico.h"

Electronico::Electronico(const QString &nombre, double precio, const QString &descripcion, const QString &modelo, QString garantia)
    : Producto(nombre, precio, descripcion), modelo(modelo), garantia(garantia) {}

QString Electronico::mostrarInfo() const {
    QString info;
    info.append("Nombre del Producto: " + nombreDelProducto + "\n");
    info.append("Precio: " + QString::number(precio) + "\n");
    info.append("Descripción: " + descripcion + "\n");
    info.append("Modelo: " + modelo + "\n");
    info.append("Garantía: " + (garantia) + " meses\n");
    return info;
}
