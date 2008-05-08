/*
 * Tiled Map Editor (Qt port)
 * Copyright 2008 Tiled (Qt port) developers (see AUTHORS file)
 *
 * This file is part of Tiled (Qt port).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef RESIZEHELPER_H
#define RESIZEHELPER_H

#include <QPoint>
#include <QSize>
#include <QWidget>

class QMouseEvent;
class QResizeEvent;

namespace Tiled {
namespace Internal {

/**
 * A special widget designed as an aid for resizing a canvas. Based on a
 * similar widget used by the GIMP.
 */
class ResizeHelper : public QWidget
{
    Q_OBJECT

public:
    ResizeHelper(QWidget *parent = 0);

    const QSize& oldSize() const
    { return mOldSize; }

    const QSize& newSize() const
    { return mNewSize; }

    const QPoint& offset() const
    { return mOffset; }

    const QRect& offsetBounds() const
    { return mOffsetBounds; }

signals:
    void offsetChanged(const QPoint &offset);

    void offsetXChanged(int value);

    void offsetYChanged(int value);

    void offsetBoundsChanged(const QRect &bounds);

public slots:
    void setOldSize(const QSize &size);

    void setNewSize(const QSize &size);

    void setOffset(const QPoint &offset);

    /** Method to set only the X offset, provided for convenience. */
    void setOffsetX(int x);

    /** Method to set only the Y offset, provided for convenience. */
    void setOffsetY(int y);

    /** Method to set only new width, provided for convenience. */
    void setNewWidth(int width);

    /** Method to set only new height, provided for convenience. */
    void setNewHeight(int height);

protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void resizeEvent(QResizeEvent *event);

    void recalculateScale();

    void recalculateMinMaxOffset();

private:
    QSize mOldSize;
    QSize mNewSize;
    QPoint mOffset;
    QRect mOffsetBounds;
    QPoint mMouseAnchorPoint;
    QPoint mOrigOffset;
    bool mDragging;
    double mScale;
};

} // namespace Internal
} // namespace Tiled

#endif // RESIZEHELPER_H