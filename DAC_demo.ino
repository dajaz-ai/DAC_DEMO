/*=============================================


        DAC_DEMO

Description: 
  is a testing setup used to evaluate the Digital-to-Analog Converter (DAC) output of an ESP32 by connecting a potentiometer to adjust and 
  monitor the output voltage at the DAC_PIN. By varying the potentiometer's resistance, the output voltage can be observed and compared with the expected DAC 
  values to verify the accuracy and functionality of the DAC output.

Engineers:
 Aragon, Edward Paul M.
 Regalado, Cid Lawremc C.

 Date:
  Oct 14, 2026


===============================================*/




// ASSIGN SANG VARIABLE SA ESP 32 WITIWIW
//GPIO pins
const byte POT = 36;
const byte DAC_PIN = 25;

//Variable
int adc_val = 0; //3102
float voltage_in = 0; //2.5V <- result calculation

void setup() {
  // put your setup code here, to run once: ASSIGN SANG MGA GIN PANG GAMIT WITIWIW
// ADC pin
pinMode(POT, INPUT);
analogReadResolution(8); // 8-bit

//DAC  pin
pinMode(DAC_PIN, OUTPUT);

Serial.begin(9600); //baud rate bps mas taas mas dasig
}

void loop() {
  // put your main code here, to run repeatedly: PROCESS WITIWIW
// 8 bit ADC numerical value
adc_val = analogRead(POT);
Serial.printf("ADC Numerica Value: %d\n", adc_val); //%d - place holder diri masulod ang adc_val
//isa pagd ka way
//Serial.print("ADC Numerica Value"); 
//Serial.println(adc_val);
delay (500);

// Convert 8-bit ADC to actual voltage
voltage_in = (adc_val/255.0)*3.3;
Serial.printf("Input Voltage: %.2f\n", voltage_in);
delay(500);

//use multimeter to verify the actual voltage
dacWrite(DAC_PIN, adc_val); //1.8v to 2.3V
}
