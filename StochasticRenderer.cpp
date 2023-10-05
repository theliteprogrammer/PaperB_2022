#include "StochasticRenderer.h"


int random(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

StochasticRenderer::StochasticRenderer() : Renderer(){
    _chance = 90;
}
void StochasticRenderer::draw(UJImage& objImage){
    for(int r = 0; r < objImage.getRows(); r++) {
        for(int c = 0; c < objImage.getCols(); c++) {
            UJPixel pixel = objImage.getPixel(r, c);
            int randValue = random(0, 100);
            int sum = pixel.seeds[0] + pixel.seeds[1] + pixel.seeds[2] +
                      pixel.seeds[3] + pixel.seeds[4];
            // seed the random number generator
            srand(sum);
            if(randValue <= _chance) {
                // draw the image
                int change = r - c;
                if(change < 0) {
                    pixel.intRed = 0;
                    pixel.intGreen = 0;
                    pixel.intBlue = 0;
                    objImage.setPixel(r, c, pixel);
                } else {
                    pixel.intRed = change;
                    pixel.intGreen = change;
                    pixel.intBlue = change;
                    objImage.setPixel(r, c, pixel);
                }
            }
        }
    }
}

StochasticRenderer::~StochasticRenderer(){

}
