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

#include <QString>
#include <QtCore/QStringList>
#include <qpa/qplatforminputcontextplugin_p.h>

bool initEximDBus(EximInputContext* reciever);

class EximPlatformInputContextPlugin : public QPlatformInputContextPlugin {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID QPlatformInputContextFactoryInterface_iid FILE "exim.json")

public:
  QPlatformInputContext* create(const QString& system, const QStringList& paramList) {
    Q_UNUSED(paramList);

    if (0 == system.compare(system, QLatin1String("exim"),
                            Qt::CaseInsensitive)) {
      EximInputContext* ctx = new EximInputContext();
      if (initEximDBus(ctx)) {
        return ctx;
      }
      delete ctx;
    }
    return nullptr;
  }
};

#include "plugin.moc"
