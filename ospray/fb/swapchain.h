#pragma once

#include "framebuffer.h"
#include <vector>

namespace ospray {
  struct SwapChain;
  struct FrameBuffer;

  /*! typedef for a 'factory' function that returns frame buffers of a given type */
  typedef FrameBuffer *(*FrameBufferFactory)(const vec2i &fbSize);

  /*! class that implements a 'swap chain' of frame buffers of a given size */
  struct SwapChain {
    SwapChain(const size_t numFBs, 
              const vec2i &fbSize, 
              FrameBufferFactory fbFactory);
    const void *map();
    void unmap(const void *mapped);

    /*! return framebuffer on frontend side (the one we can map on the host) */
    Ref<FrameBuffer> &getFrontBuffer() 
    { return swapChain[frontBufferPos]; }
    /*! return framebuffer on backend side (the one the next renderer will write to) */
    Ref<FrameBuffer> &getBackBuffer()  
    { return swapChain[(frontBufferPos+1)%swapChain.size()]; }
    
    std::vector<Ref<FrameBuffer> > swapChain;
    std::vector<long>              lastRendered;
    const vec2i                    fbSize;
    FrameBufferFactory             fbFactory;
    int                            frontBufferPos;
  };
}