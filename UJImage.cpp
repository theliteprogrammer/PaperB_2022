#include "UJImage.h"

using std::cerr, std::endl, std::ifstream, std::ofstream, std::stringstream, std::ios;

UJImage::UJImage(){
    loadFromTextFile("init_large.txt");
}

UJImage::UJImage(int rows, int cols) : UJImage(rows, cols, DEFAULT_PIXEL){
}

UJImage::UJImage(int rows, int cols, UJPixel pixel){
    constructor(rows, cols, pixel);
}

UJImage::UJImage(const UJImage& objImage){
    copyConstructor(objImage);
}

int UJImage::getRows() const{
    return _rows;
}

int UJImage::getCols() const{
    return _cols;
}

UJPixel UJImage::getPixel(int row, int col) const{
    enforceRange(row, MIN_VALUE, _rows - 1);
    enforceRange(col, MIN_VALUE, _rows - 1);
    return _pixels[row][col];
}

void UJImage::setPixel(int row, int col, UJPixel pixel){
    enforceRange(row, MIN_VALUE, _rows - 1);
    enforceRange(col, MIN_VALUE, _rows - 1);
    //enforceRange(pixel.intRed, MIN_VALUE, MAX_PIXEL);
    //enforceRange(pixel.intGreen, MIN_VALUE, MAX_PIXEL);
    //enforceRange(pixel.intBlue, MIN_VALUE, MAX_PIXEL);
    _pixels[row][col] = pixel;
}

UJImage& UJImage::operator=(const UJImage& objImage){
    if(this != &objImage) {
        destructor();
        constructor(objImage._rows, objImage._cols, DEFAULT_PIXEL);
        // we are of the same size
        copyConstructor(objImage);
    }
    return *this;
}

ostream& operator<<(ostream& oLHS, const UJImage& objRHS){
    oLHS << "P3" << endl;
    oLHS << objRHS._cols << " " << objRHS._rows << endl;
    oLHS << "255" << endl;
    for(int r = 0; r < objRHS._rows; r++) {
        for(int c = 0; c < objRHS._cols; c++){
            oLHS << objRHS._pixels[r][c].intRed << " "
                 << objRHS._pixels[r][c].intGreen << " "
                 << objRHS._pixels[r][c].intBlue << " ";
        }
        oLHS << endl;
    }
    return oLHS;
}

UJImage& UJImage::operator++(){
    for(int r = 0; r < _rows; r++) {
        for(int c = 0; c < _cols; c++) {
            ++_pixels[r][c].intRed;
            ++_pixels[r][c].intGreen;
            ++_pixels[r][c].intBlue;
        }
    }
    return *this;
}

void UJImage::saveToDAT(string fileName){
    ofstream output;
    output.open(fileName, ios::binary);
    for(int r = 0; r < _rows; r++) {
        for(int c = 0; c < _cols; c++)
            output.write(reinterpret_cast<const char*>(&_pixels[r][c]), sizeof(_pixels[r][c]));
    }
    output.close();
}

void UJImage::draw(){
    _render->draw(*this); // delegation
}

UJImage::~UJImage(){
    destructor();
}

void UJImage::loadFromTextFile(string fileName){
    ifstream input;
    input.open(fileName); // open the file
    // check if the file failed to open
    if(input.fail()){
        cerr << "failed to open the file" << endl;
        exit(ERROR_IN_FILE_OPEN);
    }
    input >> _rows >> _cols >> stochasticity;
    // allocate memory for the array
    constructor(_rows, _cols, DEFAULT_PIXEL);
    // read from the file
    string line("");
    stringstream ss;
    int row = 0, col = 0, counter = 0, value = 0;
    while(getline(input, line)){
        ss << line;
        ss >> row >> col;
        while(ss >> value){
            _pixels[row][col].seeds[counter++] = value;
        }
    }
    input.close();
}

void UJImage::enforceRange(int value, int minValue, int maxValue) const{
   if(value < minValue) {
      cerr << value << " is less than expected minimum of " << minValue << endl;
      exit(ERROR_IN_RANGE); // -2
   }
   if(value > maxValue) {
      cerr << value << " is greater than expected maximum of " << maxValue << endl;
      exit(ERROR_IN_RANGE);
   }
}

void UJImage::constructor(int rows, int cols, UJPixel pixel){
    enforceRange(rows, MIN_VALUE, MAX_VALUE - 1);
    enforceRange(cols, MIN_VALUE, MAX_VALUE - 1);
    enforceRange(pixel.intRed, MIN_VALUE, MAX_PIXEL);
    enforceRange(pixel.intGreen, MIN_VALUE, MAX_PIXEL);
    enforceRange(pixel.intBlue, MIN_VALUE, MAX_PIXEL);
    _rows = rows;
    _cols = cols;
    _pixels = new UJPixel*[_rows];
    for(int r = 0; r < _rows; r++) {
        _pixels[r] = new UJPixel[_cols];
        for(int c = 0; c < _cols; c++)
            _pixels[r][c] = pixel;
    }
    // life cycle management
    if(stochasticity == 'Y')
        _render = new StochasticRenderer();
    else if(stochasticity == 'N')
        _render = new ContinuousRenderer();
    else{
        cerr << "Could not instantiate a renderer" << endl;
        exit(ERROR_IN_INSTANTIATION);
    }
}

void UJImage::destructor(){
    assert(_pixels != nullptr);
    for(int r = 0; r < _rows; r++)
        delete [] _pixels[r];
    delete [] _pixels;
    _pixels = nullptr;
    delete _render;
    _render = nullptr;
}

void UJImage::copyConstructor(const UJImage& objImage){
    assert(objImage._rows == _rows);
    assert(objImage._cols == _cols);
    for(int r = 0; r < _rows; r++){
        for(int c = 0; c < _cols; c++)
            _pixels[r][c] = objImage._pixels[r][c];
    }
}
