<div class="enumerate">

We will need to install [PuTTY](https://www.putty.org/) for this
tutorial. For our purposes, PuTTY monitors a specific COM port for
serial communication and displays the data to the user through the PuTTY
terminal.

1.  We’ll configure the PuTTY settings later on in this tutorial

Follow steps 1 → 6 of the LED Blink tutorial to set up a new CubeMX
project. You should end up on the "Pinout & Configuration" section again

For this tutorial we want to enable USART2 on the board.

1.  USART stands for Universal Synchronous Asynchronous Receiver
    Transmitter. It is sometimes called the Serial Communications
    Interface or SCI. For our purposes we use USART to send messages to
    the COM port on our laptop through the cable connecting the STM32
    Nucleo board to your laptop

To enable USART, go to the "Connectivity" drop down menu on the left
hand side of CubeMX

<div class="center">

![image](HAL USART Tutorial 1.png)

</div>

Click on USART2 and change the mode from "Disable" to "Synchronous"  
<img src="HAL USART Tutorial 2.png" alt="image" />

Now look at the "Configuration" section that just opened in CubeMX and
open the "Parameter Settings" tab

1.  For this tutorial we will use a Baud rate of 115200 Bits/s

2.  Later on, we will tell PuTTY to monitor our laptop’s COM port at the
    same baud rate. This is important because if PuTTY and our program
    have a baud rate mismatch, then the PuTTY terminal will just display
    "garbage" (not human readable data) to the PuTTY terminal

Now follow steps 7 → 13 of the LED Blink tutorial, but name the project
"HAL_USART", and save the project in the same "UMSAE" root folder as
last time

Once the project is open, find USART.h and main.c in the project
directory

We will need to use husart2 from USART.h. This was generated when we
enabled USART2 in the connectivity tab in CubeMX

Next, open main.c and scroll down to the infinite while loop

1.  For this tutorial, we will be using the HAL_USART_Transmit() and
    HAL_Delay() functions

2.  Using ctrl + click, click on the HAL_USART_Transmit() function and
    read what parameters the function takes. I want you to try to
    understand this independently, but feel free to ask the SSO or team
    leads a question! It will definitely benefit your learning if you
    try to understand the function first though.

3.  Here’s the code I would like you to use for the parameters! Place
    the variables in the function parameters, followed by HAL_Delay()
    with a delay value of 1000.

    ```
    uint8_t message[] = "Welcome to UMSAE Software!\r\n";
    uint16_t size = sizeof(message);
    uint32_t timeOut = 10;
    ```

Once you’ve set up the parameters correctly, open PuTTY on your
computer! You should see a window that looks similar to this:

<div class="center">

![image](HAL USART Tutorial 4.png)

</div>

We need to change the Serial line and Speed settings. These are the COM
port on your computer and PuTTY’s baud rate.

1.  Open "Device Manager" on your computer and go to the "Ports (COM &
    LPT)" drop down menu. Here you’ll see which COM port your NUCLEO is
    connected to on your computer.

2.  Change the "Serial line" setting to match your COM port and change
    the "Speed" to 115200 to match our USART baud rate

Click "open" to open the PuTTY terminal

Run the program the same way we did in the Blink LED tutorial. You
should see a message in the terminal!

</div>
