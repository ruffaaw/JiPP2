#include <iostream>
#include "../include/notes.h"

string Note::getTitle() {
    return title;
}

void Note::setTitle() {
    cout << "Nazwij swoja notatke";
    cin >> title;
}

string TextNote::getContent() {
    return content;
}
void TextNote::setContent() {
    cout << "Wprowadz text do notatki";
    cin >> content;
}