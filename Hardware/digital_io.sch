EESchema Schematic File Version 4
LIBS:midi_grid-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title "midi-grid"
Date "2018-01-15"
Rev "1.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L project_library:Rotary_Encoder SW25
U 1 1 5A3979F5
P 5700 5250
F 0 "SW25" H 5700 5510 50  0000 C CNN
F 1 "EC12E24204A9" H 5700 4990 50  0000 C CNN
F 2 "project_library:EC12" H 5600 5410 50  0001 C CNN
F 3 "" H 5700 5510 50  0001 C CNN
F 4 "Alps" H 5700 5250 60  0001 C CNN "Manufacturer"
	1    5700 5250
	1    0    0    -1  
$EndComp
$Comp
L project_library:GND #PWR0129
U 1 1 5A397ADE
P 5200 5450
F 0 "#PWR0129" H 5200 5200 50  0001 C CNN
F 1 "GND" H 5200 5300 50  0000 C CNN
F 2 "" H 5200 5450 50  0001 C CNN
F 3 "" H 5200 5450 50  0001 C CNN
	1    5200 5450
	1    0    0    -1  
$EndComp
$Comp
L project_library:SW_Push SW23
U 1 1 5A39D16C
P 5700 4350
F 0 "SW23" V 5700 4100 50  0000 L CNN
F 1 "SW_Push" H 5700 4290 50  0001 C CNN
F 2 "project_library:Tactile_switch_12x12_black_cap" H 5700 4550 50  0001 C CNN
F 3 "" H 5700 4550 50  0001 C CNN
	1    5700 4350
	0    -1   -1   0   
$EndComp
Text HLabel 4700 5150 0    60   Output ~ 0
ROTARY1_A
Text HLabel 4700 5350 0    60   Output ~ 0
ROTARY1_B
$Comp
L project_library:GND #PWR0130
U 1 1 5A39D52F
P 5700 4650
F 0 "#PWR0130" H 5700 4400 50  0001 C CNN
F 1 "GND" H 5700 4500 50  0000 C CNN
F 2 "" H 5700 4650 50  0001 C CNN
F 3 "" H 5700 4650 50  0001 C CNN
	1    5700 4650
	1    0    0    -1  
$EndComp
Text HLabel 4700 4150 0    60   Output ~ 0
BUTTON1
$Comp
L project_library:Rotary_Encoder SW26
U 1 1 5A39DA31
P 7600 5250
F 0 "SW26" H 7600 5510 50  0000 C CNN
F 1 "EC12E24204A9" H 7600 4990 50  0000 C CNN
F 2 "project_library:EC12" H 7500 5410 50  0001 C CNN
F 3 "" H 7600 5510 50  0001 C CNN
F 4 "Alps" H 7600 5250 60  0001 C CNN "Manufacturer"
	1    7600 5250
	1    0    0    -1  
$EndComp
$Comp
L project_library:GND #PWR0131
U 1 1 5A39DA37
P 7100 5450
F 0 "#PWR0131" H 7100 5200 50  0001 C CNN
F 1 "GND" H 7100 5300 50  0000 C CNN
F 2 "" H 7100 5450 50  0001 C CNN
F 3 "" H 7100 5450 50  0001 C CNN
	1    7100 5450
	1    0    0    -1  
$EndComp
$Comp
L project_library:SW_Push SW24
U 1 1 5A39DA5F
P 7600 4350
F 0 "SW24" V 7600 4100 50  0000 L CNN
F 1 "SW_Push" H 7600 4290 50  0001 C CNN
F 2 "project_library:Tactile_switch_12x12_red_cap" H 7600 4550 50  0001 C CNN
F 3 "" H 7600 4550 50  0001 C CNN
	1    7600 4350
	0    -1   -1   0   
$EndComp
Text HLabel 6600 5150 0    60   Output ~ 0
ROTARY2_A
Text HLabel 6600 5350 0    60   Output ~ 0
ROTARY2_B
$Comp
L project_library:GND #PWR0132
U 1 1 5A39DA67
P 7600 4650
F 0 "#PWR0132" H 7600 4400 50  0001 C CNN
F 1 "GND" H 7600 4500 50  0000 C CNN
F 2 "" H 7600 4650 50  0001 C CNN
F 3 "" H 7600 4650 50  0001 C CNN
	1    7600 4650
	1    0    0    -1  
$EndComp
Text HLabel 6600 4150 0    60   Output ~ 0
BUTTON2
$Comp
L project_library:lcd_nokia_5110 A1
U 1 1 5A1F0214
P 7400 2800
F 0 "A1" H 7150 3300 50  0000 L CNN
F 1 "Nokia 5110 LCD" H 7150 2300 50  0000 L CNN
F 2 "project_library:Nokia_5110_lcd" H 6650 3200 50  0001 C CNN
F 3 "" H 6750 3300 50  0001 C CNN
F 4 "https://www.ebay.com/itm/84-48-LCD-Module-White-Backlight-Adapter-PCB-for-Nokia-5110-Arduino/400488314619" H 7400 2800 60  0001 C CNN "Catalog link"
	1    7400 2800
	1    0    0    -1  
$EndComp
$Comp
L project_library:+3.3V #PWR0133
U 1 1 5A1F0C1A
P 7050 2200
F 0 "#PWR0133" H 7050 2050 50  0001 C CNN
F 1 "+3.3V" H 7050 2340 50  0000 C CNN
F 2 "" H 7050 2200 50  0001 C CNN
F 3 "" H 7050 2200 50  0001 C CNN
	1    7050 2200
	1    0    0    -1  
$EndComp
$Comp
L project_library:GND #PWR0134
U 1 1 5A1F0FE5
P 7050 3400
F 0 "#PWR0134" H 7050 3150 50  0001 C CNN
F 1 "GND" H 7050 3250 50  0000 C CNN
F 2 "" H 7050 3400 50  0001 C CNN
F 3 "" H 7050 3400 50  0001 C CNN
	1    7050 3400
	1    0    0    -1  
$EndComp
$Comp
L project_library:2N7002 Q34
U 1 1 5A1F45C8
P 5600 3400
F 0 "Q34" H 5800 3450 50  0000 L CNN
F 1 "NX7002AK" H 5800 3350 50  0000 L CNN
F 2 "project_library:SOT-23" H 5800 3325 50  0001 L CIN
F 3 "" H 5600 3400 50  0001 L CNN
	1    5600 3400
	1    0    0    -1  
$EndComp
$Comp
L project_library:R_Small R63
U 1 1 5A1F45CF
P 5200 3550
F 0 "R63" H 5250 3600 50  0000 L CNN
F 1 "10K" H 5250 3500 50  0000 L CNN
F 2 "project_library:R_0603" H 5200 3550 50  0001 C CNN
F 3 "" H 5200 3550 50  0001 C CNN
	1    5200 3550
	1    0    0    -1  
$EndComp
$Comp
L project_library:GND #PWR0135
U 1 1 5A1F45D6
P 5700 3700
F 0 "#PWR0135" H 5700 3450 50  0001 C CNN
F 1 "GND" H 5700 3550 50  0000 C CNN
F 2 "" H 5700 3700 50  0001 C CNN
F 3 "" H 5700 3700 50  0001 C CNN
	1    5700 3700
	1    0    0    -1  
$EndComp
$Comp
L project_library:GND #PWR0136
U 1 1 5A1F45DC
P 5200 3700
F 0 "#PWR0136" H 5200 3450 50  0001 C CNN
F 1 "GND" H 5200 3550 50  0000 C CNN
F 2 "" H 5200 3700 50  0001 C CNN
F 3 "" H 5200 3700 50  0001 C CNN
	1    5200 3700
	1    0    0    -1  
$EndComp
Text HLabel 4700 2500 0    60   Input ~ 0
LCD_MOSI
Text HLabel 4700 2700 0    60   Input ~ 0
LCD_CS
Text HLabel 4700 2600 0    60   Input ~ 0
LCD_SCLK
Text HLabel 4700 2800 0    60   Input ~ 0
LCD_DC
Text HLabel 4700 3000 0    60   Input ~ 0
LCD_RESET
Text HLabel 4700 3400 0    60   Input ~ 0
LCD_LIGHT
Wire Wire Line
	5400 5250 5200 5250
Wire Wire Line
	5200 5250 5200 5450
Wire Wire Line
	4700 5350 5400 5350
Wire Wire Line
	4700 5150 5400 5150
Wire Wire Line
	4700 4150 5700 4150
Wire Wire Line
	7300 5250 7100 5250
Wire Wire Line
	7100 5250 7100 5450
Wire Wire Line
	6600 5350 7300 5350
Wire Wire Line
	6600 5150 7300 5150
Wire Wire Line
	6600 4150 7600 4150
Wire Wire Line
	7600 4550 7600 4650
Wire Wire Line
	5700 4550 5700 4650
Wire Wire Line
	4700 3400 5400 3400
Wire Wire Line
	5200 3400 5200 3450
Wire Wire Line
	5200 3650 5200 3700
Wire Wire Line
	5700 3600 5700 3700
Connection ~ 5200 3400
Wire Wire Line
	6600 2500 4700 2500
Wire Wire Line
	4700 2600 6600 2600
Wire Wire Line
	6600 2700 4700 2700
Wire Wire Line
	4700 2800 6600 2800
Wire Wire Line
	6600 3000 4700 3000
Wire Wire Line
	5700 3100 5700 3200
$Comp
L project_library:R_Small R62
U 1 1 5A52FA84
P 6200 3100
F 0 "R62" V 6300 3100 50  0000 C CNN
F 1 "220R" V 6400 3100 50  0000 C CNN
F 2 "project_library:R_0603" H 6200 3100 50  0001 C CNN
F 3 "" H 6200 3100 50  0001 C CNN
	1    6200 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 3100 6300 3100
Wire Wire Line
	6100 3100 5700 3100
$EndSCHEMATC
