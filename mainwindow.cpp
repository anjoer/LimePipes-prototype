#include "mainwindow.h"
#include "ui_mainwindow.h"

//Includes zum Testen

#include "musicbar.h"
#include "melodynote.h"

//Ende Includes zum Testen

#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createViewAndScene();

    MusicBar *musicbar = new MusicBar( scene );
    MelodyNote *note = new MelodyNote( QRectF(20, 30, 40, 15), scene );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createViewAndScene()
{
    view = new QGraphicsView;
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    view->setRenderHint( QPainter::Antialiasing );
    setCentralWidget(view);
    delete ui->centralWidget;  //Das zentrale Widget, vor view
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
