


#include "STP16CP26.h"




STP16CP26::STP16CP26(const int OE, const int chipSelectPin):_OE(OE),_cs(chipSelectPin){

}


void STP16CP26::init(uint16_t initLEDState){
	ledState = initLEDState;
	setState(ledState);


}

void STP16CP26::setState(uint16_t state){
	this->ledState = state;

	SPI.beginTransaction(SPISettings(14000000,MSBFIRST,SPI_MODE0));

	digitalWrite(_OE,HIGH);
	digitalWrite(_cs,LOW);
	SPI.transfer16(state);
	digitalWrite(_cs,HIGH);
	SPI.endTransaction();
	delay(10);
	digitalWrite(_cs,LOW);

	digitalWrite(_OE,LOW);
}

void STP16CP26::on(uint8_t pin){
	uint16_t pinMask = 0;
	pinMask = pinMask + (1 << pin);
	uint16_t newState = (pinMask | this->ledState);
	setState(newState);
}

void STP16CP26::off(uint8_t pin){
	uint16_t pinMask = 0;
	pinMask = pinMask + (1 << pin);
	pinMask = ~pinMask;
	uint16_t newState = (pinMask & this->ledState);
	setState(newState);
}
