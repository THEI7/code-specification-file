/* =====================================================
���ʹ����FreeRTOS��ֱ�ӵ���template.start();�������񼴿�
���û��ʹ��FreeRTOS��ֻ��Ҫ���ã�template.tick();
ģ���ļ���ֻ�轫template��Template��TEMPLATE��Ϊ��������־��С�
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
