/*!@addtogroup lego
 * @{
 * @defgroup legots Touch Sensor
 * Touch Sensor
 * @{
 */

/*
 * $Id: lego-touch.h 133 2013-03-10 15:15:38Z xander $
 */

#ifndef __LEGOTS_H__
#define __LEGOTS_H__
/** \file lego-touch.h
 * \brief Lego Touch Sensor driver
 *
 * lego-touch.h provides an API for the Lego Touch Sensor.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * License: You may use this code as you wish, provided you give credit where its due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER.

 * \author Xander Soldaat (xander_at_botbench.com)
 * \date 08 December 2009
 * \version 0.1
 * \example lego-touch-test1.c
 * \example lego-touch-SMUX-test1.c
 */

#pragma systemFile

#ifndef __COMMON_H__
#include "common.h"
#endif

bool TSreadState(tMUXSensor muxsensor);




#endif // __LEGOTS_H__

/*
 * $Id: lego-touch.h 133 2013-03-10 15:15:38Z xander $
 */
/* @} */
/* @} */
