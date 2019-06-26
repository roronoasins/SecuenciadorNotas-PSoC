#include "project.h"

uint8 readed;
uint8 change;
uint8 tenthSecond;
uint8 oneSecond;
uint16 oldPeriod;
static uint8 oneSecondCount = 0U;
char msg[40];
char input;
uint8 selectedNote = 0;
uint8 selectedNoteRange = 2;

const unsigned long frq = 24000000;
const unsigned short sampling = 20;
unsigned long cycle;

//------------------------ NOTES ----------------------
unsigned int n1, n2, n3, n4, n5, n6, n7, n8;
unsigned int l1, l2, l3, l4, l5, l6, l7, l8;
unsigned int d1, d2, d3, d4, d5, d6, d7, d8;

void setNotes() {
    cycle = frq/sampling;
    
    l1 = cycle/220; //A3
    l2 = cycle/246.942; //B3
    l3 = cycle/261.626; //C4
    l4 = cycle/293.665; //D4
    l5 = cycle/329.628; //E4
    l6 = cycle/349.228; //F4
    l7 = cycle/391.995; //G4
    l8 = cycle/440; //A4
    
    d1 = cycle/440; //A4
    d2 = cycle/493.883; //B4
    d3 = cycle/523.251; //C5
    d4 = cycle/587.330; //D5
    d5 = cycle/659.255; //E5
    d6 = cycle/698.456; //F5
    d7 = cycle/783.991; //G5
    d8 = cycle/880; //A5
    
    n1 = cycle/880; //A5
    n2 = cycle/987.76; //B5
    n3 = cycle/1046.5; //C6
    n4 = cycle/1174.66; //D6
    n5 = cycle/1318.5; //E6
    n6 = cycle/1396.9; //F6
    n7 = cycle/1568; //G6
    n8 = cycle/1760; //A6
    
    //n6 = cycle/1975.5; // B6
    //n7 = cycle/2093; // C7
    //n8 = cycle/2394.32; // D7
}
//----------------------------------------------------

void isr_timer_Interrupt_InterruptCallback() {
    tenthSecond = 1U;
    oneSecondCount++;
    if(oneSecondCount > 9U) {
        oneSecondCount = 0U;
        oneSecond = 1U;
    }
    
    if(readed) {
        change = 1U;
        readed = 0U;
    }
}

void printGlobalPeriod(int16 p) {
    sprintf(msg, "Periodo global actual: %i\r\n", p);
    UART_1_PutString(msg);
    sprintf(msg, "");
}

void printFreq(int16 f) {
    sprintf(msg, "Frecuencia actual de la nota %i: %i\r\n", selectedNote, f);
    UART_1_PutString(msg);
    sprintf(msg, "");
}

void printUpdateData() {
    UART_1_PutString("------------------------------------------\r\n");
    sprintf(msg, "Modificando la nota %i:\r\n", selectedNote);
    UART_1_PutString(msg);
    UART_1_PutString("Pulse 1-8 para notas prefijadas,\r\n");
    UART_1_PutString("o +/- para cambiar manualmente la frecuencia.\r\n");
    UART_1_PutString("Pulse L, M o H para cambiar el registro de las notas prefijadas.\r\n");
    sprintf(msg, "");
}

void printWelcome() {
    UART_1_PutString("------------------------------------------\r\n");
    UART_1_PutString("Notes sequencer: \r\n");
    UART_1_PutString("------------------------------------------\r\n");
    UART_1_PutString("Press 1, 2, 3 or 4 to select the note to configure or r to reset.\r\n");
}

void printRangeOut(uint8 under) {
    UART_1_PutString((under) ? "valor minimo alcanzado.\r\n" : "valor maximo alcanzado.\r\n");
}

void updateClock1(int valAdd, uint8 ow) {
    uint16 oldVal = Clock_1_GetDividerRegister() + 1;
    uint16 oldFreq = cycle / oldVal;
    uint16 newval = (ow) ? valAdd : (Clock_1_GetDividerRegister() + valAdd + 1);
    uint16 freq = cycle / newval;
    if ((oldFreq <= 100) && (newval > oldVal)) {
        printRangeOut(1);
    } else if ((oldFreq >= 18000) && (newval < oldVal)) {
        printRangeOut(0);
    } else {
        while (freq == oldFreq) {
            if (newval < oldVal) {
                newval--;
            } else {
                newval++;
            }
            freq = cycle / newval;
        }
        Clock_1_SetDivider(newval - 1);
        printFreq(freq);
    }
}

void updateClock2(int valAdd, uint8 ow) {
    uint16 oldVal = Clock_2_GetDividerRegister() + 1;
    uint16 oldFreq = cycle / oldVal;
    uint16 newval = (ow) ? valAdd : (Clock_2_GetDividerRegister() + valAdd + 1);
    uint16 freq = cycle / newval;
    if (oldFreq <= 100 && (newval > oldVal)) {
        printRangeOut(1);
    } else if (oldFreq >= 18000 && (newval < oldVal)) {
        printRangeOut(0);
    } else {
        while (freq == oldFreq) {
            if (newval < oldVal) {
                newval--;
            } else {
                newval++;
            }
            freq = cycle / newval;
        }
        Clock_2_SetDivider(newval - 1);
        printFreq(freq);
    }
}

void updateClock3(int valAdd, uint8 ow) {
    uint16 oldVal = Clock_3_GetDividerRegister() + 1;
    uint16 oldFreq = cycle / oldVal;
    uint16 newval = (ow) ? valAdd : (Clock_3_GetDividerRegister() + valAdd + 1);
    uint16 freq = cycle / newval;
    if (oldFreq <= 100 && (newval > oldVal)) {
        printRangeOut(1);
    } else if (oldFreq >= 18000 && (newval < oldVal)) {
        printRangeOut(0);
    } else {
        while (freq == oldFreq) {
            if (newval < oldVal) {
                newval--;
            } else {
                newval++;
            }
            freq = cycle / newval;
        }
        Clock_3_SetDivider(newval - 1);
        printFreq(freq);
    }
}

void updateClock4(int valAdd, uint8 ow) {
    uint16 oldVal = Clock_4_GetDividerRegister() + 1;
    uint16 oldFreq = cycle / oldVal;
    uint16 newval = (ow) ? valAdd : (Clock_4_GetDividerRegister() + valAdd + 1);
    uint16 freq = cycle / newval;
    if (oldFreq <= 100 && (newval > oldVal)) {
        printRangeOut(1);
    } else if (oldFreq >= 18000 && (newval < oldVal)) {
        printRangeOut(0);
    } else {
        while (freq == oldFreq) {
            if (newval < oldVal) {
                newval--;
            } else {
                newval++;
            }
            freq = cycle / newval;
        }
        Clock_4_SetDivider(newval - 1);
        printFreq(freq);
    }
}


void updateClock(int valAdd, uint8 ow) {
    switch(selectedNote)
    {
        case 1:
            updateClock1(valAdd, ow);
            break;
        case 2:
            updateClock2(valAdd, ow);
            break;
        case 3:
            updateClock3(valAdd, ow);
            break;
        case 4:
            updateClock4(valAdd, ow);
            break;
    }
}

void resetAll(void) {
    updateClock1(n1, 1);
    updateClock2(n2, 1);
    updateClock3(n3, 1);
    updateClock4(n1, 1);
    selectedNote = 0;
    UART_1_PutString("------------------------------------------\r\n");
    UART_1_PutString("Sistema reiniciado\r\n");
    UART_1_PutString("------------------------------------------\r\n");
    printWelcome();
}

void isr_rx_Interrupt_InterruptCallback(void) {
    input = UART_1_GetChar();
    if (selectedNote == 0) {
        switch(input)
        {
            case '1':
                selectedNote = 1;
                printUpdateData();
                break;
            case '2':
                selectedNote = 2;
                printUpdateData();
                break;
            case '3':
                selectedNote = 3;
                printUpdateData();
                break;
            case '4':
                selectedNote = 4;
                printUpdateData();
                break;
            case 'r':
            case 'R':
                resetAll();
                break;
            default:
                UART_1_PutString("Not a valid input\r\n");
        }
    } else {
        switch(input)
        {
            case '1':
                updateClock((selectedNoteRange == 0) ? n1 : ((selectedNoteRange == 1) ? d1 : l1), 1);
                break;
            case '2':
                updateClock((selectedNoteRange == 0) ? n2 : ((selectedNoteRange == 1) ? d2 : l2), 1);
                break;
            case '3':
                updateClock((selectedNoteRange == 0) ? n3 : ((selectedNoteRange == 1) ? d3 : l3), 1);
                break;
            case '4':
                updateClock((selectedNoteRange == 0) ? n4 : ((selectedNoteRange == 1) ? d4 : l4), 1);
                break;
            case '5':
                updateClock((selectedNoteRange == 0) ? n5 : ((selectedNoteRange == 1) ? d5 : l5), 1);
                break;
            case '6':
                updateClock((selectedNoteRange == 0) ? n6 : ((selectedNoteRange == 1) ? d6 : l6), 1);
                break;
            case '7':
                updateClock((selectedNoteRange == 0) ? n7 : ((selectedNoteRange == 1) ? d7 : l7), 1);
                break;
            case '8':
                updateClock((selectedNoteRange == 0) ? n8 : ((selectedNoteRange == 1) ? d8 : l8), 1);
                break;
            case '+':
                updateClock(-1, 0);
                break;
            case '-':
                updateClock(1, 0);
                break;
            case 'l':
            case 'L':
                selectedNoteRange = 2;
                UART_1_PutString("Selected note range: LOW\r\n");
                break;
            case 'm':
            case 'M':
                selectedNoteRange = 1;
                UART_1_PutString("Selected note range: MEDIUM\r\n");
                break;
            case 'h':
            case 'H':
                selectedNoteRange = 0;
                UART_1_PutString("Selected note range: HIGH\r\n");
                break;
            case 'q':
            case 'Q':
                printWelcome();
                selectedNote = 0;
                break;
            case 'r':
            case 'R':
                resetAll();
                break;
            default:
                UART_1_PutString("Not a valid input\r\n");
        }
    }
}


void initCP(void)
{
    UART_1_Start();
    /* delay for the UART to initialize */
    CyDelay(1LU); /* msec */
}


void toggleLED(void){
    Pin_Led_Write(Pin_Led_Read() ^ 1U);
}

uint16 LongitudNota(){
    //ADC_LongitudNota_Wakeup();
    ADC_LongitudNota_StartConvert();
    ADC_LongitudNota_IsEndConversion(ADC_LongitudNota_WAIT_FOR_RESULT);
    int Res = ADC_LongitudNota_GetResult16();
    ADC_LongitudNota_StopConvert();
    //ADC_LongitudNota_Sleep();
    
    return Res;
}

int main(void)
{
    setNotes();
    initCP();
    resetAll();
    CyGlobalIntEnable;
    isr_timer_Start();
    Timer1_Start();
    isr_rx_Start();
    isr_rx_SetVector(&(isr_rx_Interrupt));
    
    WaveDAC8_1_Start();
    Opamp_1_Start();
    PWM_1_Start();
    ADC_LongitudNota_Start();
    
    for(;;)
    {
        if(tenthSecond) {
            Timer1_ReadStatusRegister();
            tenthSecond = 0U;
            
            uint16 pe = LongitudNota();
            if ((pe > 10) && (pe < 4000) && 
            ((oldPeriod < pe - 20) || (oldPeriod > pe + 20))) {
                oldPeriod = pe;
                PWM_1_WritePeriod(pe);
                PWM_1_WriteCompare(pe/2);
                //printGlobalPeriod(pe);
            }
            
        }
        if(oneSecond) {
            oneSecond = 0U;
        }
    }
}

/* [] END OF FILE */
