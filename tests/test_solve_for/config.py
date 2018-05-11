import pbs

e = pbs.Executable(self, 'test_solve_for', __file__)

e._test = True

e.add_dep('esolv')
e.add_dep('graph')
e.add_dep('gplot')

self.parts.append(e)

