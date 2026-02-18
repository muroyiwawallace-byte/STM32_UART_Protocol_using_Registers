
#include "main.h"
void uart2_writestring(char*str){
	while(*str){

		uart2_write(*str++);
	}
}
void uart2_write(char c){
	while((USART2->SR &(1<<7))==0){
	}
		USART2->DR=c;
	}

int main(void)
{
  SystemClock_Config();
      RCC->AHB1ENR |=(1<<0);
      RCC->APB1ENR |=(1<<17);//Configuring the clocks For UART2 and GPIOA

      GPIOA->MODER &=~(3<<2*2);
      GPIOA->MODER &=~(3<<3*2);
      GPIOA->MODER &=~(3<<5*2);
      GPIOA->MODER |=(2<<2*2);
      GPIOA->MODER |=(2<<3*2);
      GPIOA->MODER |=(1<<5*2);

      GPIOA->AFR[0]&=~(0XF<<2*4);//Configuring the Alternate Function of the GPIO PORTS THAT IS CONNECTING THEM TO THE OUTPUT PERIPHERAL
      GPIOA->AFR[0]&=~(0XF<<3*4);

      GPIOA->AFR[0] |=(7<<2*4);
      GPIOA->AFR[0] |=(7<<3*4);
      USART2->BRR =365;//for usart2 we use 42mhz as it is apbi bus

      USART2->CR1 |=(1<<3);//Enable Transmitter Enable
      //USART2->CR1 |=(1<<7);//Transmitter data Register Empty Interrupt enable to allow interrupts if the data register is empty
      USART2->CR1 |=(1<<13);//Enable USART Enable


     // USART2->BRR =365;//for usart2 we use 42mhz as it is apbi bus
      //NVIC_EnableIRQ(USART2_IRQn);//This informs the CPU to accept interrupts that come from our Peripheral USART2
      //For  UART Communication Protocol you need to set the Baud Rate

  while (1)
  {

  	  GPIOA->ODR |=(1<<5);
  	  uart2_writestring("LED ON\r\n");
  	  for(volatile int i=0; i<10000000; i++);
  	  GPIOA->ODR &=~(1<<5);
  	  uart2_writestring("LED OFF\r\n");
  	  for(volatile int i=0; i<10000000; i++);
  }
  /* USER CODE END 3 */
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */

/**
  * @brief GPIO Initialization Function
  * @param None
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
#ifdef USE_FULL_ASSERT
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
