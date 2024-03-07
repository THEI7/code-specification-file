#include "interface_template.h"

/* 0. Interface structure config -------------------------------------------------- */
template_t template = {
	
	false,
	
	template_init,
	
	template_tick,
	
	#ifdef INC_FREERTOS_H //If FreeRTOS is used
	startTemplateTask,
	
	suspendTemplateTask,
	
	resumeTemplateTask,
	#endif
};

/* 1. Template init task -------------------------------------------------- */
void template_init(void)
{
    /*initializeTask：放置初始化任务*/
	
	template.isInitialized = true;
	
}

/* 2. Template run task -------------------------------------------------- */
void template_tick(void)
{
	/*0.Check the state*/
	if(template.isInitialized!=true)template.init();

    /*tickTask：调度任务*/

}

/* 3. FreeRTOS interface -------------------------------------------------- */
#ifdef INC_FREERTOS_H //If FreeRTOS is used, the following interfaces are available
//template task
void ThreadTemplateUpdate(void* argument)
{
	for(;;)
	{	
		template.tick();
		
		osDelay(1);//1000hz
	}
}

//Configure task parameters
osThreadId_t templateHandle;

const osThreadAttr_t templateTask_attributes = {
				.name = "templateTask",
				.stack_size = 1024*2, /*Usage: 1024*8  Bytes stack*/
				.priority = (osPriority_t) osPriorityNormal,/*should >= Normal*/
};
//start task 
void startTemplateTask(void)
{
	templateHandle = osThreadNew(ThreadTemplateUpdate, NULL, &templateTask_attributes);
}
//suspend task 
void suspendTemplateTask(void)
{
	vTaskSuspend(templateHandle);
}
//resume task 
void resumeTemplateTask(void)
{
	vTaskResume(templateHandle);
}
#endif
