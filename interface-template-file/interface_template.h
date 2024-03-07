/* =====================================================
如果使用了FreeRTOS则，直接调用template.start();开启任务即可
如果没有使用FreeRTOS则只需要调用，template.tick();
模板文件，只需将template、Template、TEMPLATE改为对象的名字就行。
===================================================== */
#ifndef INTERFACE_TEMPLATE_H
#define INTERFACE_TEMPLATE_H

#include <stdbool.h>

typedef struct template_{
	
	bool isInitialized;
	
	void (*init)(void);

	void (*tick)(void);
	
	#ifdef INC_FREERTOS_H //If FreeRTOS is used
	void (*start)(void);
	
	void (*suspend)(void);
	
	void (*resume)(void);
	#endif
	
	
}template_t ;

extern template_t template; //interface chassis struct

void template_init(void);
void template_tick(void);


#ifdef INC_FREERTOS_H //If FreeRTOS is used

void startChassisTask(void);
void suspendChassisTask(void);
void resumeChassisTask(void);

#endif

#endif
