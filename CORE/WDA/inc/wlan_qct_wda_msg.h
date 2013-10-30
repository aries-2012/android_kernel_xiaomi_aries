#ifndef WLAN_QCT_MSG_MAP_H
#define WLAN_QCT_MSG_MAP_H

/*===========================================================================

               W L A N   DEVICE ADAPTATION   L A Y E R 
                       MSG MAPPING  
                
                   
DESCRIPTION
  This file contains the external API exposed by the wlan adaptation layer 
  
      
  Copyright (c) 2008 QUALCOMM Incorporated. All Rights Reserved.
  Qualcomm Confidential and Proprietary
===========================================================================*/


/*===========================================================================

                      EDIT HISTORY FOR FILE


  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


  $Header:$ $DateTime: $ $Author: $


when        who          what, where, why
--------    ---         ----------------------------------------------
25/08/2010  adwivedi     MAP WDA messages on Legacy HAL messages
=========================================================================== */

/* Add Include */
#include "wlan_qct_pack_align.h"


#define      WDA_CONFIG_PARAM_UPDATE_REQ    SIR_CFG_PARAM_UPDATE_IND

#define     ALIGNED_WORD_SIZE       4

/* Config format required by HAL for each CFG item*/
WPT_PACK_START
typedef WPT_PACK_PRE struct
{
   /* Cfg Id. The Id required by HAL is exported by HAL
    * in shared header file between UMAC and HAL.*/
   tANI_U16   type;

   /* Length of the Cfg. This parameter is used to go to next cfg 
    * in the TLV format.*/
   tANI_U16   length;

   /* Padding bytes for unaligned address's */
   tANI_U16    padBytes;

   /* Reserve bytes for making cfgVal to align address */
   tANI_U16    reserved;

   /* Following the uCfgLen field there should be a 'uCfgLen' bytes
    * containing the uCfgValue ; tANI_U8 uCfgValue[uCfgLen] */
}WPT_PACK_POST tHalCfg, *tpHalCfg;
WPT_PACK_END

/////#define WDA_UT
#ifdef WDA_UT
#define      WDA_WDI_EVENT_MSG                0x00FF
void WDI_processEvent(void *wdiEventData, void *pUserData);
#endif

#endif
