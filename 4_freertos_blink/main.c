/*
	1 Juli 2026
	FreeRTOS with Makefile
	
	simple blink & adc, with customize core 
	
	ini juga sudah bisa jalan
	contoh sederhana blink & baca adc
*/


#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

#define LED_PIN 25

void task_blink1( void * parameters )
{
	( void ) parameters;
	
	while(1)
	{
		vTaskDelay(200);
		gpio_put(LED_PIN, 1);	
		vTaskDelay(200);
		gpio_put(LED_PIN, 0);	
		printf("Blink: core %d\n", portGET_CORE_ID());
	}
}

void task_adc( void * parameters )
{
	( void ) parameters;
	
	while(1)
	{
		vTaskDelay(155);
		gpio_put(LED_PIN, 1);	
		cek_adc();
		
		vTaskDelay(155);
		gpio_put(LED_PIN, 0);	
	}
}

int main(void)
{
	 TaskHandle_t handle_blink;
	 TaskHandle_t handle_adc;
	 
	 stdio_init_all();
	 
	 gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
	 
	 adc_init();
    adc_gpio_init(26);
    adc_select_input(0); // Select ADC input 0 (GPIO26)
	 
	 xTaskCreate(
    task_blink1
    ,  "Blink"   // A name just for humans
    ,  256  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  &handle_blink );
    
    vTaskCoreAffinitySet(handle_blink, 1 << 1);	// core 1
    
    xTaskCreate(
    task_adc
    ,  "ADC"   // A name just for humans
    ,  512  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  &handle_adc );
    
    vTaskCoreAffinitySet(handle_adc, 1 << 0);	// core 0
    
     vTaskStartScheduler();
}

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
   printf("  Raw value: 0x%03x, voltage: %f V", result, result * conversion_factor);
   printf(", core %d\n", portGET_CORE_ID());
}

