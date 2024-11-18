#include "NoteManager.h"
#include <fstream>
#include <iostream>
#include <regex>

void NoteManager::addNote(const std::string &title, const std::string &text) {
    if (validateInput(title) && validateInput(text)) {
        notes.push_back(Note(title, text));
    } else {
        std::cout << "Invalid characters detected. Only ., and letters are allowed.\n";
    }
}

bool NoteManager::deleteNoteByTitle(const std::string &title) {
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        if (it->getTitle() == title) {
            notes.erase(it);
            return true;
        }
    }
    return false;
}

Note* NoteManager::searchNoteByTitle(const std::string &title) {
    for (auto &note : notes) {
        if (note.getTitle() == title) {
            return &note;
        }
    }
    return nullptr;
}

bool NoteManager::modifyNoteText(const std::string &title, const std::string &newText) {
    Note *note = searchNoteByTitle(title);
    if (note && validateInput(newText)) {
        note->setText(newText);
        return true;
    }
    return false;
}

std::vector<Note> NoteManager::getAllNotes() const {
    return notes;
}

bool NoteManager::validateInput(const std::string &input) {
    std::regex pattern("^[A-Za-z0-9 .,]+$");
    return std::regex_match(input, pattern);
}

void NoteManager::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    std::string title, text;
    while (getline(file, title) && getline(file, text)) {
        notes.emplace_back(title, text);
    }
    file.close();
}

void NoteManager::saveToFile(const std::string &filename) {
    std::ofstream file(filename);
    for (const auto &note : notes) {
        file << note.getTitle() << "\n" << note.getText() << "\n";
    }
    file.close();
}
