#ifndef STOCHASTICRENDERER_H
#define STOCHASTICRENDERER_H

#include "UJImage.h"

template<typename T>
class StochasticRenderer : public Renderer<T>{
    public:
        StochasticRenderer();
        virtual void draw(UJimage<T>&);
        virtual ~StochasticRenderer();
    private:
        int _chance; // [0 - 100]
};

#include "StochasticRenderer.imp"

#endif // STOCHASTICRENDERER_H
