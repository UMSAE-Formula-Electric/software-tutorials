1.  Follow steps 2 → 6 of the HAL USART tutorial to set up a new CubeMX
    project. This time we are going to enable UART

    1.  To do this, set the mode from "Synchronous" to "Asynchronous"

    2.  Set the baud rate to 9600 Bits/s

2.  Go to the "NVIC Settings" tab and enable "USART2 global interrupt"

3.  Go to the "Project Manger" tab and name the project
    "HAL_UART_IRQ_Tutorial" and set the your project location and
    Toolchain/IDE to STM32CubeIDE

4.  First you’ll need to write the function HAL_UART_Receive_IT()

    1.  Use some of the following parameters when "enabling" this
        function

    2.  Write the function in the "USER CODE BEGIN 2" comment block of
        the code

    ```
    uint8_t msg[] = "Welcome to Software!!!\r\n"; // Data to be sent
    uint16_t msg_size = sizeof(msg); // Length of the msg

    uint8_t recvd_data; // Receive buffer
    uint16_t recvd_data_size = 1; // Size of the character 't'
    ```

5.  You’ll need to call the function HAL_UART_RxCpltCallback() to
    receive a user interrupt using PuTTY

6.  Finally we want the LED to blink whenever the character ’t’ is
    received and transmit the message assigned to the user_data pointer
    by using HAL_UART_Transmit()!

7.  You’ll know if your code works when the LED toggles on when you
    press ’t’ and off when you press ’t’ again with the PuTTY terminal
    open. Every time you press ’t’ you should also see the message
    "Welcome to Software!!!"!
