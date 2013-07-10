################################################################
# Qwt Widget Library
# Copyright (C) 1997   Josef Wilgen
# Copyright (C) 2013   Biaoqin Wen
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the Qwt License, Version 1.0
###################################################################

win32 {
	QWT_ROOT = $$system( echo %QWT_ROOT% )
} else {
	QWT_ROOT = $$system( echo $QWT_ROOT )
}

include( $${QWT_ROOT}/qwtconfig.pri )
include( $${QWT_ROOT}/qwtfunctions.pri )

TEMPLATE     = app


QMAKE_RPATHDIR *= $${QWT_ROOT}/lib

contains(QWT_CONFIG, QwtFramework) {

    LIBS      += -F$${QWT_ROOT}/lib
}
else {

    LIBS      += -L$${QWT_ROOT}/lib
}

qwtAddLibrary(qwt)

greaterThan(QT_MAJOR_VERSION, 4) {

    QT += printsupport
    QT += concurrent
}

contains(QWT_CONFIG, QwtOpenGL ) {

    QT += opengl
}
else {

    DEFINES += QWT_NO_OPENGL
}

contains(QWT_CONFIG, QwtSvg) {

    QT += svg
}
else {

    DEFINES += QWT_NO_SVG
}


win32 {
    contains(QWT_CONFIG, QwtDll) {
        DEFINES    += QT_DLL QWT_DLL
    }
}
