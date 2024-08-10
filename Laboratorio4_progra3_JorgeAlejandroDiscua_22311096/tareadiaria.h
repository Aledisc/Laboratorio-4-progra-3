#ifndef TAREADIARIA_H
#define TAREADIARIA_H

#include "tarea.h"

class TareaDiaria : public Tarea
{
private:
    QString tipo;

public:
    TareaDiaria(int d, const QString& m,const QString& t, const QString& desc);

    QString getTipo() const { return tipo; }

    QString mostrarInfo() const override {
        return QString("Título: %1\nFecha: %2 %3\nDescripción: %4\nTipo: %5")
            .arg(titulo)
            .arg(dia)
            .arg(mes)
            .arg(descripcion)
            .arg(tipo);
    }
};

#endif // TAREADIARIA_H
