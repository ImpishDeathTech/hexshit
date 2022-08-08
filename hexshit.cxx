/*
 * hexshit.cxx
 *
 * BSD 3-Clause License
 *
 * Copyright (c) 2022, Christopher Stephen Rafuse
 * All rights reserved.
 */

#include "hexshit.hxx"
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cstdint>

// hexdump function: dumps binary bytecode in a nice, formatted text block
void hexshit(DataBuffer value) {
	std::stringstream ss;
	std::string       printable;
	
	int32_t    indent    = 1,
			   relPos    = 0,
			   nulls     = 0,
			   zeros     = 0,
	           outLenA   = 0,
	           outLenB   = 0;

	uint8_t   *tempBuf, 
	           tempChar;

	bool       isEmpty   = false;
	ByteBuffer buffer    = { (uint8_t*)(value.data), value.size };

	while (buffer.size > 0) {
		tempBuf    = buffer.data;
		outLenA = buffer.size;
		printable = " [";

		if (outLenA > 16)
			outLenA = 16;
		
		ss << "{ " << std::setw(8) << std::setfill('0') << std::hex << tempBuf - buffer.data << " } ";
		outLenB = outLenA;

		for (relPos = 0, nulls = 0, zeros = 0; outLenB; outLenB--) {
			tempChar = *tempBuf++;


			if (tempChar == 0)
				nulls++;
			
			if (tempChar == '0')
				zeros++;
			
			ss << ' ' << std::setw(2) << std::hex << (uint16_t)tempChar;

			if (!isprint(tempChar))
				tempChar = '.';
			
			if (!(++relPos & 3))
				ss << ' ';

			printable += tempChar;	
		}

		while (ss.str().size() < 65)
			ss << ' ';
		
		if (nulls != 16 && zeros != 16) {
			ss << std::setfill(' ') << printable << std::setw(20 - printable.size()) << "]\n";
			std::cout << ss.str();
			isEmpty = false;
		}
		else if (!isEmpty) {
			std::cout << "{ !NULBLK! }                                                      [                ]\n";
			isEmpty = true;
		}
		
		ss.str("");
		
		buffer.data += outLenA;
		buffer.size -= outLenA;	
	}
}
