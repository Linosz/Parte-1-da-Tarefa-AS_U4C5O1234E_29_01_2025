# Projeto de Semáforo com Raspberry Pi Pico

Este projeto utiliza a função `add_repeating_timer_ms()` da ferramenta Pico SDK para projetar um semáforo com temporização de 3 segundos para cada alteração de sinal.

## Atividade 1: Temporizador Periódico

### Componentes

- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330 Ω
- Protoboard e cabos jumper

### Conexões

- LED Vermelho: GPIO 11
- LED Amarelo: GPIO 12 (Azul, mas será usado para ajustar a cor amarela)
- LED Verde: GPIO 13

### Instruções

1. Conecte o Raspberry Pi Pico ao seu computador.
2. Monte o circuito conforme a configuração sugerida.
3. Utilize os seguintes GPIOs para os LEDs:
   - LED Vermelho: GPIO 11
   - LED Amarelo: GPIO 12 (Azul, mas será usado para ajustar a cor amarela)
   - LED Verde: GPIO 13

### Funcionamento do Código

O código controla a cor dos LEDs em um semáforo, alternando entre vermelho, amarelo e verde a cada 3 segundos.

1. O acionamento dos LEDs (sinais do semáforo) inicia na cor vermelha, alterando para amarela (vermelho + verde) e, em seguida, verde.
2. O temporizador é ajustado para um atraso de 3 segundos (3.000ms).
3. A mudança de estado dos LEDs é implementada na função de call-back do temporizador, `repeating_timer_callback()`.
4. A rotina principal, presente no interior da estrutura de repetição `while`, imprime a mensagem "Semáforo operando normalmente..." a cada segundo (1.000 ms) via porta serial.

### Código

O código fonte para o projeto é o seguinte:


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
