/*
 * spi_driver.h
 *
 * Created: 3/10/2018 5:20:42 PM
 *  Author: Mohamed Zaghlol
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_
void SPI_MasterInit(void);
void SPI_SlaveInit(void);
unsigned char SPI_MasterTransmitchar(unsigned char Data);
unsigned char SPI_SlaveReceivechar(unsigned char Data);
void SPI_MasterTransmitstring(unsigned char *ptr);
#endif /* SPI_DRIVER_H_ */