# Projeto LED Control com Raspberry Pi Pico

Este projeto controla a cor de um LED RGB conectado ao Raspberry Pi Pico usando um botão. O LED alterna entre vermelho, amarelo e verde com base no estado atual. O botão inicia a sequência de mudança de cor.

Atividade 1: Configuração e Conexões
Componentes
Raspberry Pi Pico

LED RGB

Resistores (220 ohms)

Botão

Protoboard e cabos jumper

Conexões
LED Vermelho: GPIO 11

LED Verde: GPIO 13

LED Azul: GPIO 12

Botão: GPIO 5

Instruções
Conecte o Raspberry Pi Pico ao seu computador.

Monte o circuito conforme a seção de conexões.

Atividade 2: Funcionamento do Código
Descrição
O código controla a cor do LED RGB e a alterna entre vermelho, amarelo e verde, utilizando um botão para iniciar a sequência de mudança de cor.

Funcionamento
O LED começa desligado.

Quando o botão é pressionado, o LED alterna entre as cores vermelho, amarelo (vermelho + verde) e verde, com um intervalo de 3 segundos entre cada mudança.

Após a sequência, o LED desliga e o botão pode ser pressionado novamente para reiniciar a sequência.

Instruções
Compile e carregue o código no Raspberry Pi Pico.

Pressione o botão para iniciar a sequência de mudança de cor do LED.
