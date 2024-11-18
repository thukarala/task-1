#include "NoteManager.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Add Note\n";
    std::cout << "2. Search Note by Title\n";
    std::cout << "3. Delete Note by Title\n";
    std::cout << "4. Modify Note Text\n";
    std::cout << "5. Display All Notes\n";
    std::cout << "6. Save & Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    NoteManager manager;
    manager.loadFromFile("notes.txt");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title, text;
            std::cout << "Enter title: ";
            getline(std::cin, title);
            std::cout << "Enter text: ";
            getline(std::cin, text);
            manager.addNote(title, text);
        } else if (choice == 2) {
            std::string title;
            std::cout << "Enter title to search: ";
            getline(std::cin, title);
            Note *note = manager.searchNoteByTitle(title);
            if (note) {
                std::cout << "Title: " << note->getTitle() << "\nText: " << note->getText() << "\n";
            } else {
                std::cout << "Note not found.\n";
            }
        } else if (choice == 3) {
            std::string title;
            std::cout << "Enter title to delete: ";
            getline(std::cin, title);
            if (manager.deleteNoteByTitle(title)) {
                std::cout << "Note deleted.\n";
            } else {
                std::cout << "Note not found.\n";
            }
        } else if (choice == 4) {
            std::string title, newText;
            std::cout << "Enter title to modify: ";
            getline(std::cin, title);
            std::cout << "Enter new text: ";
            getline(std::cin, newText);
            if (manager.modifyNoteText(title, newText)) {
                std::cout << "Note modified.\n";
            } else {
                std::cout << "Note not found or invalid text.\n";
            }
        } else if (choice == 5) {
            std::vector<Note> notes = manager.getAllNotes();
            for (const auto &note : notes) {
                std::cout << "Title: " << note.getTitle() << "\nText: " << note.getText() << "\n\n";
            }
        }
    } while (choice != 6);

    manager.saveToFile("notes.txt");
    std::cout << "Notes saved. Goodbye!\n";
    return 0;
}
