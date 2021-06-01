import QtQuick 2.0
import QtMultimedia 5.6
import Amber.Mpris 1.0

MprisPlayer {
    property Audio player: parent
    property Playlist playlist: player ? player.playlist : null
    property int _oldLoopStatus: Playlist.Sequential

    playbackStatus: {
        switch (player.playbackState) {
        case Audio.PlayingState:
            return Mpris.Playing
        case Audio.PausedState:
            return Mpris.Paused
        default:
            return Mpris.Stopped
        }
    }

    canControl: true
    canPlay: true

    canGoNext: playlist && playlist.currentIndex < playlist.itemCount - 1 || loopStatus != Mpris.None
    canGoPrevious: playlist && playlist.currentIndex > 0 || loopStatus != Mpris.None
    canPause: true

    canSeek: player.seekable
    metaData.fillFrom: player.metaData
    metaData.url: player.source
    metaData.trackId: playlist && playlist.currentIndex >= 0 ? playlist.currentIndex : null

    loopStatus: {
        if (!playlist)
            return Mpris.None
        if (playlist.playbackMode == Playlist.Random)
            return Mpris.Playlist
        _oldLoopStatus = playlist.playbackMode
        if (playlist.playbackMode == Playlist.CurrentItemInLoop)
            return Mpris.Track
        if (playlist.playbackMode == Playlist.Loop)
            return Mpris.Playlist
        return Mpris.None
    }

    shuffle: playlist ? playlist.playbackMode == Playlist.Random : false
    rate: player.playbackRate
    volume: player.muted ? 0 : player.volume
    onPlayRequested: player.play()
    onStopRequested: player.stop()
    onPauseRequested: player.pause()
    onPlayPauseRequested: if (player.playbackState == Audio.PlayingState) { player.pause() } else { player.play() }
    onNextRequested: if (playlist) { playlist.next() }
    onPreviousRequested: if (playlist) { playlist.previous() }
    onShuffleRequested: if (playlist) { playlist.playbackMode = (shuffle ? Playlist.Random : _oldLoopStatus) }
    onLoopStatusRequested: {
        if (!playlist)
            return
        if (loopStatus == Mpris.Track)
            playlist.playbackMode = Playlist.CurrentItemInLoop
        else if (loopStatus == Mpris.Playlist)
            playlist.playbackMode = Playlist.Loop
        else
            playlist.playbackMode = Playlist.Sequential
    }

    onSetPositionRequested: {
        if (!playlist || playlist.currentIndex == trackId)
            player.seek(position)
    }

    function getPosition() {
        return player.position
    }
}
