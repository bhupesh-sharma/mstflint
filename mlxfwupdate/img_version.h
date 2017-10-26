
/*
 * Copyright (C) Jan 2006 Mellanox Technologies Ltd. All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef __IMG_VERSION_H__
#define __IMG_VERSION_H__

#include <string>
#include <compatibility.h>

using namespace std;

class ImgVersion {
public:
    ImgVersion();
    void   setVersion(const char* imgType, u_int8_t verSz, const u_int16_t* ver);
    int    compare(const ImgVersion &imv) const;
    string getPrintableVersion(int ffv,  bool show_type = true);
    string getTypeStr();
    u_int16_t getImgVerField(int index);
    u_int8_t  getVerNumFields();
    const u_int16_t* getVerArray();
    /*
    void   setExpansionRomtoUnknown();
    bool   isExpansionRomUnknown();
    */
private:
    int compareFw(const ImgVersion &imv) const;

    string _type;
    u_int16_t _ver[4];
    u_int8_t _verNumFields;
    bool _isExpansionRomUnkown;
};

#endif

