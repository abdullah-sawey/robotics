/*
 * i2c.h
 *
 * Created: 4/28/2021 2:13:15 AM
 *  Author: abdul
 */ 


#ifndef I2C_H_
#define I2C_H_
uint8_t i2c_readNack(void);
uint8_t i2c_readAck(void);
uint8_t i2c_write(uint8_t byte_data);
void i2c_stop(void);
uint8_t i2c_start(uint8_t addr);
void init_i2c(void);


#endif /* I2C_H_ */