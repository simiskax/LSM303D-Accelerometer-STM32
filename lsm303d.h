#ifndef LSM303D_H_
#define LSM303D_H_
 
#include <stdint.h>
 
#define LSM303D_TEMP_OUT			0x05
#define LSM303D_STATUS_M			0x07
#define LSM303D_OUT_X_M				0x08
#define LSM303D_OUT_Y_M				0x0a
#define LSM303D_OUT_Z_M				0x0c
#define LSM303D_WHO_AM_I			0x0f
#define LSM303D_CTRL0				0x1f
#define LSM303D_CTRL1				0x20
#define LSM303D_CTRL2				0x21
#define LSM303D_CTRL3				0x22
#define LSM303D_CTRL4				0x23
#define LSM303D_CTRL5				0x24
#define LSM303D_CTRL6				0x25
#define LSM303D_CTRL7				0x26
#define LSM303D_STATUS				0x27
#define LSM303D_OUT_X_A				0x28
#define LSM303D_OUT_Y_A				0x2a
#define LSM303D_OUT_Z_A				0x2c
 
extern void lsm_write(uint8_t reg, const void* data, int size);
extern void lsm_read(uint8_t reg, void* data, int size);
 
extern void lsm_write_reg(uint8_t reg, uint8_t value);
extern uint8_t lsm_read_reg(uint8_t reg);
extern int16_t lsm_read_value(uint8_t reg);
 
#endif /* LSM303D_H_ */