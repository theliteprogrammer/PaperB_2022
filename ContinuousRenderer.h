#ifndef CONTINUOUSRENDERER_H
#define CONTINUOUSRENDERER_H

#include "UJImage.h"

template<typename T>
class ContinuousRenderer : public Renderer<T>{
    public:
        ContinuousRenderer();
        virtual void draw(UJimage<T>&);
        virtual ~ContinuousRenderer();
    private:
        int _maximumIntensity;
};

#include "ContinuousRenderer.imp"

#endif // CONTINUOUSRENDERER_H
