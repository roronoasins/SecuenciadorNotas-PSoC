/*******************************************************************************
* File Name: Entrada_Potenciometro.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Entrada_Potenciometro_H) /* Pins Entrada_Potenciometro_H */
#define CY_PINS_Entrada_Potenciometro_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Entrada_Potenciometro_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Entrada_Potenciometro__PORT == 15 && ((Entrada_Potenciometro__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Entrada_Potenciometro_Write(uint8 value);
void    Entrada_Potenciometro_SetDriveMode(uint8 mode);
uint8   Entrada_Potenciometro_ReadDataReg(void);
uint8   Entrada_Potenciometro_Read(void);
void    Entrada_Potenciometro_SetInterruptMode(uint16 position, uint16 mode);
uint8   Entrada_Potenciometro_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Entrada_Potenciometro_SetDriveMode() function.
     *  @{
     */
        #define Entrada_Potenciometro_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Entrada_Potenciometro_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Entrada_Potenciometro_DM_RES_UP          PIN_DM_RES_UP
        #define Entrada_Potenciometro_DM_RES_DWN         PIN_DM_RES_DWN
        #define Entrada_Potenciometro_DM_OD_LO           PIN_DM_OD_LO
        #define Entrada_Potenciometro_DM_OD_HI           PIN_DM_OD_HI
        #define Entrada_Potenciometro_DM_STRONG          PIN_DM_STRONG
        #define Entrada_Potenciometro_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Entrada_Potenciometro_MASK               Entrada_Potenciometro__MASK
#define Entrada_Potenciometro_SHIFT              Entrada_Potenciometro__SHIFT
#define Entrada_Potenciometro_WIDTH              1u

/* Interrupt constants */
#if defined(Entrada_Potenciometro__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Entrada_Potenciometro_SetInterruptMode() function.
     *  @{
     */
        #define Entrada_Potenciometro_INTR_NONE      (uint16)(0x0000u)
        #define Entrada_Potenciometro_INTR_RISING    (uint16)(0x0001u)
        #define Entrada_Potenciometro_INTR_FALLING   (uint16)(0x0002u)
        #define Entrada_Potenciometro_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Entrada_Potenciometro_INTR_MASK      (0x01u) 
#endif /* (Entrada_Potenciometro__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Entrada_Potenciometro_PS                     (* (reg8 *) Entrada_Potenciometro__PS)
/* Data Register */
#define Entrada_Potenciometro_DR                     (* (reg8 *) Entrada_Potenciometro__DR)
/* Port Number */
#define Entrada_Potenciometro_PRT_NUM                (* (reg8 *) Entrada_Potenciometro__PRT) 
/* Connect to Analog Globals */                                                  
#define Entrada_Potenciometro_AG                     (* (reg8 *) Entrada_Potenciometro__AG)                       
/* Analog MUX bux enable */
#define Entrada_Potenciometro_AMUX                   (* (reg8 *) Entrada_Potenciometro__AMUX) 
/* Bidirectional Enable */                                                        
#define Entrada_Potenciometro_BIE                    (* (reg8 *) Entrada_Potenciometro__BIE)
/* Bit-mask for Aliased Register Access */
#define Entrada_Potenciometro_BIT_MASK               (* (reg8 *) Entrada_Potenciometro__BIT_MASK)
/* Bypass Enable */
#define Entrada_Potenciometro_BYP                    (* (reg8 *) Entrada_Potenciometro__BYP)
/* Port wide control signals */                                                   
#define Entrada_Potenciometro_CTL                    (* (reg8 *) Entrada_Potenciometro__CTL)
/* Drive Modes */
#define Entrada_Potenciometro_DM0                    (* (reg8 *) Entrada_Potenciometro__DM0) 
#define Entrada_Potenciometro_DM1                    (* (reg8 *) Entrada_Potenciometro__DM1)
#define Entrada_Potenciometro_DM2                    (* (reg8 *) Entrada_Potenciometro__DM2) 
/* Input Buffer Disable Override */
#define Entrada_Potenciometro_INP_DIS                (* (reg8 *) Entrada_Potenciometro__INP_DIS)
/* LCD Common or Segment Drive */
#define Entrada_Potenciometro_LCD_COM_SEG            (* (reg8 *) Entrada_Potenciometro__LCD_COM_SEG)
/* Enable Segment LCD */
#define Entrada_Potenciometro_LCD_EN                 (* (reg8 *) Entrada_Potenciometro__LCD_EN)
/* Slew Rate Control */
#define Entrada_Potenciometro_SLW                    (* (reg8 *) Entrada_Potenciometro__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Entrada_Potenciometro_PRTDSI__CAPS_SEL       (* (reg8 *) Entrada_Potenciometro__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Entrada_Potenciometro_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Entrada_Potenciometro__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Entrada_Potenciometro_PRTDSI__OE_SEL0        (* (reg8 *) Entrada_Potenciometro__PRTDSI__OE_SEL0) 
#define Entrada_Potenciometro_PRTDSI__OE_SEL1        (* (reg8 *) Entrada_Potenciometro__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Entrada_Potenciometro_PRTDSI__OUT_SEL0       (* (reg8 *) Entrada_Potenciometro__PRTDSI__OUT_SEL0) 
#define Entrada_Potenciometro_PRTDSI__OUT_SEL1       (* (reg8 *) Entrada_Potenciometro__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Entrada_Potenciometro_PRTDSI__SYNC_OUT       (* (reg8 *) Entrada_Potenciometro__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Entrada_Potenciometro__SIO_CFG)
    #define Entrada_Potenciometro_SIO_HYST_EN        (* (reg8 *) Entrada_Potenciometro__SIO_HYST_EN)
    #define Entrada_Potenciometro_SIO_REG_HIFREQ     (* (reg8 *) Entrada_Potenciometro__SIO_REG_HIFREQ)
    #define Entrada_Potenciometro_SIO_CFG            (* (reg8 *) Entrada_Potenciometro__SIO_CFG)
    #define Entrada_Potenciometro_SIO_DIFF           (* (reg8 *) Entrada_Potenciometro__SIO_DIFF)
#endif /* (Entrada_Potenciometro__SIO_CFG) */

/* Interrupt Registers */
#if defined(Entrada_Potenciometro__INTSTAT)
    #define Entrada_Potenciometro_INTSTAT            (* (reg8 *) Entrada_Potenciometro__INTSTAT)
    #define Entrada_Potenciometro_SNAP               (* (reg8 *) Entrada_Potenciometro__SNAP)
    
	#define Entrada_Potenciometro_0_INTTYPE_REG 		(* (reg8 *) Entrada_Potenciometro__0__INTTYPE)
#endif /* (Entrada_Potenciometro__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Entrada_Potenciometro_H */


/* [] END OF FILE */
