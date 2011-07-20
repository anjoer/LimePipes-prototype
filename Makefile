#############################################################################
# Makefile for building: limepipes
# Generated by qmake (2.01a) (Qt 4.6.2) on: Sa. Jul 16 11:49:15 2011
# Project:  limepipes.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile limepipes.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		pipetune.cpp \
		musicbar.cpp \
		symbol.cpp \
		controlsymbol.cpp \
		melodysymbol.cpp \
		melodynote.cpp \
		embellishment.cpp \
		pitch.cpp \
		ghbtune.cpp \
		pitchlist.cpp \
		ghbpitchlist.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		pipetune.o \
		musicbar.o \
		symbol.o \
		controlsymbol.o \
		melodysymbol.o \
		melodynote.o \
		embellishment.o \
		pitch.o \
		ghbtune.o \
		pitchlist.o \
		ghbpitchlist.o \
		moc_mainwindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		limepipes.pro
QMAKE_TARGET  = limepipes
DESTDIR       = 
TARGET        = limepipes

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: limepipes.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile limepipes.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile limepipes.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/limepipes1.0.0 || $(MKDIR) .tmp/limepipes1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/limepipes1.0.0/ && $(COPY_FILE) --parents mainwindow.h pipetune.h musicbar.h symbol.h controlsymbol.h melodysymbol.h melodynote.h embellishment.h itemtypes.h pitch.h ghbtune.h pitchlist.h ghbpitchlist.h .tmp/limepipes1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp pipetune.cpp musicbar.cpp symbol.cpp controlsymbol.cpp melodysymbol.cpp melodynote.cpp embellishment.cpp pitch.cpp ghbtune.cpp pitchlist.cpp ghbpitchlist.cpp .tmp/limepipes1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/limepipes1.0.0/ && (cd `dirname .tmp/limepipes1.0.0` && $(TAR) limepipes1.0.0.tar limepipes1.0.0 && $(COMPRESS) limepipes1.0.0.tar) && $(MOVE) `dirname .tmp/limepipes1.0.0`/limepipes1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/limepipes1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		ghbtune.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

pipetune.o: pipetune.cpp pipetune.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pipetune.o pipetune.cpp

musicbar.o: musicbar.cpp musicbar.h \
		itemtypes.h \
		pitchlist.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o musicbar.o musicbar.cpp

symbol.o: symbol.cpp symbol.h \
		pitch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o symbol.o symbol.cpp

controlsymbol.o: controlsymbol.cpp controlsymbol.h \
		symbol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o controlsymbol.o controlsymbol.cpp

melodysymbol.o: melodysymbol.cpp melodysymbol.h \
		symbol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o melodysymbol.o melodysymbol.cpp

melodynote.o: melodynote.cpp melodynote.h \
		melodysymbol.h \
		symbol.h \
		itemtypes.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o melodynote.o melodynote.cpp

embellishment.o: embellishment.cpp embellishment.h \
		melodysymbol.h \
		symbol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o embellishment.o embellishment.cpp

pitch.o: pitch.cpp pitch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pitch.o pitch.cpp

ghbtune.o: ghbtune.cpp ghbtune.h \
		ghbpitchlist.h \
		pitchlist.h \
		symbol.h \
		musicbar.h \
		itemtypes.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ghbtune.o ghbtune.cpp

pitchlist.o: pitchlist.cpp pitchlist.h \
		pitch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pitchlist.o pitchlist.cpp

ghbpitchlist.o: ghbpitchlist.cpp ghbpitchlist.h \
		pitchlist.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ghbpitchlist.o ghbpitchlist.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

