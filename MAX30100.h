#ifndef MAX30100_H
#define MAX30100_H

#define DEFAULT_MODE                MAX30100_MODE_HRONLY
#define DEFAULT_SAMPLING_RATE       MAX30100_SAMPRATE_100HZ
#define DEFAULT_PULSE_WIDTH         MAX30100_SPC_PW_1600US_16BITS
#define DEFAULT_RED_LED_CURRENT     MAX30100_LED_CURR_50MA
#define DEFAULT_IR_LED_CURRENT      MAX30100_LED_CURR_50MA
#define EXPECTED_PART_ID            0x11

ringBuffer_typedef(uint16_t, fifoBuffer);
fifoBuffer redBuffer, irBuffer;
fifoBuffer* redBuffer_ptr;
fifoBuffer* irBuffer_ptr;

bool begin();
bool isTemperatureReady();

uint8_t getPartId();
uint8_t readRegister(uint8_t address);
uint8_t retrieveTemperatureInteger();

float retrieveTemperature();

void writeRegister(uint8_t address, uint8_t data);
void setMode(Mode mode);
void setLedsPulseWidth(LEDPulseWidth ledPulseWidth);
void setSamplingRate(SamplingRate samplingRate);
void setLedsCurrent(LEDCurrent irLedCurrent, LEDCurrent redLedCurrent);
void setHighresModeEnabled(bool enabled);
void resetFifo();
void resume();
void shutdown();
void startTemperatureSampling();
void burstRead(uint8_t baseAddress, uint8_t *buffer, uint8_t length);
void readFifoData();
void update();
bool getRawValues(uint16_t *ir, uint16_t *red);

#endif
