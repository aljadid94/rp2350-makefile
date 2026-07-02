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
	
*/


#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "hardware/gpio.h"

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

int main() {
    // Initialize stdio
    stdio_init_all();
    
    // Initialize LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    printf("Blink example started on Pico 2!\n");
    int c = 0;
    
    while (true) {
    	c++;
        gpio_put(LED_PIN, 1);
        printf("LED ON %d\n", c);
        sleep_ms(100);
        
        gpio_put(LED_PIN, 0);
        printf("LED OFF\n");
        sleep_ms(500);
    }
    
    return 0;
}
