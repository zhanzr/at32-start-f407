FCARM=/d/Keil_v5/ARM/BIN/FCARM.exe
OUTPUT=binary_resource.c
#$FCARM 404.html,atstartf407_with_ethernet.jpg,board_info.html,board_little.jpg,favicon.ico,homepage.html TO $OUTPUT

#Only Transfer the binary file
$FCARM adc_info.html,led_info.html,homepage.html,atstartf407_with_ethernet.jpg,favicon.ico TO $OUTPUT

echo "post processing"
sed -i 's/#include <Net_Config.h>/\/\/#include <Net_Config.h>/' $OUTPUT
sed -i '1 a post processed by zhanzr21 script' $OUTPUT
sed -i '11 a #include <inttypes.h>' $OUTPUT
sed -i '12 a #include "at32f403a_407_board.h"' $OUTPUT
sed -i 's/U32/uint32_t/' $OUTPUT
sed -i 's/U8/uint8_t/' $OUTPUT
echo "post process complete"

