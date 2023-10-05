#ifndef STOCHASTICRENDERER_H
#define STOCHASTICRENDERER_H

#include "UJImage.h"

class StochasticRenderer : public Renderer{
    public:
        StochasticRenderer();
        virtual void draw(UJImage&);
        virtual ~StochasticRenderer();
    private:
        int _chance; // [0 - 100]
};

#endif // STOCHASTICRENDERER_H
