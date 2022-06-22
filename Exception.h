#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>


class DeckFileNotFound : public std::exception
{
public:
    const char* what() const noexcept override
    {
       return "Deck File Error: File not found";
    }
};


class DeckFileFormatError : public std::exception
{
public:
 
    DeckFileFormatError(int line) : m_message{"Deck File Error: File format error in line " + std::to_string(line)}
    {
    }

     const char* what() const  noexcept override
     {
        return m_message.c_str();
     }
    
private:
    std::string m_message;

};


class DeckFileInvalidSize : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif //HW4_EXCEPTION_H
