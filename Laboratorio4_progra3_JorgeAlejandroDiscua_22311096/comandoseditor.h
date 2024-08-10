#ifndef COMANDOSEDITOR_H
#define COMANDOSEDITOR_H
#include <QTextCursor>

class ComandosEditor
{
public:
    ComandosEditor();
    void AplicarNegrita(QTextCursor* cursor);
    void AplicarItalica(QTextCursor* cursor);
    void AplicarSubrayado(QTextCursor* cursor);
};

#endif // COMANDOSEDITOR_H
