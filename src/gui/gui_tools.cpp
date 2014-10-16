/*
 * Copyright (C) 2014 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus Quest Editor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus Quest Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "gui/gui_tools.h"
#include <QMessageBox>
#include <QPainter>

namespace GuiTools {

/**
 * @brief Shows a modal dialog box with an information message.
 * @param message The message to show.
 */
void information_dialog(const QString& message) {

  QMessageBox messageBox;
  messageBox.setIcon(QMessageBox::Information);
  messageBox.setText(message);
  messageBox.setWindowTitle(QMessageBox::tr("Information"));
  messageBox.exec();
}

/**
 * @brief Shows a modal dialog box with a warning message.
 * @param message The message to show.
 */
void warning_dialog(const QString& message) {

  QMessageBox messageBox;
  messageBox.setIcon(QMessageBox::Warning);
  messageBox.setText(message);
  messageBox.setWindowTitle(QMessageBox::tr("Warning"));
  messageBox.exec();
}

/**
 * @brief Shows a modal dialog box with an error message.
 * @param message The message to show.
 */
void error_dialog(const QString& message) {

  QMessageBox messageBox;
  messageBox.setIcon(QMessageBox::Critical);
  messageBox.setText(message);
  messageBox.setWindowTitle(QMessageBox::tr("Error"));
  messageBox.exec();
}

/**
 * @brief Draws a rectangle outline.
 *
 * Unlike QPainter::drawRect(), this function draws the outline entirely
 * inside the rectangle and does not involves half-pixels.
 *
 * @param painter The painter.
 * @param where Rectangle to draw the outline to.
 * @param color Color to use.
 */
void draw_rectangle_outline(QPainter& painter,
                            const QRect& where,
                            const QColor& color) {
  const int x = where.x();
  const int y = where.y();
  const int w = where.width();
  const int h = where.height();
  QBrush brush(color);
  painter.fillRect(QRect(        x,         y, w, 1), brush);
  painter.fillRect(QRect(        x, y + h - 1, w, 1), brush);
  painter.fillRect(QRect(        x,         y, 1, h), brush);
  painter.fillRect(QRect(x + w - 1,         y, 1, h), brush);

}

}
