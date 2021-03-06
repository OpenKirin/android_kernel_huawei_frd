

#ifndef __CNAS_HSD_TIMER_H__
#define __CNAS_HSD_TIMER_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/* HSD中定时器的时长 */
#define TI_CNAS_HSD_WAIT_CARD_FILE_CNF_LEN                  (30*1000)

#define TI_CNAS_HSD_WAIT_HRM_START_CNF_LEN                  (5*1000)

#define TI_CNAS_HSD_WAIT_HSM_START_CNF_LEN                  (6*1000)        /* 迭代12改为6s */

#define TI_CNAS_HSD_WAIT_EHSM_START_CNF_LEN                 (5*1000)

#define TI_CNAS_HSD_WAIT_HLU_START_CNF_LEN                  (5*1000)
#define TI_CNAS_HSD_WAIT_CAS_START_CNF_LEN                  (5*1000)

#define TI_CNAS_HSD_WAIT_HRM_POWEROFF_CNF_LEN               (5*1000)

#define TI_CNAS_HSD_WAIT_HSM_POWEROFF_CNF_LEN               (6*1000)
#define TI_CNAS_HSD_WAIT_HSM_POWERSAVE_CNF_LEN              (21*1000)
#define TI_CNAS_HSD_WAIT_EHSM_POWEROFF_CNF_LEN              (5*1000)
#define TI_CNAS_HSD_WAIT_HLU_POWEROFF_CNF_LEN               (5*1000)
#define TI_CNAS_HSD_WAIT_CAS_POWEROFF_CNF_LEN               (5*1000)
#define TI_CNAS_HSD_WAIT_CAS_SUSPEND_CNF_LEN                (6*1000)

#define TI_CNAS_HSD_WAIT_CAS_SYSTEM_SYNC_CNF_LEN            (120*1000)  /* 20150407由65*16s改为120s */
#define TI_CNAS_HSD_WAIT_CAS_OHM_IND_LEN                    (60*1000)
#define TI_CNAS_HSD_WAIT_CAS_STOP_SYSTEM_SYNC_CNF_LEN       (5*1000)
#define TI_CNAS_HSD_WAIT_CAS_STOP_SYSTEM_ACQUIRE_CNF_LEN    (5*1000)
#define TI_CNAS_HSD_SLICE_REVERSE_PROTECT_TIMER_LEN         (15*3600*1000)  /* 15 hours */

#define TI_CNAS_HSD_AVAILABLE_LEN                           (5*1000)

#define TI_CNAS_HSD_AVAILABLE_RATIO                         (1000)

#define TI_CNAS_HSD_WAIT_SESSION_NEG_RSLT_IND_LEN           (200*1000)  /* HSM在180s之内会回复协商结果 */
#define TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND_LEN         (65*1000)

#define TI_CNAS_HSD_WAIT_RRM_STATUS_IND_LEN                 (30*60*1000)

#define TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF_LEN            (120*1000)

#define TI_CNAS_HSD_WAIT_CAS_BG_SRCH_CNF_LEN                (181*1000)
#define TI_CNAS_HSD_WAIT_CAS_STOP_BG_SRCH_CNF_LEN           (7*1000)
#define TI_CNAS_HSD_WAIT_CAS_SYSTEM_SYNC_CNF_SRLTE_LEN      (130*1000)  /* SRLTE下等待CAS同步结果附加10s */
#define TI_CNAS_HSD_SYS_ACQ_NO_RF_PROTECT_TIMER_LEN         (10)       /* srlte do搜网不申请资源保护定时器，由NV控制，NV不控制用这里的默认值10分钟 */

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum CNAS_HSD_TIMER_ID_ENUM
{
    TI_CNAS_HSD_WAIT_CARD_FILE_CNF,
    TI_CNAS_HSD_WAIT_HSM_START_CNF,
    TI_CNAS_HSD_WAIT_HLU_START_CNF,
    TI_CNAS_HSD_WAIT_CAS_START_CNF,
    TI_CNAS_HSD_WAIT_HSM_POWEROFF_CNF,
    TI_CNAS_HSD_WAIT_HLU_POWEROFF_CNF,
    TI_CNAS_HSD_WAIT_CAS_POWEROFF_CNF,
    TI_CNAS_HSD_WAIT_CAS_SYSTEM_SYNC_CNF,
    TI_CNAS_HSD_WAIT_CAS_OHM_IND,
    TI_CNAS_HSD_WAIT_CAS_STOP_SYSTEM_SYNC_CNF,
    TI_CNAS_HSD_AVAILABLE_TIMER,

    TI_CNAS_HSD_AVAILABLE_MRU0_TIMER,

    TI_CNAS_HSD_SLICE_REVERSE_PROTECT_TIMER,

    TI_CNAS_HSD_WAIT_SESSION_NEG_RSLT_IND,
    TI_CNAS_HSD_WAIT_CAS_SUSPEND_CNF,
    TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND,

    TI_CNAS_HSD_WAIT_EHSM_START_CNF,
    TI_CNAS_HSD_WAIT_EHSM_POWEROFF_CNF,
    TI_CNAS_HSD_WAIT_HSM_POWERSAVE_CNF,

    TI_CNAS_HSD_WAIT_RRM_STATUS_IND,

    TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF,

    TI_CNAS_HSD_WAIT_HRM_START_CNF,
    TI_CNAS_HSD_WAIT_HRM_POWEROFF_CNF,

    TI_CNAS_HSD_SYS_ACQ_NO_RF_PROTECT_TIMER,

    TI_CNAS_HSD_WAIT_CAS_BG_SRCH_CNF,
    TI_CNAS_HSD_WAIT_CAS_STOP_BG_SRCH_CNF,

    TI_CNAS_HSD_TIMER_BUTT
};
typedef VOS_UINT32  CNAS_HSD_TIMER_ID_ENUM_UINT32;

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

#endif /* end of CnasHsdTimerMgmt.h */
