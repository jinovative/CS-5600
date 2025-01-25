/*
 * learnc.c / Mileage Conversion
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 14, 2025
 *
 */


#include <stdio.h>
#include "mpg2km.h"

int main() {
    printf("Testing mileage conversion functions...\n");
    printf("10 MPG = %.2f KML\n", mpg2kml(10));
    printf("10 MPG = %.2f L/100KM\n", mpg2lphm(10));
    printf("10 L/100KM = %.2f MPG\n", lph2mpg(10));
    return 0;
}
