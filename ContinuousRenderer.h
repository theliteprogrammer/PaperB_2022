#ifndef CONTINUOUSRENDERER_H
#define CONTINUOUSRENDERER_H

#include "UJImage.h"

class ContinuousRenderer : public Renderer{
    public:
        ContinuousRenderer();
        virtual void draw(UJImage&);
        virtual ~ContinuousRenderer();
    private:
        int _maximumIntensity;
};

#endif // CONTINUOUSRENDERER_H
