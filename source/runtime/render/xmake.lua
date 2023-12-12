add_requires("vulkansdk", {system = true})

target("render")
    set_kind("static")
    set_languages("cxx20")
    add_includedirs("public", {public = true})
    add_includedirs("private/rps", {public = false})
    add_files(
        "private/**.cpp")
    -- add_files(
    --     "public/**.cppm")
    add_packages("vulkansdk")
    add_deps("mimalloc-xmake")

