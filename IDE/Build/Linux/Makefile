CC=gcc
INC_PATH=-I../../Contents/Include -I../../../Release/Linux/Framework/Core/Dependencies/include -I../../../Release/Linux/Framework/Core/Dependencies/include/AL -I../../../Release/Linux/Framework/Core/include -I../../../Release/Linux/Framework/Modules/include -I../../../Release/Linux/Framework/Modules/Dependencies/include -I../../../Release/Linux/Framework/Modules/Dependencies/include/bullet -I../../../Release/Linux/Framework/Core/Dependencies/include/scintilla331
CFLAGS=-DUSE_POLYCODEUI_FILE_DIALOGS -DUSE_POLYCODEUI_MENUBAR -DSCI_NAMESPACE
LINK_PATH=-L../../../Release/Linux/Framework/Core/lib/ -L../../../Release/Linux/Framework/Core/Dependencies/lib/ -L../../../Release/Linux/Framework/Modules/Dependencies/lib/ -L../../../Release/Linux/Framework/Modules/lib/
LDFLAGS=-lrt -ldl -lpthread -lPolycore -lfreetype -llibvorbisfile -llibvorbis -llibogg -lopenal -lphysfs -lpng15 -lz -lGL -lGLU -lSDL -lPolycode2DPhysics -lBox2D -lPolycode3DPhysics -lBulletDynamics -lBulletCollision -lLinearMath -Wl, --start-group -lPolycodeUI -lscintilla3.3.1 -Wl, --end-group
LDFLAGS_DEBUG=-lrt -ldl -lm -lstdc++ -lpthread -lz -lGL -lGLU -lSDL -lPolycore_d -lfreetype_d -llibvorbisfiled -llibvorbisd -lliboggd -lopenal -lphysfsd -lpng15d -lz  -lPolycode2DPhysics_d -lBox2D_d -lPolycode3DPhysics_d -lBulletDynamics_d -lBulletCollision_d -lLinearMath_d -Wl,--start-group -lPolycodeUI_d -lscintilla3.3.1d -Wl,--end-group
SRCS=../../Contents/Source/ExampleBrowserWindow.cpp ../../Contents/Source/PolycodeEditorManager.cpp  ../../Contents/Source/PolycodeProject.cpp        ../../Contents/Source/PolycodeScreenEditor.cpp ../../Contents/Source/ExportProjectWindow.cpp  ../../Contents/Source/PolycodeFontEditor.cpp     ../../Contents/Source/PolycodeProjectBrowser.cpp ../../Contents/Source/PolycodeSpriteEditor.cpp ../../Contents/Source/NewFileWindow.cpp        ../../Contents/Source/PolycodeFrame.cpp          ../../Contents/Source/PolycodeProjectEditor.cpp  ../../Contents/Source/PolycodeTextEditor.cpp ../../Contents/Source/NewProjectWindow.cpp     ../../Contents/Source/PolycodeIDEApp.cpp         ../../Contents/Source/PolycodeProjectManager.cpp ../../Contents/Source/PolycodeToolLauncher.cpp ../../Contents/Source/PolycodeConsole.cpp      ../../Contents/Source/PolycodeImageEditor.cpp    ../../Contents/Source/PolycodeProps.cpp          ../../Contents/Source/TextureBrowser.cpp ../../Contents/Source/PolycodeEditor.cpp       ../../Contents/Source/PolycodeMaterialEditor.cpp ../../Contents/Source/PolycodeRemoteDebugger.cpp ../../Contents/Source/ToolWindows.cpp ../../Contents/Source/PolycodeClipboard.cpp

default:
	mkdir -p ./Build
	$(CC) $(INC_PATH) $(CFLAGS) -O2 main.cpp $(SRCS) -o ./Build/Polycode $(LINK_PATH) $(LDFLAGS)
	cp -R ../../Contents/Resources/* Build/
	cp ../../../Release/Linux/Framework/Core/Assets/default.pak Build/
	cp -R ../../../Release/Linux/Standalone Build
debug:
	mkdir -p ./Build
	$(CC) $(INC_PATH) $(CFLAGS) -g main.cpp $(SRCS) -o ./Build/Polycode $(LINK_PATH) $(LDFLAGS_DEBUG)
	cp -R ../../Contents/Resources/* Build/
	cp ../../../Release/Linux/Framework/Core/Assets/default.pak Build/
	cp -R ../../../Release/Linux/Standalone Build

clean:
	rm -rf ./Build
	
