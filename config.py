import os
import pbs

l = pbs.Library(self, 'manim', __file__)

l.doc_out_dir = "/home/charles/WindowsShare/html/manim"

self.parts.append(l)

#self.execfile(os.path.join(__dir__, 'tests/config.py'))





