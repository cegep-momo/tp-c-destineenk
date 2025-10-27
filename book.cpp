#include "book.h"
#include <iostream>
#include <sstream>
#include <string>


// Constructeur par défaut
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {
    // Constructeur vide avec liste d'initialisation
}

// Constructeur avec paramètres
Book::Book(const std::string& title, const std::string& author,const std::string& isbn) 
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName(""){
}



// Méthodes d'accès (getters)
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

bool Book:: getAvailability() const {
    return isAvailable;
}

std::string Book::getBorrowerName() const {
    return borrowerName;
}



// Méthodes de modification (setters)
void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

void Book::setISBN(const std::string& isbn) {
    this->isbn = isbn;
}

void Book::setAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Book::setBorrowerName(const std::string& borrowerName) {
    this->borrowerName = borrowerName;
}
void Book::checkOut(const string& borrower) {

    if (isAvailable) {
        isAvailable = false;
        borrowerName = borrower;
    }
}

void Book::returnBook() {
    isAvailable = true;
    borrowerName = "";
   
}

string Book::toString() const {
    string statut = isAvailable ? "Disponible" : ("Emprunté par: " + borrowerName);
    return "Titre: " + title + ", Auteur: " + author + ", ISBN: " + isbn + ", Statut: " + statut;
}


string Book::toFileFormat() const {
    std::stringstream bookTxt;

    bookTxt << title << "|" << author << "|" <<isbn << "|"
    << isAvailable << "|" <<borrowerName;

    return bookTxt.str();
}

void Book::fromFileFormat(const string& line) {
    stringstream bookTxt(line);
    string availableStr;
    getline(bookTxt, title, '|');
    getline(bookTxt, author, '|');
    getline(bookTxt, isbn, '|');
    getline(bookTxt, availableStr, '|');
    getline(bookTxt, borrowerName, '|');
    isAvailable = (availableStr == "1" || availableStr == "true");
}