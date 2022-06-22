#include <stdio.h>
#include <assert.h>
#include "initialize.h"

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}


int main() {
    int count = 0;
    for(int i=WHITE;i<=VIOLET;i++)
    {
        for(int j=BLUE;j<=SLATE;j++)
        {
            count++;
            testNumberToPair(count,i,j);
            testPairToNumber(i,j,count);
        }
    }
    return 0;
}
