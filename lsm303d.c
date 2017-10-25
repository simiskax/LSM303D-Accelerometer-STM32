#include "stm32f10x.h"
#include "lsm303d.h"
 
#define LSM303D_ADDR	0x3a

void lsm_set_reg(uint8_t);
void lsm_set_reg(uint8_t reg)
{
 I2C_GenerateSTART(I2C1, ENABLE);
 while (I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS);
 I2C_Send7bitAddress(I2C1, LSM303D_ADDR, I2C_Direction_Transmitter);
 while (I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) != SUCCESS);
 
 I2C_SendData(I2C1, 0x80 | reg);
 while (I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTING) != SUCCESS);
}
 
void lsm_write(uint8_t reg, const void* data, int size)
{
 int i;
 const uint8_t* buffer = (uint8_t*)data;
 
 lsm_set_reg(reg);
 for (i = 0; i < size; i++) {
 I2C_SendData(I2C1, buffer[i]);
 while (I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTING) != SUCCESS);
 }
 I2C_GenerateSTOP(I2C1, ENABLE);
}
 
void lsm_read(uint8_t reg, void* data, int size)
{
 int i;
 uint8_t* buffer = (uint8_t*)data;
 
 lsm_set_reg(reg);
 
 I2C_GenerateSTART(I2C1, ENABLE);
 while (I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT) != SUCCESS);
 
 I2C_AcknowledgeConfig(I2C1, ENABLE);
 I2C_Send7bitAddress(I2C1, LSM303D_ADDR, I2C_Direction_Receiver);
 while (I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) != SUCCESS);
 
 for (i = 0; i < size - 1; i++) {
 while(I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED) != SUCCESS);
     buffer[i] = I2C_ReceiveData(I2C1);
    }
 I2C_AcknowledgeConfig(I2C1, DISABLE);
    I2C_GenerateSTOP(I2C1, ENABLE);
    while(I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED) != SUCCESS);
    buffer[i] = I2C_ReceiveData(I2C1);
}
 
void lsm_write_reg(uint8_t reg, uint8_t value)
{
 lsm_write(reg, &value, sizeof(value));
}
 
uint8_t lsm_read_reg(uint8_t reg)
{
 uint8_t value = 0;
 lsm_read(reg, &value, sizeof(value));
 return value;
}
 
int16_t lsm_read_value(uint8_t reg)
{
 int16_t value = 0;
 lsm_read(reg, &value, sizeof(value));
 return value;
}