/*
 * global.c
 *
 *  Created on: Nov 14, 2024
 *      Author: lequo
 */


#include "main.h"
#include "global.h"
#include "software_timer.h"
#include "lcd.h"

int T_RED = 10;
int T_AMBER = 3;
int T_GREEN = 7;

int status = INIT;
int toggle_flag = 0;

void off_all_leds_road_1();
void off_all_leds_road_2();

void on_red_road_1();
void on_red_road_2();

void on_amber_road_1();
void on_amber_road_2();
void on_green_road_1();
void on_green_road_2();

void led_config() {
	switch (status) {
		case MODE1:
			off_all_leds_road_1();
			off_all_leds_road_2();
			break;

		case RED_GREEN:
			on_red_road_1();
			on_green_road_2();
			break;

		case RED_AMBER:
			on_red_road_1();
			on_amber_road_2();
			break;

		case GREEN_RED:
			on_green_road_1();
			on_red_road_2();
			break;

		case AMBER_RED:
			on_amber_road_1();
			on_red_road_2();
			break;

		case MODE2:
			on_red_road_1();
			on_red_road_2();
			toggle_flag = 0;
			break;

		case MODE3:
			on_green_road_1();
			on_green_road_2();
			toggle_flag = 0;
			break;

		case MODE4:
			on_amber_road_1();
			on_amber_road_2();
			toggle_flag = 0;
			break;

		default:
			break;
	}
}

/*
 * RED ROAD 1: lcd_DrawCircle(40, 100, RED, 20, 1);
 * AMBER ROAD 1: lcd_DrawCircle(80, 100, AMBER, 20, 1);
 * GREEN ROAD 1: lcd_DrawCircle(120, 100, GREEN, 20, 1);
 *
 * RED ROAD 2: lcd_DrawCircle(40, 150, RED, 20, 1);
 * AMBER ROAD 2: lcd_DrawCircle(80, 150, AMBER, 20, 1);
 * GREEN ROAD 2: lcd_DrawCircle(120, 150, GREEN, 20, 1);
 */

void off_all_leds_road_1() {
	lcd_DrawCircle(40, 50, WHITE, 20, 1);	// RED ROAD 1
	lcd_DrawCircle(80, 50, WHITE, 20, 1);	// AMBER ROAD 1
	lcd_DrawCircle(120, 50, WHITE, 20, 1);	// GREEN ROAD 1
}

void off_all_leds_road_2() {
	lcd_DrawCircle(40, 100, WHITE, 20, 1);	// RED ROAD 2
	lcd_DrawCircle(80, 100, WHITE, 20, 1);	// AMBER ROAD 2
	lcd_DrawCircle(120, 100, WHITE, 20, 1);	// GREEN ROAD 2
}

void on_red_road_1() {
	lcd_DrawCircle(80, 50, WHITE, 20, 1);	// OFF AMBER ROAD 1
//	off_all_leds_road_1();
	lcd_DrawCircle(40, 50, RED, 20, 1);
}

void on_red_road_2() {
	lcd_DrawCircle(80, 100, WHITE, 20, 1);	// OFF AMBER ROAD 2
//	off_all_leds_road_2();
	lcd_DrawCircle(40, 100, RED, 20, 1);
}

void on_amber_road_1() {
	lcd_DrawCircle(120, 50, WHITE, 20, 1);	// OFF GREEN ROAD 1
//	off_all_leds_road_1();
	lcd_DrawCircle(80, 50, YELLOW, 20, 1);
}

void on_amber_road_2() {
	lcd_DrawCircle(120, 100, WHITE, 20, 1);	// OFF GREEN ROAD 2
//	off_all_leds_road_2();
	lcd_DrawCircle(80, 100, YELLOW, 20, 1);
}

void on_green_road_1() {
	lcd_DrawCircle(40, 50, WHITE, 20, 1);	// OFF RED ROAD 1
//	off_all_leds_road_1();
	lcd_DrawCircle(120, 50, GREEN, 20, 1);
}

void on_green_road_2() {
	lcd_DrawCircle(40, 100, WHITE, 20, 1);	// OFF RED ROAD 2
//	off_all_leds_road_2();
	lcd_DrawCircle(120, 100, GREEN, 20, 1);
}


void toggle_red() {
	if (toggle_flag == 0) {
		on_red_road_1();
		on_red_road_2();
		toggle_flag = 1;
	} else {
		off_all_leds_road_1();
		off_all_leds_road_2();
		toggle_flag = 0;
	}
}

void toggle_amber() {
	if (toggle_flag == 0) {
		on_amber_road_1();
		on_amber_road_2();
		toggle_flag = 1;
	} else {
		off_all_leds_road_1();
		off_all_leds_road_2();
		toggle_flag = 0;
	}
}

void toggle_green() {
	if (toggle_flag == 0) {
		on_green_road_1();
		on_green_road_2();
		toggle_flag = 1;
	} else {
		off_all_leds_road_1();
		off_all_leds_road_2();
		toggle_flag = 0;
	}
}

