/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
char buffer;
int jump = 0;
int play = 0;
int gameover = 0;
int score = 0;
char charScore[];
int startscene = 1;
int speed;
int x20[3];
int x21[5];
int x22[7];
int x23[9];
int x24[11];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void resetPos() {
	x20[0] = 72;
	x20[1] = 73;
	x20[2] = 74;
	x21[0] = 71;
	x21[1] = 72;
	x21[2] = 73;
	x21[3] = 74;
	x21[4] = 75;
	x22[0] = 70;
	x22[1] = 71;
	x22[2] = 72;
	x22[3] = 73;
	x22[4] = 74;
	x22[5] = 75;
	x22[6] = 76;
	x23[0] = 69;
	x23[1] = 70;
	x23[2] = 71;
	x23[3] = 72;
	x23[4] = 73;
	x23[5] = 74;
	x23[6] = 75;
	x23[7] = 76;
	x23[8] = 77;
	x24[0] = 68;
	x24[1] = 69;
	x24[2] = 70;
	x24[3] = 71;
	x24[4] = 72;
	x24[5] = 73;
	x24[6] = 74;
	x24[7] = 75;
	x24[8] = 76;
	x24[9] = 77;
	x24[10] = 78;
}
void clear() {
	char clear[] = { 27, '[', 2, 'J', 27, '[', 'H' };
	HAL_UART_Transmit(&huart2, clear, sizeof(clear), HAL_MAX_DELAY);
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	HAL_Delay(100);
	if (startscene && buffer == 'p') {
		jump = 0;
		play = 1;
		score = 0;
		gameover = 0;
		startscene = 0;
		resetPos();
	} else if (play && !gameover && buffer == ' ') {
		jump = 1;
	} else if (gameover && buffer == 'y') {
		gameover = 0;
		score = 0;
		play = 1;
		resetPos();
	} else if (gameover && buffer == 'n') {
		startscene = 1;
	} else if (!gameover && play && buffer == 'p') {
		play = 0;
	} else if (!gameover && play == 0 && buffer == 'p') {
		play = 1;
	}
	HAL_UART_Receive_IT(&huart2, &buffer, 1);
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
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
	MX_USART2_UART_Init();
	/* USER CODE BEGIN 2 */
	HAL_UART_Receive_IT(&huart2, &buffer, 1);

	void rock() {
		speed = score + 10;
		if (speed > 15)
			speed = 15;
		for (int i = 0; i < 3; i++) {
			x20[i] -= speed;
			if (x20[i] <= 0)
				x20[i] += 78;
		}
		for (int i = 0; i < 5; i++) {
			x21[i] -= speed;
			if (x21[i] <= 0)
				x21[i] += 78;
		}
		for (int i = 0; i < 7; i++) {
			x22[i] -= speed;
			if (x22[i] <= 0)
				x22[i] += 78;
		}
		for (int i = 0; i < 9; i++) {
			x23[i] -= speed;
			if (x23[i] <= 0)
				x23[i] += 78;
		}
		for (int i = 0; i < 11; i++) {
			x24[i] -= speed;
			if (x24[i] <= 0) {
				x24[i] += 78;
			}

		}
	}
	void startScene() {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 80; j++) {
				if (i == 6 || i == 8) {
					if (j == 0)
						HAL_UART_Transmit(&huart2,
								"+                              ##################                              +",
								80, HAL_MAX_DELAY);
				} else if (i == 7) {
					if (j == 0)
						HAL_UART_Transmit(&huart2,
								"+                              # JUMP JUMP JUMP #                              +",
								80, HAL_MAX_DELAY);
				} else if (i == 9) {
					if (j == 0)
						HAL_UART_Transmit(&huart2,
								"+                          Press 'P' to Play or Pause                          +",
								80, HAL_MAX_DELAY);
				} else if (i == 10) {
					if (j == 0)
						HAL_UART_Transmit(&huart2,
								"+                           Press Space Bar to Jump!                           +",
								80, HAL_MAX_DELAY);
				} else if (j == 0 || j == 79 || i == 0 || i == 24)
					HAL_UART_Transmit(&huart2, "+", 1, HAL_MAX_DELAY);
				else
					HAL_UART_Transmit(&huart2, " ", 1, HAL_MAX_DELAY);
			}
		}
	}

	void gameOver() {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 80; j++) {
				if (i == 6 || i == 8) {
					if (j == 0)
						HAL_UART_Transmit(&huart2,
								"+                                xxxxxxxxxxxxxx                                +",
								80, HAL_MAX_DELAY);
				} else if (i == 7) {
					if (j == 0)
						HAL_UART_Transmit(&huart2,
								"+                                x GAME  OVER x                                +",
								80, HAL_MAX_DELAY);
				} else if (i == 9) {
					if (j == 0) {
						HAL_UART_Transmit(&huart2,
								"+                                   SCORE: ",
								43,
								HAL_MAX_DELAY);
						sprintf(charScore, "%d", score);
						HAL_UART_Transmit(&huart2, (uint8_t*) charScore,
								strlen(charScore), HAL_MAX_DELAY);
						int x;
						if (score < 10)
							x = 1;
						else if (score < 100)
							x = 2;
						else
							x = 3;
						for (int k = 0; k <= (35 - x); k++) {
							HAL_UART_Transmit(&huart2, " ", 1, HAL_MAX_DELAY);
						}
						HAL_UART_Transmit(&huart2, "+", 1, HAL_MAX_DELAY);
					}
				} else if (i == 10) {
					if (j == 0)
						HAL_UART_Transmit(&huart2,
								"+                               PLAY AGAIN? (y/n)                              +",
								80, HAL_MAX_DELAY);
				} else if (j == 0 || j == 79 || i == 0 || i == 24)
					HAL_UART_Transmit(&huart2, "+", 1, HAL_MAX_DELAY);
				else
					HAL_UART_Transmit(&huart2, " ", 1, HAL_MAX_DELAY);
			}
		}
	}

	void screen(int y1, int y2, int y3) {
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 80; j++) {
				if (j == 0 || j == 79 || i == 0 || i == 23) {
					HAL_UART_Transmit(&huart2, "+", 1, HAL_MAX_DELAY);
				} else if ((i == 19
						&& (j == x20[0] || j == x20[1] || j == x20[2]))
						|| (i == 21
								&& (j == x21[0] || j == x21[1] || j == x21[2]
										|| j == x21[3] || j == x21[4]))
						|| (i == 20
								&& (j == x22[0] || j == x22[1] || j == x22[2]
										|| j == x22[3] || j == x22[4]
										|| j == x22[5] || j == x22[6]))
						|| (i == 21
								&& (j == x23[0] || j == x23[1] || j == x23[2]
										|| j == x23[3] || j == x23[4]
										|| j == x23[5] || j == x23[6]
										|| j == x23[7] || j == x23[8]))
						|| (i == 22
								&& (j == x24[0] || j == x24[1] || j == x24[2]
										|| j == x24[3] || j == x24[4]
										|| j == x24[5] || j == x24[6]
										|| j == x24[7] || j == x24[8]
										|| j == x24[9] || j == x24[10]))) {
					HAL_UART_Transmit(&huart2, " ", 1, HAL_MAX_DELAY);
				} else if ((i == y1 && (j == 4 || j == 7))
						|| (i == y2 && (j == 3 || j == 5 || j == 6 || j == 8))
						|| (i == y3 && (j >= 3 && j <= 8))) {
					HAL_UART_Transmit(&huart2, " ", 1, HAL_MAX_DELAY);
				} else
					HAL_UART_Transmit(&huart2, ".", 1, HAL_MAX_DELAY);

				if (jump == 0 && i == 22 && (x24[10] >= 3 && x24[10] <= 18)) {
					gameover = 1;
				}
			}
		}
		HAL_UART_Transmit(&huart2, "score:", 6, HAL_MAX_DELAY);
		sprintf(charScore, "%d", score);
		HAL_UART_Transmit(&huart2, (uint8_t*) charScore, strlen(charScore),
		HAL_MAX_DELAY);
	}
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	int cnt = 0;
	clear();
	while (1) {
		if (startscene) {
			startScene();
			clear();
		} else if (!gameover && play) {
			int y1, y2, y3;
			if (jump) {
				y1 = 13;
				y2 = 14;
				y3 = 15;
				cnt++;
			} else {
				y1 = 20;
				y2 = 21;
				y3 = 22;
			}
			rock();
			screen(y1, y2, y3);
			clear();
			if (cnt == 2) {
				cnt = 0;
				jump = 0;
				score += 1;
			}
		} else if (gameover) {
			gameOver();
			clear();
		}
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 16;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
	RCC_OscInitStruct.PLL.PLLQ = 4;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief USART2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART2_UART_Init(void) {

	/* USER CODE BEGIN USART2_Init 0 */

	/* USER CODE END USART2_Init 0 */

	/* USER CODE BEGIN USART2_Init 1 */

	/* USER CODE END USART2_Init 1 */
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART2_Init 2 */

	/* USER CODE END USART2_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : B1_Pin */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : LD2_Pin */
	GPIO_InitStruct.Pin = LD2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
