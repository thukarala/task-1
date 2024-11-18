#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include "Note.h"
#include <vector>
#include <string>

class NoteManager {
public:
    void addNote(const std::string &title, const std::string &text);
    bool deleteNoteByTitle(const std::string &title);
    Note* searchNoteByTitle(const std::string &title);
    std::vector<Note> getAllNotes() const;
    bool modifyNoteText(const std::string &title, const std::string &newText);
    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename);

private:
    std::vector<Note> notes;
    bool validateInput(const std::string &input);
};

#endif
