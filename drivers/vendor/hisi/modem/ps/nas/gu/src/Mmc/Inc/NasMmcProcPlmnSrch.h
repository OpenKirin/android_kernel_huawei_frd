
#ifndef _NAS_MMC_PROC_PLMNSRCH_H
#define _NAS_MMC_PROC_PLMNSRCH_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"
#if (FEATURE_ON == FEATURE_LTE)
#include "MmcLmmInterface.h"
#endif
#include "Nasrrcinterface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/


/*****************************************************************************
  3 枚举定义
*****************************************************************************/

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
NAS_MMC_NET_RAT_TYPE_ENUM_U8 NAS_MMC_GetStartPlmnSrchRat( VOS_VOID );
VOS_VOID NAS_MMC_UpdateNvRplmnWithSimRplmn(VOS_VOID);
VOS_UINT32  NAS_MMC_IsSimRplmnInNvRplmn(
    MMC_PLMN_ID_STRU                   *pSimRplmnId
);
VOS_VOID NAS_MMC_InitFsmCtx_AutoPlmnSrch_RcvTafPlmnSrchReq(VOS_VOID );

VOS_VOID NAS_MMC_UpdatePlmnListInfoAsNoSuitableCellInSrchProc(VOS_VOID);

VOS_UINT32  NAS_MMC_IsAllListPlmnEquSpecPlmn(
    MMC_PLMN_ID_STRU                   *pstPlmnId,
    VOS_UINT32                          ulPlmnNum,
    NAS_MMC_PLMN_INFO_STRU             *pstPlmnListAddr
);
VOS_UINT32 NAS_MMC_UpdateLastSrchedPlmnStatus(
    NAS_MMC_NET_STATUS_ENUM_U8          enNewStatus,
    NAS_MMC_NET_RAT_TYPE_ENUM_U8        enSpecRat,
    VOS_UINT32                          ulPlmnNum,
    NAS_MMC_PLMN_INFO_STRU             *pstPlmnListAddr
);

/* NAS_MMC_ConvertLmmPlmnIDListToGuRRCPlmnIDList没有实现，删除 */

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

