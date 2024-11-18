#include "Note.h"

Note::Note(const std::string &title, const std::string &text) : title(title), text(text) {}

std::string Note::getTitle() const {
    return title;
}

std::string Note::getText() const {
    return text;
}

void Note::setText(const std::string &text) {
    this->text = text;
}
