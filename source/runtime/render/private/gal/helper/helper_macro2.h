// clang-format off
#if defined(GAL_INTERFACE)
#define __GAL_HELPER_MACRO__(ret, name, ...)                                                                           \
    ret name(__VA_ARGS__) { return (static_cast<gal_impl *>(this))->name(); }
#elif defined(GAL_IMPL_NULL)
#define __GAL_HELPER_MACRO__(ret, name, ...) \
ret name(__VA_ARGS__) {}
#else
#define __GAL_HELPER_MACRO__(ret, name, ...)
#error invalid
#endif


// clang-format on
//
// destroy gal_context
__GAL_HELPER_MACRO__(gal_error_code, destroy_gal, gal_context context);
// TODO(hyl5): how to add [[nodiscard]] attribute to these function?

// create gal instance, vkinstance or dxgifactory
__GAL_HELPER_MACRO__(gal_error_code, create_instance, gal_desc *desc, gal_context *context);
// destroy gal instance
__GAL_HELPER_MACRO__(gal_error_code, destroy_instance, gal_context *context);
// select required gpu and create gal device
__GAL_HELPER_MACRO__(gal_error_code, create_device, gal_desc *_gal_desc, gal_context *context);
// destroy gal device
__GAL_HELPER_MACRO__(gal_error_code, destroy_device, gal_context *context);
// create memory allocator, vma or d3dma
__GAL_HELPER_MACRO__(gal_error_code, create_memory_allocator, gal_context *context);
// destroy memory allocator
__GAL_HELPER_MACRO__(gal_error_code, destroy_memory_allocator, gal_context *context);
// resources
// create a gpu buffer and allocate gpu memory
__GAL_HELPER_MACRO__(gal_error_code, create_buffer, gal_context context, gal_buffer_desc *desc, gal_buffer *buffer);
// destroy a gpu buffer
__GAL_HELPER_MACRO__(gal_error_code, destroy_buffer, gal_context context, gal_buffer buffer);
// create a gpu texture and allocate memory
__GAL_HELPER_MACRO__(gal_error_code, create_texture, gal_context context, gal_texture_desc *desc, gal_texture *texture);
// destroy gpu texture
__GAL_HELPER_MACRO__(gal_error_code, destroy_texture, gal_context context, gal_texture texture);

__GAL_HELPER_MACRO__(gal_error_code, create_sampler, gal_context context, gal_sampler_desc *sampler_desc,
                     gal_sampler *sampler);
__GAL_HELPER_MACRO__(gal_error_code, destroy_sampler, gal_context context, gal_sampler sampler);

__GAL_HELPER_MACRO__(gal_error_code, create_render_target, gal_context context, gal_render_target_desc *desc,
                     gal_render_target *render_target);

__GAL_HELPER_MACRO__(gal_error_code, destroy_render_target, gal_context context, gal_render_target render_target);
// surface
__GAL_HELPER_MACRO__(gal_error_code, create_swap_chain, gal_context context, gal_swap_chain_desc *desc,
                     gal_swap_chain *_swap_chain);
__GAL_HELPER_MACRO__(gal_error_code, destroy_swap_chain, gal_context context, gal_swap_chain swap_chain);

// pipeline

//__GAL_HELPER_MACRO__(gal_error_code, create_shader, gal_context context, gal_shader_desc *desc, gal_shader *_shader);
//__GAL_HELPER_MACRO__(gal_error_code, destroy_shader, gal_context context, gal_shader _shader);
__GAL_HELPER_MACRO__(gal_error_code, create_shader_program, gal_context context, gal_shader_program_desc *desc,
                     gal_shader_program *shader_program);

__GAL_HELPER_MACRO__(gal_error_code, destroy_shader_program, gal_context context, gal_shader_program shader_program);
//__GAL_HELPER_MACRO__(gal_error_code, destroy_shader, gal_context context, gal_shader _shader);
//gal_error_code vk_create_shader_program(gal_context context, gal_shader_program_desc *desc,
//                                        gal_shader_program *_shader_program)

__GAL_HELPER_MACRO__(gal_error_code, create_pipeline_cache, gal_context context, gal_pipeline_cache_desc *desc,
                     gal_pipeline_cache *pipeline_cache);

__GAL_HELPER_MACRO__(gal_error_code, destroy_pipeline_cache, gal_context context, gal_pipeline_cache _pipeline_cache);

__GAL_HELPER_MACRO__(gal_error_code, get_pipeline_cache_data, gal_context context, gal_pipeline_cache _pipeline_cache,
                     uint64 *size, void *_data);
__GAL_HELPER_MACRO__(gal_error_code, create_compute_pipeline, gal_context context, gal_pipeline_desc *desc,
                     gal_pipeline *pipeline);
__GAL_HELPER_MACRO__(gal_error_code, create_graphics_pipeline, gal_context context, gal_pipeline_desc *desc,
                     gal_pipeline *pipeline);
// inline raytracing?
//__GAL_HELPER_MACRO__(gal_error_code, create_raytracing_pipeline, gal_context context,
//                     gal_raytracing_pipeline_desc *desc, gal_pipeline *pipeline);

__GAL_HELPER_MACRO__(gal_error_code, destroy_pipeline, gal_context context, gal_pipeline pipeline);

// consume the descriptor_set from pool
__GAL_HELPER_MACRO__(gal_error_code, get_descriptor_set, gal_context context, gal_descriptor_set_desc *desc,
                     uint32 set_count, gal_descriptor_set *sets);
__GAL_HELPER_MACRO__(gal_error_code, free_descriptor_set, gal_context context, gal_descriptor_set set,
                     bool free_all_pool);

__GAL_HELPER_MACRO__(gal_error_code, update_descriptor_set, gal_context context,
                     gal_descriptor_set_update_desc *update_desc, gal_descriptor_set set);
__GAL_HELPER_MACRO__(gal_error_code, create_root_signature, gal_context context, gal_root_signature_desc *desc,
                     gal_root_signature *root_signature);
__GAL_HELPER_MACRO__(gal_error_code, destroy_root_signature, gal_context context, gal_root_signature root_signature);
// sync
__GAL_HELPER_MACRO__(gal_error_code, create_fence, gal_context context, gal_fence *fence);
__GAL_HELPER_MACRO__(gal_error_code, wait_fences, gal_context context, gal_fence *fences, uint32 count);
__GAL_HELPER_MACRO__(gal_error_code, destroy_fence, gal_context context, gal_fence fence);
//__GAL_HELPER_MACRO__(gal_error_code, wait_gpu);
__GAL_HELPER_MACRO__(gal_error_code, create_semaphore, gal_context context, gal_semaphore *semaphore);
__GAL_HELPER_MACRO__(gal_error_code, destroy_semaphore, gal_context context, gal_semaphore semaphore);
// cmds
__GAL_HELPER_MACRO__(gal_error_code, create_command_pool, gal_context context, gal_command_pool_desc *desc,
                     gal_command_pool *command_pool);
__GAL_HELPER_MACRO__(gal_error_code, reset_command_pool, gal_context context, gal_command_pool command_pool);
__GAL_HELPER_MACRO__(gal_error_code, destroy_command_pool, gal_context context, gal_command_pool command_pool);
__GAL_HELPER_MACRO__(gal_error_code, get_command_list, gal_context context, gal_command_list_desc *desc,
                     gal_command_list *command);
__GAL_HELPER_MACRO__(gal_error_code, free_command_list, gal_context context, gal_command_list command);

__GAL_HELPER_MACRO__(gal_error_code, add_queue, gal_context context, gal_queue_desc *desc, gal_queue *queue);
__GAL_HELPER_MACRO__(gal_error_code, remove_queue, gal_context context, gal_queue queue);

__GAL_HELPER_MACRO__(gal_error_code, mapbuffer, gal_context context, gal_buffer buffer, read_range *range);
__GAL_HELPER_MACRO__(gal_error_code, unmapbuffer, gal_context context, gal_buffer buffer);

__GAL_HELPER_MACRO__(gal_error_code, cmd_begin, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_end, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_resource_barrier, gal_command_list command, uint32 buffer_barrier_count,
                     gal_buffer_barrier *buffer_barriers, uint32 texture_barrier_count,
                     gal_texture_barrier *texture_barriers);
__GAL_HELPER_MACRO__(gal_error_code, cmd_bind_index_buffer, gal_command_list command, gal_buffer index_buffer,
                     gal_index_type index_type, uint64 offset);
__GAL_HELPER_MACRO__(gal_error_code, cmd_bind_vertex_buffer, gal_command_list command, uint32 vertex_buffer_count,
                     gal_buffer *vertex_buffers, uint32 *stides, uint64 *offsets);
__GAL_HELPER_MACRO__(gal_error_code, cmd_bind_pipeline, gal_command_list command, gal_pipeline pipeline);
__GAL_HELPER_MACRO__(gal_error_code, cmd_begin_renderpass, gal_command_list command, gal_renderpass_begin_desc *desc);
__GAL_HELPER_MACRO__(gal_error_code, cmd_end_renderpass, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_dispatch, gal_command_list command, uint32 group_count_x, uint32 group_count_y,
                     uint32 group_count_z);
// __GAL_HELPER_MACRO__(gal_error_code, cmd_dispatch_indirect);
__GAL_HELPER_MACRO__(gal_error_code, cmd_draw_instanced, gal_command_list command, uint32 vertex_count,
                     uint32 first_vertex, uint32 instance_count, uint32 first_instance);
__GAL_HELPER_MACRO__(gal_error_code, cmd_draw_indexed_instanced, gal_command_list command, uint32 index_count,
                     uint32 first_index, uint32 instance_count, uint32 first_instance, uint32 first_vertex);
//__GAL_HELPER_MACRO__(gal_error_code, cmd_draw_indirect_instanced);
//__GAL_HELPER_MACRO__(gal_error_code, cmd_draw_indirect_indexed_instanced);
//__GAL_HELPER_MACRO__(gal_error_code, cmd_draw_mesh_task);
//__GAL_HELPER_MACRO__(gal_error_code, cmd_draw_indirect_mesh_task);
__GAL_HELPER_MACRO__(gal_error_code, cmd_copy_texture, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_copy_buffer, gal_command_list command, gal_buffer src, gal_buffer dst,
                     uint64 src_offset, uint64 dst_offset, uint64 size);
__GAL_HELPER_MACRO__(gal_error_code, cmd_fill_buffer, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_fill_texture, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_upload_buffer, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_upload_texture, gal_command_list command);
__GAL_HELPER_MACRO__(gal_error_code, cmd_update_subresources, gal_command_list command, gal_texture dst, gal_buffer src,
                     uint32 subresource_count, gal_texture_subresource_desc *descs);
__GAL_HELPER_MACRO__(gal_error_code, cmd_copy_texture_to_buffer, gal_command_list command);

__GAL_HELPER_MACRO__(gal_error_code, cmd_set_viewport, gal_command_list command, float32 x, float32 y, float32 width, float32 height,
                     float32 min_depth, float32 max_depth);
__GAL_HELPER_MACRO__(gal_error_code, cmd_set_scissor, gal_command_list command, int32 x, int32 y, uint32 width,
                     uint32 height);
__GAL_HELPER_MACRO__(gal_error_code, cmd_set_stencil_reference_value, gal_command_list command, uint32 val);
__GAL_HELPER_MACRO__(gal_error_code, queue_submit, gal_queue queue, gal_queue_submit_desc *desc);
__GAL_HELPER_MACRO__(gal_error_code, queue_present, gal_queue queue, gal_queue_present_desc *desc);

__GAL_HELPER_MACRO__(gal_error_code, acquire_next_image, gal_context context, gal_swap_chain swap_chain,
                     gal_semaphore signal_semaphore, gal_fence fence, uint32_t *image_index);

#ifdef __GAL_HELPER_MACRO__
#undef __GAL_HELPER_MACRO__
#endif // __GAL_HELPER_MACRO__

#if defined(GAL_IMPL_NULL)
#undef GAL_IMPL_NULL
#elif defined(GAL_INTERFACE)
#undef GAL_INTERFACE
#else
#endif

// #ifdef WIN32
// #def ine  DECLARE_GAL_RESOURCE(name) \
//    struct vk_##name;              \
//    struct d3d12_##name;           \
//    struct name                    \
//    {                              \
//        vk_##name *vk;             \
//        d3d12_##name *d3d12;       \
//    };
// #else
// #def ine  DECLARE_GAL_RESOURCE(name) \
//    struct vk_##name;              \
//    struct name                    \
//    {                              \
//        vk_##name *vk;             \
//    };
// #endif// WIN32

// TODO(hyl5): support multiple api?
