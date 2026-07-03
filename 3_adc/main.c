/*
	29 Jun 2026
	Sudah bisa compile
	tapi tetap belum bsa blink saat diflash

	30 Jun 2026
	sudah bisa di flash & blinking
	tapi /dev/ttyACM0 belum terdeteksi di linux
	
	OK, ini sudah bisa dideteksi ttyACM0 
	dan serial sudah bisa dicek outputnya
	di Gtkterm
	
	contoh untuk ADC
	Makefile lebih rapi
	disambly sudah benar
	
*/


#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

// Pico 2 uses the same LED pin (25) as Pico
#define LED_PIN 25

#define TUP_DCD_ENDPOINT_MAX	16

void blink_cepat()
{
	static int set;
	
	if (set)
	{
		gpio_put(LED_PIN, 1);	
		set = 0;
	}
	else
	{
		gpio_put(LED_PIN, 0);	
		set = 1;
	}
}

void cek_adc()
{
	// 12-bit conversion, assume max value == ADC_VREF == 3.3 V
   const float conversion_factor = 3.3f / (1 << 12);
   uint16_t result = adc_read();
   printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);
   
   float ff = 0.12345;
   printf("faktor %f\n", ff);
}

int main() {
    // Initialize stdio
    stdio_init_all();
    
    // Initialize LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    adc_init();
    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);
    
    printf("Blink example started on Pico 2!\n");
    int c = 0;
    
    while (true) {
    	c++;
        gpio_put(LED_PIN, 1);
        printf("LED ON %d\n", c);
        sleep_ms(100);
        
        gpio_put(LED_PIN, 0);
        printf("LED OFF\n");
        cek_adc();
        sleep_ms(500);
    }
    
    return 0;
}
