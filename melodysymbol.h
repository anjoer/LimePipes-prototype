/*!
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
#ifndef MELODYSYMBOL_H
#define MELODYSYMBOL_H

#include "symbol.h"

/*!
  * @class MelodySymbol
  * @brief This class is the base for all Melody-Symbols like melody-notes, embellishments,
  * gracenotes. This symbols can stand for them self, not like @ref ControlSymbol (ties, start of part ...,
  * 1st 2nd of part), which have an start and end-symbol and need a higher instance that brings (draws) them together.
  */
class MelodySymbol : public Symbol
{
public:
    MelodySymbol( QGraphicsScene *scene, const QPen *pen );
};

#endif // MELODYSYMBOL_H
