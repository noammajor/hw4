#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H
#include <exception>
#include  <iostream>
#include <string>

class DeckFileNotFound : public std::exception
{
public:
    std::string what()
    {
       return "Deck File Error: File not found";
    }
};
class DeckFileFormatError : public std::exception
{
private:
    int line;
    std::string message="Deck File Error: File format error in line ";
public:
    DeckFileFormatError(int size)
    {
       line=size;
    }
    std::string what()
    {
       message = message + std::to_string(line);
        return message;
    }
};

class DeckFileInvalidSize : public std::exception
{
public:
    std::string what()
    {
        return "Deck File Error: Deck size is invalid";
    }
};



#endif //HW4_EXCEPTION_H