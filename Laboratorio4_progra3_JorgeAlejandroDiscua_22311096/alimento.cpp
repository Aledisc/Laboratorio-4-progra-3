#include "alimento.h"

Alimento::Alimento(const QString &nombre, double precio, const QString &descripcion, const QString &fechaDeCaducidad, const QString &tipoDeEnvase)
    : Producto(nombre, precio, descripcion), fechaDeCaducidad(fechaDeCaducidad), tipoDeEnvase(tipoDeEnvase) {}

QString Alimento::mostrarInfo() const {
    QString info;
    info.append("Nombre del Producto: " + nombreDelProducto + "\n");
    info.append("Precio: " + QString::number(precio) + "\n");
    info.append("Descripción: " + descripcion + "\n");
    info.append("Fecha de Caducidad: " + fechaDeCaducidad + "\n");
    info.append("Tipo de Envase: " + tipoDeEnvase + "\n");
    return info;
}
