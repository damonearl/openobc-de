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

#ifndef FUELLEVEL_H
#define FUELLEVEL_H

#include "Input.h"
#include "InterruptManager.h"
#include "Timer.h"

class FuelLevel
{
public:
	FuelLevel(Input& dataPin, InterruptManager& interruptManager);
	~FuelLevel();
	
	uint16_t getDeciLitres() {return decilitres;}
	float getLitres() {return (float)decilitres / 10;}
	float getGallons() {return getLitres() / 3.78541f;}

private:
	void interruptHandler();
	
	Input& dataPin;
	InterruptManager& interruptManager;
	Timer timeout;
	Timer periodTimer;
	uint16_t decilitres;
};

#endif // FUELLEVEL_H
