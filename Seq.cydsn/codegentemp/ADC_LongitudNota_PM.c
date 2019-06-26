/*******************************************************************************
* File Name: ADC_LongitudNota_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_LongitudNota.h"


/***************************************
* Local data allocation
***************************************/

static ADC_LongitudNota_BACKUP_STRUCT  ADC_LongitudNota_backup =
{
    ADC_LongitudNota_DISABLED
};


/*******************************************************************************
* Function Name: ADC_LongitudNota_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_LongitudNota_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_LongitudNota_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_LongitudNota_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_LongitudNota_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_LongitudNota_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_LongitudNota_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_LongitudNota_Sleep(void)
{
    if((ADC_LongitudNota_PWRMGR_SAR_REG  & ADC_LongitudNota_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_LongitudNota_SAR_CSR0_REG & ADC_LongitudNota_SAR_SOF_START_CONV) != 0u)
        {
            ADC_LongitudNota_backup.enableState = ADC_LongitudNota_ENABLED | ADC_LongitudNota_STARTED;
        }
        else
        {
            ADC_LongitudNota_backup.enableState = ADC_LongitudNota_ENABLED;
        }
        ADC_LongitudNota_Stop();
    }
    else
    {
        ADC_LongitudNota_backup.enableState = ADC_LongitudNota_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_LongitudNota_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_LongitudNota_Sleep() was called. If the component was enabled before the
*  ADC_LongitudNota_Sleep() function was called, the
*  ADC_LongitudNota_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_LongitudNota_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_LongitudNota_Wakeup(void)
{
    if(ADC_LongitudNota_backup.enableState != ADC_LongitudNota_DISABLED)
    {
        ADC_LongitudNota_Enable();
        #if(ADC_LongitudNota_DEFAULT_CONV_MODE != ADC_LongitudNota__HARDWARE_TRIGGER)
            if((ADC_LongitudNota_backup.enableState & ADC_LongitudNota_STARTED) != 0u)
            {
                ADC_LongitudNota_StartConvert();
            }
        #endif /* End ADC_LongitudNota_DEFAULT_CONV_MODE != ADC_LongitudNota__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
