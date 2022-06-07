#include "txt.h"
#include <algorithm>

l1::Txt::Txt(){}


l1::Txt::Txt(const char* path)
{
    std::ifstream in(path);

    if(in.is_open() )
    {
        this->__size = std::count(std::istreambuf_iterator<char>(in),
                                  std::istreambuf_iterator<char>(), '\n');

        this->__data = new char*[this->__size];
        std::string line;

        for(size_t i = 0; i < this->__size; ++i)
        {
            std::getline(in, line);

            this->__data[i] = new char[line.size() + 1];
            strncpy(this->__data[i], line.c_str(), line.size());
        }

        in.close();
    }
}


l1::Txt::Txt(const Txt& other)
    : __size(other.__size)
    , __data(new char*[other.__size])
{
    size_t lineLength = 0;

    for(size_t i = 0; i < this->__size; ++i)
    {
        lineLength = strlen(other.__data[i]) + 1;
        this->__data[i] = new char[lineLength];

        strncpy(this->__data[i], other.__data[i], lineLength);
    }
}


l1::Txt::Txt(Txt&& other)
    : __size(other.__size)
    , __data(other.__data)
{
    other.__size = 0;
    other.__data = nullptr;
}


l1::Txt::~Txt()
{
    clear();
}


void l1::Txt::clear()
{
    if(__data != nullptr)
    {
        for(size_t i = 0; i < __size; ++i)
        {
            delete[] __data[i];
        }

        delete[] __data;
        __data = nullptr;
    }

    __size = 0;

}


l1::Txt& l1::Txt::operator=(const Txt& other)
{
    if(this != &other)
    {
        clear();

        this->__size = other.__size;
        this->__data = new char*[this->__size];

        size_t lineLength = 0;

        for(size_t i = 0; i < this->__size; ++i)
        {
            lineLength = strlen(other.__data[i]) + 1;
            this->__data[i] = new char[lineLength];

            strncpy(this->__data[i], other.__data[i], lineLength);
        }
    }

    return *this;
}


l1::Txt& l1::Txt::operator=(Txt&& other)
{
    if(this != &other)
    {
        clear();

        this->__size = other.__size;
        this->__data = other.__data;

        other.__data = nullptr;
    }

    return *this;
}


size_t l1::Txt::size() const
{
    return __size;
}
