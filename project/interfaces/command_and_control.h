#ifndef __COMMAND_CONTROL__
#define __COMMAND_CONTROL__ value

typedef void(*functionPointerType)(void);
struct commandStruct {
    char const *name;
    functionPointerType execute;
    char const *help;
};
const struct commandStruct commands[] ={
    {"ver", &CmdVersion,
        "Display firmware version"},
    {"flashTest", &CmdFlashTest,
        "Runs the flash unit test, printis number of errors upon completion"},
    {"blinkLed", &CmdBlinkLed,
        "Sets the LED to blink at a desired rate (parameter: frequency (Hz))"},
    {"",0,""} //End of table indicator. MUST BE LAST!!!
}; 
#endif /* ifndef __COMMAND_CONTROL__ */
