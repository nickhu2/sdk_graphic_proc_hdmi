#
# This file is the qtreplay recipe.
#

SUMMARY = "Simple qtreplay application"
SECTION = "PETALINUX/apps"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://qtreplay.cpp \
		   file://mainwindow.h \
		   file://ui_mainwindow.h \
           file://qtreplay.pro \
           file://Makefile \
		  "



S = "${WORKDIR}"

require recipes-qt/qt5/qt5.inc

DEPENDS += "qtbase qtdeclarative icu ruby-native sqlite3 glib-2.0 libxslt qtxmlpatterns"




do_compile() {
	     oe_runmake
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 qtreplay ${D}${bindir}
}