#include <iostream>
#include <list>
using namespace std;

class Song{
    friend class Playlist;

private:
    string name;

public:
    Song(string name);
};

class Playlist{
private:
    string name;
    list<Song*> playlist;

public:
    void play();
    void createPlaylist();
    void loop();
    void nextSong();
    void previousSong();
    void addSongToPlaylist();
    void addSong(Song* song);
    void deletesong();
};