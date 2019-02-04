/*****************************************************************************
* Copyright 2015-2019 Alexander Barthel alex@littlenavmap.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef ATOOLS_GUI_GRIDDELEGATE_H
#define ATOOLS_GUI_GRIDDELEGATE_H

#include <QPen>
#include <QStyledItemDelegate>

namespace atools {
namespace gui {

/* Delegate that is used to draw a grid around cells in e.g. a QTreeWidget */
class GridDelegate :
  public QStyledItemDelegate
{
public:
  GridDelegate(QObject *parent);
  virtual ~GridDelegate();

  void styleChanged();

private:
  void paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

  QPen gridPen;
};

} // namespace gui
} // namespace atools

#endif // ATOOLS_GUI_GRIDDELEGATE_H
