/**
  ******************************************************************************
  * @file    taskScheduler_cfg.h
  * @author  taoynkkx@github.com
  * @version V1.0
  * @date    2018.7.28
  * @brief   task scheduler
  ******************************************************************************
  * @history
  *
  *
  ******************************************************************************
  */

#ifndef  __TASK_SCHEDULER_CFG_H
#define  __TASK_SCHEDULER_CFG_H

#define tasch_cfg_init()       task_init()
#define tasch_cfg_idle()       task_idle()
#define tasch_cfg_taskX2()
#define tasch_cfg_taskX4()
#define tasch_cfg_taskX8()
#define tasch_cfg_taskX16()
#define tasch_cfg_taskX32()
#define tasch_cfg_taskX64()
#define tasch_cfg_taskX128()   task_128ms()
#define tasch_cfg_taskX256()   task_256ms()
#define tasch_cfg_taskX512()   task_512ms()
#define tasch_cfg_taskX1024()  task_1024ms()

extern void task_init(void);
extern void task_idle(void);
extern void task_128ms(void);
extern void task_256ms(void);
extern void task_512ms(void);
extern void task_1024ms(void);

#endif // __TASK_SCHEDULER_CFG_H
