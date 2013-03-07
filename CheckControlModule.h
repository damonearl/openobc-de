/*
    Copyright (c) 2012 <benemorius@gmail.com>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CHECKCONTROLMODULE_H
#define CHECKCONTROLMODULE_H
#include <stdint.h>
#include "Input.h"
#include "IO.h"

/* thanks veskobx
bit 7 L 1 Brake Light Fail
bit 6 L 1 Brake Light Fail
bit 5 H Tail Light Failure
bit 4 H Lic Plate Light Fail
bit 3 H Low Beam
bit 2 L Coolant level
bit 1 L Washer Fluid
bit 0 H Pulldown
*/

class CheckControlModule
{

public:
    CheckControlModule(Input& data, IO& clock, IO& latch);

	 void task();

	 uint8_t getRawByte() {return rawByte;}

private:
	void updateStatus();
	
	Input& data;
	IO& clock;
	IO& latch;
	uint8_t rawByte;
};

#endif // CHECKCONTROLMODULE_H
