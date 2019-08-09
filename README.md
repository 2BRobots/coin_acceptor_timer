# Coin Acceptor Timer module for Vending Machines

The timer must be powered with regulated 12 VDC. When there is electric power, the POWER LED will remain lit as the power present indicator and the STAT LED will light momentarily once. Whenever the timer is enabled, the RELAY LED will illuminate while the timer remains active. When a pulse is received from the coin acceptor, the STAT LED will flash rapidly for each pulse received (credit), the pulses are always counted regardless of the timer is active or not.

The pulse input from the coin acceptor in the timer is open collector type. Which means that the coin acceptor must send a low logic signal (GND) every time it sends a credit and in standby state it must be floating (no voltage). The pulses must have a minimum width of 10 ms and a separation of 5 ms between pulses.

The timer is programmed to disable the relay between each transaction, if you need it to be constantly enabled while it has enough credits please contact us for customization.

How to modify the settings:

1. To change the number of pulses (credits) with which the timer is activated press the UP and DOWN buttons. With UP it increases and with DOWN it decreases, each time the setting is changed the STAT LED will flash rapidly. When the upper or lower limit is reached, the STAT LED flash slowly.

2. To change the time (seconds) that the timer is enabled, the procedure is the same as the previous one, exept you must keep the TIME / RESET button pressed while pressing UP and DOWN.

3. To reset the timer to factory settings, press and hold the TIME / RESET button when the timer is turned on. The STAT LED will flash rapidly 2 times indicating that the restart was successful. Default values are 1 credit for 5 seconds.

Note: the maximum value for both cases (time and credits) is 100 and the minimum is 1.
The timer does not lose its settings when it is turned on and off.

You can purchase this module on Tindie: https://www.tindie.com/products/Danny024/timer-module-for-vending-machine/
