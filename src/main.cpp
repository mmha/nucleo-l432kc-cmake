#include "RTC.h"
#include <mbed.h>

[[noreturn]] auto main() -> int
{
	Serial pc{USBTX, USBRX};	// 9600B 8N1
	DigitalOut led{LED1};

	while(1)
	{
		const auto t = sys::RTCClock::now();

		led = 1;
		wait(0.5);
		led = 0;
		wait(0.5);

		pc.printf("Hello world from Nucleo! It is %d\r\n", t.time_since_epoch());
	}
}
