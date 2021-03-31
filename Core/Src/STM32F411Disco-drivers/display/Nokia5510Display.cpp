//
// Created by grzegorz on 3/25/21.
//

#include "Nokia5510Display.h"

tama::Nokia5510Display::Nokia5510Display(DisplayConfig & displayConfig)
{
    this->cfg = displayConfig;
    HAL_GPIO_WritePin(cfg.reset_port, cfg.reset_pin, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(cfg.reset_port, cfg.reset_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg.bl_port, cfg.bl_pin, GPIO_PIN_SET);
    writeCommand(0x21);
    writeCommand(0x04);
    writeCommand(0x10 | 0x04);
    writeCommand(0x80 | 0x41); //contrast
    writeCommand(0x20);
    writeCommand(0x08 | 0x04);
    for (int i = 0; i < 504; i++)
        displayPixel(0x0);
    writeCommand(0x20 | 0x00);
    writeCommand(0x80 | 0); // Wybˇr kolumny
    writeCommand(0x40 | 0); // Wybˇr wiersza
}

void tama::Nokia5510Display::displayData()
{

}

void tama::Nokia5510Display::setData(DisplayData & pixels)
{


	for (unsigned i = 0; i <504; ++i)
	{
		displayPixel(((uint8_t *)pixels.data)[i]);
	}

//    HAL_GPIO_WritePin(cfg.dc_port, cfg.dc_pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_RESET);
//    HAL_SPI_Transmit(cfg.spi, (uint8_t*)pixels.data, 252, 100);
//    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_SET);
//
//    HAL_GPIO_WritePin(cfg.dc_port, cfg.dc_pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_RESET);
//    HAL_SPI_Transmit(cfg.spi, ((uint8_t *)pixels.data + 252), 252, 100);
//    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_SET);
}


void tama::Nokia5510Display::displayPixel(uint8_t pixelData)
{
    HAL_GPIO_WritePin(cfg.dc_port, cfg.dc_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(cfg.spi, &pixelData, 1, 100);
    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_SET);
}

void tama::Nokia5510Display::writeCommand(uint8_t cmd)
{
    HAL_GPIO_WritePin(cfg.dc_port, cfg.dc_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(cfg.spi, &cmd, 1, 100);
    HAL_GPIO_WritePin(cfg.ce_port, cfg.ce_pin, GPIO_PIN_SET);
}
