
/*
 * File Name          : MCP4922.h
 * Author             : Show Kawabata(5ide6urns lab)
 * Version            : v0.02
 * Date               : 07/27/2017
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

#ifndef MCP4922_H
#define MCP4922_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <SPI.h>


class MCP4922
{
  public:
    MCP4922();
    void setup(unsigned char slaveSelect[], size_t length, unsigned char spiClock);
    void write(unsigned short value, unsigned char slaveSelect, unsigned char channel);

  private:

};

#endif
