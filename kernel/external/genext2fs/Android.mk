# Copyright 2008 The Android Open Source Project

LOCAL_PATH:= $(call my-dir)

################################
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	genext2fs.c

LOCAL_CFLAGS := -O2 -g -Wall -DHAVE_CONFIG_H -DANDROID_STATS_FIXING

LOCAL_MODULE := genext2fs

include $(BUILD_HOST_EXECUTABLE)
