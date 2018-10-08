# LSM303D-Accelerometer-STM32

in lsm303d.h header file : 
---------------------------------------------------------------

/*
@brief:Accelerometer write function,data is written to reg adress up to size

@param:uint8_t reg, const void* data, int size

@return:-
*/

1.void lsm_write(uint8_t reg, const void* data, int size);
---------------------------------------------------------------
/*
@brief:Accelerometer write function,data is read from reg adress up to size

@param:uint8_t reg, void* data, int size

@return:-
*/

2.void lsm_read(uint8_t reg, void* data, int size);
---------------------------------------------------------------

 /*
@brief:Accelerometer register value write function

@param:uint8_t reg, uint8_t value

@return:-

*/

3.void lsm_write_reg(uint8_t reg, uint8_t value);
---------------------------------------------------------------

/*
@brief:Accelerometer register read function

@param:uint8_t reg

@return: register

*/

4.uint8_t lsm_read_reg(uint8_t reg);
---------------------------------------------------------------

/*
@brief:Accelerometer register read function

@param:uint8_t reg

@return:register value
*/

5.int16_t lsm_read_value(uint8_t reg);
---------------------------------------------------------------
