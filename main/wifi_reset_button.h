/*
 * wifi_reset_button.h
 *
 *  Created on: Feb 21, 2024
 *      Author: danialbozorgtar
 */

#ifndef MAIN_WIFI_RESET_BUTTON_H_
#define MAIN_WIFI_RESET_BUTTON_H_

// Default Interrupt flag
#define ESP_INTR_FLAG_DEFAULT	0

// Wifi reset button
#define WIFI_RESET_BUTTON 		7

/*
 * Configures Wifi reset button and interrupt configuration
 */
void wifi_reset_button_config(void);

#endif /* MAIN_WIFI_RESET_BUTTON_H_ */
