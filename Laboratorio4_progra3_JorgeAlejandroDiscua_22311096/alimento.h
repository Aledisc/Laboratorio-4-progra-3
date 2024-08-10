#ifndef ALIMENTO_H
#define ALIMENTO_H

#include "producto.h"

class Alimento : public Producto
{
private:
    QString fechaDeCaducidad; // En formato YYYY-MM-DD
    QString tipoDeEnvase;

public:
    Alimento(const QString &nombre, double precio, const QString &descripcion, const QString &fechaDeCaducidad, const QString &tipoDeEnvase);

    //double calcularValorTotal() const override; // No aplicable en este caso, puedes implementarlo si necesitas
    QString mostrarInfo() const override;
};

#endif // ALIMENTO_H
