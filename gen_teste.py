#!/usr/bin/env python3

import random
import shutil
import os

# Generate first 3 tests
N_min = 5
N_max = 30

for i in range(3):
    N = random.randint(N_min, N_max)
    print(f'Test {i}: N = {N:5d}', end= ', ')
    open(f'teste/lego-{i}.in', 'w').write(str(N))

    shutil.copyfile(f'teste/lego-{i}.in', 'lego.in')
    os.system('exec/sol_dp')

    R = int(open('lego.out').read())
    print(f'Solution: {R}')

    shutil.copyfile('lego.out', f'teste/lego-{i}.ok')

    os.remove('lego.in')
    os.remove('lego.out')

# Generate the rest
N_min = 30
N_max = 5000

for i in range(3, 10):
    N = random.randint(N_min, N_max)
    print(f'Test {i}: N = {N:5d}', end=', ')
    open(f'teste/lego-{i}.in', 'w').write(str(N))

    shutil.copyfile(f'teste/lego-{i}.in', 'lego.in')
    os.system('exec/sol_dp')

    R = int(open('lego.out').read())
    print(f'Solution: {R}')

    shutil.copyfile('lego.out', f'teste/lego-{i}.ok')

    os.remove('lego.in')
    os.remove('lego.out')
