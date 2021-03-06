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

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include "InterruptManager.h"

#define TIMER_PERIPHERAL (LPC_TIM0)
#define TIMER_INTERRUPT (TIMER0_IRQn)
#define TIMER_MANAGED_INTERRUPT (IRQ_TIMER0)

class Timer
{
public:
	Timer();
	Timer(InterruptManager& interruptManager);
	~Timer();
	void start();
	uint32_t read();
	uint32_t read_ms();
	uint32_t read_us();
	void overflowHandler();

private:
	static bool timerInitialized;
	uint32_t startCount;
	uint32_t overflows;
	InterruptManager* interruptManager;
};

#endif // TIMER_H
