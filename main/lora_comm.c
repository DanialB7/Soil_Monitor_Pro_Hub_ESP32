/*
 * lora_comm.c
 *
 *  Created on: Feb 22, 2024
 *      Author: danialbozorgtar
 */


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_err.h"
#include "esp_log.h"
#include "lora.h"
#include "tasks_common.h"

// Tag used for ESP serial console messages
static const char TAG [] = "lora_app";

//buffer to store received data
uint8_t buf[32];

static void task_tx(void *p)
{
   for(;;) {
      vTaskDelay(pdMS_TO_TICKS(5000));
      lora_send_packet((uint8_t*)"Hello", 5);
      printf("packet sent...\n");
   }
}

uint8_t buf[32];

static void task_rx(void *p)
{
   int x;
   for(;;) {
      lora_receive();    // put into receive mode
      while(lora_received()) {
         x = lora_receive_packet(buf, sizeof(buf));
         buf[x] = 0;
         printf("Received: %s\n", buf);
         lora_receive();
      }
      vTaskDelay(1);
   }
}


void lora_start(void)
{

	ESP_LOGI(TAG, "STARTING LORA APPLICATION");

	lora_init();
	lora_set_frequency(915e6);
	lora_enable_crc();

	xTaskCreatePinnedToCore(&task_tx, "task_tx", LORA_TX_TASK_STACK_SIZE, NULL, LORA_TX_TASK_PRIORITY, NULL,LORA_TX_TASK_CORE_ID);
	xTaskCreatePinnedToCore(&task_rx, "task_rx", LORA_RX_TASK_STACK_SIZE, NULL, LORA_RX_TASK_PRIORITY, NULL,LORA_RX_TASK_CORE_ID);


}
