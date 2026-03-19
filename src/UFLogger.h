/*
 *    Copyright 2026 UDFOwner
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 *
 *    More details: https://udfsoft.com/
 */

#pragma once
#include <Arduino.h>

#ifndef USER_DEBUG_LEVEL
  #define USER_DEBUG_LEVEL 3
#endif

#ifdef ESP32
  #include "esp32-hal-log.h"
#else

  #define _LOG_PF(tag, fmt, ...) Serial.printf_P(PSTR("[" tag "] " fmt "\n"), ##__VA_ARGS__)
  #define _LOG_PF_FULL(tag, fmt, ...) Serial.printf_P(PSTR("[" tag "][%s:%d] " fmt "\n"), __FILE__, __LINE__, ##__VA_ARGS__)

  #if USER_DEBUG_LEVEL >= 1
    #define log_e(fmt, ...) _LOG_PF_FULL("E", fmt, ##__VA_ARGS__)
  #endif
  #if USER_DEBUG_LEVEL >= 2
    #define log_w(fmt, ...) _LOG_PF_FULL("W", fmt, ##__VA_ARGS__)
  #endif
  #if USER_DEBUG_LEVEL >= 3
    #define log_i(fmt, ...) _LOG_PF("I", fmt, ##__VA_ARGS__)
  #endif
  #if USER_DEBUG_LEVEL >= 4
    #define log_d(fmt, ...) Serial.printf_P(PSTR("[D][%s] " fmt "\n"), __FUNCTION__, ##__VA_ARGS__)
  #endif
  #if USER_DEBUG_LEVEL >= 5
    #define log_v(fmt, ...) _LOG_PF("V", fmt, ##__VA_ARGS__)
  #endif

  #ifndef log_e
    #define log_e(...) ((void)0)
  #endif
  #ifndef log_w
    #define log_w(...) ((void)0)
  #endif
  #ifndef log_i
    #define log_i(...) ((void)0)
  #endif
  #ifndef log_d
    #define log_d(...) ((void)0)
  #endif
  #ifndef log_v
    #define log_v(...) ((void)0)
  #endif
#endif
