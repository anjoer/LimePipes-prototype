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
#include "stemdrawer.h"
#include "symbol.h"
#include <QtGui>
#include <QDebug>


StemDrawer::StemDrawer(QGraphicsScene *scene, const QList<Symbol *> *symbolList, const QPen *pen)
{
    m_symbolList = symbolList;
    if( pen == 0)
    {
        m_pen = new QPen();
    } else {
        m_pen = pen;
    }
    m_rect = QRectF();
    setVisible(true);
}


