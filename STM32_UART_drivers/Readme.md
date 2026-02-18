This project illustrate the Concept of Universal Asychronous Receiver Transmitter Receiver using the Polling method to transfer data from the STM2 to the Pc via a USB
I connected an LED and send message via UART the state of the LED over PUTTY
Features
	- UART2 initialization
	- Transmit single character
	- Transmit string
	- Polling-based transmission
	- Direct register-level programming
 Hardware Used
	- STM32 (Specify your exact MCU, e.g., STM32F401RE)
	- USB to Serial (via ST-Link VCP)
	- PuTTY serial terminal
	
 UART Configuration
	- Peripheral: USART2
	- TX Pin: PA2
	- Baud Rate: 115200
	- Data Bits: 8
	- Stop Bits: 1
	- Parity: None
HOW IT WORKS?
The USART uses TXE [Transmitter Data Empty Register]  flag.Once it is set then the data is send using  USART->SR.The STM32 and PC needs to have same Baud rate that is 115200 that is the speed at which the data is send from one to another. 


Learning Outcome
This project demonstrates:
	- Peripheral register configuration
	- Embedded driver abstraction
	- Polling vs interrupt concept
	- Modular firmware structure
