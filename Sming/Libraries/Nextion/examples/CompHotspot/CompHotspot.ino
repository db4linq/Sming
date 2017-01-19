/**
 * @example CompHotspot.ino
 *
 * @par How to Use
 * Show how to use API of class NexHotspot.  
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/7/10
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "Nextion.h"

NexHotspot hot0    = NexHotspot(0, 1, "hot0");
NexHotspot hot1    = NexHotspot(0, 2, "hot1");

NexTouch *nex_listen_list[] = 
{
    &hot0,
    &hot1,
    NULL
};

void hot0PushCallback(void *ptr)
{
    dbSerialPrint("hot0PushCallback");
    dbSerialPrint("ptr=");
    dbSerialPrint((uint32_t)ptr);
}

void hot1PushCallback(void *ptr)
{
    dbSerialPrint("hot1PushCallback");    
    dbSerialPrint("ptr=");
    dbSerialPrint((uint32_t)ptr);
}

void hot0PopCallback(void *ptr)
{
    dbSerialPrint("hot0PopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrint((uint32_t)ptr);
}

void hot1PopCallback(void *ptr)
{
    dbSerialPrint("hot1PopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrint((uint32_t)ptr);
}

void setup(void)
{
    nexInit();
    hot0.attachPush(hot0PushCallback, &hot0);
    hot0.attachPop(hot0PopCallback, &hot0);
    hot1.attachPush(hot1PushCallback, &hot1);
    hot1.attachPop(hot1PopCallback, &hot1);
    dbSerialPrint("setup done");
}

void loop(void)
{
    nexLoop(nex_listen_list);
}
