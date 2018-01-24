// Useful defines
#ifndef _BV
#define _BV(n) (1<<(n))
#endif

#define EXPAND(...) __VA_ARGS__
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define PBV(r,b) _BV(CAT(P,CAT(EXPAND(r),EXPAND(b))))
#define PORT(r)  CAT(PORT,EXPAND(r))
#define PIN(r)   CAT(PIN,EXPAND(r))
#define DDR(r)   CAT(DDR,EXPAND(r))

#define data_low   (PORT(data_reg) &= ~PBV(data_reg,data_bit))
#define data_high  (PORT(data_reg) |=  PBV(data_reg,data_bit))

#define led_toggle (PORT(led_reg) ^=  PBV(led_reg,led_bit))
#define led_high   (PORT(led_reg) |=  PBV(led_reg,led_bit))
#define led_low    (PORT(led_reg) &= ~PBV(led_reg,led_bit))

#define clk   (PIN(clk_reg) & PBV(clk_reg,clk_bit))
#define latch (PIN(latch_reg) & PBV(latch_reg,latch_bit))
