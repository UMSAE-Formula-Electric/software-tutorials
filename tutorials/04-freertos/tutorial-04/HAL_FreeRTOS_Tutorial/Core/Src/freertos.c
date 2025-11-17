/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern UART_HandleTypeDef huart2;
/* USER CODE END Variables */
/* Definitions for queueAppendTask */
osThreadId_t queueAppendTaskHandle;
const osThreadAttr_t queueAppendTask_attributes = {
  .name = "queueAppendTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for queueRemoveTask */
osThreadId_t queueRemoveTaskHandle;
const osThreadAttr_t queueRemoveTask_attributes = {
  .name = "queueRemoveTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for coolQueue */
osMessageQueueId_t coolQueueHandle;
const osMessageQueueAttr_t coolQueue_attributes = {
  .name = "coolQueue"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartQueueAppendTask(void *argument);
void StartQueueRemoveTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of coolQueue */
  coolQueueHandle = osMessageQueueNew (8, sizeof(uint16_t), &coolQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of queueAppendTask */
  queueAppendTaskHandle = osThreadNew(StartQueueAppendTask, NULL, &queueAppendTask_attributes);

  /* creation of queueRemoveTask */
  queueRemoveTaskHandle = osThreadNew(StartQueueRemoveTask, NULL, &queueRemoveTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartQueueAppendTask */
/**
  * @brief  Function implementing the queueAppendTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartQueueAppendTask */
void StartQueueAppendTask(void *argument)
{
  /* USER CODE BEGIN StartQueueAppendTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartQueueAppendTask */
}

/* USER CODE BEGIN Header_StartQueueRemoveTask */
/**
* @brief Function implementing the queueRemoveTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartQueueRemoveTask */
void StartQueueRemoveTask(void *argument)
{
  /* USER CODE BEGIN StartQueueRemoveTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartQueueRemoveTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

