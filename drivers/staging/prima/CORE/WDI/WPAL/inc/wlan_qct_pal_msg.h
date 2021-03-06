#if !defined( __WLAN_QCT_PAL_MSG_H )
#define __WLAN_QCT_PAL_MSG_H

/**=========================================================================
  
  \file  wlan_qct_pal_msg.h
  
  \brief define general message APIs PAL exports to support legacy UMAC. 
   wpt = (Wlan Pal Type) wpal = (Wlan PAL)
               
   Definitions for platform dependent. Only work with legacy UMAC.
  
   Copyright 2010 (c) Qualcomm, Incorporated.  All Rights Reserved.
   
   Qualcomm Confidential and Proprietary.
  
  ========================================================================*/

#include "wlan_qct_pal_type.h"
#include "wlan_qct_pal_status.h"

typedef struct swpt_msg wpt_msg;

typedef void (*wpal_msg_callback)(wpt_msg *pMsg);

struct swpt_msg
{
   wpt_uint16 type;
   wpt_uint16 reserved;
   void *ptr;
   wpt_uint32 val;
   wpal_msg_callback callback;
   void *pContext;
}; 


/*---------------------------------------------------------------------------
   wpalPostCtrlMsg ? Post a message to control context so it can 
                           be processed in that context.
   Param: 
      pPalContext ? A PAL context
      pMsg ? a pointer to called allocated object; Caller retain the ownership 
             after this API returns.
---------------------------------------------------------------------------*/
wpt_status wpalPostCtrlMsg(void *pPalContext, wpt_msg *pMsg);


/*---------------------------------------------------------------------------
   wpalPostTxMsg ? Post a message to TX context so it can be processed in that context.
   Param: 
      pPalContext ? A PAL context
      pMsg ? a pointer to called allocated object; Caller retain the ownership 
             after this API returns.
---------------------------------------------------------------------------*/
wpt_status wpalPostTxMsg(void *pPalContext, wpt_msg *pMsg);

/*---------------------------------------------------------------------------
   wpalPostRxMsg ? Post a message to RX context so it can be processed in that context.
   Param: 
      pPalContext ? A PAL context
      pMsg ? a pointer to called allocated object; Caller retain the ownership 
             after this API returns.
---------------------------------------------------------------------------*/
wpt_status wpalPostRxMsg(void *pPalContext, wpt_msg *pMsg);



#endif // __WLAN_QCT_PAL_API_H
