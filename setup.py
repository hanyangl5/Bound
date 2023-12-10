from script.build import BuildDesc
# build
build_desc = BuildDesc()

build_desc.build()

run_test = False
if run_test:
    # communicate with xmake to get test program list
    pass