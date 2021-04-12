#Description:#
	This toy illuminates the green LED at 20% and flashes the red LED at 100%.  Each button on the board creates a unique buzzer tone and when mixed together can create a song.

#Compile/Run:#
	*In project directory type 'make' to create the necessary files for execution (compile)
	*Type 'make load' to load toy onto MSP430 (run)

#Uses#
	*red LED flickers 100% every 120 interrupts
	*green LED is on at 20%
	*S1 Button: Plays an A flat note from the 7th register
	*S2 Button: Plays a G sharp note from the 7th register
	*S4 Button: Plays a A flat note from the 8th register
	*S4 Button: Stops the buzzer
