import os

class BuildDesc():
    def __init__(self):
        self.build_type = "release"
        self.build_editor = "false"
        self.rebuild = False
        self.toolchain = "msvc"
        self.cross_compile = False
        # cross compile
        self.target_platform = "windows"
        self.build_thread = 0
    def clean(self):
        os.system ("xmake clean")
    def build(self):
        if self.rebuild:
            self.clean()
        setup_toolchain_cmd = "xmake f --toolchain=" + self.toolchain
        os.system(setup_toolchain_cmd)
        
        build_cmd = "xmake "
        if self.build_thread != 0:
            build_cmd += "-j" + str(self.build_thread)
        os.system (build_cmd)
        
