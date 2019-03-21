#include <iostream>
#include "String.h"

using namespace std;

int main() {
    MyString::String string1;
    MyString::String string2("Welt");

    string1.setText("Hallo ");
    string2.add("!");

    MyString::String pstring = string1 + string2 + " with character array added";

    cout << "String1 and String2: " << string1 << string2 << endl;
    cout << "String1 + String2: " << pstring << endl;
    cout << "Comparing 1 with 2: " << (string1 == string2) << endl;
    cout << "Comparing 1 with 1: " << (string1 == string1) << endl;
    cout << "Get: " << string1[0] << endl;

    MyString::It<char> it = pstring.begin();
    while ( it != pstring.end()) {
        cout<<*it<<endl;
        ++it;
    }
    return 0;
}
 String.cpp
#include "String.h"
#include <string.h>

namespace MyString {

    /**
    * Constructor with empty initialization
    */
    String::String(size_t init_size) {
        this->data = new char[init_size];
        this->size = init_size;

        if (this->data != NULL) {
            for (size_t i = 0; i < init_size; i++) {
                data[i] = '\0';
            }
        }
    }

    /**
    * Constructor with char*
    */
    String::String(const char* data) {
        size_t size = strlen(data);

        this->data = new char[size];
        this->size = size;

        if (this->data != NULL) {
            strncpy(this->data, data, size);
        }
    }

    /**
    * Copy Constructor
    */
    String::String(const String &string) {
        this->size = string.getLength();
        this->data = new char[this->size];

        if (this->data != NULL) {
            strncpy(this->data, string.data, this->size);
        }
    }

    /**
    * Destructor
    */
    String::~String() {
        if (this->data != NULL)
            delete[] this->data;
    }


    /** Methods **/


    char* String::getText() {
        return data;
    }

    void String::setText(const char* text) {
        delete[] this->data;

        this->size = strlen(text);
        this->data = new char[this->size];

        strncpy(this->data, text, this->size);
    }

    size_t String::getLength() const {
        return strlen(this->data);
    }

    void String::setLength(size_t size) {
        size_t old_length = this->getLength();
        char* old_data = this->data;

        this->size = size;
        this->data = new char[size];

        // Copy the characters (or add \0 if there are no characters anymore).
        for (size_t i = 0; i < size; i++) {
            if (i < old_length) {
                this->data[i] = old_data[i];
            } else {
                this->data[i] = '\0';
            }
        }

        // Destroy the old data
        delete[] old_data;

        // Ensure that the last element is \0
        this->data[size] = '\0';
    }

    void String::add(const String &text) {
        size_t new_size = this->size + text.size;
        setLength(new_size);

        size_t length = getLength();
        for (size_t i = length; i < new_size; i++) {
            this->data[i] = text.data[i - length];
        }
    }

    char String::get(size_t pos) const {
        if (pos > getLength()) {
            return '\0';
        }
        return data[pos];
    }

    bool String::compare(const String &string) const {
        return strcmp(this->data, string.data) == 0;
    }

    char String::operator[](size_t pos) {
        return this->get(pos);
    }


    /** Free Operator Methods **/

    String operator+(const String &string1, const String &string2) {
        String string = String(string1);
        string.add(string2);

        return string;
    }

    bool operator==(const String &string1, const String &string2) {
        return string1.compare(string2);
    }


    std::ostream &operator<<(std::ostream &ostream, const MyString::String &string) {
        return (ostream << string.data);
    }
}

