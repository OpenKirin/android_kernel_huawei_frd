
#ifndef _MM_GLOBAL_H_
#define _MM_GLOBAL_H_


#include "NasMmlCtx.h"
#include "Nasrrcinterface.h"
#include "asnasapi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif                                                                          /* __cpluscplus                             */
#endif                                                                          /* __cpluscplus                             */

#pragma pack(4)

/* 封装OSA申请消息接口 */
#define NAS_MM_ALLOC_MSG_WITH_HDR(ulMsgLen)\
            PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MM, (ulMsgLen))

/* 封装OSA消息头 */
#define NAS_MM_CFG_MSG_HDR(pstMsg, ulRecvPid, ulMsgId)\
           { \
            ((MSG_HEADER_STRU *)(pstMsg))->ulSenderCpuId   = VOS_LOCAL_CPUID;\
            ((MSG_HEADER_STRU *)(pstMsg))->ulSenderPid     = WUEPS_PID_MM;\
            ((MSG_HEADER_STRU *)(pstMsg))->ulReceiverCpuId = VOS_LOCAL_CPUID;\
            ((MSG_HEADER_STRU *)(pstMsg))->ulReceiverPid   = (ulRecvPid);\
            ((MSG_HEADER_STRU *)(pstMsg))->ulMsgName       = (ulMsgId); \
           }

/* 获取OSA消息内容 */
#define NAS_MM_GET_MSG_ENTITY(pstMsg)\
            ((VOS_VOID *)&(((MSG_HEADER_STRU *)(pstMsg))->ulMsgName))

/* 获取OSA消息长度 */
#define NAS_MM_GET_MSG_LENGTH(pstMsg)\
            (((MSG_HEADER_STRU *)(pstMsg))->ulLength)

/* 封装OSA消息初始化消息内容接口 */
#define NAS_MM_CLR_MSG_ENTITY(pstMsg)\
            PS_MEM_SET(NAS_MM_GET_MSG_ENTITY(pstMsg), 0x0, NAS_MM_GET_MSG_LENGTH(pstMsg))

/* 封装OSA发送消息接口 */
#define NAS_MM_SEND_MSG(pstMsg)\
            PS_SEND_MSG(WUEPS_PID_MM, pstMsg)

/******************************************************************************/
/****************************  MM全局控制信息 *********************************/
/******************************************************************************/

/*****************************************************************************
 枚举名    : NAS_MM_CONN_STATE
 结构说明  : MM连接状态枚举
*****************************************************************************/
enum NAS_MM_CONN_STATE
{
    NAS_MM_CONN_NOT_EXIST           = 0,                                        /* MM 连接不存在 */
    NAS_MM_CONN_EXIST               = 1,                                        /* MM 连接存在或正在建 MM 连接 */
    NAS_MM_CONN_STATE_BUTT
};
typedef VOS_UINT8 NAS_MM_CONN_STATE_ENUM_UINT8;

/*****************************************************************************
 枚举名    : NAS_MM_CONN_CTRL_ENUM
 结构说明  : MM Connection控制
*****************************************************************************/
enum NAS_MM_CONN_CTRL_ENUM
{
    MM_CONN_CTRL_CC                     = 0 ,
    MM_CONN_CTRL_SMS,
    MM_CONN_CTRL_SS,
    MM_CONN_CTRL_LCS,
    MM_CONN_CTRL_BUTT
};
typedef VOS_UINT8   NAS_MM_CONN_CTRL_ENUM_UINT8;

/*****************************************************************************
 结构名      : NAS_MM_PROC_TYPE_ENUM
 结构说明    : MM 流程类型
*****************************************************************************/
enum NAS_MM_PROC_TYPE_ENUM
{
    MM_NULL_PROC                        = 0,
    MM_LU_PROC                          = 1,
    MM_GMM_ATTACH_PROC                  = 2,
    MM_GMM_RAU_PROC                     = 3,
    MM_COMB_ATTACH_PROC                 = 4,
    MM_COMB_RAU_PROC                    = 5,
    MM_GMM_SR_PROC                      = 6,
    MM_NET_DETACH_PROC                  = 7,
    MM_AUTH_FAIL_PROC                   = 8,
    MM_MM_CONN_PROC                     = 9,
    MM_MM_NET_ABORT                     = 10,
    MM_IMSI_DETACH                      = 11,
    MM_MM_MS_AUTH_FAIL_PROC             = 12,
    NAS_MM_PROC_TYPE_BUTT
};
typedef VOS_UINT8   NAS_MM_PROC_TYPE_ENUM_UINT8;


enum NAS_MM_T3212_START_SCENE_ENUM
{
    NAS_MM_T3212_START_SCENE_NORMAL_START                                 = 0,  /* 正常的启动T3212场景 */
    NAS_MM_T3212_START_SCENE_LAU_RRC_EST_REL_BY_AS                        = 1,  /* 在LAU建联时候被REL启动T3212场景 */
    NAS_MM_T3212_START_SCENE_LAU_RRC_EST_CONN_FAIL                        = 2,  /* 在LAU建联时失败时候启动T3212场景 */
    NAS_MM_T3212_START_SCENE_LAU_RRC_EST_FAIL_CELL_BAR                    = 3,  /* 在LAU建联时被BAR失败时候启动T3212场景 */

    NAS_MM_T3212_START_SCENE_BUTT
};
typedef VOS_UINT32 NAS_MM_T3212_START_SCENE_ENUM_UINT32;



enum NAS_MM_T3212_LEN_TYPE_ENUM
{
    NAS_MM_T3212_LEN_TYPE_NETWORK_ALLOC_LEN             = 0,
    NAS_MM_T3212_LEN_TYPE_NETWORK_ALLOC_RANDOM_LEN      = 1,
    NAS_MM_T3212_LEN_TYPE_NV_DEFINED                    = 2,
    NAS_MM_T3212_LEN_TYPE_BUTT
};
typedef VOS_UINT8 NAS_MM_T3212_LEN_TYPE_ENUM_UINT8;
/*****************************************************************************
 结构名      : NAS_MM_LINK_CTRL_STRU
 结构说明    : MM 信令连接管理
*****************************************************************************/
typedef struct
{
    NAS_MM_PROC_TYPE_ENUM_UINT8         ucCurrentProc;                          /* 当前流程 */
    VOS_UINT8                           ucExistedRrcConn;                       /* 流程是否建立在已存在的RRC连接上 */
    VOS_UINT8                           ucSmcOrFirstNasMsgRcvdFlg;              /* 是否从网测收到Security Mode Command或者NAS层消息 */
    VOS_UINT8                           ucReserve;
}NAS_MM_LINK_CTRL_STRU;


#ifndef _PLMN_ID_
#define _PLMN_ID_
typedef struct
{
    VOS_UINT32                               ulMcc;                             /* MCC,3 bytes                              */
    VOS_UINT32                               ulMnc;                             /* MNC,2 or 3 bytes                         */
}MM_PLMN_ID_STRU;
#endif

#ifndef _LAI_
#define _LAI_
typedef struct
{
    MM_PLMN_ID_STRU                          PlmnId;
    VOS_UINT32                               ulLac;                             /* BIT STRING(SIZE(16))                     */
}MM_LAI_STRU;
#endif

/* CS域的安全信息 */


typedef struct
{
#define     MM_CIPHER_NOSTART           0
#define     MM_CIPHER_START             1

    VOS_UINT8                   ucSecurityType;                                 /* 取值同 RRMM_SECURITY_IND_STRU ulRptMode  */
}MM_CS_SECURITY_INFO_STRU;


/* MS CS域的信息 */
typedef struct
{
    VOS_UINT8                               ucLength;                           /* 以digit为单位,一个字节存放2个digit       */
    VOS_UINT8                               aucImsi[8];                         /* IMSI采用BCD编码,长度不超过15位,其中
                                                                                 * aucImsi[0]高四位存放的是IMSI的digit 1,
                                                                                 * aucImsi[0]低四位全为1,不存储信息,
                                                                                 * aucImsi[1]高四位存放的是IMSI的digit 3,
                                                                                 * aucImsi[1]低四位存放的是IMSI的digit 2,
                                                                                 * 以此类推                                 */
}MM_IMSI_STRU;

typedef struct {
#define     MM_MS_ID_ABSENT             0x00
#define     MM_MS_ID_IMSI_PRESENT       0x01
#define     MM_MS_ID_IMEI_PRESENT       0x02

#define     MM_MS_ID_IMEISV_PRESENT     0x04
#define     MM_MS_ID_TMSI_PRESENT       0x08

    VOS_UINT8                           ucMsIdFlg;                              /* MsId存在标识                             */
    MM_IMSI_STRU                        Imsi;
    VOS_UINT8                           aucImei[8];                             /* IMEI 采用BCD编码,共有15位,编码同IMSI     */
    VOS_UINT8                           aucImeisv[9];                           /* IMEISV 采用BCD编码,共有16位,编码同IMSI   */
    VOS_UINT8                           aucTmsi[4];                             /* BIT STRING(SIZE(32))                     */
}MM_MOBILE_ID_STRU;

typedef struct
{

    #define     MM_NO_FORBIDDEN                         MMCMM_NO_FORBIDDEN
    #define     MM_FORBIDDEN_PLMN                       MMCMM_FORBIDDEN_PLMN
    #define     MM_FORBIDDEN_PLMN_FOR_GPRS              MMCMM_FORBIDDEN_PLMN_FOR_GPRS
    #define     MM_FORBIDDEN_LA_FOR_ROAM                MMCMM_FORBIDDEN_LA_FOR_ROAM
    #define     MM_FORBIDDEN_LA_FOR_REG_PRVS_SVS        MMCMM_FORBIDDEN_LA_FOR_REG_PRVS_SVS
    VOS_UINT32                          ulCurFobidnFlg;                         /* 当前PLMN的禁止信息                       */

    /* 删除新旧LAI信息,旧的LAI放到MML中保存 */

    VOS_UINT8                           ucCsDrxLen;                             /* CS域的DRX length系数 */
    MM_MOBILE_ID_STRU                   MobileId;                               /* MOBILE ID  */
    MM_PLMN_ID_STRU                     stPlmnId;                               /* 对应TMSI的PLMN ID */
    VOS_UINT32                          ulCellId;
    VOS_UINT8                           ucCellChgFlg;

    VOS_UINT8                           ucOldRac;                               /* 最后一次注册成功的RAC */

    VOS_UINT8                           aucReserved[2];

    MM_LAI_STRU                         stAttemptToUpdateLai;                   /* 如果注册被拒在ATTEMPT TO UPDATE状态，则记录该LAI信息，在发起LAU时候，则清除该标记 */
}MM_MS_CS_INFO_STRU;

#define     MM_AUTHEN_RAND_REPEAT           0
#define     MM_AUTHEN_RAND_DIFFER           1

/* Authentication 部分控制参数 */
typedef struct
{
#define     MM_AUTHEN_SUPPORT_UMTS_ALGO     0
#define     MM_AUTHEN_NOSUPPORT_UMTS_ALGO   1
    VOS_UINT8                               ucSptUmtsAuthAlgo;                  /* 支持UMTS 鉴权算法的标识                  */

#define     MM_AUTHEN_COUNTER_MAX_CNT       3                                   /* Authentication attempt counter最大个数   */
    VOS_UINT8                               ucAuthenAttmptCnt;                  /* Authentication attempt counter           */

#define     MM_AUTHEN_NO_CAUSE              0
#define     MM_MAC_CODE_FAIL                1
#define     MM_SQN_FAIL                     2
    VOS_UINT8                               ucLastFailCause;                    /* 上次Authentication失败的原因             */
    VOS_UINT8                               ucFailParaLength;                   /* Failure Parameter的长度，单位为字节      */
    VOS_UINT8                               aucFailPara[14];                    /* Failure Parameter                        */

#define     MM_AUTHEN_RAND_PRESENT          0
#define     MM_AUTHEN_RAND_ABSENT           1
    VOS_UINT8                               ucRandFlg;                          /* 此RAND是否有效                           */

    VOS_UINT8                               ucRandRepeat;                       /* 此 RAND 是否与上次相同 */
    VOS_UINT8                               ucSresFlg;                          /* SRES存在标志,                             */

#define     MM_MAX_SIZE_RAND                16
    VOS_UINT8                               aucOldRand[MM_MAX_SIZE_RAND];       /* 旧的RAND                                 */
    VOS_UINT8                               aucCurRand[MM_MAX_SIZE_RAND];       /* 当前的RAND                               */

#define     MM_AUTN_MAX_LENGTH              0x10
    VOS_UINT8                               ucAutnLen;
    VOS_UINT8                               aucAutn[MM_AUTN_MAX_LENGTH];

#define     MM_AUTHEN_RES_ABSENT            0
#define     MM_AUTHEN_RES_PRESENT           1
    VOS_UINT8                               ucResFlg;                           /* RES存在标志,                             */
                                                                                /* 1:易失性内存不为空,
                                                                                 * RAND和RES为易失性内存中的值              *
                                                                                 * 0:易失性内存为空,RAND为上一次的RAND的值  */
    VOS_UINT8                               aucRes[4];                          /* RES                                      */
    VOS_UINT8                               ucExtRspLength;                     /* Extension Response的长度，单位为字节     */

#define     MM_MAX_RES_EXT_LEN              12
    VOS_UINT8                               aucExtRes[MM_MAX_RES_EXT_LEN];      /* Extension Response                       */

    VOS_UINT8                               ucLastAuthType;                     /* 上次鉴权类型                             */
    VOS_UINT8                               ucOpId;
}MM_AUTHEN_CTRL_STRU;


/* MM Connection  部分的数据结构 */

typedef struct
{
    VOS_UINT32   ulTransactionId;                                               /* TI                                       */
    VOS_UINT32   ulCallType;                                                    /* 呼叫类型                                 */
    VOS_UINT32   ulCallPri ;                                                    /* 呼叫优先级                               */
    VOS_UINT32   ulCallMode;                                                    /* 呼叫模式,speech或video或其他的 */
    VOS_UINT8    ucFlg;                                                         /* 是否需要建立该连接                       */
    VOS_UINT8    ucReserved[3];
}MM_RCV_XX_EST_REQ_STRU;

typedef struct
{
    MM_RCV_XX_EST_REQ_STRU  RcvXXEstReq;                                        /* 记录在建立或重建MM连接的过程中           *
                                                                                 * CM层要求建立的第一个建立MM连接的请求信息 */
    VOS_UINT8                   aucMMConnExtFlg[2];                             /* 记录MM连接是否存在标志                   */
    VOS_UINT8                   aucMMConnReestFlg[2];                           /* 向CC发送重建请求时记录需要重建的MM连接   */

#define  NO_MM_CONN_ESTING                                  255                 /* 没有正在建立的MM连接,                    *
                                                                                 * 该宏也用于ucMMConnEstingPD               */
    VOS_UINT8                   ucMMConnEstingTI;                               /* 正在建立的MM连接的TI                     */

    VOS_UINT8                   ucEstingCallTypeFlg;                            /* 正在建立的MM连接是否是紧急呼叫           */
    VOS_UINT8                   ucRat;

    VOS_UINT8                   ucReserved;
}MM_CONN_CTRL_STRU;

enum LAU_TYPE_ENUM
{
    MM_IE_LUT_NORMAL_LU                   = 0,
    MM_IE_LUT_PERIODIC_UPDATING           = 1,
    MM_IE_LUT_IMSI_ATTACH                 = 2,
    MM_IE_LUT_TYPE_BUTT
};
typedef VOS_UINT8 LAU_TYPE_ENUM_UINT8;


typedef struct
{
    LAU_TYPE_ENUM_UINT8       ucLuType;                                         /* Location updating type                   */
    VOS_UINT8                 ucLuAttmptCnt;                                    /* LU attempt counter                       */
    VOS_UINT8                 ucRetryFlg;                                       /* 进入新的小区是否进行LU                   */
    VOS_UINT8                 ucEnterState;                                     /* 释放RR连接之后进入的状态                 */
    VOS_UINT8                 ucT3212ExpiredFlg;                                /* 记录T3212溢出的标志                      */
    VOS_UINT8                 ucT3213AttmptCnt;                                 /* T3213超时计数器                          */
    VOS_UINT8                 ucImmAccRejLuAttmptCnt;                           /* G下立即指派拒绝场景LU尝试次数*/


    VOS_UINT8                 ucPsRandomAccessFailCnt;                                /* W下联合Attach或者RAU，建链失败的次数 */
}MM_LU_INFO_STRU;


/* MM 全局量 */
#define  MM_RAU_ATTACH_COUNTER_MAX                      5                       /* RAU/ATTACH attempt counter最大个数       */


enum NAS_MM_STATE_ENUM
{
    MM_STATE_NULL                                           = 0,
    MM_IDLE_NO_CELL_AVAILABLE                               = 1,
    MM_IDLE_PLMN_SEARCH                                     = 2,
    MM_IDLE_NORMAL_SERVICE                                  = 3,
    MM_IDLE_LIMITED_SERVICE                                 = 4,
    MM_IDLE_ATTEMPTING_TO_UPDATE                            = 5,
    MM_IDLE_LOCATION_UPDATE_NEEDED                          = 6,
    MM_IDLE_PLMN_SEARCH_NORMAL_SERVICE                      = 7,
    MM_IDLE_NO_IMSI                                         = 8,
    WAIT_FOR_OUTGOING_MM_CONNECTION                         = 9,
    MM_CONNECTION_ACTIVE                                    = 10,
    WAIT_FOR_NETWORK_COMMAND                                = 11,
    WAIT_FOR_RR_CONNECTION_MM_CONNECTION                    = 12,
    WAIT_FOR_REESTABLISH_WAIT_FOR_REEST_REQ                 = 13,
    WAIT_FOR_REESTABLISH_WAIT_FOR_EST_CNF                   = 14,
    WAIT_FOR_RR_ACTIVE                                      = 15,
    WAIT_FOR_ADDITIONAL_OUTGOING_MM_CONNECTION              = 16,
    LOCATION_UPDATING_PENDING                               = 17,
    IMSI_DETACH_PENDING                                     = 18,
    MM_WAIT_FOR_ATTACH                                      = 19,
    WAIT_FOR_RR_CONNECTION_LOCATION_UPDATING                = 22,
    LOCATION_UPDATING_INITIATED                             = 23,
    LOCATION_UPDATE_REJECTED                                = 24,
    WAIT_FOR_RR_CONNECTION_IMSI_DETACH                      = 25,
    IMSI_DETACH_INITIATED                                   = 26,
    PROCESS_CM_SERVICE_PROMPT                               = 27,
    MM_STATE_RR_CONNECTION_RELEASE_NOT_ALLOWED              = 30,
    TEST_CONTROL_ACTIVE                                     = 31,
    MM_INTER_RAT_CHANGE                                     = 32,
    MM_IDLE_ECALL_INACTIVE                                  = 33,

    MM_STATE_MAX
};
typedef VOS_UINT8 NAS_MM_STATE_ENUM_UINT8;

/* 服务状态定义 */
enum MM_SERVICE_STATUS_ENUM
{
    MM_NORMAL_SERVICE       =           0,
    MM_LIMITED_SERVICE      =           1,
    MM_LIMIT_REGION_SERVICE =           2,
    MM_NO_IMSI              =           3,
    MM_NO_SERVICE           =           4,
    MM_ATTEMPTING_TO_UPDATE =           7,
    MM_DETACHED             =           8,
    MM_DISABLE              =           9
};

typedef VOS_UINT8 MM_SERVICE_STATUS_ENUM_UINT8;

/* MM_SUSPEND_SHARE_STRU ucSuspendFlg 取值*/
#define MM_SUSPEND_STATE        1
#define MM_SUSPEND_STATE_NOT    0

/* 恢复结果 ResumeResult 取值 */
#define MM_RESUME_RESULT_SUCCESS    0x00
#define MM_RESUME_RESULT_FAILURE    0x01

typedef struct
{
    NAS_RRC_RE_TX_MSG_STRU              astReTxMsg[NAS_RRC_MAX_RE_TX_MSG_NUM];  /* 接入层上报的重传消息 */
    VOS_UINT8                           ucSuspendFlg;                           /* MM是否处于挂起状态标志             */
    VOS_UINT8                           ucSuspendCause;                         /* 挂起原因，切换引起还是小区重选引起 */
    NAS_MML_NET_RAT_TYPE_ENUM_UINT8     enOldNetType;                           /* 挂起前的网络接入技术 */

    NAS_MML_NET_RAT_TYPE_ENUM_UINT8     enDestSuspendRat;                       /* 要挂起的目标RAT */
}MM_SUSPEND_SHARE_STRU;


typedef struct
{
    VOS_UINT8                                       ucState;                           /* MM状态*/
    VOS_UINT8                                       ucPreState;                        /* MM前状态                                 */
    MM_SERVICE_STATUS_ENUM_UINT8                    enMmServiceState;                  /* MM的服务状态*/
    VOS_UINT8                                       ucNtMod;                           /* 网络模式*/
    VOS_UINT8                                       ucCsSigConnFlg;                    /* CS域信令连接是否存在标志 */
    NAS_MML_RRC_INTEGRITY_PROTECT_ENUM_UINT8        enCsIntegrityProtect;              /* 完整性保护 */
    VOS_UINT16                                      usRac;                             /* RAC                                      */
    VOS_UINT32                                      ulT3212Value;                      /* T3212的时长                              */
    MM_LU_INFO_STRU                                 stLuInfo;                          /* LU过程需要的相关参数 */
    VOS_UINT8                                       ucT3211Status;
    VOS_UINT8                                       aucReserved1[2];
    MM_CS_SECURITY_INFO_STRU                        stCsSecutityInfo;                  /* CS域的安全infomation*/
    MM_MS_CS_INFO_STRU                              stMsCsInfo;                        /* MS CS域信息                              */

    NAS_MML_LOCATION_UPDATE_STATUS_ENUM_UINT8       enCsUpdateStatus;                  /* status of location update */
    VOS_UINT8                                       aucTmsi[NAS_MML_MAX_TMSI_LEN];     /* tmsi的内容 */
    NAS_MML_SIM_CS_SECURITY_INFO_STRU               stCsSimSecuInfo;
    VOS_UINT8                                       aucReserved2[3];
    NAS_MML_LAI_STRU                                stCsSuccLai;
    NAS_MML_EQUPLMN_INFO_STRU                       stBackupEquPlmnInfo;

}MM_BACKUP_SHARE_STRU;


typedef struct
{
    NAS_MML_TIN_TYPE_ENUM_UINT8         enTinType;                              /* TIN类型 */
    VOS_UINT8                           aucReserve[2];
    VOS_UINT8                           aucImsi[NAS_MML_MAX_IMSI_LEN];          /* 上次保存的IMSI的内容 */
}NAS_MM_NVIM_TIN_INFO_STRU;



enum NAS_MM_ATTACH_TYPE_ENUM
{
    MM_WAIT_NULL_ATTACH  = 0,
    MM_WAIT_PS_ATTACH,
    MM_WAIT_CS_ATTACH,
    MM_WAIT_CS_PS_ATTACH,
    MM_WAIT_ATTACH_BUTT
};
typedef VOS_UINT32 NAS_MM_ATTACH_TYPE_ENUM_UINT32;


enum NAS_MM_DETACH_TYPE_ENUM
{
    MM_WAIT_NULL_DETACH  = 0,
    MM_WAIT_PS_DETACH,
    MM_WAIT_CS_DETACH,
    MM_WAIT_CS_PS_DETACH,
    MM_WAIT_DETACH_BUTT
};
typedef VOS_UINT32 NAS_MM_DETACH_TYPE_ENUM_UINT32;


typedef struct
{
    VOS_UINT32                          ulOpid;                                 /* MMA生成和使用 */
    NAS_MM_ATTACH_TYPE_ENUM_UINT32      enAttachType;                           /* 等待ATTACH响应消息的类型 */
}NAS_MM_ATTACH_INFO_STRU;


typedef struct
{
    VOS_UINT32                          ulOpid;                                 /* MMA生成和使用 */
    NAS_MM_DETACH_TYPE_ENUM_UINT32      enDetachType;                           /* 等待DETACH响应消息的类型                 */
}NAS_MM_DETACH_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucT3242ExpiredFlg;
    VOS_UINT8                           ucT3243ExpiredFlg;
    VOS_UINT8                           ucT3242StartNeededFlg;
    VOS_UINT8                           ucT3243StartNeededFlg;

}NAS_MM_ECALL_INFO_STRU;


enum NAS_MM_NETWORK_T3212_VALUE_TYPE_ENUM
{
    NAS_MM_T3212_VALUE_TYPE_BROADCAST,       /* T3212定时器时长取自系统消息中携带的时长 */
    NAS_MM_T3212_VALUE_TYPE_NONE_BROADCAST,  /* T3212定时器时长取自lau accept中Per MS T3212 IE 携带的时长 */
    NAS_MM_T3212_VALUE_TYPE_BUTT
};
typedef VOS_UINT8 NAS_MM_NETWORK_T3212_VALUE_TYPE_ENUM_UINT8;



typedef struct
{
    /* 使用NV中的T3212时长计数 */
    VOS_UINT32                          ulUseNvT3212StartLenCount;

    /* 网络分配的T3212时长改变后的随机定时器时长 */
    VOS_UINT32                          ulNetworkT3212RandLen;

    NAS_MML_LAI_STRU                            stAllocT3212ValueLaiInfo;    /* 下发t3212定时器时长的网络信息 */
    NAS_MM_NETWORK_T3212_VALUE_TYPE_ENUM_UINT8  enNetworkT3212ValueType;      /* 定义T3212定时器时长来源是从系统消息还是从lau accept中
                                                                                 Per Ms t3212 IE,lau accept中优先 */
    VOS_UINT8                                   aucReserved[3];
}NAS_MM_T3212_INFO_STRU;


typedef struct
{


    VOS_UINT32                               ulCnfStatus;                       /* 等待CNF原语的标记                        */

    MM_MS_CS_INFO_STRU                       MsCsInfo;                          /* MS CS域信息                              */


#define                 MM_CONN_CM_ENTITY_NUM         0x04                      /* CM层实体最大个数                         */

    MM_CONN_CTRL_STRU                   ConnCtrlInfo[MM_CONN_CM_ENTITY_NUM];    /* MM连接控制参数                           */

    VOS_UINT16                               usRac;                             /* RAC                                      */
    NAS_MM_STATE_ENUM_UINT8                  ucState;                           /* MM状态                                   */
    NAS_MM_STATE_ENUM_UINT8                  ucPreState;                        /* MM前状态                                 */

#define MM_ATT_NOT_NEED                                 0                       /* ATT FLG不存在                            */

#define MM_ATT_NEED                                     1                       /* ATT FLG存在                              */

    VOS_UINT8                               ucAttFlg;                           /* ATT存在标志                              */
#define MM_NOT_SUPPORT                                  0                       /* 不支持                                   */
#define MM_SUPPORTING                                   1                       /* 支持                                     */
    VOS_UINT8                               ucMmInfoSuprt;                      /* 是否支持MM INFORMAITON                   */
    VOS_UINT8                               ucEmlppSuprt;                       /* 是否支持eMLPP                            */

#define     MM_NET_MODE_I                               1                       /* 网络模式I                                */
#define     MM_NET_MODE_II                              2                       /* 网络模式II                               */

#define     MM_NET_MODE_III                             3                       /* 网络模式III                              */
#define     MM_NET_MODE_INVALID                         0                       /* 网络模式无效                              */

    VOS_UINT8                               ucNtMod;                            /* 网络模式                                 */
    VOS_UINT8                               ucNewNtMod;                         /* 新的网络模式                             */

#define     MM_MS_MODE_NULL                             0                       /* 空模式                                   */
#define     MM_MS_MODE_CS_PS                            1                       /* 模式A                                    */
#define     MM_MS_MODE_CS                               2                       /* 模式B                                    */
#define     MM_MS_MODE_PS                               3                       /* 模式C                                    */
    VOS_UINT8                               ucMsMod;                            /* 用户模式                                 */

#define     MM_CS_SIG_CONN_PRESENT                      0                       /* CS域信令连接存在                         */
#define     MM_CS_SIG_CONN_ABSENT                       1                       /* CS域信令连接不存在                       */
    VOS_UINT8                               ucCsSigConnFlg;                     /* CS域信令连接是否存在标志                 */

#define     MM_FOLLOW_ON                                0                       /* 指示Follow on                            */
#define     MM_NO_FOLLOW_ON                             1                       /* 没有指示Follow on                        */
    VOS_UINT8                               ucFollowOnFlg;                      /* 信令延长使用标志                         */

    MM_SERVICE_STATUS_ENUM_UINT8            ucMmServiceState;                   /* MM的服务状态                             */

    VOS_UINT8                               ucSecurityMode;                     /* 安全模式 */

    MM_CS_SECURITY_INFO_STRU                CsSecutityInfo;                     /* CS域的安全infomation                     */

#define                 MM_DETACH_CS_POWEROFF           1
#define                 MM_DETACH_USIM_REMOVE           2
#define                 MM_DETACH_CS_NORMAL             3
#define                 MM_DETACH_NEED_DELAY            4
#define                 MM_DETACH_TYPE_BUTT             5

    VOS_UINT8                               ucDetachType;                       /* DETACH的类型                             */


    MM_AUTHEN_CTRL_STRU                     AuthenCtrlInfo;                     /* 鉴权过程控制参数                         */

    VOS_UINT8    ucStaAfterWaitForNwkCmd;                                       /* 记录WAIT FOR NETWORK COMMAND状态后       *
                                                                                 * 要进入的IDLE子状态                       */

    VOS_UINT8                   ucMMConnEstingPD;                               /* 正在建立的MM连接的PD，宏定义用消息中的   */

    VOS_UINT8                   ucStaOfRcvXXEstReq;                             /* 记录收到MMXX_EST_REQ时MM的状态           */

    /* 层间原语管理结构 */
    /* 与RRC的接口管理结构 */
    /* RRMM_EST_REQ/RRMM_EST_CNF管理 */
#define                 MM_RCV_FLG_NULL                 0x00
#define                 MM_RCV_RRMM_EST_CNF_FLG         0x01
    VOS_UINT8                               ucRcvRrcFlg;

    /* 与AGENT的接口管理结构 */
#define                 MM_RCV_STATUS_CNF_FLG               0x01
#define                 MM_RCV_AUTH_CNF_FLG                 0x02
#define                 MM_RCV_IMEI_CNF_FLG                 0x04

#define                 MM_RCV_READ_FILE_CNF_IMSI_FLG       0x08
#define                 MM_RCV_READ_FILE_CNF_CKIK_FLG       0x10
#define                 MM_RCV_READ_FILE_CNF_LOCA_INFO_FLG  0x20

    VOS_UINT8                               ucRcvAgentFlg;
    /* 空中接口消息管理结构 */
    /* CM SERVICE REQUEST管理 */
    /* CM RE-ESTABILISHMENT REQUEST管理 */
    /* LOCATION UPDATING REQUEST管理 */
#define                 MM_RCV_CM_SVC_ACCPT_FLG         0x01
#define                 MM_RCV_LU_ACCPT_FLG             0x02
    VOS_UINT8                               ucRcvMsgFlg;

    VOS_UINT8                               ucSimStatusOpid;
    VOS_UINT8                               ucRrEstReqOpid;

    MM_LU_INFO_STRU                         LuInfo;                             /* LU相关信息                               */

    VOS_UINT16                      usCauseVal;                                 /* 记录的原因值                             */

    NAS_MM_PROC_TYPE_ENUM_UINT8     ucProc;                                     /* 当前的流程                               */

    VOS_UINT8                       ucLikeB;                                    /* 在A+I模式的时候,是否类似A+II或B的处理    */

    VOS_UINT8                       ucAttDelay;                                 /* 缓存的Attach标志                         */

    VOS_UINT8                       ucSysInfoFlg;

    VOS_UINT8                       ucConnRcvSysFlg;

    VOS_UINT8                       ucPowerOnFlg;

    VOS_UINT8                       ucPagingCause;                              /* Paging Cause                             */

    VOS_UINT8                       ucRejectCause;                              /* 最后一次被拒绝或失败的原因值，
                                                                                   对应MM查询信息窗口的"enRejectCause"      */
    VOS_UINT8                       ucCsCipherAlgor ;                           /* 加密算法                                 */

#define MM_IMSI_PAGING                  1
#define MM_TMSI_PAGING                  2

#define MM_STMSI_PAGING                (3)                                      /* L的s-tmsi寻呼*/

    VOS_UINT8                       ucPagingRecordTypeId;                       /* Paging Record Type Id                    */

#define MM_NO_PAGING                    0
#define MM_MO_PAGING                    1
#define MM_MT_PAGING                    2
    VOS_UINT8                       ucPagingType;                               /* Paging Type,只记录短消息主叫和被叫        */

#define MM_LU_FALSE                     0
#define MM_LU_TRUE                      1
    VOS_UINT8                       ucLuState;
    /* 在MM连接建立过程中收到系统信息，如果LAI改变，
    需要中止当前的MM连接建立过程，并发起LU。
    在收到RRMM_REL_IND后处理此标志。
    在收到RRMM_SYS_INFO_IND后清除此标志
    VOS_TRUE:收到RRMM_REL_IND后需要做LU
    VOS_FALSE:不需要做LU */
    VOS_UINT8                       ucPendingLu;
    VOS_UINT8                       ucLikeNetmode2;
    VOS_UINT8                       ucSuspendPreState;                                /* MM挂起前状态 */

    VOS_UINT8                       ucTime2Sndout;                                    /* 当前是否需要导出全局变量供回放 */

    VOS_BOOL                        bWaitingEstCnf;

    NAS_MM_LINK_CTRL_STRU           stMmLinkCtrl;                               /* MM连接释放管理 */
    VOS_UINT8                       ucRetryLauFlg;                              /* 是否需要在收到sys info 重新发起LAU */
    VOS_UINT8                       ucGasRrChanIndMsgValidFlg;                  /* GAS发送的GAS_RR_CHAN_IND消息是否仍有效标志 */
    VOS_UINT8                       ucCallRetryCount;                           /* GSM下，建链失败后，重新发起建链请求次数 */
    VOS_UINT8                       ucNotCampONPreState;

    MM_SUSPEND_SHARE_STRU           stSuspendShare;                           /* 在异系统重选，切换，CCO中MM共用的一些全局变量*/
    MM_BACKUP_SHARE_STRU            stBackupShare;
    NAS_MM_ATTACH_INFO_STRU         stAttachInfo;                           /* 等待ATTACH结果的信息 */
    NAS_MM_DETACH_INFO_STRU         stDetachInfo;                           /* 等待DETACH结果的信息 */

    /* MM中增加全局变量指示是否进行联合注册 */
    VOS_UINT8                        ucIsComBined;


    NAS_MML_NET_RAT_TYPE_ENUM_UINT8     enPreRatType;

    VOS_UINT8                           ucLauAcceptContainDiffNbLaiFlg;             /* lau accept消息中携带与系统消息中位置区不同的NB LAI,UE需要在连接释放后马上发起lau */

    VOS_UINT8                           ucSrvccFlg;
    /* VOS_TRUE:当前处于SRVCC过程中 VOS_FALSE:当前不处于SRVCC过程中;收到RRC的SRVCC通知更新为TRUE,收到RRC的RESUME IND指示后清除 */

    VOS_UINT8                           ucRcvSrvccCallInfoFlg;                  /* SRVCC过程中CC同步CALLINFO标识 */
    VOS_UINT8                           ucCsPagingFlg;                          /* 记录当前是否有CS PAGING */
    VOS_UINT8                           aucReserve[2];

    NAS_MM_ECALL_INFO_STRU              stEcallInfo;

    RRC_NAS_EST_RESULT_ENUM_UINT32     enEstCnfResult;

    NAS_MM_T3212_INFO_STRU              stT3212Info;
    VOS_UINT32                          ulTransactionEnqSenderPid;
}MM_GLOBAL_CTRL_STRU;


/* MM Timer管理结构 */
#define             MM_TIMER_STOP        0
#define             MM_TIMER_RUNNING     1
#define             MM_TIMER_PAUSE       2
typedef struct{
    HTIMER               hTimer;
    VOS_UINT32           ulTimerLen;
    VOS_UINT32           ulParam;
    VOS_UINT8            ucMode;
    VOS_UINT8            ucTimerStatus;
    VOS_UINT8            aucReserved[2];
}MM_TIMER_STRU;

typedef VOS_VOID  (*MM_CELL_FUN_TYPE)(VOS_VOID *);

typedef VOS_INT32 (*RR_DATA_REQ_FUNC)(VOS_UINT8 ucCnDomain, VOS_UINT8 ucPriority, VOS_UINT32 ulSize, VOS_INT8 *pData);
typedef VOS_INT32 (*RR_EST_REQ_FUNC)(VOS_UINT32 ulOpId, VOS_UINT8 ucCnDomain, VOS_UINT32 ulEstCause, IDNNS_STRU *pIdnnsInfo,
                                     RRC_PLMN_ID_STRU *pstPlmnId, VOS_UINT32 ulSize, VOS_INT8 *pFisrstMsg);
typedef VOS_INT32 (*RR_REL_REQ_FUNC)(VOS_UINT8 ucCnDomain,RRC_CELL_BAR_ENUM_UINT32 enBarValidFlg);
typedef VOS_INT32 (*RR_ABORT_REQ_FUNC)(VOS_UINT32 ulAbortType);
typedef VOS_INT32 (*ATTACH_INFO_REQ_FUNC)(ATTACH_INFO_STRU *pAttachInfo);
typedef VOS_INT32 (*SIM_STATUS_REQ_FUNC) (USIM_VALID_INFO_STRU *pUsimValidInfo);
typedef VOS_INT32 (*PS_DRX_LEN_REQ_FUNC)(VOS_UINT8 ucDrxLen);
typedef VOS_INT32 (*SK_CHANGE_REQ_FUNC)(SECURITY_KEY_INFO_STRU *pSecurityKeyInfo);
typedef VOS_INT32 (*TMSI_LAI_INFO_REQ_FUNC)(NAS_INFO_TMSI_LAI_STRU*);
typedef VOS_INT32 (*DEL_KEY_REQ_FUNC)(VOS_UINT8 ucCnDomain);

typedef struct
{

    struct
    {
        RR_DATA_REQ_FUNC            RrDataReqFunc;
    }SigDataTransfer;

    struct
    {
        RR_EST_REQ_FUNC             RrEstReqFunc;
        RR_REL_REQ_FUNC             RrRelReqFunc;
    }SigConnCtrl;

    /* 指示当前函数指针指向 GSM 还是 WCDMA 网发送函数 */
    VOS_UINT8           ucFuncEnvironment;

    VOS_UINT8           aucReserved[3];

}NAS_MM_IMPORTED_FUNC_LIST_STRU;

typedef struct
{
    VOS_UINT8       ucExtRspLength;                                             /* Extension Response的长度，单位为字节     */
#define AGENT_AUTH_FAIL_MAC_CODE   0
#define AGENT_AUTH_FAIL_SQN        1
    VOS_UINT8       ucFailureCause;                                             /* AUTN错误的原因                           */
    VOS_UINT8       ucFailParaLength;                                           /* Failure Parameter的长度，单位为字节      */

#define AGENT_AUTH_RST_SUCCESS   0
#define AGENT_AUTH_RST_FAILURE   1
    VOS_UINT8       ucCheckRst;                                                 /* 检查结果                                 */
    VOS_UINT8       aucResponse[4];                                             /* RES的byte1～byte4                        */

    VOS_UINT8       aucExtResponse[12];                                         /* Extension Response                       */
    VOS_UINT8       aucCipheringKey[16];                                        /* Cipher Key                               */
    VOS_UINT8       aucIntegrityKey[16];                                        /* Integrity Key                            */

    VOS_UINT8       ucKcLength;
    VOS_UINT8       aucKc[NAS_MML_GSM_KC_LEN];                                        /* Kc */
    VOS_UINT8       aucFailPara[16];                                            /* Failure Parameter                        */
}MM_USIM_AUTHENTICATION_CNF_STRU;

#define WAIT_FOR_WUEPS_START                0
#define WAIT_FOR_MMCMM_START_REQ            1
#define WAIT_FOR_NORMAL_MSG                 2

#define     MM_NSD_MOD_R98_OR_OLDER         2
#define     MM_NSD_MOD_R99_ONWARDS          4

#define     MM_NSD_INITAL_VALUE             0
typedef struct{
    VOS_UINT8           ucNsd;
    VOS_UINT8           ucNsdMod;
}MM_NSD_INFO_ST;

typedef struct
{
    VOS_UINT32                   ulTransactionId;                               /* TI                                       */
    VOS_UINT32                   ulCallType;                                    /* 呼叫类型                                  */
    VOS_UINT32                   ulCallMode;
    VOS_UINT32                   ulCallPri ;                                    /* 呼叫优先级                                */
}MMCC_EST_REQ_ST;


typedef struct
{
    VOS_UINT32                   ulReleaseType;                                 /* 释放类型                                  */
    VOS_UINT32                   ulTransactionId;                               /* TI                                       */
}MMCC_REL_REQ_ST;

typedef struct
{
    VOS_UINT32                   ulTransactionId;                               /* TI                                       */
}MMCC_ABORT_REQ_ST;

typedef struct
{
    VOS_UINT32                   ulTransactionId;                               /* TI                                       */
}MMCC_REEST_REQ_ST;

typedef struct
{
    VOS_UINT32                   ulRefuseCause;                                 /* 拒绝原因                                  */
}MMCC_PROMPT_REJ_ST;

typedef struct
{
    VOS_UINT32                 ulTi;                                            /* Transaction Id                          */
}MMSS_EST_REQ_ST;

typedef struct
{
    VOS_UINT32                 ulTi;                                            /* Transaction Id                         */
}MMSS_REL_REQ_ST;

typedef struct
{
    VOS_UINT32                   ulTransactionId;                               /* TI                                       */
}MMSS_ABORT_REQ_ST;

typedef struct
{
    VOS_UINT32   ulTi;                                                          /* Transaction Id                           */
    VOS_UINT32   ulEstCause;                                                    /* RRC连接建立原因                          */
}MMSMS_EST_REQ_ST;

typedef struct
{
    VOS_UINT32               ulTi;                                              /* transaction id                           */
}MMSMS_REL_REQ_ST;

typedef struct
{
    VOS_UINT32                   ulTransactionId;                               /* TI                                       */
}MMSMS_ABORT_REQ_ST;

typedef struct rrmm_sync_ind_st
{
    VOS_UINT32                   ulChannelMode;                                 /* 信道模式，仅GSM */
    VOS_UINT32                   ulRabCnt;                                      /* 需要同步RAB数量                          */
    struct
    {
        VOS_UINT32               ulRabId;                                       /* RAB ID                                   */
        VOS_UINT32               ulCnDomainId;                                  /* 该RAB所属域                              */
        VOS_UINT32               ulRabSyncInfo;                                 /* 该RAB的同步指示                          */
    }NasSyncInfo[RRC_NAS_MAX_RAB_SETUP];
    VOS_UINT32                   ulReason;
}RRMM_SYNC_IND_ST;

typedef struct
{
    VOS_UINT32                   ulCcMsgSize;
    VOS_UINT8                    aucCcMsg[256];
}CC_MSG_FOR_PCLINT_STRU;

typedef struct
{
    MSG_HEADER_STRU              MsgHeader;
    VOS_UINT32                   ulTransactionId;
    CC_MSG_FOR_PCLINT_STRU       RcvCcMsg;
}MMCC_DATA_IND_FOR_PCLINT_STRU;

typedef struct
{
    VOS_UINT32                   ulSsMsgSize;
    VOS_UINT8                    aucSsMsg[256];
}SS_MSG_FOR_PCLINT_STRU;
typedef struct
{
    MSG_HEADER_STRU              MsgHeader;
    VOS_UINT32                   ulTi;
    SS_MSG_FOR_PCLINT_STRU       SsMsg;
}MMSS_DATA_IND_FOR_PCLINT_STRU;

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif                                                                          /* __cpluscplus                             */

#endif



