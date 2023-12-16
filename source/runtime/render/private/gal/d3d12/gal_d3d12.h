// #pragma once

// // standard libraries
// // third party libraries

// // project headers
// import types;
// #include "render/gal/gal.h"

// namespace bd::gal {

// #define D3D12_FUNCTION_DECLARE
// #include "../helper/helper_macro.h"
// #undef D3D12_FUNCTION_DECLARE

// } // namespace bd::gal

#pragma once
#include "../shader/shader_compiler.h"
#include "gal_d3d12_enum.h"
#include "render/gal/gal.h"

namespace bd {
namespace gal {

constexpr bd::stl::str gal_d3d12_logger = "d3d12_logger";

class gal_impl_d3d12 : public gal_interface<gal_impl_d3d12> {
  public:
    gal_error_code init_gal(gal_context *context);

    gal_error_code destroy_gal(gal_context context);

    gal_error_code create_instance(gal_desc *gal_desc, gal_context *context);
    gal_error_code destroy_instance(gal_context *context);
    gal_error_code create_device(gal_desc *gal_desc, gal_context *context);

    gal_error_code destroy_device(gal_context *context);

    gal_error_code create_memory_allocator(gal_context *context);
    gal_error_code destroy_memory_allocator(gal_context *context);

    gal_error_code create_buffer(gal_context context, gal_buffer_desc *desc, gal_buffer *buffer);

    gal_error_code destroy_buffer(gal_context context, gal_buffer buffer);

    gal_error_code create_texture(gal_context context, gal_texture_desc *desc, gal_texture *texture);

    gal_error_code destroy_texture(gal_context context, gal_texture texture);

    gal_error_code create_sampler(gal_context context, gal_sampler_desc *sampler_desc, gal_sampler *sampler);

    gal_error_code destroy_sampler(gal_context context, gal_sampler sampler);

    gal_error_code create_render_target(gal_context context, gal_render_target_desc *desc,
                                        gal_render_target *render_target);

    gal_error_code destroy_render_target(gal_context context, gal_render_target render_target);

    gal_error_code create_swap_chain(gal_context context, gal_swap_chain_desc *desc, gal_swap_chain *swap_chain);
    gal_error_code destroy_swap_chain(gal_context context, gal_swap_chain swap_chain);

    gal_error_code create_shader_program(gal_context context, gal_shader_program_desc *desc,
                                         gal_shader_program *shader_program);

    gal_error_code destroy_shader_program(gal_context context, gal_shader_program shader_program);

    gal_error_code create_pipeline_cache(gal_context context, gal_pipeline_cache_desc *desc,
                                         gal_pipeline_cache *pipeline_cache);
    gal_error_code destroy_pipeline_cache(gal_context context, gal_pipeline_cache _pipeline_cache);
    gal_error_code get_pipeline_cache_data(gal_context context, gal_pipeline_cache _pipeline_cache, uint64 *_size,
                                           void *_data);

    gal_error_code create_compute_pipeline(gal_context context, gal_pipeline_desc *desc, gal_pipeline *pipeline);

    gal_error_code create_graphics_pipeline(gal_context context, gal_pipeline_desc *desc, gal_pipeline *pipeline);

    gal_error_code create_raytracing_pipeline(gal_context context, gal_raytracing_pipeline_desc *desc,
                                              gal_pipeline *pipeline);

    gal_error_code destroy_pipeline(gal_context context, gal_pipeline pipeline);

    //we don't expose descriptor pool creation in gal A descriptor pool maintains a pool of descriptors, from which
    //    descriptor sets are allocated.Descriptor pools are externally synchronized,
    //    meaning that the application must not allocate and / or
    //        free descriptor sets from the same pool in multiple threads simultaneously.

    gal_error_code get_descriptor_set(gal_context context, gal_descriptor_set_desc *desc, uint32 set_count,
                                      gal_descriptor_set *sets);
    gal_error_code free_descriptor_set(gal_context context, gal_descriptor_set set, bool free_all_pool);
    //FIXME(hyl5)
    //    : this function is too messy
    gal_error_code update_descriptor_set(gal_context context, gal_descriptor_set_update_desc *update_desc,
                                         gal_descriptor_set set);
    //FIXME(hyl5)
    //    : this function is too messy
    gal_error_code create_root_signature(gal_context context, gal_root_signature_desc *desc,
                                         gal_root_signature *root_signature);
    gal_error_code destroy_root_signature(gal_context context, gal_root_signature root_signature);

    //sync
    gal_error_code create_fence(gal_context context, gal_fence *fence);
    gal_error_code wait_fences(gal_context context, gal_fence *fences, uint32 count);

    gal_error_code getFenceStatus(gal_context context, gal_fence fence, gal_fence_status *fence_status);

    gal_error_code destroy_fence(gal_context context, gal_fence fence);
    gal_error_code wait_gpu();
    gal_error_code create_semaphore(gal_context context, gal_semaphore *semaphore);

    gal_error_code destroy_semaphore(gal_context context, gal_semaphore semaphore);
    // cmds
    gal_error_code create_command_pool(gal_context context, gal_command_pool_desc *desc,
                                       gal_command_pool *command_pool);
    gal_error_code reset_command_pool(gal_context context, gal_command_pool command_pool);
    gal_error_code destroy_command_pool(gal_context context, gal_command_pool command_pool);

    gal_error_code get_command_list(gal_context context, gal_command_list_desc *desc, gal_command_list *command);

    gal_error_code free_command_list(gal_context context, gal_command_list command);

    gal_error_code mapbuffer(gal_context context, gal_buffer buffer, read_range *range);

    gal_error_code unmapbuffer(gal_context context, gal_buffer buffer);
    //TODO(hylu) : gal_error_code create_command_list;

    gal_error_code cmd_begin(gal_command_list command);

    gal_error_code cmd_end(gal_command_list command);
    gal_error_code cmd_set_render_target();
    gal_error_code cmd_set_viewport(gal_command_list command, float32 x, float32 y, float32 width, float32 height,
                                    float32 min_depth, float32 max_depth);

    gal_error_code cmd_set_scissor(gal_command_list command, int32 x, int32 y, uint32 width, uint32 height);

    gal_error_code cmd_set_stencil_reference_value(gal_command_list command, uint32 val);

    gal_error_code cmd_resource_barrier(gal_command_list command, uint32 buffer_barrier_count,
                                        gal_buffer_barrier *buffer_barriers, uint32 texture_barrier_count,
                                        gal_texture_barrier *texture_barriers);

    gal_error_code cmd_bind_index_buffer(gal_command_list command, gal_buffer index_buffer, gal_index_type index_type,
                                         uint64 offset);
    gal_error_code cmd_bind_vertex_buffer(gal_command_list command, uint32 vertex_buffer_count,
                                          gal_buffer *vertex_buffers, [[maybe_unused]] uint32 *strides,
                                          uint64 *offsets);
    gal_error_code cmd_bind_descriptor_set();

    gal_error_code cmd_bind_push_constant(gal_command_list command, gal_root_signature root_signature, const char *name,
                                          void *data, uint64 size);

    gal_error_code cmd_bind_pipeline(gal_command_list command, gal_pipeline pipeline);
    gal_error_code cmd_begin_renderpass(gal_command_list command, gal_renderpass_begin_desc *desc);
    gal_error_code cmd_end_renderpass(gal_command_list command);
    gal_error_code cmd_dispatch(gal_command_list command, uint32 group_count_x, uint32 group_count_y,
                                uint32 group_count_z);

    gal_error_code cmd_draw_instanced(gal_command_list command, uint32 vertex_count, uint32 first_vertex,
                                      uint32 instance_count, uint32 first_instance);
    gal_error_code cmd_draw_indexed_instanced(gal_command_list command, uint32 index_count, uint32 first_index,
                                              uint32 instance_count, uint32 first_instance, uint32 first_vertex);

    gal_error_code cmd_dispatch_indirect();
    gal_error_code cmd_draw_indirect_instanced();
    gal_error_code cmd_draw_indirect_indexed_instanced();

    gal_error_code cmd_draw_indirect_mesh_task();

    gal_error_code cmd_draw_mesh_task(gal_command_list command);
    gal_error_code cmd_copy_texture(gal_command_list command);

    gal_error_code cmd_copy_buffer(gal_command_list command, gal_buffer src, gal_buffer dst, uint64 src_offset,
                                   uint64 dst_offset, uint64 size);
    gal_error_code cmd_fill_buffer(gal_command_list command);
    gal_error_code cmd_fill_texture(gal_command_list command);
    gal_error_code cmd_upload_buffer(gal_command_list command);
    gal_error_code cmd_upload_texture(gal_command_list command);
    gal_error_code cmd_update_subresources(gal_command_list command, gal_texture dst, gal_buffer src,
                                           uint32 subresource_count, gal_texture_subresource_desc *descs);
    gal_error_code cmd_copy_texture_to_buffer(gal_command_list command);

    gal_error_code cmd_set_shading_rate();

    gal_error_code add_queue(gal_context context, gal_queue_desc *desc, gal_queue *queue);

    gal_error_code remove_queue(gal_context context, gal_queue queue);

    gal_error_code queue_submit(gal_queue queue, gal_queue_submit_desc *desc);

    gal_error_code queue_present(gal_queue queue, gal_queue_present_desc *desc);

    gal_error_code acquire_next_image(gal_context context, gal_swap_chain swap_chain, gal_semaphore signal_semaphore,
                                      gal_fence fence, uint32_t *image_index);

    gal_error_code wait_queue(gal_queue queue);

    gal_error_code create_srvuav(gal_context context, gal_texture texture);

    //pipeline
    //gal_error_code create_shader(gal_context context, gal_shader_desc *desc, gal_shader *_shader);
    //gal_error_code destroy_shader(gal_context context, gal_shader _shader);
};

} // namespace gal
} // namespace bd