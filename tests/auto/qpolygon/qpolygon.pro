load(qttest_p4)
QT += widgets
SOURCES  += tst_qpolygon.cpp

unix:!mac:!symbian:LIBS+=-lm


