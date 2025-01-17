#!/bin/bash
#
# ESPRESSIF MIT License
#
# Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
#
# Permission is hereby granted for use on ESPRESSIF SYSTEMS ESP32 only, in which case,
# it is free of charge, to any person obtaining a copy of this software and associated
# documentation files (the "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the Software is furnished
# to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

PARTITION_NAME=$1
TARGET_FOLDER=$2
TOOL_PATH=$IDF_PATH/../tools/factory_param_generate.py

RAW_DATA_FOLDER=$IDF_PATH/../components/customized_partitions/raw_data/factory_param

MODULE_FILE=$(ls $RAW_DATA_FOLDER/factory_param_data.csv | awk '{print $1}')
DEFINE_FILE=$(ls $RAW_DATA_FOLDER/factory_param_type.csv | awk '{print $1}')

LOG_FILE=$PROJECT_PATH/build/factory/factory_parameter.log

echo "generating factory_param.bin($MODULE_NAME): python $TOOL_PATH -t $TARGET_FOLDER/$PARTITION_NAME.bin $MODULE_FILE"

python $TOOL_PATH --platform $ESP_AT_PROJECT_PLATFORM --module WROVER-32 --bin_name $TARGET_FOLDER/$PARTITION_NAME.bin --define_file $DEFINE_FILE --module_file $MODULE_FILE --log_file $LOG_FILE
