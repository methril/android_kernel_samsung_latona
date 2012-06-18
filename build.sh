#!/bin/sh
#
# Kernel build script
#
# By Mark "Hill Beast" Kennard
#

TOOLCHAIN=/usr/arm-toolchain/bin/arm-eabi-
ARCH=arm
MKBOOTIMG=./mkbootimg
RAMDISK=~/devel/android/cm9/out/target/product/galaxysl/bootstrap.cpio.gz
BOOTIMAGE=normalboot.img

if [ -z $1 ]; then
	if [ -z $KBUILD_BUILD_VERSION ]; then
		export KBUILD_BUILD_VERSION="Test-`date '+%Y%m%d-%H%M'`"
	fi
	echo "Kernel will be labelled ($KBUILD_BUILD_VERSION)"
else
	if [ $1 = "config" ]; then
		make menuconfig CROSS_COMPILE=$TOOLCHAIN ARCH=$ARCH
		exit
	fi
	if [ $1 = "saveconfig" ]; then
		if [ -z $2 ]; then
			echo "You need to specify a defconfig filename"
			echo "./build.sh saveconfig [x_defconfig]"
			exit
		fi
		if test -f arch/$ARCH/configs/$2; then
			cp arch/$ARCH/configs/$2 arch/$ARCH/configs/$2.bak
		fi
		grep "=" .config > arch/$ARCH/configs/$2
		echo ".config saved to arch/$ARCH/configs/$2"
		exit
	fi
	echo "Setting kernel name to ($1)"
	export KBUILD_BUILD_VERSION=$1
fi

echo "Compiling the kernel"
if test -f arch/arm/boot/zImage; then
	rm arch/arm/boot/zImage
fi

make -j2 CROSS_COMPILE=$TOOLCHAIN ARCH=$ARCH


if test -f arch/arm/boot/zImage; then
	TARBALL=$KBUILD_BUILD_VERSION-boot.tar

	echo "  BOOTIMG $BOOTIMAGE using ramdisk ($RAMDISK)"
	$MKBOOTIMG --kernel arch/arm/boot/zImage --ramdisk $RAMDISK --pagesize 1000 -o $BOOTIMAGE
	echo "  TAR     $TARBALL"
	tar cf $TARBALL $BOOTIMAGE
else
	echo "Will not tarball as make didn't produce zImage"
fi

echo "Done"
