// EXIM-Qt5 integration plugin
//
// Copyright (C) 2018 Andrew Savonichev
//
// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this file.  If not, see <http://www.gnu.org/licenses/>.

#include "input_context.h"
#include <QInputMethodEvent>
#include <QtCore/QCoreApplication>

void EximInputContext::commitText(const QString& text) {
   if (!m_focusObject || text.isEmpty()) {
    return;
  }

  QInputMethodEvent ev;
  ev.setCommitString(text);
  QCoreApplication::sendEvent(m_focusObject, &ev);
}

#include "input_context.moc"
