#ifndef TAREASEMANAL_H
#define TAREASEMANAL_H

#include "tarea.h"

class TareaSemanal : public Tarea {
private:
    QString tipo;

public:
    TareaSemanal(int d, const QString& m, const QString& desc, const QString& t);

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

#endif // TAREASEMANAL_H
