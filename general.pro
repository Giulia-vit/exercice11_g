
TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++17 -g

# Input
HEADERS += argon.h \
           contenu.h \
           dessinable.h \
           Enceinte.h \
           neon.h \
           Particule.h \
           support_a_dessin.h \
           Systeme.h \
           testrandom.h \
           textviewer.h \
           Vecteur3D.h\
           ParticuleTrajet.h 
SOURCES += argon.cc \
           Enceinte.cc \
           neon.cc \
           Particule.cc \
           Systeme.cc \
           testParticule.cc \
           testrandom.cc \
           testSystem1.cc \
           testVecteur3D.cc \
           Vecteur3D.cc\
           ParticuleTrajet.cc 
