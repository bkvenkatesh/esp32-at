/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on ESPRESSIF SYSTEMS ESP32 only, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __AT_CONFIG_H__
#define __AT_CONFIG_H__

#if defined(CONFIG_AT_OTA_SUPPORT)
#define CONFIG_ESP_AT_OTA_TOKEN_DEFAULT       CONFIG_AT_OTA_TOKEN_KEY
#if defined(CONFIG_AT_OTA_SSL_SUPPORT)
#define CONFIG_ESP_AT_OTA_SSL_TOKEN_DEFAULT   CONFIG_AT_OTA_SSL_TOKEN_KEY
#else
#define CONFIG_ESP_AT_OTA_SSL_TOKEN_DEFAULT   CONFIG_AT_OTA_TOKEN_KEY
#endif
#else
#define CONFIG_ESP_AT_OTA_TOKEN_DEFAULT       NULL
#define CONFIG_ESP_AT_OTA_SSL_TOKEN_DEFAULT   NULL
#endif

#if defined(CONFIG_TARGET_PLATFORM_ESP32)
#define CONFIG_ESP_AT_OTA_TOKEN_WROOM32        CONFIG_ESP_AT_OTA_TOKEN_DEFAULT
#define CONFIG_ESP_AT_OTA_TOKEN_WROVER32       CONFIG_ESP_AT_OTA_TOKEN_DEFAULT
#define CONFIG_ESP_AT_OTA_TOKEN_ESP32_PICO_D4  CONFIG_ESP_AT_OTA_TOKEN_DEFAULT
#define CONFIG_ESP_AT_OTA_TOKEN_ESP32_SOLO_1   CONFIG_ESP_AT_OTA_TOKEN_DEFAULT

#define CONFIG_ESP_AT_OTA_SSL_TOKEN_WROOM32        CONFIG_ESP_AT_OTA_SSL_TOKEN_DEFAULT
#define CONFIG_ESP_AT_OTA_SSL_TOKEN_WROVER32       CONFIG_ESP_AT_OTA_SSL_TOKEN_DEFAULT
#define CONFIG_ESP_AT_OTA_SSL_TOKEN_ESP32_PICO_D4  CONFIG_ESP_AT_OTA_SSL_TOKEN_DEFAULT
#define CONFIG_ESP_AT_OTA_SSL_TOKEN_ESP32_SOLO_1   CONFIG_ESP_AT_OTA_SSL_TOKEN_DEFAULT
#endif
#endif