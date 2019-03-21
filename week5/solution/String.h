#ifndef _H_MyString
#define _H_MyString

#include <iostream>

namespace MyString {

    template<typename T>
    class It {
    private:
        T* data;
    public:
        It(T* data) {
            this->data = data;
        }

        T &operator*() {
            return *data;
        }

        It<T> &operator++() {
            data++;
            return *this;
        }

        bool operator==(const It<T> &a) {
            return data == a.data;
        }

        bool operator!=(const It<T> &a) {
            return data != a.data;
        }

    };

    class String {
        /**
        * Friendship to implement the ostream operator <<
        */
        friend std::ostream &operator<<(std::ostream &iostream, const MyString::String &string);

    private:
        char* data;
        size_t size;
    public:
        String(const char* data);

        String(size_t init_size = 20);

        String(const String &string);

        ~String();

        char* getText();

        void setText(const char* text);

        /**
        * Returns the current string length (\0 is the end of the string)
        */
        size_t getLength() const;

        /**
        * Set the length of the string
        * If the new length is smaller than its data, everything beyond will be cur
        * If the new length is bigger, all elements will be initialized with \0
        */
        void setLength(size_t size);

        void add(const String &text);

        char get(size_t pos) const;

        bool compare(const String &string) const;

        /** Operators **/

        char operator[](size_t pos);

        /** Iterator **/

        It<char> begin() {
            It<char> it(data);
            return it;
        }

        It<char> end()
        {
            It<char> it(data + size);
            return it;
        }
    };

    /** Free operator methods **/

    String operator+(const String &string1, const String &string2);

    bool operator==(const String &string1, const String &string2);

    std::ostream &operator<<(std::ostream &iostream, const MyString::String &string);
}
#endif
