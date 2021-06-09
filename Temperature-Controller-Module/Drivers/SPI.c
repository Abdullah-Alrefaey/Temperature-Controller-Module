/************************************************************************/
/*                          SPI    Driver                               */
/************************************************************************/
#include "SPI.h"
extern char PORTS[4];

/************************************************************************/
/* Function Description:                                                */
/* SPI Protocol Initialization. Master Mode is set, Also the Clock Phase*/
/* and Polarity. Pre-Scaler is set to 128                               */
/************************************************************************/
void SPI_MasterInit(void)
{	
	/* Set SS / MOSI / SCK  as output pins for master */
	DIO_vsetPINDir(PORTS[1], 4U, 1U);
	DIO_vsetPINDir(PORTS[1], 5U, 1U);
	DIO_vsetPINDir(PORTS[1], 7U, 1U);
	
	/* Set MISO as Input */
	DIO_vsetPINDir(PORTS[1], 6U, 0U);
	
	/* Enable Master mode */
	SPCR |= (U_ONE << MSTR);
	
	/* Select SPI Mode, Found Mode Compatible with Proteus 8.10 */
	SPCR &= ~(U_ONE << CPOL);
	SPCR |= (U_ONE << CPHA);

	/* Set clock to SC/128 */
	SPCR |= (U_ONE << SPR0);
	SPCR |= (U_ONE << SPR1);
	
	/* Enable SPI */
    SPCR |= (U_ONE << SPE);
}

/************************************************************************/
/* Function Description:                                                */
/* Main Data Send Function, The Data is Written on the Data Registers   */
/* The Shifting Operation then starts, Then the Content of the SPDR is  */
/* Returned                                                             */
/************************************************************************/
char SPI_MasterTransmitchar(char Data)
{	
	/* Write to SPDR */
	SPDR = Data;
	
	while( ((SPSR & (U_ONE << SPIF)) >> SPIF) == U_ZERO )
	{
			/* Await SPI Communication to Finish */
	}
	
	/* FLush SPDR Register */
	return SPDR ;
}
