#include "mainwindow.h"
#include "ui_mainwindow.h"

//Includes zum Testen
#include <QDebug>

#include "ghbtune.h"
#include "musicbar.h"
#include "ghbpitchlist.h"
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

    GHBTune *tune = new GHBTune( scene );

    GHBPitchList *pitchList = new GHBPitchList( 20.0 );

    //QPen um Elemente zu zeichnen
    QPen *m_pen = new QPen();
    m_pen->setWidthF(1.0);
    m_pen->setColor(Qt::black);

    //MusicBar *musicbar = new MusicBar( scene, pitchList, m_pen);
    //qDebug() << "musicbar-sizeHint-minimum: " << musicbar->sizeHint(Qt::MinimumSize);
   // musicbar->append( new MelodyNote(scene, m_pen, pitchList->getPitch(GHBPitchList::LowG)));
    //MelodyNote *note = new MelodyNote( QRectF(20, 30, 40, 15), scene );
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
