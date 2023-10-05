#include "Renderer.h"

Renderer::Renderer() : Renderer(DEFAULT_COORDINATE){
}

Renderer::Renderer(Coordinate coordinate){
    _coordinate = coordinate;
}

Renderer::~Renderer(){
   // ujImage manages it's life cycle
}


