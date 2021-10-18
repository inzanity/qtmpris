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


import QtQuick 2.0
import Amber.Mpris 1.0

Item {
    id: controls

    property MprisManager mprisManager
    property bool isPlaying: mprisManager.currentService && mprisManager.playbackStatus == Mpris.Playing

    height: parent.height
    width: column.width

    Column {
        id: column

        Text {
            id: artistLabel

            text: mprisManager.metaData.contributingArtist || ''
            width: parent.width
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: songLabel

            text: mprisManager.metaData.title || ''
            width: parent.width
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
        }

        Row {

            MouseArea {

                width: controls.parent.width * 0.25
                height: width

                onClicked: if (mprisManager.canGoPrevious) mprisManager.previous()

                Text {
                    anchors.centerIn: parent
                    text: "⏮"
                }
            }
            MouseArea {

                width: controls.parent.width * 0.25
                height: width

                onClicked: if (mprisManager.canPlay || mprisManager.canPause) mprisManager.playPause()

                Text {
                    anchors.centerIn: parent
                    text: controls.isPlaying ? "⏸" : "⏵"
                }
            }
            MouseArea {

                width: controls.parent.width * 0.25
                height: width

                onClicked: if (mprisManager.canGoNext) mprisManager.next()

                Text {
                    anchors.centerIn: parent
                    text: "⏭"
                }
            }
        }
    }
}

