/*
 * input_processing.c
 *
 *  Created on: Nov 15, 2024
 *      Author: lequo
 */


#include "main.h"
#include "global.h"
#include "input_processing.h"
#include "button.h"
#include "software_timer.h"
#include "lcd.h"

//enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};

//enum ButtonState button_0_state = BUTTON_PRESSED;
//enum ButtonState button_1_state = BUTTON_PRESSED;
//enum ButtonState button_2_state = BUTTON_PRESSED;
//enum ButtonState button_3_state = BUTTON_PRESSED;

void input_processing() {
	while (!flag_timer2);
//	flag_timer2 = 0;
	setTimer2(50);
	button_Scan();

	if (button_count[0] == 1) {
		if (status == RED_GREEN
			|| status == RED_AMBER
			|| status == GREEN_RED
			|| status == AMBER_RED
				)	status = MODE2; // ???
		if (status == AUTO_RED) 	status = MODE3;
		if (status == AUTO_GREEN) 	status = MODE4;
		if (status == AUTO_AMBER) 	status = MODE1;
	}

	if (button_count[1] == 1) {
		if (status == AUTO_RED || status == ADJ_RED) {
			status = ADJ_RED;
			T_RED++;
			if (T_RED >= 99) T_RED = 1;

			// Display T_RED on LCD
			lcd_ShowIntNum(140, 260, T_RED, 2, BRED, WHITE, 32);
		}
		if (status == AUTO_AMBER || status == ADJ_AMBER) {
			status = ADJ_AMBER;
			T_AMBER++;
			if (T_AMBER >= 5) T_AMBER = 1;

			// Display T_RED on LCD
			lcd_ShowIntNum(140, 260, T_AMBER, 2, BRED, WHITE, 32);
		}
		if (status == AUTO_GREEN || status == ADJ_GREEN) {
			status = ADJ_GREEN;
			T_GREEN++;
			if (T_GREEN >= 99) T_GREEN = 1;

			// Display T_RED on LCD
			lcd_ShowIntNum(140, 260, T_GREEN, 2, BRED, WHITE, 32);
		}
	}

	if (button_count[2] == 1) {
		if (status == ADJ_RED) {
			status = AUTO_RED;
			if (T_RED <= T_AMBER) T_RED = T_AMBER + 1;
			T_GREEN = T_RED - T_AMBER;

		}
		if (status == ADJ_AMBER) {
			status = AUTO_AMBER;
			if (T_RED <= T_AMBER) T_RED = T_AMBER + 1;
			T_GREEN = T_RED - T_AMBER;
		}
		if (status == ADJ_GREEN) {
			status = AUTO_GREEN;
			if (T_AMBER + T_GREEN >= 99) {
				T_AMBER = 4;
				T_GREEN = 95;
			}
			T_RED = T_AMBER + T_GREEN;
		}

		lcd_StrCenter(0, 300, "SAVED SUCESSFULLY !!!", RED, BLUE, 16, 1);
	}
}
