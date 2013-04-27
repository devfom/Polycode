/*
Copyright (C) 2013 by Vasily Fomin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <algorithm>
#include <cstdio>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "PolyFont.h"
#include "PolyFontMetrics.h"

// TODO: THink about making this class friend of the PolyFont
using namespace Polycode;

PolyFontMetrics::PolyFontMetrics(Font* font)
    : m_font(font)
{

}

PolyFontMetrics::~PolyFontMetrics()
{

}

int PolyFontMetrics::ascent() const
{
    FT_Face face =m_font->getFace();
    return face->ascender;
}

int PolyFontMetrics::descent() const
{
    FT_Face face = m_font->getFace();
    return face->descender;
}

int PolyFontMetrics::width(const String& text, int len) const
{   
    const std::string& str = text.getSTLString();
    
    int begin = 0;    
    std::string::size_type usedLen = std::max(len, 0);
    int end = std::min(str.size(), usedLen);

    int returnValue = 0;
    for (int charPosition = begin; charPosition < end; ++charPosition)
    {
        returnValue += width(str.at(charPosition));

    }

    return returnValue; 
}

int PolyFontMetrics::width(char ch) const
{
    printf("***DEBUG***: %s\n", __PRETTY_FUNCTION__);    

    // TODO: what about Unicode?
    FT_Face face = m_font->getFace();
    
    FT_Set_Char_Size(face, face->units_per_EM << 6, face->units_per_EM << 6, 0, 0);
    int result = FT_Load_Char(face, (int)ch, FT_LOAD_RENDER);
    printf("***DEBUG***: Result is %d\n", result);    

    // FT_Load_Char(face, (int)ch, FT_LOAD_RENDER);
    // FT_Load_Glyph(face, glyph, FT_LOAD_NO_BITMAP);

    int left  = face->glyph->metrics.horiBearingX;
    int right = face->glyph->metrics.horiBearingX + face->glyph->metrics.width;
    int top    = face->glyph->metrics.horiBearingY;
    int bottom = face->glyph->metrics.horiBearingY - face->glyph->metrics.height;

    printf("***DEBUG***: left-[%d], right-[%d], top-[%d], bottom-[%d]\n", left, right, top, bottom);    
    
    int width = right-left;
    int height = top-bottom;

    return width;
}

int PolyFontMetrics::averageCharWidth() const
{
    FT_Face face = m_font->getFace();
    printf("***DEBUG***: Av is %d\n", face->num_fixed_sizes);    
    printf("***DEBUG***: Size is %d\n", face->size);    


    return 0;
}
