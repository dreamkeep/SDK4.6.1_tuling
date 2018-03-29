/* Copyright Statement:
 *
 * (C) 2005-2016  MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. ("MediaTek") and/or its licensors.
 * Without the prior written permission of MediaTek and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) MediaTek Software
 * if you have agreed to and been bound by the applicable license agreement with
 * MediaTek ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of MediaTek Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT MEDIATEK SOFTWARE RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#ifndef __TASK_DEF_H__
#define __TASK_DEF_H__

#include "FreeRTOSConfig.h"

typedef enum {
    TASK_PRIORITY_IDLE = 0,                                 /* lowest, special for idle task */
    TASK_PRIORITY_SYSLOG,                                   /* special for syslog task */

    /* User task priority begin, please define your task priority at this interval */
    TASK_PRIORITY_LOW,                                      /* low */
    TASK_PRIORITY_BELOW_NORMAL,                             /* below normal */
    TASK_PRIORITY_NORMAL,                                   /* normal */
    TASK_PRIORITY_ABOVE_NORMAL,                             /* above normal */
    TASK_PRIORITY_HIGH,                                     /* high */
    TASK_PRIORITY_SOFT_REALTIME,                            /* soft real time */
    TASK_PRIORITY_HARD_REALTIME,                            /* hard real time */
    /* User task priority end */

    /*Be careful, the max-priority number can not be bigger than configMAX_PRIORITIES - 1, or kernel will crash!!! */
    TASK_PRIORITY_TIMER = configMAX_PRIORITIES - 1,         /* highest, special for timer task to keep time accuracy */
} task_priority_type_t;

/* part_1: SDK tasks configure infomation, please don't modify */

/*The following is an example to define the XXXX task.
#define XXXX_TASK_NAME "XXXX"
#define XXXX_TASK_STACKSIZE 512
#define XXXX_TASK_PRIO TASK_PRIORITY_LOW
#define XXXX_QUEUE_LENGTH  16
*/

/* for wifi net task */
#define UNIFY_NET_TASK_NAME                 "net"
#define UNIFY_NET_TASK_STACKSIZE            (1024*4) /*unit byte!*/
#define UNIFY_NET_TASK_PRIO                 TASK_PRIORITY_HIGH
#define UNIFY_NET_QUEUE_LENGTH              16

/* for wifi inband task */
#define UNIFY_INBAND_TASK_NAME              "inband"
#define UNIFY_INBAND_TASK_STACKSIZE         (1024*4) /*unit byte!*/
#define UNIFY_INBAND_TASK_PRIO              TASK_PRIORITY_HIGH
#define UNIFY_INBAND_QUEUE_LENGTH           16


/* for smart connection task */
#define UNIFY_SMTCN_TASK_NAME              "smtcn"
#define UNIFY_SMTCN_TASK_STACKSIZE         (512*4) /*unit byte!*/
#define UNIFY_SMTCN_TASK_PRIO              TASK_PRIORITY_NORMAL

/* for multi smart connection */
#define MSC_TASK_NAME                     "msc"
#define MSC_TASK_STACKSIZE                (512*4) /*unit byte!*/
#define MSC_TASK_PRIO                     TASK_PRIORITY_NORMAL

/* for joylink main task */
#define JOYLINK_TASK_NAME                       "joylink"
#define JOYLINK_TASK_STACKSIZE                  (20*1024)
#define JOYLINK_TASK_PRIO                       TASK_PRIORITY_NORMAL

/* for joylink fota download task */
#define JOYLINK_FOTA_DOWNLOAD_TASK_NAME         "FOTADownloadTask"
#define JOYLINK_FOTA_DOWNLOAD_TASK_STACKSIZE    (5*1024)
#define JOYLINK_FOTA_DOWNLOAD_TASK_PRIO         TASK_PRIORITY_NORMAL

/* for airkiss host task */
#define AIRKISS_HOST_TASK_NAME                  "cdrtest thread"
#define AIRKISS_HOST_TASK_STACKSIZE             (1*1024)
#define AIRKISS_HOST_TASK_PRIO                  TASK_PRIORITY_NORMAL

/* for airkiss cloud task */
#define AIRKISS_CLOUD_TASK_NAME                 "cloud thread"
#define AIRKISS_CLOUD_TASK_STACKSIZE            (2*1024)
#define AIRKISS_CLOUD_TASK_PRIO                 TASK_PRIORITY_NORMAL

/* for alink main task */
#define ALINK_TASK_NAME                         "alinK_demo"
#define ALINK_TASK_STACKSIZE                    (6*1024)
#define ALINK_TASK_PRIO                         TASK_PRIORITY_NORMAL

/* for alink button monitor task */
#define ALINK_BUTTON_MONITOR_TASK_NAME          "press_time_monitor"
#define ALINK_BUTTON_MONITOR_TASK_STACKSIZE     (4*1024)
#define ALINK_BUTTON_MONITOR_TASK_PRIO          TASK_PRIORITY_HIGH
#define ALINK_BUTTON_MONITOR_QUEUE_LENGTH       2

/* for alink button monitor task */
#define ALINK_AWS_TASK_NAME                     "aws test thread"
#define ALINK_AWS_TASK_STACKSIZE                (4*1024)
#define ALINK_AWS_TASK_PRIO                     TASK_PRIORITY_HIGH


/* for lwIP task */
#define TCPIP_THREAD_NAME              "lwIP"
#define TCPIP_THREAD_STACKSIZE         (512 * 4)
#define TCPIP_THREAD_PRIO              TASK_PRIORITY_HIGH

/* for ping task */
#define PING_TASK_NAME                 "ping"
#define PING_TASK_STACKSIZE            (512 * 4)
#define PING_TASK_PRIO                 TASK_PRIORITY_NORMAL

/* syslog task definition */
#define SYSLOG_TASK_NAME "SYSLOG"
/*This definition determines whether the port service feature is enabled. If it is not defined, then the port service feature is not supported.*/
#if defined(MTK_PORT_SERVICE_ENABLE)
#define SYSLOG_TASK_STACKSIZE 1024
#else
#define SYSLOG_TASK_STACKSIZE 192
#endif
#define SYSLOG_TASK_PRIO TASK_PRIORITY_SYSLOG
/*MTK_NO_PSRAM_ENABLE: the definition of MTK_NO_PSRAM_ENABLE determines whether the demo uses PSRAM. If it is defined, means no PSRAM in this project.*/
#if (PRODUCT_VERSION == 7687) || (PRODUCT_VERSION == 7697) || (PRODUCT_VERSION == 7686) || (PRODUCT_VERSION == 7682) || (PRODUCT_VERSION == 5932) || defined(MTK_NO_PSRAM_ENABLE)
#define SYSLOG_QUEUE_LENGTH 8
#elif (PRODUCT_VERSION == 2523)
#define SYSLOG_QUEUE_LENGTH 512
#endif

/* for os utilization task */
/*MTK_OS_CPU_UTILIZATION_ENABLE: This definition determines whether enable CPU utilization profiling feature, if enabled, can use AT command on MT25x3 or CLI command on MT76x7 to do CPU utilization profiling.*/
#if defined(MTK_OS_CPU_UTILIZATION_ENABLE)
#define MTK_OS_CPU_UTILIZATION_TASK_NAME "CPU"
#define MTK_OS_CPU_UTILIZATION_STACKSIZE 512
#define MTK_OS_CPU_UTILIZATION_PRIO      TASK_PRIORITY_SOFT_REALTIME
#endif

/* for dhcpd task */
#define DHCPD_TASK_NAME                 "dhcpd"
#define DHCPD_TASK_STACKSIZE            (1024)
#define DHCPD_TASK_PRIO                 TASK_PRIORITY_NORMAL

/* part_2: Application and customer tasks configure information */
/* currently, only UI task and tasks to show example project function which define in apps/project/src/main.c */

/* for create cli */
/*This option is to enable and disable CLI (command line interface) engine.*/
#if defined(MTK_MINICLI_ENABLE)
#define MINICLI_TASK_NAME               "cli"
#define MINICLI_TASK_STACKSIZE          (4096)
#define MINICLI_TASK_PRIO               TASK_PRIORITY_SOFT_REALTIME
#endif

/* for Application task */
#define APP_TASK_NAME                   "user entry"
#define APP_TASK_STACKSIZE              (4*1024)
#define APP_TASK_PRIO                   TASK_PRIORITY_NORMAL

/* for set n9log cli task */
#define N9LOG_TASK_NAME                 "n9log"
#define N9LOG_TASK_STACKSIZE            (512)
#define MAX_N9LOG_SIZE                  (1024)
#define N9LOG_TASK_PRIO                 TASK_PRIORITY_LOW

#endif
