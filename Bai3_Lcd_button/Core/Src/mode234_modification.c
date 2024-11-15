/*
 * mode234_modification.c
 *
 *  Created on: Nov 14, 2024
 *      Author: lequo
 */


#include "main.h"
#include "global.h"
#include "mode234_modification.h"
#include "software_timer.h"
#include "lcd.h"

void mode2_red() {
	switch(status) {
		case MODE2:
			lcd_Clear(WHITE);
			led_config();
			setTimer1(500);

			// Display time of T_RED
			lcd_ShowIntNum(140, 260, T_RED, 2, BRED, WHITE, 32);

			// Display mode on LCD
			lcd_ShowStr(20, 260, "Mode 2", WHITE, RED, 24, 0);

			status = AUTO_RED;
			break;

		case AUTO_RED:
			if (flag_timer1 == 1) {
				toggle_red();
				setTimer1(500);
			}
			break;

		case ADJ_RED:
			if (flag_timer1 == 1) {
				toggle_red();
				setTimer1(500);
			}
			break;

		default:
			break;
	}
}

void mode3_green() {
	switch(status) {
		case MODE3:
			lcd_Clear(WHITE);
			led_config();

			setTimer1(500);

			// Display time of T_RED
			lcd_ShowIntNum(140, 260, T_GREEN, 2, BRED, WHITE, 32);

			// Display mode on LCD
			lcd_ShowStr(20, 260, "Mode 3", WHITE, RED, 24, 0);

			status = AUTO_GREEN;
			break;

		case AUTO_GREEN:
			if (flag_timer1 == 1) {
				toggle_green();
				setTimer1(500);
			}
			break;

		case ADJ_GREEN:
			if (flag_timer1 == 1) {
				toggle_green();
				setTimer1(500);
			}
			break;

		default:
			break;
	}
}

void mode4_amber() {
	switch(status) {
		case MODE4:
			lcd_Clear(WHITE);
			led_config();
			setTimer1(500);

			// Display time of T_RED
			lcd_ShowIntNum(140, 260, T_AMBER, 2, BRED, WHITE, 32);

			// Display mode on LCD
			lcd_ShowStr(20, 260, "Mode 4", WHITE, RED, 24, 0);

			status = AUTO_AMBER;
			break;

		case AUTO_AMBER:
			if (flag_timer1 == 1) {
				toggle_amber();
				setTimer1(500);
			}
			break;

		case ADJ_AMBER:
			if (flag_timer1 == 1) {
				toggle_amber();
				setTimer1(500);
			}
			break;

		default:
			break;
	}
}
