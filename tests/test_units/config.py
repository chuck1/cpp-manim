import pbs

e = pbs.Executable(self, 'esolv_test_units', __file__)

#e.l_defines.append('ESOLV_RESOLVER_BASE_HPP_IN_LOGGER_COMPILE_MODE=logs::mode::COMPILE_TIME')
#e.l_defines.append('ESOLV_RESOLVER_BASE_HPP_IN_LOGGER_COMPILE_LEVEL=1')
#e.l_defines.append('ESOLV_SYMBOL_OPERAND_HPP_IN_LOGGER_COMPILE_LEVEL=1')

e.add_dep("esolv")
e.add_dep("graph")

self.parts.append(e)

