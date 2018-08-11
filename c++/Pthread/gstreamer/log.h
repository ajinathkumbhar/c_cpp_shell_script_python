#include <stdio.h>

#ifndef TAG
#define TAG "app"
#endif

#define LOGD(msg) printf("%s  %s : %s:%d - %s \n" \
					,TAG,"D",__func__,__LINE__,msg)
#define LOGE(msg) printf("%s  %s : %s:%d - %s \n" \
					,TAG,"E",__func__,__LINE__,msg)
#define LOGI(msg) printf("%s  %s : %s:%d - %s \n" \
					,TAG,"I",__func__,__LINE__,msg)
