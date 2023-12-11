import os
class Tests():
    def __init__(self):
        self.run_test = True
        self.run_test_cmd = "xmake run"
    def run(self):
        if self.run_test == True:
            os.system(self.run_test_cmd)

