/*
 *    UFLogger - Cross-platform Arduino Logger
 *    Copyright 2026 UDFOwner
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    You may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    More details: https://udfsoft.com/
 */

#pragma once
#include <Arduino.h>

#ifndef USER_DEBUG_LEVEL
  #define USER_DEBUG_LEVEL 3
#endif

// --- Platform detection ---
#if defined(ESP32) || defined(ESP8266)
  #define UFLOGGER_USE_PRINTF 1
#else
  #define UFLOGGER_USE_PRINTF 0
#endif

// --- Internal macros ---
#if UFLOGGER_USE_PRINTF
  #define _LOG_PF(tag, fmt, ...) Serial.printf_P(PSTR("[" tag "] " fmt "\n"), ##__VA_ARGS__)
  #define _LOG_PF_FULL(tag, fmt, ...) Serial.printf_P(PSTR("[" tag "][%s:%d] " fmt "\n"), __FILE__, __LINE__, ##__VA_ARGS__)
#else
  // Fallback for AVR / boards without printf
  #define _LOG_PF(tag, fmt, ...) do { Serial.print("[" tag "] "); Serial.println(fmt); } while(0)
  #define _LOG_PF_FULL(tag, fmt, ...) do { Serial.print("[" tag "][" __FILE__ ":" ); Serial.print(__LINE__); Serial.print("] "); Serial.println(fmt); } while(0)
#endif

// --- Log macros ---
#if USER_DEBUG_LEVEL >= 1
  #define log_e(fmt, ...) _LOG_PF_FULL("E", fmt, ##__VA_ARGS__)
#else
  #define log_e(...) ((void)0)
#endif

#if USER_DEBUG_LEVEL >= 2
  #define log_w(fmt, ...) _LOG_PF_FULL("W", fmt, ##__VA_ARGS__)
#else
  #define log_w(...) ((void)0)
#endif

#if USER_DEBUG_LEVEL >= 3
  #define log_i(fmt, ...) _LOG_PF("I", fmt, ##__VA_ARGS__)
#else
  #define log_i(...) ((void)0)
#endif

#if USER_DEBUG_LEVEL >= 4
  #define log_d(fmt, ...) _LOG_PF_FULL("D", fmt, ##__VA_ARGS__)
#else
  #define log_d(...) ((void)0)
#endif

#if USER_DEBUG_LEVEL >= 5
  #define log_v(fmt, ...) _LOG_PF("V", fmt, ##__VA_ARGS__)
#else
  #define log_v(...) ((void)0)
#endif
