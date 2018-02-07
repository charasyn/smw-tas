#include <stdint.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "defines.h"
#include "pins.h"

#define MAX_BYTES 2

static const uint16_t data[] PROGMEM = {
    #include "../buttons-tas.txt"
    #include "../buttons-first.txt"
    #include "../buttons-second.txt"
};
#define data_size ((sizeof(data)/sizeof(data[0])))

static const uint16_t data_del[] PROGMEM = {
    #include "../buttons-delete-saves.txt"
};
#define data_del_size ((sizeof(data_del)/sizeof(data_del[0])))

static uint8_t buffer[MAX_BYTES];
static volatile uint8_t waiting_for_int;

int main(void){
    uint16_t offset;

    // set for 16 MHz clock
    // idk if this is necessary but i'm keeping it here anyways
    // this is the only piece of PJRC code still in this file
    // expanded the macro because why not
    CLKPR = 0x80; CLKPR = 0;

	DDR(data_reg)  |=  PBV(data_reg,data_bit);   // data out
	DDR(led_reg)   |=  PBV(led_reg,led_bit);     // led out
	DDR(clk_reg)   &= ~PBV(clk_reg,clk_bit);     // clk in
	DDR(latch_reg) &= ~PBV(latch_reg,latch_bit); // latch in

    led_low;

    _delay_ms(500);

    //led_high;

	cli();
	EIFR  = 0xff;            // clear interrupt flags (for good luck)
	EICRA = latch_EICRA_val; // interrupt on falling edge of INT0
	EIMSK = latch_EIMSK_val; // enable only INT0 (D0 on ATmega32u4)
    sei();

    // delete saves
    for(offset = 0; offset < data_del_size; offset++){
        uint16_t tmp = pgm_read_word(data_del + offset);
        buffer[0] = tmp & 0xff;
        buffer[1] = tmp >> 8;
        waiting_for_int = 1;
        if(offset & 0xf)
            led_low;
        else
            led_high;
        for(; waiting_for_int;) { _delay_us(1); }
    }

    // wait 5 ticks
    for(offset = 0; offset < 5; offset++){
        led_high;
        _delay_ms(800);
        led_low;
        _delay_ms(200);
    }

    // run main payload
    for(offset = 0; offset < data_size; offset++){
        uint16_t tmp = pgm_read_word(data + offset);
        buffer[0] = tmp & 0xff;
        buffer[1] = tmp >> 8;
        waiting_for_int = 1;
        if(offset & 0xf)
            led_low;
        else
            led_high;
        for(; waiting_for_int;) { _delay_us(1); }
    }
    for(;;){
        led_high;
        _delay_ms(200);
        led_low;
        _delay_ms(800);
    }
}

static inline uint8_t wait_clock(void){
	static uint8_t c8;
	c8=0;
	for(;(clk)&&(c8<16);c8++){
		_delay_us(0.5); // we delay by a short amount of time to avoid
		                //   missing the edge of the clock cycle
		                // the time could be shorter but, no need :)
	}
	if(clk)
		return 1;
	c8=0;
	for(;(!clk)&&(c8<16);c8++){
		_delay_us(0.5);
	}
	if(!clk)
		return 1;
	return 0;
}

ISR(latch_ISR_vect)
{
	// do these have to be static? probably not
	static uint8_t bits, bytes, tmp;
	
	// this interrupt only triggers on the falling edge of latch
	//   so we don't have to check the latch pin or anything
	
	bits=0;
	bytes=0;

    tmp=buffer[0];
    while(bytes<MAX_BYTES){
        if(tmp&0x01) {
            data_low;
        }
        else {
            data_high;
        }
        tmp>>=1;
        bits++;
        if(bits==8){
            bits=0;
            bytes++;
            tmp=buffer[bytes];
        }
        if(wait_clock())
            return;
    }
	data_low;
    waiting_for_int = 0;
}