EESchema Schematic File Version 4
LIBS:midi_grid-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title "midi-grid"
Date "2018-01-15"
Rev "1.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3800 2800 1000 1000
U 5A0A02C3
F0 "grid" 60
F1 "grid.sch" 60
F2 "GRID_BUTTON[1..4]" O R 4800 3400 60 
F3 "PWM_RED[1..4]" I R 4800 3000 60 
F4 "PWM_GREEN[1..4]" I R 4800 3100 60 
F5 "PWM_BLUE[1..4]" I R 4800 3200 60 
F6 "COLUMN[1..6]" I R 4800 3600 60 
$EndSheet
$Sheet
S 5300 2800 2200 2300
U 5A3217AD
F0 "mcu" 60
F1 "mcu.sch" 60
F2 "PWM_RED[1..4]" O L 5300 3000 60 
F3 "PWM_GREEN[1..4]" O L 5300 3100 60 
F4 "PWM_BLUE[1..4]" O L 5300 3200 60 
F5 "GRID_BUTTON[1..4]" I L 5300 3400 60 
F6 "USB_DP" B L 5300 4000 60 
F7 "USB_DM" B L 5300 4100 60 
F8 "BUTTON1" I R 7500 4500 60 
F9 "BUTTON2" I R 7500 4600 60 
F10 "ROTARY1_A" I R 7500 3900 60 
F11 "ROTARY1_B" I R 7500 4000 60 
F12 "ROTARY2_A" I R 7500 4200 60 
F13 "ROTARY2_B" I R 7500 4300 60 
F14 "LCD_MOSI" O R 7500 3000 60 
F15 "LCD_SCLK" O R 7500 3100 60 
F16 "LCD_LIGHT" O R 7500 3600 60 
F17 "LCD_DC" O R 7500 3300 60 
F18 "LCD_CS" O R 7500 3200 60 
F19 "LCD_RESET" O R 7500 3500 60 
F20 "COL[1..6]" O L 5300 3600 60 
F21 "MIDI_IN_SRC" I L 5300 4500 60 
F22 "MIDI_IN_SINK" I L 5300 4400 60 
F23 "MIDI_OUT_SRC" O L 5300 4800 60 
F24 "MIDI_OUT_SINK" O L 5300 4700 60 
F25 "MIDI_OUT_DETECT" I L 5300 4900 60 
$EndSheet
$Sheet
S 8000 2800 2000 2000
U 5A3979DD
F0 "digital_io" 60
F1 "digital_io.sch" 60
F2 "ROTARY1_A" O L 8000 3900 60 
F3 "ROTARY1_B" O L 8000 4000 60 
F4 "BUTTON1" O L 8000 4500 60 
F5 "ROTARY2_A" O L 8000 4200 60 
F6 "ROTARY2_B" O L 8000 4300 60 
F7 "BUTTON2" O L 8000 4600 60 
F8 "LCD_MOSI" I L 8000 3000 60 
F9 "LCD_CS" I L 8000 3200 60 
F10 "LCD_SCLK" I L 8000 3100 60 
F11 "LCD_DC" I L 8000 3300 60 
F12 "LCD_RESET" I L 8000 3500 60 
F13 "LCD_LIGHT" I L 8000 3600 60 
$EndSheet
$Sheet
S 2500 2800 1000 1000
U 5A21B701
F0 "psu" 60
F1 "psu.sch" 60
F2 "Vin" I L 2500 3300 60 
$EndSheet
Wire Wire Line
	7500 3000 8000 3000
Wire Wire Line
	8000 3100 7500 3100
Wire Wire Line
	7500 3200 8000 3200
Wire Wire Line
	8000 3300 7500 3300
Wire Wire Line
	7500 3500 8000 3500
Wire Wire Line
	7500 3600 8000 3600
Wire Wire Line
	8000 3900 7500 3900
Wire Wire Line
	7500 4000 8000 4000
Wire Wire Line
	7500 4500 8000 4500
Wire Wire Line
	7500 4600 8000 4600
Wire Wire Line
	8000 4300 7500 4300
Wire Wire Line
	7500 4200 8000 4200
Wire Bus Line
	4800 3000 5300 3000
Wire Bus Line
	4800 3100 5300 3100
Wire Bus Line
	4800 3200 5300 3200
Wire Bus Line
	5300 3400 4800 3400
Wire Bus Line
	4800 3600 5300 3600
Wire Wire Line
	2100 3800 2300 3800
Wire Wire Line
	2300 3800 2300 3300
Wire Wire Line
	2300 3300 2500 3300
$Comp
L project_library:GND #PWR01
U 1 1 5A326E77
P 1800 4600
F 0 "#PWR01" H 1800 4350 50  0001 C CNN
F 1 "GND" H 1800 4450 50  0000 C CNN
F 2 "" H 1800 4600 50  0001 C CNN
F 3 "" H 1800 4600 50  0001 C CNN
	1    1800 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 4400 1800 4500
Wire Wire Line
	1800 4500 1700 4500
Wire Wire Line
	1700 4500 1700 4400
Connection ~ 1800 4500
Wire Wire Line
	5300 4000 2100 4000
Wire Wire Line
	5300 4100 2100 4100
Wire Wire Line
	2500 5300 2500 5400
$Comp
L project_library:GND #PWR02
U 1 1 5A337D47
P 2500 5400
F 0 "#PWR02" H 2500 5150 50  0001 C CNN
F 1 "GND" H 2500 5250 50  0000 C CNN
F 2 "" H 2500 5400 50  0001 C CNN
F 3 "" H 2500 5400 50  0001 C CNN
	1    2500 5400
	1    0    0    -1  
$EndComp
$Comp
L project_library:USB_OTG J1
U 1 1 5A33503F
P 1800 4000
F 0 "J1" H 1600 4450 50  0000 L CNN
F 1 "USB_OTG" H 1600 4350 50  0000 L CNN
F 2 "project_library:USB_Micro-B_Molex-105017-0001" H 1950 3950 50  0001 C CNN
F 3 "" H 1950 3950 50  0001 C CNN
F 4 "https://www.lemona.lt/?page=item&i_id=216110" H 1800 4000 60  0001 C CNN "Catalog link"
	1    1800 4000
	1    0    0    -1  
$EndComp
NoConn ~ 2100 4200
$Comp
L project_library:Audio-Jack-3_2Switches J2
U 1 1 5A3F863B
P 2700 4500
F 0 "J2" H 2550 4800 50  0000 C CNN
F 1 "3.5mm jack" H 2550 4300 50  0000 L CNN
F 2 "project_library:3.5mm-jack" H 2950 4600 50  0001 C CNN
F 3 "" H 2950 4600 50  0001 C CNN
F 4 "http://lt.farnell.com/cliff-electronic-components/fc68133/stereo-jack-3-5mm-5pos-pcb/dp/2518190" H 2700 4500 60  0001 C CNN "Catalog link"
	1    2700 4500
	1    0    0    -1  
$EndComp
$Comp
L project_library:Audio-Jack-3_2Switches J3
U 1 1 5A422E89
P 2700 5100
F 0 "J3" H 2550 5400 50  0000 C CNN
F 1 "3.5mm jack" H 2550 4900 50  0000 L CNN
F 2 "project_library:3.5mm-jack" H 2950 5200 50  0001 C CNN
F 3 "" H 2950 5200 50  0001 C CNN
F 4 "http://lt.farnell.com/cliff-electronic-components/fc68133/stereo-jack-3-5mm-5pos-pcb/dp/2518190" H 2700 5100 60  0001 C CNN "Catalog link"
	1    2700 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4400 2900 4400
Wire Wire Line
	5300 4500 2900 4500
Wire Wire Line
	2900 5000 3200 5000
Wire Wire Line
	3200 5000 3200 4700
Wire Wire Line
	3200 4700 5300 4700
Wire Wire Line
	2900 5100 3300 5100
Wire Wire Line
	3300 5100 3300 4800
Wire Wire Line
	3300 4800 5300 4800
Wire Wire Line
	2900 5200 3400 5200
Wire Wire Line
	3400 5200 3400 4900
Wire Wire Line
	3400 4900 5300 4900
NoConn ~ 2500 4700
NoConn ~ 2900 4900
NoConn ~ 2900 4600
NoConn ~ 2900 4300
$Comp
L project_library:Graphical GR1
U 1 1 5A53D346
P 700 7100
F 0 "GR1" H 700 7250 50  0000 C CNN
F 1 "OSHW" H 700 6950 50  0000 C CNN
F 2 "project_library:Logo_OSHW" H 700 7100 50  0001 C CNN
F 3 "" H 700 7100 50  0001 C CNN
	1    700  7100
	1    0    0    -1  
$EndComp
$Comp
L project_library:Graphical GR2
U 1 1 5A53DA73
P 1100 7100
F 0 "GR2" H 1100 7250 50  0000 C CNN
F 1 "QR" H 1100 6950 50  0000 C CNN
F 2 "project_library:qr_url" H 1100 7100 50  0001 C CNN
F 3 "" H 1100 7100 50  0001 C CNN
	1    1100 7100
	1    0    0    -1  
$EndComp
$Comp
L project_library:Graphical GR3
U 1 1 5A6786D2
P 1100 7500
F 0 "GR3" H 1100 7650 50  0000 C CNN
F 1 "Kicad" H 1100 7350 50  0000 C CNN
F 2 "project_library:Symbol_KiCAD-Logo_CopperAndSilkScreenTop" H 1100 7050 60  0001 C CNN
F 3 "" H 1150 7500 60  0001 C CNN
	1    1100 7500
	1    0    0    -1  
$EndComp
$Comp
L project_library:Mounting_hole M1
U 1 1 5A73E20A
P 1500 7100
F 0 "M1" H 1500 7250 60  0000 C CNN
F 1 "Mounting_hole" H 1300 6950 60  0001 L CNN
F 2 "project_library:MountingHole_2.2mm_M2" H 1500 6650 60  0001 C CNN
F 3 "" H 1550 7100 60  0001 C CNN
	1    1500 7100
	1    0    0    -1  
$EndComp
$Comp
L project_library:Mounting_hole M2
U 1 1 5A740E09
P 1900 7100
F 0 "M2" H 1900 7250 60  0000 C CNN
F 1 "Mounting_hole" H 1700 6950 60  0001 L CNN
F 2 "project_library:MountingHole_2.2mm_M2" H 1900 6650 60  0001 C CNN
F 3 "" H 1950 7100 60  0001 C CNN
	1    1900 7100
	1    0    0    -1  
$EndComp
$Comp
L project_library:Mounting_hole M3
U 1 1 5A740F4F
P 1500 7500
F 0 "M3" H 1500 7650 60  0000 C CNN
F 1 "Mounting_hole" H 1300 7350 60  0001 L CNN
F 2 "project_library:MountingHole_2.2mm_M2" H 1500 7050 60  0001 C CNN
F 3 "" H 1550 7500 60  0001 C CNN
	1    1500 7500
	1    0    0    -1  
$EndComp
$Comp
L project_library:Graphical GR4
U 1 1 5A5BCF08
P 700 7500
F 0 "GR4" H 700 7650 50  0000 C CNN
F 1 "USB" H 700 7350 50  0000 C CNN
F 2 "project_library:usb_logo_6x3mm" H 700 7050 60  0001 C CNN
F 3 "" H 750 7500 60  0001 C CNN
	1    700  7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 4500 1800 4600
$EndSCHEMATC
