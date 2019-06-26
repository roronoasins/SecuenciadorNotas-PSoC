/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef CYAPICALLBACKS_H
#define CYAPICALLBACKS_H
    
    /*Define your macro callbacks here */
    /*For more information, refer to the Writing Code topic in the PSoC Creator Help.*/

    #define isr_timer_INTERRUPT_INTERRUPT_CALLBACK
        void isr_timer_Interrupt_InterruptCallback(void);
    #define isr_rx_INTERRUPT_INTERRUPT_CALLBACK
        void isr_rx_Interrupt_InterruptCallback(void);
    
#endif /* CYAPICALLBACKS_H */   
/* [] */
