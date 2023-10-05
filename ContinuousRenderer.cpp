#include "ContinuousRenderer.h"

ContinuousRenderer::ContinuousRenderer() : Renderer(){
    _maximumIntensity = 10;
}

void ContinuousRenderer::draw(UJImage& objImage) {
    for(int r = 0; r < objImage.getRows(); r++) {
        for(int c = 0; c < objImage.getCols(); c++) {
            UJPixel pixel = objImage.getPixel(r, c);
            int change = r - c;
            if(pixel.intRed < _maximumIntensity &&
               pixel.intGreen < _maximumIntensity &&
               pixel.intBlue < _maximumIntensity) {
                if(change < 0) {
                    pixel.intRed = 0;
                    pixel.intGreen = 0;
                    pixel.intBlue = 0;
                    objImage.setPixel(r, c, pixel);
                } else {
                    pixel.intRed = change;
                    pixel.intGreen = change;
                    pixel.intBlue = change;
                }
            }
        }
    }
}

ContinuousRenderer::~ContinuousRenderer(){
}
