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

class UJImage{
    public:
        // constructors - builders
        UJImage(); // builders that help us build the object
        UJImage(int, int);
        UJImage(int, int, UJPixel);
        UJImage(const UJImage&);

        // class constants
        static constexpr UJPixel DEFAULT_PIXEL = {0, 0, 0, {0, 0, 0, 0, 0}};
        static const int MIN_VALUE = 0;
        static const int MAX_VALUE = 10'000;
        static const int MAX_PIXEL = 255;
        // accessors - getters
        int getRows() const; // READONLY
        int getCols() const;
        UJPixel getPixel(int, int) const;

        // mutators - setters
        void setPixel(int, int, UJPixel);

        // operators - operator overloading
        UJImage& operator=(const UJImage&);
        friend ostream& operator<<(ostream&, const UJImage&);
        UJImage& operator++();

        // functions for file handling
        void saveToDAT(string);

        void draw();

        // destructor - destroyer -demolishin team
        ~UJImage();
    private:
        UJPixel** _pixels;
        Renderer* _render;
        int _rows, _cols;
        char stochasticity;
        void loadFromTextFile(string);
        void enforceRange(int, int, int) const;
        void constructor(int, int, UJPixel);
        void destructor();
        void copyConstructor(const UJImage&);
};
#endif // UJIMAGE_H
