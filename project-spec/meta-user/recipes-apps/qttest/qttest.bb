#
# This file is the qttest recipe.
#

SUMMARY = "Simple qttest application"
SECTION = "PETALINUX/apps"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://qttest.cpp \
           file://qttest.pro \
		  "



S = "${WORKDIR}"

require recipes-qt/qt5/qt5.inc

DEPENDS += "qtbase qtwebkit qtdeclarative icu ruby-native sqlite3 glib-2.0 libxslt qtxmlpatterns"

RDEPENDS_${PN} += "qtwebkit-qmlplugins"
RDEPENDS_${PN} += "${@bb.utils.contains('PACKAGECONFIG_OPENSSL', 'openssl', 'ca-certificates', '', d)}"



do_compile() {
	     oe_runmake
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 qttest ${D}${bindir}
}
