#include "display.h"

void display_setup(struct display_config * cfg)
{
    HAL_GPIO_WritePin(cfg->reset_port, cfg->reset_pin, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(cfg->reset_port, cfg->reset_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->bl_port, cfg->bl_pin, GPIO_PIN_SET);
    display_write_cmd(cfg, 0x21);
    display_write_cmd(cfg, 0x04);
    display_write_cmd(cfg, 0x10 | 0x04);
    display_write_cmd(cfg, 0x80 | 0x41); //contrast
    display_write_cmd(cfg, 0x20);
    display_write_cmd(cfg, 0x08 | 0x04);
    for (int i = 0; i < 504; i++)
        display_write_data(cfg, 0x00);
}

void display_set_dxy(struct display_config * cfg,
                     enum display_direction direction,
                     uint8_t column, uint8_t row)
{
    if(direction == vertical)
        display_write_cmd(cfg, 0x20 | 0x02);
    else
        display_write_cmd(cfg, 0x20 | 0x00);

    display_write_cmd(cfg, 0x80 | column); // Wybˇr kolumny
    display_write_cmd(cfg, 0x40 | row); // Wybˇr wiersza
}

void display_write_cmd(struct display_config * cfg, uint8_t cmd) {
    HAL_GPIO_WritePin(cfg->dc_port, cfg->dc_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(cfg->spi, &cmd, 1, 100);
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_SET);
}

void display_write_data(struct display_config * cfg, uint8_t data) {
    HAL_GPIO_WritePin(cfg->dc_port, cfg->dc_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(cfg->spi, &data, 1, 100);
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_SET);
}
