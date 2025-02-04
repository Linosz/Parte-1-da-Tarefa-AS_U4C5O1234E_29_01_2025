#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

#define LED_RED 11
#define LED_GREEN 13
#define LED_BLUE 12 // Azul, mas será usado para ajustar a cor amarela

volatile int state = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    if (state == 0) { // Vermelho
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
    } else if (state == 1) { // Amarelo (vermelho + verde)
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 0);
    } else { // Verde
        gpio_put(LED_RED, 0);
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 0);
    }
    
    state = (state + 1) % 3; // Alterna entre os estados do semáforo
    return true;
}

int main() {
    stdio_init_all();
    
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (1) {
        printf("Semáforo operando normalmente...\n");
        sleep_ms(1000);
    }
}
