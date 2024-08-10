#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QButtonGroup>
#include <QDebug>
#include <QList>
#include <QTimer>
#include <QGraphicsPolygonItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPolygonF>

#include "tareadiaria.h"
#include "tareasemanal.h"
#include "producto.h"
#include "electronico.h"
#include "ropa.h"
#include "alimento.h"

QButtonGroup *tipoTarea = new QButtonGroup;

QList<Producto*> productos;
QList<Tarea*> listaTareas;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    crearRatio();

    ui->estatusTarea->setVisible(false);
    ui->statusAgr->setVisible(false);
    ui->sttsElim->setVisible(false);
    //connect(ui->listaDeTareas,&QListWidget::itemClicked, this, &MainWindow)
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_5_clicked()
{
    exit(0);
}

void MainWindow::crearRatio(){
    //QButtonGroup *tipoTarea = new QButtonGroup;
    tipoTarea->addButton(ui->radioButton, 1);
    tipoTarea->addButton(ui->radioButton_2, 2);

    //connect(tipoTarea, SIGNAL(buttonClicked(int)), this, SLOT(onRadioButtonClicked(int)));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->listaDeTareas->clear();

    for (Tarea* tarea : listaTareas){
        ui->listaDeTareas->addItem(tarea->getTitulo());
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    int id = tipoTarea->checkedId();
    if(id==1){
        TareaDiaria* tarea = new TareaDiaria(ui->comboBoxDia->currentIndex()+1,ui->comboBoxMes->currentText(),ui->tituloTarea->text(),ui->descTarea->toPlainText());
        listaTareas.append(tarea);
        ui->listaDeTareas->addItem(tarea->getTitulo());
    }else{
        TareaSemanal* tareaSem = new TareaSemanal(ui->comboBoxDia->currentIndex()+1,ui->comboBoxMes->currentText(),ui->tituloTarea->text(),ui->descTarea->toPlainText());
        listaTareas.append(tareaSem);
        ui->listaDeTareas->addItem(tareaSem->getTitulo());
    }
    ui->estatusTarea->setVisible(true);
    QTimer::singleShot(3000, [&](){
        qDebug() << "Han pasado 3 segundos.";
        ui->estatusTarea->setVisible(false);
    });
}


void MainWindow::on_listaDeTareas_itemClicked(QListWidgetItem *item)
{
    int row = ui->listaDeTareas->currentRow();

    if(row>=0 && row < listaTareas.size()){
        Tarea* tareaSeleccionada = listaTareas.at(row);
        /*
        QString mostrar;
        mostrar.append("Titulo: "+tareaSeleccionada->getTitulo()+"\n");
        mostrar.append("Fecha: "+)
        */
        ui->descripcionDeTareas->setText(tareaSeleccionada->mostrarInfo());
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    QTextCursor cursor = ui->paginaWord->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontWeight(format.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    cursor.setCharFormat(format);
    ui->paginaWord->setTextCursor(cursor);
}


void MainWindow::on_pushButton_10_clicked()
{
    QTextCursor cursor = ui->paginaWord->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontItalic(!format.fontItalic());
    cursor.setCharFormat(format);
    ui->paginaWord->setTextCursor(cursor);
}


void MainWindow::on_pushButton_11_clicked()
{
    QTextCursor cursor = ui->paginaWord->textCursor();
    QTextCharFormat format = cursor.charFormat();
    format.setFontUnderline(!format.fontUnderline());
    cursor.setCharFormat(format);
    ui->paginaWord->setTextCursor(cursor);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    if(index==0){
        ui->l1->setText("Modelo:");
        ui->l2->setText("Garantia:");
    }else if(index==1){
        ui->l1->setText("Tamaño:");
        ui->l2->setText("Color");
    }else if(index==2){
        ui->l1->setText("Expira");
        ui->l2->setText("Envase");
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->statusAgr->setVisible(true);
    int index = ui->comboBox->currentIndex();
    if(index==0){
        productos.append(new Electronico(ui->leNombre->text(),ui->doubleSpinBox->value(),ui->leDesc->toPlainText(),ui->adicional1->text(),ui->adicional2->text()));
    }else if(index==1){
        productos.append(new Ropa(ui->leNombre->text(),ui->doubleSpinBox->value(),ui->leDesc->toPlainText(),ui->adicional1->text(),ui->adicional2->text()));
    }else if(index==2){
        productos.append(new Alimento(ui->leNombre->text(),ui->doubleSpinBox->value(),ui->leDesc->toPlainText(),ui->adicional1->text(),ui->adicional2->text()));
    }
    QTimer::singleShot(3000, [&](){
        //qDebug() << "Han pasado 3 segundos.";
        ui->statusAgr->setVisible(false);
    });
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);

    ui->listaEliminar->clear();

    for (Producto* producto : productos){
        ui->listaEliminar->addItem(producto->getNombre());
    }
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    //QString figuraSeleccionada = ui->comboBox_figura->currentText();
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    if (index == 1) {
        QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 100, 100);
        scene->addItem(rect);
    } else if (index == 0) {
        QPolygonF triangle;
        triangle << QPointF(0, 100) << QPointF(50, 0) << QPointF(100, 100);
        QGraphicsPolygonItem *polygon = new QGraphicsPolygonItem(triangle);
        scene->addItem(polygon);
    } else if (index == 2) {
        QGraphicsEllipseItem* circulo = new QGraphicsEllipseItem(50, 50, 200, 200);
        circulo->setBrush(Qt::blue);
        scene->addItem(circulo);
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->sttsElim->setVisible(true);

    int row = ui->listaEliminar->currentRow();
    //qDebug()<< row;
    productos.remove(row);
    ui->listaEliminar->clear();

    for (Producto* producto : productos){
        ui->listaEliminar->addItem(producto->getNombre());
    }
    QTimer::singleShot(3000, [&](){

        ui->sttsElim->setVisible(false);
    });
}

