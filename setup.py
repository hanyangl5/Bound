from script.build import BuildDesc
from script.test import Tests
# build
build_desc = BuildDesc()
tests = Tests()

build_desc.build()


tests.run()