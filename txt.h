#ifndef TXT_H
#define TXT_H

#include <cstring>
#include <fstream>


namespace l1
{
    class Txt
    {
    public:
        Txt();
        Txt(const char* path);
        Txt(const Txt& other);
        Txt(Txt&& other);
        ~Txt();

        Txt& operator=(const Txt& other);
        Txt& operator=(Txt&& other);

        size_t size() const;
        void clear();

    private:


        size_t __size = 0;
        char** __data = nullptr;


    };

}

#endif // TXT_H
