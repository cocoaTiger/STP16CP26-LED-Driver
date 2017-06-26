#include <Arduino.h>
#include <SPI.h>
class STP16CP26 {
	public:
		STP16CP26(const int OE, const int chipSelectPin);
		const int _OE;
		const int _cs;
		void init(uint16_t initLEDState);
		void on(uint8_t);
		void off(uint8_t);
		void setState(uint16_t);
		uint16_t ledState;
	private:
		uint16_t state;
	
		
	
};