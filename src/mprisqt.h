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


#ifndef MPRIS_QT_H
#define MPRIS_QT_H

#include <QDBusConnection>

#if defined(MPRIS_QT_LIBRARY)
#  define MPRIS_QT_EXPORT Q_DECL_EXPORT
#else
#  define MPRIS_QT_EXPORT Q_DECL_IMPORT
#endif

static inline QDBusConnection getDBusConnection()
{
#ifdef USE_SYSTEM_DBUS
    return QDBusConnection::systemBus();
#else
    return QDBusConnection::sessionBus();
#endif
}

#endif /* MPRIS_QT_H */
