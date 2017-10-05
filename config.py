import os
import pbs2

l = pbs2.Library(self, 'manim', __file__)

l.doc_out_dir = "/media/sf_P_DRIVE/html/manim"

self.parts.append(l)

#self.execfile(os.path.join(__dir__, 'tests/config.py'))





