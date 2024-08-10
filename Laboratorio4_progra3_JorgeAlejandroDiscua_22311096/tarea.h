#ifndef TAREA_H
#define TAREA_H

#include <QString>

class Tarea
{
protected:
    int dia;
    QString mes;
    QString titulo;
    QString descripcion;
public:
    Tarea(int d, const QString& m, const QString& t, const QString& desc);
    virtual ~Tarea() = default;
    virtual QString mostrarInfo() const = 0;

    QString getTitulo() const { return titulo; }
    QString getDescripcion() const { return descripcion; }
    QString getFecha() const { return QString::number(dia) + mes;}
};

#endif // TAREA_H
