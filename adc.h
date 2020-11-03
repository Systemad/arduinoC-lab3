#ifndef _ADC_H_
#define _ADC_H_

void init_adc(void);

const uint8_t convert_range(uint32_t reference_value, uint32_t reference_minimum, uint32_t reference_maximum, uint32_t out_minimum, uint32_t out_maximum);

#endif // _ADC_H_

