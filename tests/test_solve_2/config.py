import pbs

e = pbs.Executable(self, 'test_solve_for', __file__)

#e.l_defines.append('ESOLV_RESOLVER_BASE_HPP_IN_LOGGER_COMPILE_MODE=logs::mode::COMPILE_TIME')
#e.l_defines.append('ESOLV_RESOLVER_BASE_HPP_IN_LOGGER_COMPILE_LEVEL=1')
#e.l_defines.append('ESOLV_SYMBOL_OPERAND_HPP_IN_LOGGER_COMPILE_LEVEL=1')

e.add_dep('esolv')
e.add_dep('graph')

e.args.append('-lglpk')

self.parts.append(e)

