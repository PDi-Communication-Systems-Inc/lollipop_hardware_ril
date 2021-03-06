/* //device/system/reference-ril/misc.h
**
** Copyright 2006, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
/* Copyright (C) 2011-2013 Freescale Semiconductor, Inc. */
#ifdef __cplusplus
extern "C" {
#endif
#include <utils/Log.h>
/* For Jelly Bean, it use ALOG */
#ifdef ALOGE
#define LOGE ALOGE
#define LOGW ALOGW
#define LOGI ALOGI
#define LOGD ALOGD
#endif

#define TLV_DATA(tlv, pos) (((unsigned)char2nib(tlv.data[(pos) * 2 + 0]) << 4) | \
((unsigned)char2nib(tlv.data[(pos) * 2 + 1]) << 0))

struct tlv {
    unsigned tag;
    const char *data;
    const char *end;
};

int parseTlv(const char *stream,
             const char *end,
             struct tlv *tlv);

/** returns 1 if line starts with prefix, 0 if it does not */
int strStartsWith(const char *line, const char *prefix);


int binaryToString(const unsigned char *binary,
                   size_t len,
                   char *string);

char char2nib(char c);


char *getFirstElementValue(const char *document,
                           const char *elementBeginTag,
                           const char *elementEndTag,
                           char **remainingDocument);

#ifdef __cplusplus
}
#endif
