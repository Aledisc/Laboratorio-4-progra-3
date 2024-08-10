#include "tareadiaria.h"

TareaDiaria::TareaDiaria(int d, const QString& m, const QString& t,const QString& desc)
    : Tarea(d, m, t, desc), tipo("Diaria")
{

}
