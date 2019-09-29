extern "C"
{
	#include "freertos/FreeRTOS.h"
	#include "freertos/task.h"
	#include "nvs_flash.h"	
	#include "esp_log.h"
	#include "esp_system.h"
	#include "esp_partition.h"
	#include "esp_wifi.h"	
	#include "httpd.h"
	#include "httpdespfs.h"
	#include "cgiat.h"
	#include "atparse.h"
};

#include <iostream>
#include "testEmil.hpp"
#include "espfs.h"

static const char* TAG = "HTTPAT";

HttpdBuiltInUrl builtInUrls[] = {
    {"/", cgiRedirect, "/login.html"},
    {"/routeinfo", cgiRouteInfo, NULL},
    {"/showapinfo", cgiShowApInfo, NULL},
    {"/configapinfo", cgiConfigApInfo, NULL},
    {"/connap", cgiConnAp, NULL},
    {"/getramsize", getRamSize, NULL},
    {"/ping", cgiping, NULL},
    {"/rst", cgirst, NULL},
    {"/restore", cgirestore, NULL},
    {"/loginpwd", cgiloginpwd, NULL},
    {"/changeloginpwd", cgiChangeLoginPwd, NULL},
    {"/closeap", cgiCloseAp, NULL},
    {"/setap", cgiSetAp, NULL},
    {"/scanap", cgiScanAp, NULL},
    {"/setdhcp", cgiSetDhcp, NULL},
    {"/showdhcpinfo", cgiShowDhcp, NULL},
    {"/setstaipinfo", cgiSetStaIpInfo, NULL},
    {"/setapipinfo", cgiSetApIpInfo, NULL},
    {"/setstamac", cgiSetStaMac, NULL},
    {"/setapmac", cgiSetApMac, NULL},
    {"/connip", cgiConnIp, NULL},
    {"/closeip", cgiCloseIp, NULL},
    {"/getipstatus", cgiGetIpStatus, NULL},
    {"/softapdevice", getConnDev, NULL},

    {"/bleset", cgiBleSet, NULL},
    {"/blescan", cgiBleScan, NULL},
    {"/getbleset", cgiGetBleSet, NULL},
    {"/bleconnect", cgiBleConn, NULL},
    {"/getbleconnect", cgiGetBleConn, NULL},
    {"/blecloseconnect", cgiBleCloseConn, NULL},
    {"/bleadvset", cgiBleAdvSet, NULL},
    {"/getbleadvset", cgiGetBleAdvSet, NULL},
    {"/bleadvstart", cgiBleAdvStart, NULL},
    {"/bleadvstop", cgiBleAdvStop, NULL},
    {"*", cgiEspFsHook, NULL}, //Catch-all cgi function for the filesystem
    {NULL, NULL, NULL}
};

extern "C" void app_main()
{
	int ret = 0;
	Venky niki;
	std::cout << "Welcome to c++" <<  niki.print() <<std::endl;
	
	nvs_flash_init();
	esp_at_init_parse();
	ret = espFsInit();
	httpdInit(builtInUrls, 80);
}
