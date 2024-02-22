/*
 * lora_comm.h
 *
 *  Created on: Feb 22, 2024
 *      Author: danialbozorgtar
 */

#ifndef MAIN_LORA_COMM_H_
#define MAIN_LORA_COMM_H_

/**
 *  LoRa transmit function
 */
void task_tx(void *p);

/**
 *  LoRa receive function
 */
void task_rx(void *p);

/**
 * Starting the LoRa process
 */
void lora_start(void);

#endif /* MAIN_LORA_COMM_H_ */
