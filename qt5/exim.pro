TARGET = eximplatforminputcontext
QT += dbus gui-private
CONFIG += plugin
TEMPLATE = lib

HEADERS += $$PWD/input_context.h

SOURCES += $$PWD/plugin.cpp \
           $$PWD/input_context.cpp \
           $$PWD/dbus_proxy.cpp

OTHER_FILES += $$PWD/ibus.json

PLUGIN_TYPE = platforminputcontexts
PLUGIN_EXTENDS = -
PLUGIN_CLASS_NAME = EximPlatformInputContextPlugin

target.path = $$[QT_INSTALL_PLUGINS]/platforminputcontexts
INSTALLS += target
