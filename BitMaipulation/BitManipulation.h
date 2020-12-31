#pragma once
#include <climits>
#include<iostream>
#include <bitset>

//how to update only single  bit of a number without changing other bits from another number (a) copy an int to another int initialized as 0 (b) reverse an int
namespace BitManipulation {
	const size_t byteSize = 8;
	const size_t bitsetSize = byteSize * sizeof(int);
	static void print(int num, int ans) {
		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " number ";
		std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " converted ";
	}
	static void print(int num, unsigned ans) {
		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " number ";
		std::cout << std::endl << std::bitset<byteSize * sizeof(unsigned int)>(ans) << " :" << ans << " converted ";
	}
	static void shiftLeft(int  num, int position) {
		std::cout << std::endl << "ShiftLeft " << num << " to " << position;
		print(num, (num << position));
	}
	static void shiftRight(int  num, int position) {
		std::cout << std::endl << "shiftRight" << num << " to " << position;
		print(num, (num >> position));
	}
	static int setBit(int num, short position) {
		int ans = (1 << position) | num;
		std::cout << std::endl << "setBit position " << position << " from " << bool((1 << position) & num) << " to " << bool((1 << position) & ans);
		print(num, ans);
		return ans;
	}
	static bool getBit(int num, short position) {
		bool ans = (1 << position) & num;
		//std::cout << std::endl << "getBit position " << position << " " << ans;		
		//print(num, ans);
		return ans;
	}
	static int updateBit(int num, short position, bool newVal) {
		//reset the bit first and leave rest of the bits unchanged.
		int ans = ~(1 << position) & num;
		//then | the reset bit with the new value will give new value and OR rest of the bits with the same bits will keep them unchanged
		ans = (newVal << position) | ans;
		std::cout << std::endl << "updateBit position " << position << " from " << bool((1 << position) & num) << " to " << newVal << " is " << bool((1 << position) & ans);
		print(num, ans);
		return ans;
	}
	static int resetBit(int num, short position) {
		int ans = ~(1 << position) & num;
		std::cout << std::endl << "resetBit position " << position << " from " << bool((1 << position) & num) << " to " << bool((1 << position) & ans);
		print(num, ans);
		return ans;
	}



	static int setAllBits(int num) {
		int ans = num | -1;
		std::cout << std::endl << "setAllBits";
		print(num, ans);
		return ans;
	}
	static int resetAllBits(int num) {
		int ans = num & 0;
		std::cout << std::endl << "resetAllBits";
		print(num, ans);
		return ans;
	}
	static int updateAllBits(int num, bool newVal) {
		int ans = 0 | ~(newVal - 1);
		std::cout << std::endl << "updateAllBits to " << newVal;
		print(num, ans);
		return ans;
	}
	static int setBitsFromMSBTill(int num, short position) {
		//00100 - 1 = 00011				
		int ans = ~((1 << (position)) - 1);
		ans = ans | num;
		std::cout << std::endl << "setBitsFromMSBTill " << "position to " << position;
		print(num, ans);
		return ans;
	}

	static int resetBitsFromMSBTill(int num, short position) {
		int ans = (1 << position) - 1;
		ans = ans & num;
		std::cout << std::endl << "resetBitsFromMSBTill " << "position to " << position;
		print(num, ans);
		return ans;
	}
	static int updateBitsFromMSBTill(int num, short position, bool newVal) {
		int ans = (1 << position) - 1;
		ans = ans & num;
		ans = ~((newVal << position) - 1) | ans;
		std::cout << std::endl << "updateBitsFromMSBTill " << "position till " << position << " to " << newVal;
		print(num, ans);
		return ans;
	}

	static int setBitsTillLSB(int num, short position) {
		int ans = (1 << (position + 1)) - 1;
		ans = ans | num;
		std::cout << std::endl << "setBitsTillLSB " << "position to " << position;
		print(num, ans);
		return ans;
	}

	static int resetBitsTillLSB(int num, short position) {
		int ans = ~((1 << (position + 1)) - 1);
		ans = ans & num;
		std::cout << std::endl << "resetBitsTillLSB " << "position to " << position;
		print(num, ans);
		return ans;
	}
	static int updateBitsTillLSB(int num, short position, bool newVal) {
		int num1 = (1 << (position + 1)) - 1;
		num1 = ~num1;
		num1 = num1 & num;

		unsigned int ans = -1;
		ans = (ans >> (bitsetSize - position - 1));
		ans = (ans & newVal) == 0 ? 0 : ans;
		ans = ans | num1;
		std::cout << std::endl << "updateBitsTillLSB " << "position till " << position << " to " << newVal;
		print(num, ans);
		return ans;


		//std::cout << std::endl << std::bitset<byteSize * sizeof(unsigned int)>(num) << ": num move position " << position;
		//std::cout << std::endl << std::bitset<byteSize * sizeof(unsigned int)>(mask) << ": mask newVal = 1";
		/*mask = -1;
		newVal = false;
		mask = (newVal >> (bitsetSize - position - 1)) + mask;
		std::cout << std::endl << std::bitset<byteSize * sizeof(unsigned int)>(mask) << ": mask newVal = 0";*/


	}

	static int insertBits(int num, int toInsert, int startPos, int endPos) {
		std::cout << std::endl << "insertBits startPos " << startPos << " endPos " << endPos;
		int mask = ~(((1 << (startPos + 1)) - 1) ^ ((1 << (endPos + 1)) - 1));
		int num1 = num & mask;
		int toInsert1 = (toInsert << (startPos + 1));
		int ans = num1 | toInsert1;

		std::cout << std::endl << std::bitset<bitsetSize>(toInsert) << " :" << toInsert << " toInsert ";
		print(num, ans);
		return ans;
	}

	static int longestSequenceOfOne(int num) {
		int maxseq = 0;
		int readyToMerge = 0;
		int currSeq = 0;
		bool isZeroBit = false;
		for (int i = 0; i < bitsetSize; i++) {
			if (((1 << i) & num) > 0) //it is a 1
			{
				++currSeq;
				isZeroBit = false;
			}
			else
			{
				if (readyToMerge > 0) { //we have already merged
					if (currSeq + readyToMerge > maxseq)
						maxseq = currSeq + readyToMerge;
					readyToMerge = 0;
				}
				if (isZeroBit) {//received 2 consecutive 0s
					if (currSeq + readyToMerge > maxseq)
						maxseq = currSeq + readyToMerge;
					currSeq = 0;
					readyToMerge = 0;
				}
				else {
					readyToMerge = currSeq +1;
					currSeq = 0;
				}
				isZeroBit = true;
			}
		}
		if (currSeq + readyToMerge > maxseq)
			maxseq = currSeq + readyToMerge;

		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " number ";
		std::cout << std::endl << " longest sequence of 1s with a single flip is: " << maxseq;
		return maxseq;

	}
	int nextSmallest(unsigned int num) {
		//left to right. Find first 1, set it to 0
		//set the previous bit to 1 and break
		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " number ";
		unsigned int ans = 0;		
		if (num == 0) {			
			std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " number already smallest";
			return 0;
		}
		if (num == 1) {
			ans = 1;
			std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " next smallest with same carinality";
			return ans;
		}
		size_t size = 8 * sizeof(unsigned int);
		for (int i = 0; i < size; ++i) {
			if (
				((1 << i) & num) > 1 //found 1
				) {
				ans = (~(1 << i)) & num;
				ans = (1 << (i - 1)) | ans;
				break;
			}
		}
		std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " next smallest with same carinality";
		return ans;
	}
	

	int nextLargest(unsigned int num) {		
		//left to right. Find first 1, set it to 0
		//continue and find first 0 and convert to 1 and break
		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " number ";
		unsigned int ans = 0;
		if (num == UINT_MAX) {
			std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " number Already largest";
			return ans;
		}
		if (num == 0) {
			ans = 1;
			std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " next largest with same carinality";
			return ans;
		}
		size_t size = 8 * sizeof(unsigned int);
		for (int i = 0; i  < size; ++i) {
			if (
				((1 << i & num) > 0) && //found 1
				ans == 0
				) {
				ans = (~(1 << i)) & num;
			}
			else if (
				((1 << i & num) == 0) && //found 0
				ans > 0
				) {
				ans = (1 << i) | ans;
				break;
			}
		}
		
		std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " next largest with same carinality";
		return ans;
	}
	int bitDiffCount(int num1, int num2) {
		int ans = num1 ^ num2;
		int count = 0;
		for (int i = 0; i < byteSize; i++) {
			if (((1 << i) & ans) != 0) //found a zero
				count++;
		}

		std::cout << std::endl << " bitDifference is:" << count;
		std::cout << std::endl << std::bitset<bitsetSize>(num1) << " :" << num1 << " num1 ";
		std::cout << std::endl << std::bitset<bitsetSize>(num2) << " :" << num2 << " num2 ";
		std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " ans ";
		return count;
	}
	int bitOddEvenSwap(int num) {
		int oddBits = num & 0xAAAAAAAA;
		int evenBits = num & 0x55555555;
		int oddBitsRightShifted = oddBits >> 1;
		int evenBitsLeftShifted = evenBits << 1;
		int ans = oddBitsRightShifted | evenBitsLeftShifted;

		std::cout << std::endl << " bitOddEvenSwap";
		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " num ";
		std::cout << std::endl << std::bitset<bitsetSize>(oddBits) << " :" << " oddBits - num & 0xAAAAAAAA";
		std::cout << std::endl << std::bitset<bitsetSize>(oddBitsRightShifted) << " :" << "  oddBits >> 1 RightShifted";
		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " num ";
		std::cout << std::endl << std::bitset<bitsetSize>(evenBits) << " :" << " evenBits - num & 0x55555555";
		std::cout << std::endl << std::bitset<bitsetSize>(evenBitsLeftShifted) << " :" << "  evenBits << 1 Left Shifted";
		std::cout << std::endl << std::bitset<bitsetSize>(num) << " :" << num << " num ";
		std::cout << std::endl << std::bitset<bitsetSize>(ans) << " :" << ans << " ans ";
		
		return num;
		
	}
	int reverseBits(int num) {
		int ans = num;
		std::cout << std::endl << "ReverseBit";
		for (int i = 0; i < bitsetSize / 2; i++) {
			int temp = bitsetSize - 1 - i;
			bool msbSideBit = ((1 << temp) & num) !=0 ; //get bit
			bool lsbSideBit = ((1 << i) & num) != 0;			//get bit
			ans = (~(1 << i)) & ans; //reset from lsb
			ans = (~(1 << temp)) & ans; //reset from msb			
			ans = (lsbSideBit << temp) | ans; //update bit
			ans = (msbSideBit << i) | ans; //update bit
		}
		
		print(num, ans);
		return ans;
	}
}