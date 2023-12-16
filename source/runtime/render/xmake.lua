add_requires("vulkansdk", { system = true })
target("render")
	set_kind("static")
	set_languages("cxx20")
	add_includedirs("public", { public = true })
	add_includedirs("private/rps", { public = false })
	add_includedirs("private/gal", { public = false })
	add_includedirs("../utils/public", { public = false })

	add_includedirs(path.join(bound_third_party_dir ,"D3D12MemoryAllocator/include"), {public = false})
	add_includedirs(path.join(bound_third_party_dir ,"VulkanMemoryAllocator/include"), {public = false})

	add_rules("setup_dxc")
	add_includedirs(dxc_inc, {public = false})
	
	--add_files("private/rps/**.cpp")
	--add_files("private/gal/vulkan/gal_vulkan2.cpp")
	add_files("private/gal/**.cpp")
	-- if not is_plat("windows") then
	-- 	remove_files("private/rps/runtime/d3d*/*.cpp")
	-- 	add_defines("BD_IGNORE_D3D")
	-- end
	if is_plat("windows") then
		add_defines("NOMINMAX") -- spirvcross conflict with wnidows
	end
	add_packages("vulkansdk")
	add_deps("utils", "platform")
	
	add_deps("d3d12ma-xmake", "spirv-cross-xmake")