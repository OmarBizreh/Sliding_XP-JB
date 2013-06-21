/**
  src/audio_renderer/audio_renderer_test.h

  This simple test application take an input stream from a file,
  passes it to the audio_splitter component and writes the output
  streams to files.

  Copyright (C) 2007-2009 STMicroelectronics
  Copyright (C) 2007-2009  Nokia Corporation and/or its subsidiary(-ies).

  This library is free software; you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation; either version 2.1 of the License, or (at your option)
  any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
  details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St, Fifth Floor, Boston, MA
  02110-1301  USA

*/

#ifndef __AUDIO_RENDERER_TEST_H__
#define __AUDIO_RENDERER_TEST_H__

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>

#include <OMX_Core.h>
#include <OMX_Component.h>
#include <OMX_Types.h>
#include <OMX_Audio.h>

#include <bellagio/omx_comp_debug_levels.h>
#include <bellagio/tsemaphore.h>

#include <ctype.h>

#include "audio_renderer.h"

#define BUFFER_COUNT_ACTUAL 2

/** Specification version*/
#define VERSIONMAJOR    1
#define VERSIONMINOR    1
#define VERSIONREVISION 0
#define VERSIONSTEP     0

/* Application's private data */
typedef struct appPrivateType{

  int ipd;

  OMX_HANDLETYPE rendererHandle;
  tsem_t* eventSem;
  tsem_t* eofSem;

}appPrivateType;

OMX_ERRORTYPE audiorendererEventHandler(
  OMX_HANDLETYPE hComponent,
  OMX_PTR pAppData,
  OMX_EVENTTYPE eEvent,
  OMX_U32 Data1,
  OMX_U32 Data2,
  OMX_PTR pEventData);

OMX_ERRORTYPE audiorendererEmptyBufferDone(
  OMX_HANDLETYPE hComponent,
  OMX_PTR pAppData,
  OMX_BUFFERHEADERTYPE* pBuffer);

#endif
