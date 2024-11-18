#ifndef NOTE_H
#define NOTE_H

#include <string>

class Note {
public:
    Note(const std::string &title, const std::string &text);

    std::string getTitle() const;
    std::string getText() const;
    void setText(const std::string &text);

private:
    std::string title;
    std::string text;
};

#endif
