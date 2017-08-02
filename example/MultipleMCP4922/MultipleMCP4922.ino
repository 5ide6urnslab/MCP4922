/*************************************************************************
 * File Name          : MultipleMCP4922
 * Author             : Show Kawabata(5ide6urns lab)
 * Version            : v0.01
 * Date               : 07/26/2017
 * Parts required     :
 * Description        :
 *
 * License            : Released under the MIT license.
 *                      http://opensource.org/licenses/mit-license.php
 *
 * Copyright          : Copyright (C) 2017 5ide6urns lab All right reserved.
 *
 * History            : 07/26/2017 v0.01 Show Kawabata Create on.
 **************************************************************************/

#include <Arduino.h>
#include <MCP4922.h>


#define DEF_DAC_SLAVE_A_1  10
#define DEF_DAC_SLAVE_B_1  9

#define DEF_DAC_CHANNEL_A  0
#define DEF_DAC_CHANNEL_B  1

//(11,13,10,5)(MOSI,SCK,CS,LDAC)
MCP4922 _laser = MCP4922();

void setup(){
  unsigned char slaveSelect_[] = {DEF_DAC_SLAVE_A_1, DEF_DAC_SLAVE_B_1};

  _laser.setup(slaveSelect_,
               sizeof(slaveSelect_) / sizeof(slaveSelect_[0]),
               SPI_CLOCK_DIV2); // 24MHz
  return;
}

void loop(){
  _laser.write(4095, DEF_DAC_SLAVE_A_1, DEF_DAC_CHANNEL_A);
  _laser.write(0, DEF_DAC_SLAVE_B_1, DEF_DAC_CHANNEL_A);
  delay(1000);
  _laser.write(0, DEF_DAC_SLAVE_A_1, DEF_DAC_CHANNEL_A);
  _laser.write(4095, DEF_DAC_SLAVE_B_1, DEF_DAC_CHANNEL_A);
  delay(1000);
  return;
}
