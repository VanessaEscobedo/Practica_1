#include <stdint.h>
#include "inc/tm4c123gh6pm.h" // ../../../inc/tm4c123gh6pm.h

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************

volatile int32_t a; //variable, se puede cambiar el valor en tiempo real

int main(void)
{
    volatile uint32_t ui32Loop;
    a = 66667; //cambia la velocidad del parpadeo
    //para el tiempo de una cuenta se pone a=1 
    //(el tiempo que se obtuvo, segun los cursores, fue 1.5 us para una cuenta)

    //para los 100 ms, se obtuvo a=66667 (usando una regla de 3)
    //los 100 ms son para todo el ciclo 

    //para la medicion se utiliza el pin PF3 y tierra

    //con el pin F3, se prendió un LED externo a la misma velocidad de 100 ms

    // Enable the GPIO port that is used for the on-board LED.
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOB;
    //para la cascada de LEDS, se hizo el cambio de puerto del F al B

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    ui32Loop = SYSCTL_RCGC2_R;

    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIO_PORTB_DIR_R = 0x02;
    GPIO_PORTB_DEN_R = 0x02;
    //para cambiar el color se cambia el registro
    //azul->PF2 (0x04)
    //rojo->PF1 (0x02)
    //verde->PF3 (0x08)

    // Loop forever.
    while(1)
    {
        //enciende el LED
        GPIO_PORTB_DATA_R |= 0x02; 

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < a; ui32Loop++) //evalua esas operaciones, tiempo de espera
        {
        }

        //apaga el LED
        GPIO_PORTB_DATA_R &= ~(0x02);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < a; ui32Loop++)
        {
        }
    }
}
