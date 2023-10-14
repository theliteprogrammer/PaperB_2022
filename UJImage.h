#ifndef UJIMAGE_H
#define UJIMAGE_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include "Renderer.h"
#include "StochasticRenderer.h"
#include "ContinuousRenderer.h"

using std::ostream, std::string;

const int LENGTH = 5;

#pragma pack(push, 1)
struct UJPixel{
    int intRed;  // [0 - 255]
    int intGreen; // [0 - 255]
    int intBlue; // [0 - 255]
    int seeds[LENGTH];
};
#pragma pack(pop)

enum Status{
    ERROR_IN_RANGE = -3,
    ERROR_IN_FILE_OPEN,
    ERROR_IN_INSTANTIATION,
    SUCCESS
};

template<typename T>
class UJimage{
    public:
        // constructors - builders
        UJimage(); // builders that help us build the object
        UJimage(int, int);
        UJimage(const UJimage<T>&);

        // class constants
        static const int MIN_VALUE = 0;
        static const int MAX_VALUE = 10'000;
        static const int MAX_PIXEL = 255;
        // accessors - getters
        int getRows() const; // READONLY
        int getCols() const;
        T getPixel(int, int) const;

        // mutators - setters
        void setPixel(int, int, T);

        // operators - operator overloading
        UJimage<T>& operator=(const UJimage<T>&);
        template<typename T1>
        friend ostream& operator<<(ostream&, const UJimage<T1>&);
        UJimage<T>& operator++();

        // functions for file handling
        void saveToDAT(string);

        void draw();

        // destructor - destroyer -demolishin team
        ~UJimage();
    private:
        T** _pixels;
        Renderer<T>* _render;
        int _rows {0}, _cols {0};
        char stochasticity {'\0'};
        void loadFromTextFile(string);
        void enforceRange(int, int, int) const;
        void constructor(int, int);
        void destructor();
        void copyConstructor(const UJimage<T>&);
};

#include "UJImage.imp"

#endif // UJIMAGE_H
