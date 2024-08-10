#include "tareasemanal.h"

TareaSemanal::TareaSemanal(int d, const QString& m, const QString& t, const QString& desc)
    : Tarea(d, m, t,desc), tipo("Semanal") // Inicializa el constructor de la clase base y el tipo
{
    // Lógica adicional si fuese necesario
}
