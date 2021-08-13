/*!
 *
 * Copyright (C) 2015-2021 Jolla Ltd.
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
 *
 * This file was initially generated by qdbusxml2cpp version 0.8
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 */

#include "mprisserviceadaptor_p.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

#include "mprisplayer_p.h"

/*
 * Implementation of adaptor class MprisServiceAdaptor
 */

MprisServiceAdaptor::MprisServiceAdaptor(MprisPlayerPrivate *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

MprisServiceAdaptor::~MprisServiceAdaptor()
{
    // destructor
}

MprisPlayerPrivate *MprisServiceAdaptor::parent() const
{
    return static_cast<MprisPlayerPrivate *>(QObject::parent());
}

bool MprisServiceAdaptor::canQuit() const
{
    // get the value of property CanQuit
    return parent()->m_canQuit;
}

bool MprisServiceAdaptor::canRaise() const
{
    // get the value of property CanRaise
    return parent()->m_canRaise;
}

bool MprisServiceAdaptor::canSetFullscreen() const
{
    // get the value of property CanSetFullscreen
    return parent()->m_canSetFullscreen;
}

QString MprisServiceAdaptor::desktopEntry() const
{
    // get the value of property DesktopEntry
    return parent()->m_desktopEntry;
}

bool MprisServiceAdaptor::fullscreen() const
{
    // get the value of property Fullscreen
    return parent()->m_fullscreen;
}

void MprisServiceAdaptor::setFullscreen(bool value)
{
    // set the value of property Fullscreen
    parent()->setProperty("Fullscreen", QVariant::fromValue(value));
}

bool MprisServiceAdaptor::hasTrackList() const
{
    // get the value of property HasTrackList
    return parent()->m_hasTrackList;
}

QString MprisServiceAdaptor::identity() const
{
    // get the value of property Identity
    return parent()->m_identity;
}

QStringList MprisServiceAdaptor::supportedMimeTypes() const
{
    // get the value of property SupportedMimeTypes
    return parent()->m_supportedMimeTypes;
}

QStringList MprisServiceAdaptor::supportedUriSchemes() const
{
    // get the value of property SupportedUriSchemes
    return parent()->m_supportedUriSchemes;
}

void MprisServiceAdaptor::Quit()
{
    // handle method call org.mpris.MediaPlayer2.Quit
    parent()->quit();
}

void MprisServiceAdaptor::Raise()
{
    // handle method call org.mpris.MediaPlayer2.Raise
    parent()->raise();
}

