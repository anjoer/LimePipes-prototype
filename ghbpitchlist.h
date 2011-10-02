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
#ifndef GHBPITCHLIST_H
#define GHBPITCHLIST_H

#include "pitchlist.h"

/*! @class GHBPitchList
  * @brief The @ref PitchList for the Great Highland Bagpipes with its 9 pitches.
  */
class GHBPitchList : public PitchList
{
public:
    GHBPitchList( qreal lineHeight );
    /*! The Pitches for the Great Highland Bagpipes */
    enum Pitches{
        LowG,   /*!< The Low G */
        LowA,   /*!< The Low A */
        B,      /*!< The B */
        C,      /*!< The C */
        D,      /*!< The D */
        E,      /*!< The E */
        F,      /*!< The F */
        HighG,  /*!< The High G */
        HighA   /*!< The High A */
    };

};

#endif // GHBPITCHLIST_H
