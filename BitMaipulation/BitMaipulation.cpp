// BitMaipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BitManipulation.h"

int main()
{
    std::cout << "Hello World!\n";
    BitManipulation::setBit(-1, 0);
    BitManipulation::setBit(0, 0);
    BitManipulation::setBit(18, 0);
    BitManipulation::setBit(18, 1);
    BitManipulation::setBit(18, 31);
    

    BitManipulation::getBit(-1, 0);
    BitManipulation::getBit(-1, 31);
    BitManipulation::getBit(0, 0);
    BitManipulation::getBit(18, 0);
    BitManipulation::getBit(18, 1);
    BitManipulation::getBit(18, 31);

    BitManipulation::updateBit(-1, 0, false);
    BitManipulation::updateBit(-1, 0, true);
    BitManipulation::updateBit(-1, 31, false);
    BitManipulation::updateBit(-1, 31, true);

    BitManipulation::resetBit(-1, 0);
    BitManipulation::resetBit(0, 0 );
    BitManipulation::resetBit(-1, 31);
    BitManipulation::resetBit(1, 31);

    BitManipulation::setAllBits(-1);
    BitManipulation::setAllBits(0);
    BitManipulation::setAllBits(1);
    BitManipulation::setAllBits(55689);

    BitManipulation::resetAllBits(-1);
    BitManipulation::resetAllBits(0);
    BitManipulation::resetAllBits(1);
    BitManipulation::resetAllBits(55689);

    BitManipulation::updateAllBits(-1, true);
    BitManipulation::updateAllBits(-1, false);
    BitManipulation::updateAllBits(0, true);
    BitManipulation::updateAllBits(0, false);
    BitManipulation::updateAllBits(12589, true);
    BitManipulation::updateAllBits(-7785, false);

    BitManipulation::setBitsFromMSBTill(0, 6);
    BitManipulation::setBitsFromMSBTill(-1, 0);
    BitManipulation::setBitsFromMSBTill(-1, 31);
    BitManipulation::setBitsFromMSBTill(0, 31);
    BitManipulation::setBitsFromMSBTill(0, 0);
    BitManipulation::setBitsFromMSBTill(8457, 4);

    BitManipulation::resetBitsFromMSBTill(0, 6);
    BitManipulation::resetBitsFromMSBTill(-1, 0);
    BitManipulation::resetBitsFromMSBTill(-1, 31);
    BitManipulation::resetBitsFromMSBTill(0, 31);
    BitManipulation::resetBitsFromMSBTill(0, 0);
    BitManipulation::resetBitsFromMSBTill(8457, 4);

    BitManipulation::updateBitsFromMSBTill(0, 6, true);
    BitManipulation::updateBitsFromMSBTill(0, 6, false);
    BitManipulation::updateBitsFromMSBTill(-1, 6, true);
    BitManipulation::updateBitsFromMSBTill(-1, 6, false);
    BitManipulation::updateBitsFromMSBTill(8457, 4, true);
    BitManipulation::updateBitsFromMSBTill(8457, 4, false);
    

    BitManipulation::setBitsTillLSB(0, 6);
    BitManipulation::setBitsTillLSB(-1, 0);
    BitManipulation::setBitsTillLSB(-1, 31);
    BitManipulation::setBitsTillLSB(0, 30);
    BitManipulation::setBitsTillLSB(0, 0);
    BitManipulation::setBitsTillLSB(8457, 4);


    BitManipulation::resetBitsTillLSB(0, 6);
    BitManipulation::resetBitsTillLSB(-1, 0);
    BitManipulation::resetBitsTillLSB(-1, 31);
    BitManipulation::resetBitsTillLSB(0, 30);
    BitManipulation::resetBitsTillLSB(0, 0);
    BitManipulation::resetBitsTillLSB(8457, 4);


    
    BitManipulation::updateBitsTillLSB(0, 6, true);
    BitManipulation::updateBitsTillLSB(0, 6, false);
    BitManipulation::updateBitsTillLSB(-1, 6, true);
    BitManipulation::updateBitsTillLSB(-1, 6, false);
    BitManipulation::updateBitsTillLSB(8457, 4, true);
    BitManipulation::updateBitsTillLSB(8457, 4, false);

    BitManipulation::insertBits(4096, 7, 6, 10);
    
    BitManipulation::longestSequenceOfOne(-1);

    BitManipulation::nextLargest(24);

    BitManipulation::nextSmallest(45789);
    BitManipulation::bitDiffCount(29,15);
    BitManipulation::bitOddEvenSwap(45789);
    
    
  //  BitManipulation::reverseBits(-1);
//    BitManipulation::reverseBits(0);
    BitManipulation::reverseBits(-1    );
    BitManipulation::reverseBits(0);
    BitManipulation::reverseBits(47814486);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
