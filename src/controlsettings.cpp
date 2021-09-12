/* ControlSettings is an extention for Swifty Assistant.

   Copyright (C) <2021>  <SwiftyApp>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include "controlsettings.h"

#include <QFile>
#include <QLocale>

QString ControlSettings::getDataXml()
{
    QString locale = QLocale::system().name().section('_', 0, 0);
    QFile file(":/XML/ControlSettingsData_"+locale+".xml");
    if (!file.exists()) {
        file.setFileName(":/XML/ControlSettingsData_en.xml");
    }
    file.open(QIODevice::ReadOnly);

    return file.readAll();
}

QString ControlSettings::pluginIid()
{
    return "fr.swifty.controlsettings";
}

QList<QString> ControlSettings::getCommande()
{
    QList<QString> list;
    QString locale = QLocale::system().name().section('_', 0, 0);

    if (locale == "fr") list << "Ouvre les paramètres" << "Affiche la configuration";
    else list << "Opens the settings" << "Show configuration";

    return list;
}

void ControlSettings::execAction(QList<QString>) {}

void ControlSettings::messageReceived(QString, QString) {}
