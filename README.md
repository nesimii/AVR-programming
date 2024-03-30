### AVR Programming

------------


######   the tools needed to use it;
- Circuit Simulation Tool -> SimulIDE Circuit Simulator : V1.1.0 [download link](https://simulide.com/p/downloads/ "download link")
- AVR IDE -> Microchip Studio for AVR V7.0 [download link](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio "download link")
- avrdude V5.11: It is required to upload to the physical card, if you are going to use the simulation tool, you do not need to install it. [download link](http://download.savannah.gnu.org/releases/avrdude/avrdude-5.11-Patch7610-win32.zip "download link")

- **If you want to use it on a physical board**, add the following code to use it on avr ide;

	you need to find the **port number** through device manager !!!
1. Open Microchip Studio -> Tools -> External Tools then click add;
- Title: you can write the name of the card, used to select it in the menu
- Command: "C:\avrdude\avrdude.exe"
- Arguments: 
> -C "C:\avrdude\avrdude.conf" -p atmega328p -c arduino -P COM3 -b 115200 -U flash:w:"$(ProjectDir)Debug\$(ItemFileName).hex":i 

------------

###### Use of:
When you open sim1 extension files with SimulIDE, you will see the sample circuit. Right click on the Arduino Uno board and select load firmware; GccApplication1\GccApplication1\Debug
Select the file with '.hex' extension.