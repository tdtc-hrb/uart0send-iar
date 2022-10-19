This project built using IAR V6.40.5.

Download: http://files.iar.com/ftp/pub/box/CD-EWARM-6405-4275.zip

========================================================================
About the PC serial port debug tool

See: https://tdtc-hrb.github.io/csdn/post/vc-serial_communication/

========================================================================
About jumpers

Control LED lights used can be done in two ways:
1. that a macro definition
    In front of the power on,
    Make sure P2.8 no other devices in use, and the LED connected.

2. the array definition
    In front of the power on,
    Make sure P2.0~P2.7 no other devices in use, and the LED connected.

========================================================================
About the project folder

CMSIS: Cortex Microcontroller Software Interface Standard
UART: Universal Asynchronous Receiver/Transmitter
Includes: Header files.

========================================================================
About project settings

After you open a project, please check:
1. Library Configure
    Check the "Use CMSIS" option.
2. Preprocessor
    Include the following:
    $PROJ_DIR$\CMSIS
    $PROJ_DIR$\UART
    $PROJ_DIR$\Includes
    $PROJ_DIR$\..\Includes

========================================================================