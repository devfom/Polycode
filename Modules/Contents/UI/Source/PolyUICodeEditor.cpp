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

#include <cstdio>
#include "PolyUICodeEditor.h"
#include "Scintilla.h"
#include "SciLexer.h"

using namespace Polycode;


PolyUICodeEditor::PolyUICodeEditor(String windowName, Number width, Number height)
: BaseClass(windowName, width, height)
{
    printf("***DEBUG***: %s\n", __FUNCTION__);

    scintilla = new Scintilla::ScintillaPolycode(this);
    scintilla->WndProc(SCI_SETLEXER, SCLEX_CPP, 0);
    scintilla->WndProc(SCI_INSERTTEXT, 0, (sptr_t)
        "int main(int argc, char **argv) {\n"
        "    // Start up the gnome\n"
        "    gnome_init(\"stest\", \"1.0\", argc, argv);\n}"
    );
}

PolyUICodeEditor::~PolyUICodeEditor()
{
    if (scintilla)
    {
        delete scintilla;
        scintilla = NULL;
    }
    
}
