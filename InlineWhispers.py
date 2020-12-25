#!/usr/bin/env python
# coding: utf-8
import re

functionsInName = "functions.txt"
fileInName = "syscalls.asm"
fileOutName = fileInName.replace('.asm','-asm.h')

print(r"""
 ________          __    _____.__                 __
 \_____  \  __ ___/  |__/ ____\  | _____    ____ |  | __
  /   |   \|  |  \   __\   __\|  | \__  \  /    \|  |/ /
 /    |    \  |  /|  |  |  |  |  |__/ __ \|   |  \    <
 \_______  /____/ |__|  |__|  |____(____  /___|  /__|_ \
         \/                             \/     \/     \/
                                   InlineWhispers
                              By @_DaWouw @Outflank 2020
""")
print("[i] in  {}".format(fileInName))
print("[i] out {}".format(fileOutName))

regexFunctionStart = re.compile(r'([a-z0-9]{1,70})(\s+PROC)', re.IGNORECASE)
regexFunctionEnd = re.compile(r'([a-z0-9]{1,70})(\s+ENDP)', re.IGNORECASE)
regexAsmComment = re.compile(r'([^;\r\n]*)', re.IGNORECASE)
regexHexNotation = re.compile(r'([^;\r\n]*[\s\+\[])([0-9a-f]{1,5})(?:h)([^;\r\n]*)', re.IGNORECASE)

functions = []
filterFunctions = False
try:
	with open(functionsInName, mode='r') as functionsIn:
		functions = ['Nt'+f[2:] if f[:2] == 'Zw' else f for f in [l.strip() for l in functionsIn.readlines()]]
		filterFunctions = len(functions) and "*" not in functions
		print('[i] Function filter file "{}" contains {} functions.'.format(functionsInName,len(functions)))
except:
	print('[i] Function filter file "{}" not found. So not filtering functions.'.format(functionsInName))

filterThisFunction = False
with open(fileInName, mode='r') as fileIn:
	lines = fileIn.readlines()
	lines.pop(0)	#remove .code line
	
	out = '#pragma once\n#include "Syscalls.h"\n'
	inFunction = False
	for line in lines:
		if inFunction:
			if regexFunctionEnd.match(line):
				inFunction = False
				out += '' if filterThisFunction else '");'+'\n'
			elif not filterThisFunction:
				mhex = regexHexNotation.match(line)
				if mhex:
					out += mhex[1]+'0x'+mhex[2]+mhex[3]+' \\n\\'+'\n'
				else:
					out += regexAsmComment.match(line)[1]+' \\n\\'+'\n'
		else:
			mstart = regexFunctionStart.match(line)
			if mstart:
				inFunction = True
				filterThisFunction = filterFunctions and not(mstart[1] in functions)
				out += '' if filterThisFunction else '#define Zw'+mstart[1][2:]+' '+mstart[1]+'\n'
				out += '' if filterThisFunction else '__asm__("'+mstart[1]+': \\n\\'+'\n'
			elif not filterThisFunction:
				out += '\n'
	
	with open(fileOutName, mode='w') as fileOut:
		fileOut.write(out)
		fileOut.close()
		print("[+] Success!")
	