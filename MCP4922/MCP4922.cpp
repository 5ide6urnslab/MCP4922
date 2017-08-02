
/*
 * File Name          : MCP4922.cpp
 * Author             : Show Kawabata(5ide6urns lab)
 * Version            : v0.02
 * Parts required     :
 * Description        :
 *
 * License            : Released under the MIT license.
 *                      http://opensource.org/licenses/mit-license.php
 *
 * Copyright          : Copyright (C) 2017 5ide6urns lab All right reserved.
 * History            : 07/27/2017 v0.01 Show Kawabata Create on.
 *                      08/01/2017 v0.02 Show Kawabata [New func] Change the Channel of MCP4922.
 */

#include "MCP4922.h"

/*!
 *  @fn         MCP4922 [Constructor]
 *  @brief      It is Constructor for MCP4922 class to
 *              initialize the data and initializing process.
 *
 *  @param[in]  void
 *  @return     void
 *  @version    v0.01
 *  @date       07/27/2017 v0.01  Create on.
 */
MCP4922::MCP4922(){

}

/*! 
 *  @fn         setup [Public function]
 *  @brief      It is starting process of MCP4922 device.
 *
 *  @param[in]  slaveSelect[]     :   Slave Pins.
 *              length            :   Slave Pins Number.
 *              spiClock          :   SPI Clock.
 *  @return     void
 *  @version    v0.01
 *  @date       07/27/2017 v0.01  Create on.
 */
void MCP4922::setup(unsigned char slaveSelect[], size_t length, unsigned char spiClock){
    
    for(byte i = 0; i < length; ++i) pinMode(slaveSelect[i], OUTPUT);
    SPI.begin();
    SPI.setClockDivider(spiClock);
    return;
}

/*! 
 *  @fn         write [Public function]
 *  @brief      It is writing process by SPI.
 *
 *  @param[in]  value             :    Writing Value.
 *              slaveSelect       :    Slave Pin.
 *              channel           :    Channel of MCP4922(OutA, OutB)
 *  @return     void
 *  @version    v0.01
 *  @date       07/27/2017 v0.01  Create on.
 *              08/01/2017 v0.02 Show Kawabata [New func] Change the Channel of MCP4922.
 */
void MCP4922::write(unsigned short value, unsigned char slaveSelect, unsigned char channel){
    
    /*  [Note]:
     *
     *       bit number     0                       1
     *      ----------------------------------------------------
     *       15             OutA                    OutB
     *       14             no Buffered             Buffering
     *       13             2x(Vout=2*VRef*D/4096)  1x(Vout=VRef*D/4096)
     *       12             Output buffer disabled  Output analog value from I/O
     */
    unsigned short out_ = (0 << 15) | (1 << 14) | (1<< 13) | (1 << 12) | ( value );
    
    if(channel == 1){
        out_ = (1 << 15) | (1 << 14) | (1<< 13) | (1 << 12) | ( value );
    }
    
    digitalWrite(slaveSelect, LOW);
    //  digitalWriteFast(slaveSelectPin,LOW);
    SPI.transfer(out_ >> 8);
    SPI.transfer(out_ & 0xFF);
    digitalWrite(slaveSelect, HIGH);
    //  digitalWriteFast(slaveSelectPin,HIGH);

    return;
}



 

 