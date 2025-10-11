1.  FreeRTOS is a form of [co-operative
    multitasking](https://en.wikipedia.org/wiki/Cooperative_multitasking).
    Basically the microprocessor (STM32) will switch between the tasks
    as each one finishes its processing

2.  Follow steps 1-6 of the LED Blink tutorial to set up a new CubeMX
    project

3.  Now enable UART (same as last tutorial) but with a baud rate of
    115200 Bits/s

    - No need to enable the global interrupt for this tutorial

4.  Now, scroll down to the "Middleware and Software Packs" drop down
    menu and click on "FreeRTOS"

    - Select "CMSIS_V2" on the "Interface" drop down menu
<br><br>
![1](../../Media/FreeRTOS%201.png)

5.  Go to the "Tasks and Queues" tab and click the "Add" button

    - Here is where we will make two FreeRTOS tasks to add (append),
        and remove from a queue

6.  Here are the settings you need to change for the first task:

    - Call the first task "queueAppendTask"

    - Set it’s priority to "osPriorityLow"

    - Leave Stack Size (Words) as 128

    - Change the name of the entry function to "StartQueueAppendTask"

    - Leave Code Generation Option as "Default"

    - Leave Parameter as "NULL"

    - Leave Allocation as "Dynamic"

7.  Now, create another task according to these settings:

    - Call the first task "queueRemoveTask"

    - Set it’s priority to "osPriorityLow"

    - Leave Stack Size (Words) as 128

    - Change the name of the entry function to "StartQueueRemoveTask"

    - Leave Code Generation Option as "Default"

    - Leave Parameter as "NULL"

    - Leave Allocation as "Dynamic"

8.  Next, we want to make the queue that these two tasks will use to
    send and receive messages

9.  Click "Add" under the Queues section

10. Here are the queue settings:

    - Call the queue "coolQueue"

    - Set the queue size to 8

    - Set the item size to "uint16_t"

    - Set the allocation to "Dynamic"

11. Now, go to the "Project manager" tab and call the project
    "HAL_FreeRTOS_Tutorial", set the project file location and set the
    Toolchain/IDE to STM32CubeIDE

12. Click generate code

13. The functions you will need to use in this tutorial come from the
    CMSIS-RTOS2 (CMSIS_V2) version of FreeRTOS

    - You can find these functions in the "Middlewares" folder of our
        project. CubeMX automatically generated these files when we
        enabled the CMSIS_V2 FreeRTOS functionality

14. Here’s a hyperlink to some documentation on these functions:
    [CMSIS_V2 FreeRTOS Queue
    Functions](https://www.keil.com/pack/doc/CMSIS_Dev/RTOS2/html/group__CMSIS__RTOS__Message.html)

15. In main.c, we want to add (append) data to the queue using the
    `StartQueueAppendTask()` and remove data from the queue using
    `StartQueueRemoveTask()`.

16. Use the following code inside `StartQueueAppendTask()`. We want to
    increment dataSend inside the infinite loop and append it to the
    queue

    ```C
    uint16_t dataSend = 0;
    const uint16_t MAX = 100;
    ```

17. Once the count reaches a max of 100 we want to reset the data sent
    value to 0.

18. Use the following code inside `StartQueueRemoveTask()`:

    ```C
    uint16_t dataReceived = 0;
    char new_char[5];
    ```

19. In `StartQueueRemoveTask()`, you want to remove the data from the
    queue and transmit the data you get to your COM port so PuTTY can
    view it. `Use the HAL_UART_Transmit()` function to transmit the
    message!

    - Hint: You’ll need to use the following code to convert the data
        to the correct type to transmit via UART!

        ```C
        snprintf(new_char,"%d\r\n",dataReceived);
        ```

20. At the end of the FreeRTOS tasks, `StartQueueAppendTask()` and
    `StartQueueRemoveTask()` you’ll need to use `osDelay()` to guarantee the
    function has enough time to fully execute its processing

    - Pass the function the following code as its parameter converting
        the number you enter in milliseconds to the equivalent number of
        ticks:

        ```C
        pdMS_TO_TICKS(100)
        ```

21. Once you run PuTTY with the correct baud rate, you’ll know if your
    code works if you get the output that counts to 99 then resets to 0
    and continues counting!
