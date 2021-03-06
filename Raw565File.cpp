/*
 * Copyright (c) 2014, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <Raw565File.h>

void Raw565File::draw(TFT *dev, int16_t x, int16_t y) {
    uint16_t data[getWidth() * 2];
    dev->openWindow(x, y, getWidth(), getHeight());
    for (uint32_t ryi = 0; y < getHeight(); y++) {
        _file->read(data, getWidth() * 2);
        dev->windowData(data, getWidth());
    }
    dev->closeWindow();
}

void Raw565File::draw(TFT *dev, int16_t x, int16_t y, uint16_t trans) {
    dev->openWindow(x, y, getWidth(), getHeight());
    for (uint32_t i = 0; i < (getWidth() * getHeight()); i++) {
        uint16_t v = 0;
        _file->read(&v, 2);
        dev->windowData(v);
    }
    dev->closeWindow();
}

void Raw565File::drawTransformed(TFT *dev, int16_t x, int16_t y, uint8_t transform) {}
void Raw565File::drawTransformed(TFT *dev, int16_t x, int16_t y, uint8_t transform, uint16_t t) {}
