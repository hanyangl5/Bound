target("utils")
    set_kind("static")
    set_languages("c99", "cxx20")
    add_includedirs("public", {public = true})
    add_includedirs("private", {public = false})
    add_files(
        "public/stl/*.mpp",
        "public/utils/*.mpp")

    --add_deps("mimalloc-xmake")

