// -*- c++ -*-

/*!
 *
 * Copyright (C) 2015 Jolla Ltd.
 *
 * Contact: Valerio Valerio <valerio.valerio@jolla.com>
 * Author: Andres Gomez <andres.gomez@jolla.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include "mprisplugin.h"

#include <Mpris>
#include <MprisPlayer>
#include <MprisManager>
#include <MprisController>
#include <MprisMetaData>

#include <qqml.h>

MprisPlugin::MprisPlugin(QObject *parent) :
    QQmlExtensionPlugin(parent)
{
}

MprisPlugin::~MprisPlugin()
{
}

void MprisPlugin::registerTypes(const char *uri)
{
    qmlRegisterUncreatableType<Mpris>(uri, 1, 0, "Mpris", QStringLiteral("Mpris is a namespace object"));
    qmlRegisterType<MprisPlayer>(uri, 1, 0, "MprisPlayer");
    qmlRegisterType<MprisManager>(uri, 1, 0, "MprisManager");
    qmlRegisterUncreatableType<MprisMetaData>(uri, 1, 0, "MprisMetaData", QStringLiteral("MprisMetaData can't be created"));
    qmlRegisterUncreatableType<MprisController>(uri, 1, 0, "MprisController", QStringLiteral("MprisMetaData can't be created"));
}
