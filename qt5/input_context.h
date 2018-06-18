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

#ifndef EXIM_INPUT_CONTEXT_H
#define EXIM_INPUT_CONTEXT_H

#include <QString>
#include <qpa/qplatforminputcontext.h>

class EximInputContext : public QPlatformInputContext {
  Q_OBJECT
public:
  EximInputContext() : m_focusObject(nullptr) {}

  bool isValid() const Q_DECL_OVERRIDE { return true; }
  void setFocusObject(QObject *obj) Q_DECL_OVERRIDE { m_focusObject = obj; }

  void commitText(const QString& text);

private:
  QObject* m_focusObject;
};

#endif
