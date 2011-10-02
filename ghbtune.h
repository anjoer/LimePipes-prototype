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
#ifndef GHBTUNE_H
#define GHBTUNE_H

#include <QList>
#include <QVector>
#include <QGraphicsWidget>

class QGraphicsScene;
class QGraphicsLinearLayout;

class PitchList;
class MusicBar;
class Symbol;

/*! @class GHBTune
  * @brief This class represents a Tune for the Great Highland Bagpipes.
  */
class GHBTune : public QGraphicsWidget
{
public:
    /*! @brief Constructor
      * @param scene The QGraphicsScene to add the Tune
      */
    GHBTune( QGraphicsScene *scene );
    /*! @brief Destructor */
    ~GHBTune();
    /*! @brief Reimplemented from QGraphicsItem::boundingRect() */
    QRectF boundingRect() const;
    /*! @brief Reimplemented from QGraphicsLayoutItem */
    QSizePolicy sizePolicy() const;

private:
    /*! @brief The music bars of the Tune */
    QVector<MusicBar *> m_bars;
    /*! @brief The Pitch List of the Tune. Here GHBPitchList */
    const PitchList *m_pitchList;
    /*! @brief A Layout for the musicbars */
    QGraphicsLinearLayout *m_layout;
    /*! @brief The bounding rect */
    QRectF m_rect;
    /*! @brief The pen for drawing everything in the tune. It is passed to the bars, symbols, etc. */
    QPen *m_pen;
};

#endif // GHBTUNE_H
