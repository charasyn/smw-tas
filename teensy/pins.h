// status LED on D6 (built-in LED)
#define led_reg D
#define led_bit 6

// SNES data on C7 
#define data_reg F
#define data_bit 5

// SNES clock on D1
#define clk_reg D
#define clk_bit 1

// SNES latch on D0
#define latch_reg D
#define latch_bit 0

#define latch_EICRA_val 0x02
#define latch_EIMSK_val _BV(INT0)
#define latch_ISR_vect  INT0_vect
