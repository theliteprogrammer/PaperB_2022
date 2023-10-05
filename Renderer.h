#ifndef RENDERER_H
#define RENDERER_H

struct Coordinate{
    int row;
    int col;
};

class UJImage; // forward declaration

class Renderer{
    public:
        Renderer();
        Renderer(Coordinate);
        static constexpr Coordinate DEFAULT_COORDINATE = {0, 0};
        virtual void draw(UJImage&) = 0;
        virtual ~Renderer();
    private:
        Coordinate _coordinate;
};

#endif // RENDERER_H
