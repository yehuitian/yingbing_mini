/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bsp-led.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint16_t t=0;
uint16_t second_arm_angle=500;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM5_Init();
  MX_TIM1_Init();
  MX_TIM8_Init();
  /* USER CODE BEGIN 2 */
   
    HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start(&htim5);
	HAL_TIM_Base_Start(&htim8);
    
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 0);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, 0);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, 0);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
        
        HAL_Delay(10000);

//        //yaw轴舵机驱动
//        //初始正向位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,1500);
//        HAL_Delay(1000);
//        //右偏90度位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,500);
//        HAL_Delay(1000);
//        //左偏90度位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,2500);
//        HAL_Delay(1000);
//      
//      
//      
//        //小臂舵机驱动
//        //初始正向位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,500);
//        HAL_Delay(1000);
//        //旋转90度位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,1500);
//        HAL_Delay(1000);
//        //旋转180度位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,2500);
//        HAL_Delay(1000);
//      
//
//        //大臂舵机驱动
//        //初始平躺位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,1350);
//        HAL_Delay(1000);
//        //启动90度位置
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2000);
//        HAL_Delay(1000);

        //初始化机械臂位置
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,1500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,1350);
        HAL_Delay(1000);
        //开始碰铃铛任务
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,1500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2000);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,2500);
        HAL_Delay(1000);
        //结束碰铃铛任务
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,1350);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,1500);
        HAL_Delay(1000);
        //开始推右矿任务
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2000);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,900);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2500);
        HAL_Delay(1000);
        //结束推右矿任务
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2000);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,1500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,1350);
        HAL_Delay(1000);
        //开始推左矿任务
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2000);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,900);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,2500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2500);
        HAL_Delay(1000);
        //结束推左矿任务
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2000);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,1500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,500);
        HAL_Delay(1000);
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,1350);
        HAL_Delay(1000);
	
    
    
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,2500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,1500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1,500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,2500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,1500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,2500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,1500);
//        HAL_Delay(1000);
//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3,500);
//        HAL_Delay(1000);

//        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2,second_arm_angle);
//        second_arm_angle+=50;
//        HAL_Delay(100);
   
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
