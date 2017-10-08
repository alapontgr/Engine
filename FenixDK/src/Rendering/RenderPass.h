#pragma once

#include "Utilities/VulkanInclude.h"

namespace fdk {
namespace Rendering {

class RenderInterface;
class CommandBuffer;
class Framebuffer;

// TODO: Refactor that. Hide VK implementation of a render pass.
class RenderPass {

public:
  RenderPass();
  ~RenderPass();

  void init();

  void release(RenderInterface& rRI);

  VkRenderPass handle() const { return m_renderPassImpl; }

  void start(RenderInterface& rRI, CommandBuffer& rCmdBuffer, Framebuffer& rFramebuffer);

  void next_subpass(RenderInterface& rRI, CommandBuffer& rCmdBuffer);

  void end(RenderInterface& rRI, CommandBuffer& rCmdBuffer);

private:

  VkRenderPass m_renderPassImpl;
};

}
}