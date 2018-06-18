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

#include <QtDBus/QtDBus>
#include <QString>
#include <stdio.h>

const char* dbusService =  "org.freedesktop.Exim.InputContext";
const char* dbusPath    = "/";

class EximDBusProxy: public QDBusAbstractAdaptor {
  Q_OBJECT
  Q_CLASSINFO("D-Bus Interface", "org.freedesktop.Exim.Interface")
private:
  EximInputContext* m_Input;

public:
    EximDBusProxy(EximInputContext* inputContext)
        : QDBusAbstractAdaptor(inputContext), m_Input(inputContext) {}

public slots:
  Q_NOREPLY void commitText(QString text) {
    m_Input->commitText(text);
  }
};

static const char* dbusError() {
  return qPrintable(QDBusConnection::sessionBus().lastError().message());
}

bool initEximDBus(EximInputContext* reciever) {
  QDBusConnection& bus = QDBusConnection::sessionBus();
  if (!bus.isConnected()) {
    fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
            "To start it, run:\n"
            "\teval `dbus-launch --auto-syntax`\n");
    return false;
  }

  if (!bus.registerService(dbusService)) {
    fprintf(stderr, "%s\n", dbusError());
    return false;
  }

  new EximDBusProxy(reciever);

  if (!bus.registerObject(dbusPath, reciever)) {
    fprintf(stderr, "%s\n", dbusError());
    return false;
  }

  return true;
}

#include "dbus_proxy.moc"
