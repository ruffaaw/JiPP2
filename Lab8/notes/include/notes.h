#ifndef FIGURE_NOTES_H
#define FIGURE_NOTES_H
#include <iostream>

using namespace std;

class Note{
    string title;

public:
    string getTitle();
    void setTitle();
    virtual string getContent() = 0;
    virtual void setContent() = 0;
};

class TextNote: public Note{
    string content;
public:
    string getContent();
    void setContent();
};
#endif //FIGURE_NOTES_H
