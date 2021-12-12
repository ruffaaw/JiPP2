#include "../include/odtwarzacz.h"

Song::Song(string name): name(name){};

void Playlist::addSong(Song *song) {
    playlist.push_back(song);
}

void Playlist::createPlaylist(){
    cout<<"Podaj tytul swojej playlisty"<<endl;
    getline(cin >> ws, name);

    Song* newSong = new Song("Pierwsza piosenka");
    addSong(newSong);
}
void Playlist::loop(){
    int i=1;
    list<Song*>::iterator x;
    if (playlist.size() > 0) {
        cout << "Odtwarzanie w petli: " << endl;
        for (x = playlist.begin(); x != playlist.end(); ++x) {
            cout<<"Piosenka nr. "<<i<<"\t\t";
            cout << (*x)->name << endl;
            i++;
        }
    }
}
void Playlist::nextSong(){
    list<Song*>::iterator x = playlist.begin();

    playlist.pop_front();
    playlist.push_back((*x));
    cout << "Obecnie grana: " << (*x)->name<<endl;
}
void Playlist::previousSong(){
    list<Song*>::iterator y = playlist.end();
    auto lastSong = prev(y, 1);
    playlist.pop_back();
    playlist.push_front(*lastSong);
    cout << "Obecnie grana: " << (*y) ->name << endl;
}
void Playlist::addSongToPlaylist(){
    string newTitle;
    cout << "Podaj tytul utworu: ";
    getline(cin >> ws, newTitle);

    Song* newSong = new Song(newTitle);
    addSong(newSong);
}
void Playlist::play(){
    list<Song *>::iterator song = playlist.begin();
    cout << "Aktualnie gra: " << endl;
    cout << "Tytul: "  << (*song)->name << endl;
}
void Playlist::deletesong(){
    string usun;
    int i = 0;
    list<Song*>::iterator x = playlist.begin();

    cout << "Podaj usuwany tytul: ";
    getline(cin >> ws, usun);

    while (x != playlist.end()) {
        if (((*x)->name.compare(usun)) == 0) {
            playlist.erase(x++);
            i++;
            cout<<"Piosenka usunieta\n";
            break;
        }
        else {
            ++x;
            i++;
        }
    }

    cout << "Nie ma utworu" << endl;
}