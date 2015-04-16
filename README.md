# Ping)))

Playing with the Parallax Ping Board (Ultrasonic Sensor).

Need:

* Device: PIC16F1709 (or other PIC16F1 in 20-pin DIP)
* Board: PICDEM(tm) Low Pin Count + mikroBUS connector = [Simplicity](https://github.com/luciodj/Simplicity) 
* Debugger: PICkit(tm) 3

## The Basic Idea
1. Add a [MikroBUS](http://www.mikroe.com/mikrobus/) connector to the LPC board 
2. Connect a [Ping))) Board](https://www.parallax.com/product/28015) to the expansion board (bottom three pins: GND, VDD, RC2)
3. Launch MPLAB X and MPLAB Code Configurator to quickly initialise all the peripherals
4. Play ...


## Limitations
* Using only the 4 LEDs on the Simplicity(LPC) board is severely limiting what can be shown. Especially because LED2 is not available (used by the Ping). 
* Perhaps a better demo could use the 8x8 LED Click board? 
* Or one of the OLED Click boards?

## Related Projects and Demos

* Check the [Simplicity](https://github.com/luciodj/Simplicity) project for more demo like this using the MPLAB Code Configurator and the MikroElektronika Click(tm) boards.
