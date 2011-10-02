/**
 * @file
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 *
 * <h3>GNU General Public License version 3</h3>
 * This program is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software Foundation;
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program;
 * if not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

//Includes for testing
#include <QDebug>

#include "ghbtune.h"
#include "musicbar.h"
#include "ghbpitchlist.h"
#include "melodynote.h"

//End Includes for Testing

#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createViewAndScene();

    new GHBTune( scene );

    new GHBPitchList( 20.0 );
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
    delete ui->centralWidget;  /*! Delete the central widget before we set it to the view */
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
