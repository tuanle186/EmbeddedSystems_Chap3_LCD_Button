/*
 * mode1_normal.c
 *
 *  Created on: Nov 14, 2024
 *      Author: lequo
 */

#include "main.h"
#include "global.h"
#include "mode1_normal.h"
#include "software_timer.h"
#include "button.h"
#include "lcd.h"

int t_road_1 = 0, t_road_2 = 0;

void mode1_normal() {
	switch (status) {
		case INIT:
			status = MODE1;
			break;

		case MODE1:
			lcd_Clear(WHITE);
			led_config();
			t_road_1 = T_RED;
			t_road_2 = T_GREEN;
			setTimer4(1000);
			status = RED_GREEN;

			// Display mode on LCD
			lcd_ShowStr(20, 260, "Mode 1", WHITE, RED, 24, 0);

			break;

		case RED_GREEN:
			led_config();
			if (flag_timer4 == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_2 <= 0) { // next state pre-setup
					t_road_2 = T_AMBER;
					status = RED_AMBER; // Change state
				}

				// Display time of T_RED
				lcd_ShowIntNum(140, 30, t_road_1, 2, BRED, WHITE, 32);
				lcd_ShowIntNum(140, 80, t_road_2, 2, BRED, WHITE, 32);

				setTimer4(1000);
			}
			break;

		case RED_AMBER:
			led_config();
			if (flag_timer4 == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_1 <= 0) { // next state pre-setup
					t_road_1 = T_GREEN;
					t_road_2 = T_RED;
					status = GREEN_RED; // Change state
				}

				// Display time of T_RED
				lcd_ShowIntNum(140, 30, t_road_1, 2, BRED, WHITE, 32);
				lcd_ShowIntNum(140, 80, t_road_2, 2, BRED, WHITE, 32);

				setTimer4(1000);
			}
			break;

		case GREEN_RED:
			led_config();
			if (flag_timer4 == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_1 <= 0) { // next state pre-setup
					t_road_1 = T_AMBER;
					status = AMBER_RED; // Change state
				}

				// Display time of T_RED
				lcd_ShowIntNum(140, 30, t_road_1, 2, BRED, WHITE, 32);
				lcd_ShowIntNum(140, 80, t_road_2, 2, BRED, WHITE, 32);

				setTimer4(1000);
			}
			break;

		case AMBER_RED:
			led_config();
			if (flag_timer4 == 1) {
				t_road_1--;
				t_road_2--;
				if (t_road_1 <= 0) { // next state pre-setup
					t_road_1 = T_RED;
					t_road_2 = T_GREEN;
					status = RED_GREEN; // Change state
				}

				// Display time of T_RED
				lcd_ShowIntNum(140, 30, t_road_1, 2, BRED, WHITE, 32);
				lcd_ShowIntNum(140, 80, t_road_2, 2, BRED, WHITE, 32);

				setTimer4(1000);
			}
			break;

		default:
			break;
	}
}
