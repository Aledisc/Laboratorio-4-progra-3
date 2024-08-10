#include "ropa.h"

Ropa::Ropa(const QString &nombre, double precio, const QString &descripcion, const QString &tamaño, const QString &color)
    : Producto(nombre, precio, descripcion), tamaño(tamaño), color(color) {}

QString Ropa::mostrarInfo() const {
    QString info;
    info.append("Nombre del Producto: " + nombreDelProducto + "\n");
    info.append("Precio: " + QString::number(precio) + "\n");
    info.append("Descripción: " + descripcion + "\n");
    info.append("Tamaño: " + tamaño + "\n");
    info.append("Color: " + color + "\n");
    return info;
}
