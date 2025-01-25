#include "mpg2km.h"

double mpg2kml(double mpg) {
    return mpg * 1.60934 / 3.78541;
}

double mpg2lphm(double mpg) {
    return 100.0 / (mpg * 1.60934 / 3.78541);
}

double lph2mpg(double lph) {
    return 100.0 / lph * 3.78541 / 1.60934;
}
