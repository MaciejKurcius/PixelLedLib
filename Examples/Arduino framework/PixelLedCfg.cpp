/**
 * @file PixelLedCfg.cpp
 * @author Maciej Kurcius
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <PixelLedCfg.h>

SPIClass PixelSpi(PIXEL_MOSI, PB14, PIXEL_SCK);
PixelLedClass PixelStrip(PIXEL_LENGTH);
PixelStripSubsetClass RL_Light(&PixelStrip, 0, 4);
PixelStripSubsetClass FL_Light(&PixelStrip, 5, 8);
PixelStripSubsetClass FR_Light(&PixelStrip, 9, 12);
PixelStripSubsetClass RR_Light(&PixelStrip, 13, 17);


uint8_t PixelInitActions(void){
    PixelStrip.PixelStripMapSwap(13,17);
    PixelStrip.PixelStripMapSwap(14,16);
}

uint8_t PixelSpiInit(void){
    SPISettings SpiSettings(PIXEL_SPI_SPEED, LSBFIRST, SPI_MODE3, SPI_TRANSMITONLY);
    PixelSpi.beginTransaction(CS_PIN_CONTROLLED_BY_USER, SpiSettings);
}

void PixelSpiTransferData(uint8_t Data_){
    PixelSpi.transfer(Data_);
}

void PixelDelay(uint16_t Time_){
    Delay(Time_)
}