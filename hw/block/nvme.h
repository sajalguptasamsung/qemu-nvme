#ifndef HW_NVME_H
#define HW_NVME_H

typedef struct NvmeBar {
    uint64_t    cap;
    uint32_t    vs;
    uint32_t    intms;
    uint32_t    intmc;
    uint32_t    cc;
    uint32_t    rsvd1;
    uint32_t    csts;
    uint32_t    nssrc;
    uint32_t    aqa;
    uint64_t    asq;
    uint64_t    acq;
} NvmeBar;

enum NvmeCapShift {
    CAP_MQES_SHIFT     = 0,
    CAP_CQR_SHIFT      = 16,
    CAP_AMS_SHIFT      = 17,
    CAP_TO_SHIFT       = 24,
    CAP_DSTRD_SHIFT    = 32,
    CAP_NSSRS_SHIFT    = 33,
    CAP_CSS_SHIFT      = 37,
    CAP_MPSMIN_SHIFT   = 48,
    CAP_MPSMAX_SHIFT   = 52,
};

enum NvmeCapMask {
    CAP_MQES_MASK      = 0xffff,
    CAP_CQR_MASK       = 0x1,
    CAP_AMS_MASK       = 0x3,
    CAP_TO_MASK        = 0xff,
    CAP_DSTRD_MASK     = 0xf,
    CAP_NSSRS_MASK     = 0x1,
    CAP_CSS_MASK       = 0xff,
    CAP_MPSMIN_MASK    = 0xf,
    CAP_MPSMAX_MASK    = 0xf,
};

#define NVME_CAP_MQES(cap)  (((cap) >> CAP_MQES_SHIFT)   & CAP_MQES_MASK)
#define NVME_CAP_CQR(cap)   (((cap) >> CAP_CQR_SHIFT)    & CAP_CQR_MASK)
#define NVME_CAP_AMS(cap)   (((cap) >> CAP_AMS_SHIFT)    & CAP_AMS_MASK)
#define NVME_CAP_TO(cap)    (((cap) >> CAP_TO_SHIFT)     & CAP_TO_MASK)
#define NVME_CAP_DSTRD(cap) (((cap) >> CAP_DSTRD_SHIFT)  & CAP_DSTRD_MASK)
#define NVME_CAP_NSSRS(cap) (((cap) >> CAP_NSSRS_SHIFT)  & CAP_NSSRS_MASK)
#define NVME_CAP_CSS(cap)   (((cap) >> CAP_CSS_SHIFT)    & CAP_CSS_MASK)
#define NVME_CAP_MPSMIN(cap)(((cap) >> CAP_MPSMIN_SHIFT) & CAP_MPSMIN_MASK)
#define NVME_CAP_MPSMAX(cap)(((cap) >> CAP_MPSMAX_SHIFT) & CAP_MPSMAX_MASK)

#define NVME_CAP_SET_MQES(cap, val)   (cap |= (uint64_t)(val & CAP_MQES_MASK)  \
                                                           << CAP_MQES_SHIFT)
#define NVME_CAP_SET_CQR(cap, val)    (cap |= (uint64_t)(val & CAP_CQR_MASK)   \
                                                           << CAP_CQR_SHIFT)
#define NVME_CAP_SET_AMS(cap, val)    (cap |= (uint64_t)(val & CAP_AMS_MASK)   \
                                                           << CAP_AMS_SHIFT)
#define NVME_CAP_SET_TO(cap, val)     (cap |= (uint64_t)(val & CAP_TO_MASK)    \
                                                           << CAP_TO_SHIFT)
#define NVME_CAP_SET_DSTRD(cap, val)  (cap |= (uint64_t)(val & CAP_DSTRD_MASK) \
                                                           << CAP_DSTRD_SHIFT)
#define NVME_CAP_SET_NSSRS(cap, val)  (cap |= (uint64_t)(val & CAP_NSSRS_MASK) \
                                                           << CAP_NSSRS_SHIFT)
#define NVME_CAP_SET_CSS(cap, val)    (cap |= (uint64_t)(val & CAP_CSS_MASK)   \
                                                           << CAP_CSS_SHIFT)
#define NVME_CAP_SET_MPSMIN(cap, val) (cap |= (uint64_t)(val & CAP_MPSMIN_MASK)\
                                                           << CAP_MPSMIN_SHIFT)
#define NVME_CAP_SET_MPSMAX(cap, val) (cap |= (uint64_t)(val & CAP_MPSMAX_MASK)\
                                                            << CAP_MPSMAX_SHIFT)

enum NvmeCcShift {
    CC_EN_SHIFT     = 0,
    CC_CSS_SHIFT    = 4,
    CC_MPS_SHIFT    = 7,
    CC_AMS_SHIFT    = 11,
    CC_SHN_SHIFT    = 14,
    CC_IOSQES_SHIFT = 16,
    CC_IOCQES_SHIFT = 20,
};

enum NvmeCcMask {
    CC_EN_MASK      = 0x1,
    CC_CSS_MASK     = 0x7,
    CC_MPS_MASK     = 0xf,
    CC_AMS_MASK     = 0x7,
    CC_SHN_MASK     = 0x3,
    CC_IOSQES_MASK  = 0xf,
    CC_IOCQES_MASK  = 0xf,
};

#define NVME_CC_EN(cc)     ((cc >> CC_EN_SHIFT)     & CC_EN_MASK)
#define NVME_CC_CSS(cc)    ((cc >> CC_CSS_SHIFT)    & CC_CSS_MASK)
#define NVME_CC_MPS(cc)    ((cc >> CC_MPS_SHIFT)    & CC_MPS_MASK)
#define NVME_CC_AMS(cc)    ((cc >> CC_AMS_SHIFT)    & CC_AMS_MASK)
#define NVME_CC_SHN(cc)    ((cc >> CC_SHN_SHIFT)    & CC_SHN_MASK)
#define NVME_CC_IOSQES(cc) ((cc >> CC_IOSQES_SHIFT) & CC_IOSQES_MASK)
#define NVME_CC_IOCQES(cc) ((cc >> CC_IOCQES_SHIFT) & CC_IOCQES_MASK)

enum NvmeCstsShift {
    CSTS_RDY_SHIFT      = 0,
    CSTS_CFS_SHIFT      = 1,
    CSTS_SHST_SHIFT     = 2,
    CSTS_NSSRO_SHIFT    = 4,
};

enum NvmeCstsMask {
    CSTS_RDY_MASK   = 0x1,
    CSTS_CFS_MASK   = 0x1,
    CSTS_SHST_MASK  = 0x3,
    CSTS_NSSRO_MASK = 0x1,
};

enum NvmeCsts {
    NVME_CSTS_READY         = 1 << CSTS_RDY_SHIFT,
    NVME_CSTS_FAILED        = 1 << CSTS_CFS_SHIFT,
    NVME_CSTS_SHST_NORMAL   = 0 << CSTS_SHST_SHIFT,
    NVME_CSTS_SHST_PROGRESS = 1 << CSTS_SHST_SHIFT,
    NVME_CSTS_SHST_COMPLETE = 2 << CSTS_SHST_SHIFT,
    NVME_CSTS_NSSRO         = 1 << CSTS_NSSRO_SHIFT,
};

#define NVME_CSTS_RDY(csts)     ((csts >> CSTS_RDY_SHIFT)   & CSTS_RDY_MASK)
#define NVME_CSTS_CFS(csts)     ((csts >> CSTS_CFS_SHIFT)   & CSTS_CFS_MASK)
#define NVME_CSTS_SHST(csts)    ((csts >> CSTS_SHST_SHIFT)  & CSTS_SHST_MASK)
#define NVME_CSTS_NSSRO(csts)   ((csts >> CSTS_NSSRO_SHIFT) & CSTS_NSSRO_MASK)

enum NvmeAqaShift {
    AQA_ASQS_SHIFT  = 0,
    AQA_ACQS_SHIFT  = 16,
};

enum NvmeAqaMask {
    AQA_ASQS_MASK   = 0xfff,
    AQA_ACQS_MASK   = 0xfff,
};

#define NVME_AQA_ASQS(aqa) ((aqa >> AQA_ASQS_SHIFT) & AQA_ASQS_MASK)
#define NVME_AQA_ACQS(aqa) ((aqa >> AQA_ACQS_SHIFT) & AQA_ACQS_MASK)

typedef struct NvmeCmd {
    uint8_t     opcode;
    uint8_t     fuse;
    uint16_t    cid;
    uint32_t    nsid;
    uint64_t    res1;
    uint64_t    mptr;
    uint64_t    prp1;
    uint64_t    prp2;
    uint32_t    cdw10;
    uint32_t    cdw11;
    uint32_t    cdw12;
    uint32_t    cdw13;
    uint32_t    cdw14;
    uint32_t    cdw15;
} NvmeCmd;

enum NvmeAdminCommands {
    NVME_ADM_CMD_DELETE_SQ      = 0x00,
    NVME_ADM_CMD_CREATE_SQ      = 0x01,
    NVME_ADM_CMD_GET_LOG_PAGE   = 0x02,
    NVME_ADM_CMD_DELETE_CQ      = 0x04,
    NVME_ADM_CMD_CREATE_CQ      = 0x05,
    NVME_ADM_CMD_IDENTIFY       = 0x06,
    NVME_ADM_CMD_ABORT          = 0x08,
    NVME_ADM_CMD_SET_FEATURES   = 0x09,
    NVME_ADM_CMD_GET_FEATURES   = 0x0a,
    NVME_ADM_CMD_ASYNC_EV_REQ   = 0x0c,
    NVME_ADM_CMD_ACTIVATE_FW    = 0x10,
    NVME_ADM_CMD_DOWNLOAD_FW    = 0x11,
    NVME_ADM_CMD_FORMAT_NVM     = 0x80,
    NVME_ADM_CMD_SECURITY_SEND  = 0x81,
    NVME_ADM_CMD_SECURITY_RECV  = 0x82,
};

enum LnvmeAdminCommands {
    LNVME_ADM_CMD_IDENTIFY          = 0xc0,
    LNVME_ADM_CMD_IDENTIFY_CHANNEL  = 0xc1,
    LNVME_ADM_CMD_GET_FEATURES      = 0xc2,
    LNVME_ADM_CMD_SET_FEATURES      = 0xc3,
    LNVME_ADM_CMD_GET_L2P_TBL       = 0xc4,
    LNVME_ADM_CMD_GET_P2L_TBL       = 0xc5,
    LNVME_ADM_CMD_FLUSH_TBLS        = 0xc6,
};

enum NvmeIoCommands {
    NVME_CMD_FLUSH              = 0x00,
    NVME_CMD_WRITE              = 0x01,
    NVME_CMD_READ               = 0x02,
    NVME_CMD_WRITE_UNCOR        = 0x04,
    NVME_CMD_COMPARE            = 0x05,
    NVME_CMD_DSM                = 0x09,
};

enum LnvmeDmCommands {
    LNVME_CMD_ERASE_SYNC        = 0x80,
    LNVME_CMD_ERASE_ASYNC       = 0x81,
};

typedef struct LnvmeGetTbl {
    uint8_t opcode;
    uint8_t flags;
    uint16_t cid;
    uint32_t nsid;
    uint32_t rsvd1[4];
    uint64_t prp1;
    uint64_t prp2;
    uint64_t slba;
    uint16_t nlb;
    uint16_t rsvd2[7];
} LnvmeGetTbl;

typedef struct NvmeDeleteQ {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    rsvd1[9];
    uint16_t    qid;
    uint16_t    rsvd10;
    uint32_t    rsvd11[5];
} NvmeDeleteQ;

typedef struct NvmeCreateCq {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    rsvd1[5];
    uint64_t    prp1;
    uint64_t    rsvd8;
    uint16_t    cqid;
    uint16_t    qsize;
    uint16_t    cq_flags;
    uint16_t    irq_vector;
    uint32_t    rsvd12[4];
} NvmeCreateCq;

#define NVME_CQ_FLAGS_PC(cq_flags)  (cq_flags & 0x1)
#define NVME_CQ_FLAGS_IEN(cq_flags) ((cq_flags >> 1) & 0x1)

typedef struct NvmeCreateSq {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    rsvd1[5];
    uint64_t    prp1;
    uint64_t    rsvd8;
    uint16_t    sqid;
    uint16_t    qsize;
    uint16_t    sq_flags;
    uint16_t    cqid;
    uint32_t    rsvd12[4];
} NvmeCreateSq;

#define NVME_SQ_FLAGS_PC(sq_flags)      (sq_flags & 0x1)
#define NVME_SQ_FLAGS_QPRIO(sq_flags)   ((sq_flags >> 1) & 0x3)

enum NvmeQueueFlags {
    NVME_Q_PC           = 1,
    NVME_Q_PRIO_URGENT  = 0,
    NVME_Q_PRIO_HIGH    = 1,
    NVME_Q_PRIO_NORMAL  = 2,
    NVME_Q_PRIO_LOW     = 3,
};

typedef struct NvmeIdentify {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    nsid;
    uint64_t    rsvd2[2];
    uint64_t    prp1;
    uint64_t    prp2;
    uint32_t    cns;
    uint32_t    rsvd11[5];
} NvmeIdentify;

typedef struct NvmeRwCmd {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    nsid;
    uint64_t    rsvd2;
    uint64_t    mptr;
    uint64_t    prp1;
    uint64_t    prp2;
    uint64_t    slba;
    uint16_t    nlb;
    uint16_t    control;
    uint32_t    dsmgmt;
    uint32_t    reftag;
    uint16_t    apptag;
    uint16_t    appmask;
} NvmeRwCmd;

enum {
    NVME_RW_LR                  = 1 << 15,
    NVME_RW_FUA                 = 1 << 14,
    NVME_RW_DSM_FREQ_UNSPEC     = 0,
    NVME_RW_DSM_FREQ_TYPICAL    = 1,
    NVME_RW_DSM_FREQ_RARE       = 2,
    NVME_RW_DSM_FREQ_READS      = 3,
    NVME_RW_DSM_FREQ_WRITES     = 4,
    NVME_RW_DSM_FREQ_RW         = 5,
    NVME_RW_DSM_FREQ_ONCE       = 6,
    NVME_RW_DSM_FREQ_PREFETCH   = 7,
    NVME_RW_DSM_FREQ_TEMP       = 8,
    NVME_RW_DSM_LATENCY_NONE    = 0 << 4,
    NVME_RW_DSM_LATENCY_IDLE    = 1 << 4,
    NVME_RW_DSM_LATENCY_NORM    = 2 << 4,
    NVME_RW_DSM_LATENCY_LOW     = 3 << 4,
    NVME_RW_DSM_SEQ_REQ         = 1 << 6,
    NVME_RW_DSM_COMPRESSED      = 1 << 7,
    NVME_RW_PRINFO_PRACT        = 1 << 13,
    NVME_RW_PRINFO_PRCHK_GUARD  = 1 << 12,
    NVME_RW_PRINFO_PRCHK_APP    = 1 << 11,
    NVME_RW_PRINFO_PRCHK_REF    = 1 << 10,
};

typedef struct NvmeDsmCmd {
    uint8_t     opcode;
    uint8_t     flags;
    uint16_t    cid;
    uint32_t    nsid;
    uint64_t    rsvd2[2];
    uint64_t    prp1;
    uint64_t    prp2;
    uint32_t    nr;
    uint32_t    attributes;
    uint32_t    rsvd12[4];
} NvmeDsmCmd;

enum {
    NVME_DSMGMT_IDR = 1 << 0,
    NVME_DSMGMT_IDW = 1 << 1,
    NVME_DSMGMT_AD  = 1 << 2,
};

typedef struct NvmeDsmRange {
    uint32_t    cattr;
    uint32_t    nlb;
    uint64_t    slba;
} NvmeDsmRange;

enum NvmeAsyncEventRequest {
    NVME_AER_TYPE_ERROR                     = 0,
    NVME_AER_TYPE_SMART                     = 1,
    NVME_AER_TYPE_IO_SPECIFIC               = 6,
    NVME_AER_TYPE_VENDOR_SPECIFIC           = 7,
    NVME_AER_INFO_ERR_INVALID_SQ            = 0,
    NVME_AER_INFO_ERR_INVALID_DB            = 1,
    NVME_AER_INFO_ERR_DIAG_FAIL             = 2,
    NVME_AER_INFO_ERR_PERS_INTERNAL_ERR     = 3,
    NVME_AER_INFO_ERR_TRANS_INTERNAL_ERR    = 4,
    NVME_AER_INFO_ERR_FW_IMG_LOAD_ERR       = 5,
    NVME_AER_INFO_SMART_RELIABILITY         = 0,
    NVME_AER_INFO_SMART_TEMP_THRESH         = 1,
    NVME_AER_INFO_SMART_SPARE_THRESH        = 2,
};

typedef struct NvmeAerResult {
    uint8_t event_type;
    uint8_t event_info;
    uint8_t log_page;
    uint8_t resv;
} NvmeAerResult;

typedef struct NvmeCqe {
    uint32_t    result;
    uint32_t    rsvd;
    uint16_t    sq_head;
    uint16_t    sq_id;
    uint16_t    cid;
    uint16_t    status;
} NvmeCqe;

enum NvmeStatusCodes {
    NVME_SUCCESS                = 0x0000,
    NVME_INVALID_OPCODE         = 0x0001,
    NVME_INVALID_FIELD          = 0x0002,
    NVME_CID_CONFLICT           = 0x0003,
    NVME_DATA_TRAS_ERROR        = 0x0004,
    NVME_POWER_LOSS_ABORT       = 0x0005,
    NVME_INTERNAL_DEV_ERROR     = 0x0006,
    NVME_CMD_ABORT_REQ          = 0x0007,
    NVME_CMD_ABORT_SQ_DEL       = 0x0008,
    NVME_CMD_ABORT_FAILED_FUSE  = 0x0009,
    NVME_CMD_ABORT_MISSING_FUSE = 0x000a,
    NVME_INVALID_NSID           = 0x000b,
    NVME_CMD_SEQ_ERROR          = 0x000c,
    NVME_LBA_RANGE              = 0x0080,
    NVME_CAP_EXCEEDED           = 0x0081,
    NVME_NS_NOT_READY           = 0x0082,
    NVME_NS_RESV_CONFLICT       = 0x0083,
    NVME_INVALID_CQID           = 0x0100,
    NVME_INVALID_QID            = 0x0101,
    NVME_MAX_QSIZE_EXCEEDED     = 0x0102,
    NVME_ACL_EXCEEDED           = 0x0103,
    NVME_RESERVED               = 0x0104,
    NVME_AER_LIMIT_EXCEEDED     = 0x0105,
    NVME_INVALID_FW_SLOT        = 0x0106,
    NVME_INVALID_FW_IMAGE       = 0x0107,
    NVME_INVALID_IRQ_VECTOR     = 0x0108,
    NVME_INVALID_LOG_ID         = 0x0109,
    NVME_INVALID_FORMAT         = 0x010a,
    NVME_FW_REQ_RESET           = 0x010b,
    NVME_INVALID_QUEUE_DEL      = 0x010c,
    NVME_FID_NOT_SAVEABLE       = 0x010d,
    NVME_FID_NOT_NSID_SPEC      = 0x010f,
    NVME_FW_REQ_SUSYSTEM_RESET  = 0x0110,
    NVME_CONFLICTING_ATTRS      = 0x0180,
    NVME_INVALID_PROT_INFO      = 0x0181,
    NVME_WRITE_TO_RO            = 0x0182,
    NVME_WRITE_FAULT            = 0x0280,
    NVME_UNRECOVERED_READ       = 0x0281,
    NVME_E2E_GUARD_ERROR        = 0x0282,
    NVME_E2E_APP_ERROR          = 0x0283,
    NVME_E2E_REF_ERROR          = 0x0284,
    NVME_CMP_FAILURE            = 0x0285,
    NVME_ACCESS_DENIED          = 0x0286,
    NVME_MORE                   = 0x2000,
    NVME_DNR                    = 0x4000,
    NVME_NO_COMPLETE            = 0xffff,
};

typedef struct NvmeFwSlotInfoLog {
    uint8_t     afi;
    uint8_t     reserved1[7];
    uint8_t     frs1[8];
    uint8_t     frs2[8];
    uint8_t     frs3[8];
    uint8_t     frs4[8];
    uint8_t     frs5[8];
    uint8_t     frs6[8];
    uint8_t     frs7[8];
    uint8_t     reserved2[448];
} NvmeFwSlotInfoLog;

typedef struct NvmeErrorLog {
    uint64_t    error_count;
    uint16_t    sqid;
    uint16_t    cid;
    uint16_t    status_field;
    uint16_t    param_error_location;
    uint64_t    lba;
    uint32_t    nsid;
    uint8_t     vs;
    uint8_t     resv[35];
} NvmeErrorLog;

typedef struct NvmeSmartLog {
    uint8_t     critical_warning;
    uint8_t     temperature[2];
    uint8_t     available_spare;
    uint8_t     available_spare_threshold;
    uint8_t     percentage_used;
    uint8_t     reserved1[26];
    uint64_t    data_units_read[2];
    uint64_t    data_units_written[2];
    uint64_t    host_read_commands[2];
    uint64_t    host_write_commands[2];
    uint64_t    controller_busy_time[2];
    uint64_t    power_cycles[2];
    uint64_t    power_on_hours[2];
    uint64_t    unsafe_shutdowns[2];
    uint64_t    media_errors[2];
    uint64_t    number_of_error_log_entries[2];
    uint8_t     reserved2[320];
} NvmeSmartLog;

enum NvmeSmartWarn {
    NVME_SMART_SPARE                  = 1 << 0,
    NVME_SMART_TEMPERATURE            = 1 << 1,
    NVME_SMART_RELIABILITY            = 1 << 2,
    NVME_SMART_MEDIA_READ_ONLY        = 1 << 3,
    NVME_SMART_FAILED_VOLATILE_MEDIA  = 1 << 4,
};

enum LogIdentifier {
    NVME_LOG_ERROR_INFO     = 0x01,
    NVME_LOG_SMART_INFO     = 0x02,
    NVME_LOG_FW_SLOT_INFO   = 0x03,
};

typedef struct NvmePSD {
    uint16_t    mp;
    uint16_t    reserved;
    uint32_t    enlat;
    uint32_t    exlat;
    uint8_t     rrt;
    uint8_t     rrl;
    uint8_t     rwt;
    uint8_t     rwl;
    uint8_t     resv[16];
} NvmePSD;

typedef struct NvmeIdCtrl {
    uint16_t    vid;
    uint16_t    ssvid;
    uint8_t     sn[20];
    uint8_t     mn[40];
    uint8_t     fr[8];
    uint8_t     rab;
    uint8_t     ieee[3];
    uint8_t     cmic;
    uint8_t     mdts;
    uint8_t     rsvd255[178];
    uint16_t    oacs;
    uint8_t     acl;
    uint8_t     aerl;
    uint8_t     frmw;
    uint8_t     lpa;
    uint8_t     elpe;
    uint8_t     npss;
    uint8_t     rsvd511[248];
    uint8_t     sqes;
    uint8_t     cqes;
    uint16_t    rsvd515;
    uint32_t    nn;
    uint16_t    oncs;
    uint16_t    fuses;
    uint8_t     fna;
    uint8_t     vwc;
    uint16_t    awun;
    uint16_t    awupf;
    uint8_t     rsvd703[174];
    uint8_t     rsvd2047[1344];
    NvmePSD     psd[32];
    uint8_t     vs[1024];
} NvmeIdCtrl;

enum LnvmeIoSched {
    LNVME_IOSCHED_CHANNEL	= 0,
    LNVME_IOSCHED_CHIP		= 1,
};

typedef struct LnvmeIdChannel {
    uint64_t    queue_size;
    uint64_t	gran_read;
    uint64_t	gran_write;
    uint64_t	gran_erase;
    uint64_t    oob_size;
    uint32_t    t_r;
    uint32_t    t_sqr;
    uint32_t    t_w;
    uint32_t    t_sqw;
    uint32_t    t_e;
    uint8_t     io_sched;
    uint64_t    laddr_begin;
    uint64_t    laddr_end;
    uint8_t     unused[4019];
} QEMU_PACKED LnvmeIdChannel;

enum LnvmeNvmType {
    NVM_BLOCK_ADDRESSABLE     = 0,
    NVM_BYTE_ADDRESSABLE      = 1,
};

typedef struct LnvmeIdCtrl {
    uint16_t           ver_id;
    uint8_t            nvm_type;
    uint16_t           nchannels;
    uint8_t            unused[4091];
} QEMU_PACKED LnvmeIdCtrl;

enum LnvmeResponsibility {
    LNVME_R_L2P         = 0,
    LNVME_R_P2L         = 1,
    LNVME_R_GC          = 2,
    LNVME_R_ECC         = 3,
};

enum LnvmeExtension {
    LNVME_EXT_BLK_MV    = 1 << 0,
    LNVME_EXT_CPB       = 1 << 1,
    LNVME_EXT_PS        = 2 << 2,
};

enum NvmeIdCtrlOacs {
    NVME_OACS_SECURITY  = 1 << 0,
    NVME_OACS_FORMAT    = 1 << 1,
    NVME_OACS_FW        = 1 << 2,
    NVME_OACS_LNVME_DEV = 1 << 3,
};

enum NvmeIdCtrlOncs {
    NVME_ONCS_COMPARE       = 1 << 0,
    NVME_ONCS_WRITE_UNCORR  = 1 << 1,
    NVME_ONCS_DSM           = 1 << 2,
    NVME_ONCS_WRITE_ZEROS   = 1 << 3,
    NVME_ONCS_FEATURES      = 1 << 4,
    NVME_ONCS_RESRVATIONS   = 1 << 5,
};

#define NVME_CTRL_SQES_MIN(sqes) ((sqes) & 0xf)
#define NVME_CTRL_SQES_MAX(sqes) (((sqes) >> 4) & 0xf)
#define NVME_CTRL_CQES_MIN(cqes) ((cqes) & 0xf)
#define NVME_CTRL_CQES_MAX(cqes) (((cqes) >> 4) & 0xf)

typedef struct NvmeFeatureVal {
    uint32_t    arbitration;
    uint32_t    power_mgmt;
    uint32_t    temp_thresh;
    uint32_t    err_rec;
    uint32_t    volatile_wc;
    uint32_t    num_queues;
    uint32_t    int_coalescing;
    uint32_t    *int_vector_config;
    uint32_t    write_atomicity;
    uint32_t    async_config;
    uint32_t    sw_prog_marker;
} NvmeFeatureVal;

#define NVME_ARB_AB(arb)    (arb & 0x7)
#define NVME_ARB_LPW(arb)   ((arb >> 8) & 0xff)
#define NVME_ARB_MPW(arb)   ((arb >> 16) & 0xff)
#define NVME_ARB_HPW(arb)   ((arb >> 24) & 0xff)

#define NVME_INTC_THR(intc)     (intc & 0xff)
#define NVME_INTC_TIME(intc)    ((intc >> 8) & 0xff)

enum NvmeFeatureIds {
    NVME_ARBITRATION                = 0x1,
    NVME_POWER_MANAGEMENT           = 0x2,
    NVME_LBA_RANGE_TYPE             = 0x3,
    NVME_TEMPERATURE_THRESHOLD      = 0x4,
    NVME_ERROR_RECOVERY             = 0x5,
    NVME_VOLATILE_WRITE_CACHE       = 0x6,
    NVME_NUMBER_OF_QUEUES           = 0x7,
    NVME_INTERRUPT_COALESCING       = 0x8,
    NVME_INTERRUPT_VECTOR_CONF      = 0x9,
    NVME_WRITE_ATOMICITY            = 0xa,
    NVME_ASYNCHRONOUS_EVENT_CONF    = 0xb,
    NVME_SOFTWARE_PROGRESS_MARKER   = 0x80
};

typedef struct NvmeRangeType {
    uint8_t     type;
    uint8_t     attributes;
    uint8_t     rsvd2[14];
    uint64_t    slba;
    uint64_t    nlb;
    uint8_t     guid[16];
    uint8_t     rsvd48[16];
} NvmeRangeType;

typedef struct NvmeLBAF {
    uint16_t    ms;
    uint8_t     ds;
    uint8_t     rp;
} NvmeLBAF;

typedef struct NvmeIdNs {
    uint64_t    nsze;
    uint64_t    ncap;
    uint64_t    nuse;
    uint8_t     nsfeat;
    uint8_t     nlbaf;
    uint8_t     flbas;
    uint8_t     mc;
    uint8_t     dpc;
    uint8_t     dps;
    uint8_t     res30[98];
    NvmeLBAF    lbaf[16];
    uint8_t     res192[192];
    uint8_t     vs[3712];
} NvmeIdNs;

#define NVME_ID_NS_NSFEAT_THIN(nsfeat)      ((nsfeat & 0x1))
#define NVME_ID_NS_FLBAS_EXTENDED(flbas)    ((flbas >> 4) & 0x1)
#define NVME_ID_NS_FLBAS_INDEX(flbas)       ((flbas & 0xf))
#define NVME_ID_NS_MC_SEPARATE(mc)          ((mc >> 1) & 0x1)
#define NVME_ID_NS_MC_EXTENDED(mc)          ((mc & 0x1))
#define NVME_ID_NS_DPC_LAST_EIGHT(dpc)      ((dpc >> 4) & 0x1)
#define NVME_ID_NS_DPC_FIRST_EIGHT(dpc)     ((dpc >> 3) & 0x1)
#define NVME_ID_NS_DPC_TYPE_3(dpc)          ((dpc >> 2) & 0x1)
#define NVME_ID_NS_DPC_TYPE_2(dpc)          ((dpc >> 1) & 0x1)
#define NVME_ID_NS_DPC_TYPE_1(dpc)          ((dpc & 0x1))
#define NVME_ID_NS_DPC_TYPE_MASK            0x7

enum NvmeIdNsDps {
    DPS_TYPE_NONE   = 0,
    DPS_TYPE_1      = 1,
    DPS_TYPE_2      = 2,
    DPS_TYPE_3      = 3,
    DPS_TYPE_MASK   = 0x7,
    DPS_FIRST_EIGHT = 8,
};

static inline void _nvme_check_size(void)
{
    QEMU_BUILD_BUG_ON(sizeof(NvmeAerResult) != 4);
    QEMU_BUILD_BUG_ON(sizeof(NvmeCqe) != 16);
    QEMU_BUILD_BUG_ON(sizeof(NvmeDsmRange) != 16);
    QEMU_BUILD_BUG_ON(sizeof(NvmeCmd) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeDeleteQ) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeCreateCq) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeCreateSq) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeIdentify) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeRwCmd) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeDsmCmd) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeRangeType) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeErrorLog) != 64);
    QEMU_BUILD_BUG_ON(sizeof(NvmeFwSlotInfoLog) != 512);
    QEMU_BUILD_BUG_ON(sizeof(NvmeSmartLog) != 512);
    QEMU_BUILD_BUG_ON(sizeof(NvmeIdCtrl) != 4096);
    QEMU_BUILD_BUG_ON(sizeof(NvmeIdNs) != 4096);
}

typedef struct NvmeAsyncEvent {
    QSIMPLEQ_ENTRY(NvmeAsyncEvent) entry;
    NvmeAerResult result;
} NvmeAsyncEvent;

typedef struct NvmeRequest {
    struct NvmeSQueue       *sq;
    struct NvmeNamespace    *ns;
    BlockDriverAIOCB        *aiocb;
    uint16_t                status;
    uint64_t                slba;
    uint16_t                is_write;
    uint16_t                nlb;
    uint16_t                ctrl;
    uint64_t                meta_size;
    uint64_t                mptr;
    void                    *meta_buf;
    uint32_t                host_lba;
    NvmeCqe                 cqe;
    BlockAcctCookie         acct;
    QEMUSGList              qsg;
    QTAILQ_ENTRY(NvmeRequest)entry;
} NvmeRequest;

typedef struct NvmeSQueue {
    struct NvmeCtrl *ctrl;
    uint8_t     phys_contig;
    uint8_t     arb_burst;
    uint16_t    sqid;
    uint16_t    cqid;
    uint32_t    head;
    uint32_t    tail;
    uint32_t    size;
    uint64_t    dma_addr;
    uint64_t    completed;
    uint64_t    *prp_list;
    QEMUTimer   *timer;
    NvmeRequest *io_req;
    QTAILQ_HEAD(sq_req_list, NvmeRequest) req_list;
    QTAILQ_HEAD(out_req_list, NvmeRequest) out_req_list;
    QTAILQ_ENTRY(NvmeSQueue) entry;
} NvmeSQueue;

typedef struct NvmeCQueue {
    struct NvmeCtrl *ctrl;
    uint8_t     phys_contig;
    uint8_t     phase;
    uint8_t     cqes_pending;
    uint16_t    cqid;
    uint16_t    irq_enabled;
    uint32_t    head;
    uint32_t    tail;
    uint32_t    vector;
    uint32_t    size;
    uint64_t    dma_addr;
    uint64_t    *prp_list;
    QEMUTimer   *timer;
    QTAILQ_HEAD(sq_list, NvmeSQueue) sq_list;
    QTAILQ_HEAD(cq_req_list, NvmeRequest) req_list;
} NvmeCQueue;

typedef struct NvmeNamespace {
    struct NvmeCtrl *ctrl;
    NvmeIdNs        id_ns;
    NvmeRangeType   lba_range[64];
    unsigned long   *util;
    unsigned long   *uncorrectable;
    uint32_t        id;
    uint64_t        start_block;
    uint64_t        meta_start_offset;
    uint64_t        tbl_dsk_start_offset;
    uint32_t        tbl_entries;
    uint32_t        *tbl;
} NvmeNamespace;

#define TYPE_NVME "nvme"
#define NVME(obj) \
        OBJECT_CHECK(NvmeCtrl, (obj), TYPE_NVME)

typedef struct LnvmeCtrl {
    LnvmeIdCtrl     id_ctrl;
    uint64_t        features[8];
    LnvmeIdChannel  *channels;
} LnvmeCtrl;

enum LnvmeFeatures {
    R_L2P_MAPPING	= 0U,
    R_P2L_MAPPING	= 1U,
    R_GC		= 2U,
    R_ECC		= 3U,
    E_BLK_MOVE		= 256U,
    E_NVM_COPY_BACK	= 257U,
    E_SAFE_SHUTDOWN	= 258U,
};

typedef struct NvmeCtrl {
    PCIDevice    parent_obj;
    MemoryRegion iomem;
    NvmeBar      bar;
    BlockConf    conf;

    time_t      start_time;
    uint16_t    temperature;
    uint16_t    page_size;
    uint16_t    page_bits;
    uint16_t    max_prp_ents;
    uint16_t    cqe_size;
    uint16_t    sqe_size;
    uint16_t    oacs;
    uint16_t    oncs;
    uint32_t    reg_size;
    uint32_t    num_namespaces;
    uint32_t    num_queues;
    uint32_t    max_q_ents;
    uint64_t    ns_size;
    uint8_t     db_stride;
    uint8_t     aerl;
    uint8_t     acl;
    uint8_t     elpe;
    uint8_t     elp_index;
    uint8_t     error_count;
    uint8_t     mdts;
    uint8_t     cqr;
    uint8_t     max_sqes;
    uint8_t     max_cqes;
    uint8_t     meta;
    uint8_t     vwc;
    uint8_t     mc;
    uint8_t     dpc;
    uint8_t     dps;
    uint8_t     nlbaf;
    uint8_t     extended;
    uint8_t     lba_index;
    uint8_t     mpsmin;
    uint8_t     mpsmax;
    uint8_t     intc;
    uint8_t     intc_thresh;
    uint8_t     intc_time;
    uint8_t     outstanding_aers;
    uint8_t     temp_warn_issued;
    uint8_t     num_errors;
    uint8_t     cqes_pending;

    char            *serial;
    NvmeErrorLog    *elpes;
    NvmeRequest     **aer_reqs;
    NvmeNamespace   *namespaces;
    NvmeSQueue      **sq;
    NvmeCQueue      **cq;
    NvmeSQueue      admin_sq;
    NvmeCQueue      admin_cq;
    NvmeFeatureVal  features;
    NvmeIdCtrl      id_ctrl;

    QSIMPLEQ_HEAD(aer_queue, NvmeAsyncEvent) aer_queue;
    QEMUTimer   *aer_timer;
    uint8_t     aer_mask;

    LnvmeCtrl     lnvme_ctrl;
} NvmeCtrl;

typedef struct NvmeDifTuple {
    uint16_t guard_tag;
    uint16_t app_tag;
    uint32_t ref_tag;
} NvmeDifTuple;

/* Copied from Linux, lib/crc-t10dif.c */
static const uint16_t t10_dif_crc_table[256] = {
    0x0000, 0x8BB7, 0x9CD9, 0x176E, 0xB205, 0x39B2, 0x2EDC, 0xA56B,
    0xEFBD, 0x640A, 0x7364, 0xF8D3, 0x5DB8, 0xD60F, 0xC161, 0x4AD6,
    0x54CD, 0xDF7A, 0xC814, 0x43A3, 0xE6C8, 0x6D7F, 0x7A11, 0xF1A6,
    0xBB70, 0x30C7, 0x27A9, 0xAC1E, 0x0975, 0x82C2, 0x95AC, 0x1E1B,
    0xA99A, 0x222D, 0x3543, 0xBEF4, 0x1B9F, 0x9028, 0x8746, 0x0CF1,
    0x4627, 0xCD90, 0xDAFE, 0x5149, 0xF422, 0x7F95, 0x68FB, 0xE34C,
    0xFD57, 0x76E0, 0x618E, 0xEA39, 0x4F52, 0xC4E5, 0xD38B, 0x583C,
    0x12EA, 0x995D, 0x8E33, 0x0584, 0xA0EF, 0x2B58, 0x3C36, 0xB781,
    0xD883, 0x5334, 0x445A, 0xCFED, 0x6A86, 0xE131, 0xF65F, 0x7DE8,
    0x373E, 0xBC89, 0xABE7, 0x2050, 0x853B, 0x0E8C, 0x19E2, 0x9255,
    0x8C4E, 0x07F9, 0x1097, 0x9B20, 0x3E4B, 0xB5FC, 0xA292, 0x2925,
    0x63F3, 0xE844, 0xFF2A, 0x749D, 0xD1F6, 0x5A41, 0x4D2F, 0xC698,
    0x7119, 0xFAAE, 0xEDC0, 0x6677, 0xC31C, 0x48AB, 0x5FC5, 0xD472,
    0x9EA4, 0x1513, 0x027D, 0x89CA, 0x2CA1, 0xA716, 0xB078, 0x3BCF,
    0x25D4, 0xAE63, 0xB90D, 0x32BA, 0x97D1, 0x1C66, 0x0B08, 0x80BF,
    0xCA69, 0x41DE, 0x56B0, 0xDD07, 0x786C, 0xF3DB, 0xE4B5, 0x6F02,
    0x3AB1, 0xB106, 0xA668, 0x2DDF, 0x88B4, 0x0303, 0x146D, 0x9FDA,
    0xD50C, 0x5EBB, 0x49D5, 0xC262, 0x6709, 0xECBE, 0xFBD0, 0x7067,
    0x6E7C, 0xE5CB, 0xF2A5, 0x7912, 0xDC79, 0x57CE, 0x40A0, 0xCB17,
    0x81C1, 0x0A76, 0x1D18, 0x96AF, 0x33C4, 0xB873, 0xAF1D, 0x24AA,
    0x932B, 0x189C, 0x0FF2, 0x8445, 0x212E, 0xAA99, 0xBDF7, 0x3640,
    0x7C96, 0xF721, 0xE04F, 0x6BF8, 0xCE93, 0x4524, 0x524A, 0xD9FD,
    0xC7E6, 0x4C51, 0x5B3F, 0xD088, 0x75E3, 0xFE54, 0xE93A, 0x628D,
    0x285B, 0xA3EC, 0xB482, 0x3F35, 0x9A5E, 0x11E9, 0x0687, 0x8D30,
    0xE232, 0x6985, 0x7EEB, 0xF55C, 0x5037, 0xDB80, 0xCCEE, 0x4759,
    0x0D8F, 0x8638, 0x9156, 0x1AE1, 0xBF8A, 0x343D, 0x2353, 0xA8E4,
    0xB6FF, 0x3D48, 0x2A26, 0xA191, 0x04FA, 0x8F4D, 0x9823, 0x1394,
    0x5942, 0xD2F5, 0xC59B, 0x4E2C, 0xEB47, 0x60F0, 0x779E, 0xFC29,
    0x4BA8, 0xC01F, 0xD771, 0x5CC6, 0xF9AD, 0x721A, 0x6574, 0xEEC3,
    0xA415, 0x2FA2, 0x38CC, 0xB37B, 0x1610, 0x9DA7, 0x8AC9, 0x017E,
    0x1F65, 0x94D2, 0x83BC, 0x080B, 0xAD60, 0x26D7, 0x31B9, 0xBA0E,
    0xF0D8, 0x7B6F, 0x6C01, 0xE7B6, 0x42DD, 0xC96A, 0xDE04, 0x55B3
};

static uint16_t crc_t10dif(const unsigned char *buffer, size_t len)
{
    uint16_t crc = 0;
    unsigned int i;

    for (i = 0 ; i < len ; i++) {
        crc = (crc << 8) ^ t10_dif_crc_table[((crc >> 8) ^ buffer[i]) & 0xff];
    }

    return crc;
}
/* End lib/crc-t10dif.c */

#endif /* HW_NVME_H */
