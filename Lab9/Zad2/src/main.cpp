#include "../include/odtwarzacz.h"

int main() {

    Playlist playlist;
    playlist.createPlaylist();
    int wybor;

    cout << "Co chcesz zrobic?\n"
         << "1 - dodaj piosenke do playlisty\n"
         << "2 - usun piosenke z playlisty\n"
         << "3 - odtwarzaj playliste\n"
         << "4 - odtwarzaj playliste w petli\n"
         << "5 - kolejna piosenka\n"
         << "6 - poprzednia piosenka\n"
         << "7 - zakoncz\n";


    while (1) {
        cout << "Wybor = ";
        cin >> wybor;
        switch (wybor) {
            case 1:
                playlist.addSongToPlaylist();
                break;
            case 2:
                playlist.deletesong();
                break;
            case 3:
                playlist.play();
                break;
            case 4:
                playlist.loop();
                break;
            case 5:
                playlist.nextSong();
                break;
            case 6:
                playlist.previousSong();
                break;
            case 7:
                exit(1);
            default:
                cout << "Podano zly numer\n";
                break;
        }
    }
}

