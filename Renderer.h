#ifndef RENDERER_H
#define RENDERER_H

struct Coordinate{
    int row;
    int col;
};

template<typename T>
class UJimage;

template<typename T>
class Renderer{
    public:
        Renderer();
        Renderer(Coordinate);
        static constexpr Coordinate DEFAULT_COORDINATE = {0, 0};
        virtual void draw(UJimage<T>&) = 0;
        virtual ~Renderer();
    private:
        Coordinate _coordinate;
};

#include "Renderer.imp"

#endif // RENDERER_H
