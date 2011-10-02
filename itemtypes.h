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
#ifndef ITEMTYPES_H
#define ITEMTYPES_H

#include <QGraphicsItem>

const int MelodyNoteType = QGraphicsItem::UserType + 1;
const int MusicBarType = QGraphicsItem::UserType + 2;
const int StemDrawerType = QGraphicsItem::UserType + 3;
const int StandardStemDrawerType = QGraphicsItem::UserType + 4;

#endif // ITEMTYPES_H
